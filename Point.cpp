#include "Point.h"

Point::Point()
{
	animation_time_ = 300.f;
	expire_time_ = 1000.f;
	point_texture_.loadFromFile("Resources/Textures/pointtexturesheet.png");
	point_texture_rect_ = new sf::IntRect(0, 0, 50, 50);
	point_.setTexture(point_texture_);
	point_.setTextureRect(*point_texture_rect_);
}

Point::Point(sf::Vector2f pos)
{
	animation_time_ = 128.f;
	expire_time_ = 5000.f;
	point_texture_.loadFromFile("Resources/Textures/pointtexturesheet.png");
	point_texture_rect_ = new sf::IntRect(0, 0, 50, 50);
	point_.setTexture(point_texture_);
	point_.setTextureRect(*point_texture_rect_);
	point_.setPosition(pos);
}

Point::~Point()
{
}

void Point::AnimatePoint()
{
	if (animation_time_ <= 0.f)
	{
		if (point_texture_rect_->top == 50)
		{
			point_texture_rect_->top = 0;
		}
		else
			point_texture_rect_->top += 50;
		animation_time_ = 300.f;
		point_.setTextureRect(*point_texture_rect_);
	}
	else
		animation_time_ -= 1.f;
}

bool Point::CheckExpired()
{
	if (expire_time_ <= 0.f)
		return true;
	else
		expire_time_ -= 1.f;
	return false;
}

void Point::RenderPoint(sf::RenderWindow* renderwin)
{
	renderwin->draw(point_);
}
