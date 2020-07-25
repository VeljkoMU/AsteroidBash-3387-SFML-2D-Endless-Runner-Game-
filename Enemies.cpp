#include "Enemies.h"

void Enemies::InitSpawnTimer()
{
	std::srand(static_cast<unsigned>(time(NULL)));
	spawn_timer_ = 50.f;
}

Enemies::Enemies()
{
	this->InitSpawnTimer();
	enemy_texture_.loadFromFile("Resources/Textures/asteroidtexturesheet.png");
	enemy_texture_rect_ = new sf::IntRect(0, 0, 220, 220);
	enemy_move_speed_ = 0.45;
	enemy_move_speed_offset_ = 0.f;
	enemy_animation_timer_ = 50.f;
}

Enemies::~Enemies()
{
	delete enemy_texture_rect_;
}

void Enemies::SpawnEnemy(int size_of_main_window_x, int size_of_main_window_y)
{
	if (max_num_ == enemies_.size())
		return;
	float x = static_cast<float>(size_of_main_window_x);
	float y = static_cast<float>(rand()% (size_of_main_window_y));


	sf::Sprite* enemy = new sf::Sprite(enemy_texture_,*enemy_texture_rect_);
	enemy->setPosition(x, y);
	enemies_.push_back(enemy);
	
}

void Enemies::UpdateEnemies(int size_of_main_window_x, int size_of_main_window_y)
{
	if (spawn_timer_==max_spawn_time_)
	{
		SpawnEnemy(size_of_main_window_x, size_of_main_window_y);
		spawn_timer_ = 0;
	}
       else
		spawn_timer_ += 1.f;
	for (auto i : enemies_)
	{
		i->move(-(enemy_move_speed_+enemy_move_speed_offset_), 0);
		if (enemy_move_speed_offset_<0.1)
			enemy_move_speed_offset_ += 0.000000001f;
	}
	

	for (int i = 0; i < enemies_.size(); i++)
	{
		if (enemies_[i]->getPosition().x < 0)
		{
			sf::Sprite* delptr = enemies_[i];
			enemies_.erase(enemies_.begin() + i);
			delete delptr;
		}
	}
	AnimateEnemies();

}

void Enemies::RenderEnemies(sf::RenderWindow* renderwin)
{
	for (auto i : enemies_)
		renderwin->draw(*i);
}

void Enemies::AnimateEnemies()
{
	if (enemy_animation_timer_ <= 0.f)
	{
		if (enemy_texture_rect_->top == 660)
			enemy_texture_rect_->top = 0;
		else
			enemy_texture_rect_->top += 220;
		for (auto i : enemies_)
			i->setTextureRect(*enemy_texture_rect_);
		enemy_animation_timer_ = 400.f;
	}
	else
	enemy_animation_timer_ -= 1.f;
}
