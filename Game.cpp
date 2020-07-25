#include "Game.h"
#include <iostream>
#include "AudioPlayer.h"
Game::Game()
{
	main_window_ = new sf::RenderWindow(sf::VideoMode(1280, 720), "SkullGame", sf::Style::Close | sf::Style::Titlebar);
	main_window_->setFramerateLimit(500);
	player = new Player(100, sf::Vector2f(15, 15));
	enemies = new Enemies();
	background_ = new Background();
	main_window_->setKeyRepeatEnabled(false);
	player_shoot_available_time_ = 1000.f;
	player_ammune_ = false;
	interface_ = new Interface();
	player_laser_available_ = true;
}

Game::~Game()
{
	delete main_window_;
	delete player;
	delete enemies;
}

void Game::PollWindowEvent()
{
	while (main_window_->pollEvent(this->evnt_))
	{
		switch (evnt_.type)
		{
		case sf::Event::Closed:
				main_window_->close();
				break;
		case sf::Event::KeyPressed:
			if (evnt_.key.code==sf::Keyboard::Escape)
				main_window_->close();
			break;
		}
	}
}

int Game::Update()
{
	

		this->PollWindowEvent();
		//player movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			player->setPos(sf::Vector2f(player->getPos().x+0.3, player->getPos().y));
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			player->setPos(sf::Vector2f(player->getPos().x-0.3, player->getPos().y));
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			player->setPos(sf::Vector2f(player->getPos().x, player->getPos().y-0.3));
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			player->setPos(sf::Vector2f(player->getPos().x, player->getPos().y+0.3));
		// check if player out of bounds
		if (player->getPos().y < 0)
			player->setPos(sf::Vector2f(player->getPos().x,0));
		else if (player->getPos().y > main_window_->getSize().y)
			player->setPos(sf::Vector2f(player->getPos().x,350));
		if (player->getPos().x < 0)
			player->setPos(sf::Vector2f(0 + 5, player->getPos().y));
		else if (player->getPos().x > main_window_->getSize().x)
			player->setPos(sf::Vector2f(650, player->getPos().y));
		// spawning and moving of enemies
		enemies->UpdateEnemies(static_cast<int>(main_window_->getSize().x),static_cast<int>(main_window_->getSize().y));
		//update background
		background_->UpdateBackground(static_cast<int>(main_window_->getSize().x), static_cast<int>(main_window_->getSize().y));
		//move and animate projectile if it exists, and spawn it on space button press
		if (player->laser_ != nullptr)
		{
			player->laser_->AnimateProjectile();
			if (player->laser_->GetProjectileSprite().getPosition().x > main_window_->getSize().x)
				player->DeleteLaser();
			if(player->laser_->Move()) // the laser moves and checks for colissions in that frame
			{ 
				//collision detection between laser and enemies
				//spawns points for the player to pick up
				//spawns explosion
				for (int i = 0; i < enemies->GetEnemyVector().size(); i++)
				{
					if (CollisionDetection(player->laser_->GetProjectileSprite(), *enemies->GetEnemyVector()[i]))
					{
						SpawnPoint(enemies->GetEnemyVector()[i]->getPosition());
						SpawnExplosion(enemies->GetEnemyVector()[i]->getPosition());
						enemies->GetEnemyVector().erase(enemies->GetEnemyVector().begin() + i);
						player->DeleteLaser();
						SoundEffectPlayer.PlayExplosionSound();
						break;
					}
				}
			}
		}
		// laser spawning when the timer is out
		if (player_shoot_available_time_ <= 0.f)
		{
			player_laser_available_ = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				player->ShootLaser();
				SoundEffectPlayer.PlayLaserSound();
				player_shoot_available_time_ = 8000.f;
			}
		}
		else
		{
			player_shoot_available_time_ -= 1.f;
			player_laser_available_ = false;
		}

		// collision detection between player and enemies
		bool collision_happening = false;
		if (enemies->GetEnemyVector().size() > 0)
			for (int i=0;i<enemies->GetEnemyVector().size();i++)
				if (PlayerEnemySpecificCollision(*enemies->GetEnemyVector()[i]))
				{
					collision_happening = true; // checks if at least one collision has happened
					if (!player_ammune_)
					{
						SpawnExplosion(enemies->GetEnemyVector()[i]->getPosition());
						enemies->GetEnemyVector().erase(enemies->GetEnemyVector().begin() + i);
						player->SetLife(player->GetLife()-10);
						SoundEffectPlayer.PlayExplosionSound();
						player_ammune_ = true; // once a collision is detected player is ammune from another collision until the current one ends
					}
				}
		if (!collision_happening)
		{
			// resets the player ammunity if no collsions were detected in that frame
			player_ammune_ = false;
	
		}

		// point aniamtion and expiration
		UpdatePoints();

		// points collision 
		for (int i=0;i<points_.size();i++)
			if (CollisionDetection(player->GetPlayerSprite(), points_[i]->GetSprite()))
			{
				player->SetPoints(player->GetPoints()+1);
				points_.erase(points_.begin() + i);
			}

		// updates ongoing explosions and removes the finished ones
		UpdateExplosion();

		// interface text updates
		interface_->setLife(player->GetLife());
		interface_->setPoints(player->GetPoints());
		interface_->changeAvailability(player_laser_available_);

		
			
	return 0;
}

void Game::Render()
{
	main_window_->clear(sf::Color(5,5,5,200));
	//draws here
	background_->RenderBackground(main_window_);
	enemies->RenderEnemies(main_window_);
	player->RenderPlayer(main_window_);
	for (auto i : points_)
		i->RenderPoint(main_window_);
	for (auto i : explosions_)
		i->RenderExplosion(main_window_);
	interface_->Render(main_window_);
	//
	main_window_->display();

}

bool Game::CollisionDetection(sf::Sprite & s1, sf::Sprite & s2)
{
	if (&s1 != nullptr)
	{
		return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
	}
}

void Game::SpawnPoint(sf::Vector2f pos)
{
	points_.push_back(new Point(pos));
}

void Game::UpdatePoints()
{
	for (int i = 0; i<points_.size(); i++)
	{
		if (points_[i]->CheckExpired())
			points_.erase(points_.begin() + i);
	}
	for (auto i : points_)
	{
		i->AnimatePoint();
	}
}


void Game::SpawnExplosion(sf::Vector2f pos)
{
	explosions_.push_back(new Explosion(pos));
}

void Game::UpdateExplosion()
{
	for (int i = 0; i < explosions_.size(); i++)
	{
		if (explosions_[i]->AnimateExplosion())
			explosions_.erase(explosions_.begin() + i);
	}
}

bool Game::PlayerEnemySpecificCollision(sf::Sprite& enemy)
{
	// a more precise way of detecting a collision between a layer and an enemy, need for the game to be playable
	sf::Rect<float>* rect_col;
	bool collision = false;

	// a smaller collision detection box, which detects more precise collision between the player and the enemies
	rect_col = new sf::Rect<float>(enemy.getGlobalBounds().left + 100, enemy.getGlobalBounds().top + 100, 80, 80);

	if (player->GetPlayerSprite().getGlobalBounds().intersects(*rect_col))
		collision = true;
	delete rect_col;
	return collision;
}

bool Game::GameOverCondCheck()
{
	if (player->GetLife() == 0)
		return true;
	else
	  return false;
}

void Game::Reset()
{
	player->SetLife(100);
	player->SetPoints(0);
}

int Game::getPlayerPoints()
{
	return player->GetPoints();
}
