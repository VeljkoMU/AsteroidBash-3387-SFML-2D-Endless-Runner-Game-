#pragma once
#include "SFMLINCLUDE.h"
#include <ctime>
#include<vector>

class Enemies {

private:
	//private vars
	std::vector<sf::Sprite*> enemies_;
	sf::Texture enemy_texture_;
	sf::IntRect* enemy_texture_rect_;
	const int max_num_=20;
	const float max_spawn_time_=800.f;
	float spawn_timer_;
	float enemy_move_speed_;
	float enemy_move_speed_offset_;
	float enemy_animation_timer_;

	//privte methods
	void InitSpawnTimer();


public:
	// constructors destcrucotes
	Enemies();
	~Enemies();

	// public methods
	void SpawnEnemy(int size_of_main_window_x,  int size_of_main_window_y);
	void UpdateEnemies(int size_of_main_window_x, int size_of_main_window_y);
	void RenderEnemies(sf::RenderWindow* renderwin);
	void AnimateEnemies();
	std::vector<sf::Sprite*>& GetEnemyVector() { return enemies_; }
};
