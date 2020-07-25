#pragma once
#include "SFMLINCLUDE.h"

class Point
{
private:
	//private vars
	sf::Sprite point_;
	sf::Texture point_texture_;
	sf::IntRect* point_texture_rect_;
	float animation_time_;
	float expire_time_;

public:
	Point();
	Point(sf::Vector2f pos);
	~Point();
	void AnimatePoint();
	bool CheckExpired();
	void RenderPoint(sf::RenderWindow* renderwin);
	inline sf::Sprite& GetSprite() { return point_; }
};