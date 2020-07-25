#include "Player.h"

Player::Player()
{
	p_life_ = 50;
	p_pos_ = sf::Vector2f(0.f, 0.f);
	laser_ = nullptr;
	points_gathered_ = 0;
}

Player::Player(int life, sf::Vector2f startpos)
{
	p_life_ = life;
	p_pos_ = startpos;
	InitSprite();
	laser_ = nullptr;
	points_gathered_ = 0;

}

Player::~Player()
{
	//delete player_;
	delete laser_;
}

void Player::InitSprite()
{
	player_texture_.loadFromFile("Resources/Textures/playerspritesheet1.png");
	rectSprite = new sf::IntRect(0, 0, 150, 103);
	player_sprite_.setTexture(player_texture_,rectSprite);
	player_sprite_.setPosition(p_pos_);
}

//void Player::AnimatePlayer(sf::Clock& clock)
//{
//	// player animation 
//	if (clock.getElapsedTime().asSeconds() > 1.0f)
//	{
//		if (rectSprite->top == 192)
//			rectSprite->top = 0;
//		else
//			rectSprite->top = 192;
//		clock.restart();
//	}
//	player_sprite_.setTextureRect(*rectSprite);
//}

void Player::setPos(sf::Vector2f pos)
{
	p_pos_ = pos;
	player_sprite_.setPosition(pos);
}

sf::Vector2f Player::getPos()
{
	return p_pos_;
}


void Player::SetLife(int points)
{

	p_life_ = points;
}

int Player::GetLife()
{
	return p_life_;
}

void Player::SetPoints(int newpoints)
{
	points_gathered_ = newpoints;
}

void Player::RenderPlayer(sf::RenderWindow * r)
{
	r->draw(player_sprite_);
	if(laser_!=nullptr)
	   laser_->RenderProjectile(r);
}

void Player::ShootLaser()
{
	laser_ = new Projectile(p_pos_, 50.f);
}

void Player::DeleteLaser()
{
	Projectile* delptr = laser_;
	laser_ = nullptr;
	delete delptr;
}
