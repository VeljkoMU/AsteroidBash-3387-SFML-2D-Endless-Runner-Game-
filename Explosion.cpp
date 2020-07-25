#include "Explosion.h"

Explosion::Explosion()
{
	explosion_texture_.loadFromFile("Resources/Textures/explosiontexturesheet.png");
	explosion_texture_rect_ = new sf::IntRect(0, 0, 220, 220);
	explosion_sprite_.setTexture(explosion_texture_);
	explosion_sprite_.setTextureRect(*explosion_texture_rect_);
	explosion_animation_timer_ = 150.f;
}

Explosion::Explosion(sf::Vector2f pos)
{
	explosion_texture_.loadFromFile("Resources/Textures/explosiontexturesheet.png");
	explosion_texture_rect_ = new sf::IntRect(0, 0, 220, 220);
	explosion_sprite_.setTexture(explosion_texture_);
	explosion_sprite_.setTextureRect(*explosion_texture_rect_);
	explosion_animation_timer_ = 150.f;
	explosion_sprite_.setPosition(pos);
}

Explosion::~Explosion()
{
	delete explosion_texture_rect_;
}

bool Explosion::AnimateExplosion()
{
	if (explosion_animation_timer_ <= 0)
	{
		explosion_texture_rect_->top += 220;
		if (explosion_texture_rect_->top == 660)
			return true;
		explosion_animation_timer_ = 150.f;
		explosion_sprite_.setTextureRect(*explosion_texture_rect_);
	}
	else
		explosion_animation_timer_ -= 1.f;
	return false;
}

void Explosion::RenderExplosion(sf::RenderWindow* rendwin)
{
	rendwin->draw(explosion_sprite_);
}
