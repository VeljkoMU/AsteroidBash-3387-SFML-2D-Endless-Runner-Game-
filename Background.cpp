#include "Background.h"
#include <time.h>
Background::Background()
{
	curr_stars_ = 0;
	InitEarth();
	InitBackgroundImage();
}

Background::~Background()
{
	delete earth_rect_;
}

void Background::InitEarth()
{
	earth_texture_.loadFromFile("Resources/Textures/earthtexturesheet1.png");
	earth_.setTexture(earth_texture_);
	earth_rect_ = new sf::IntRect(0, 0, 200, 200);
	earth_.setTextureRect(*earth_rect_);
	earth_.setPosition(sf::Vector2f(640, 80));
	earth_animation_time_ = 0;
}

void Background::InitBackgroundImage()
{
	backgoround_image_texture_.loadFromFile("Resources/Textures/backgroundtexture.png");
	background_static_image_.setSize(sf::Vector2f(2560, 1440));
	background_static_image_.setTexture(&backgoround_image_texture_);
}

void Background::SpawnStars(int size_of_main_window_x, int size_of_main_window_y)
{
	if (curr_stars_ < max_stars_)
	{
		sf::CircleShape* star=new sf::CircleShape(3.f);
		star->setFillColor(sf::Color::White);
		float x = static_cast<float>(rand() % size_of_main_window_x);
		float y = static_cast<float>(rand() % size_of_main_window_y);
		star->setPosition(x, y);
		stars_.push_back(star);
		curr_stars_++;
	}
}

void Background::UpdateBackground(int size_of_main_window_x, int size_of_main_window_y)
{
	SpawnStars(size_of_main_window_x, size_of_main_window_y);
	AnimateEarth();
}

void Background::RenderBackground(sf::RenderWindow * renderwin)
{
	renderwin->draw(background_static_image_);
	renderwin->draw(earth_);
	if (stars_.size() > 0)
		for (auto i : stars_)
			renderwin->draw(*i);
}

void Background::AnimateEarth()
{
	if (earth_animation_time_ >= earth_animation_max_)
	{
		if (earth_rect_->top == 400)
		{
			earth_rect_->top = 0;
		}
		else
			earth_rect_->top += 200;
		earth_.setTextureRect(*earth_rect_);
		earth_animation_time_ = 0;
	}
	else
		earth_animation_time_ += 1.f;
}
