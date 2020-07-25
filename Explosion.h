#pragma once
#include "SFMLINCLUDE.h"

class Explosion
{
private:
	sf::Sprite explosion_sprite_;
	sf::Texture explosion_texture_;
	sf::IntRect* explosion_texture_rect_;
	float explosion_animation_timer_;

public:
	Explosion();
	Explosion(sf::Vector2f pos);
	~Explosion();
	bool AnimateExplosion();// return ture when the animaion is over
	void RenderExplosion(sf::RenderWindow* rendwin);
};