#pragma once
#include"SFMLINCLUDE.h"
class Background
{
private:
	//private vars
	sf::RectangleShape background_static_image_;
	sf::Texture backgoround_image_texture_;
	std::vector<sf::CircleShape*> stars_;
	sf::Sprite earth_;
	sf::Texture earth_texture_;
	sf::IntRect* earth_rect_;
	float earth_animation_time_;
	const float earth_animation_max_=2000.f;
	const int max_stars_ = 10;
	int curr_stars_;

public:
	//constructors and destructors
	Background();
	~Background();

	//public functtions
	void InitEarth();
	void InitBackgroundImage();
	void SpawnStars(int size_of_main_window_x, int size_of_main_window_y);
	void UpdateBackground(int size_of_main_window_x, int size_of_main_window_y);
	void RenderBackground(sf::RenderWindow* renderwin);
	void AnimateEarth();


 };
