#include "Projectile.h"

Projectile::Projectile()
{
	movement_speed_ = 0.f;
	InitProjectile();
	curr_movement_speed_ = 0.f;
}

Projectile::Projectile(sf::Vector2f & pos, float speed)
{
	movement_speed_ = speed;
	InitProjectile();
	projectile_.setPosition(pos);
	curr_movement_speed_ = 0.f;


}

Projectile::~Projectile()
{
	projectile_texture_rect_;
}

void Projectile::AnimateProjectile()
{
	if (animation_time_ <= 0.f)
	{
		if (projectile_texture_rect_->top == 192)
			animation_direction_ = true;
		else if (projectile_texture_rect_->top == 0)
			animation_direction_ = false;
		if (animation_direction_)
			projectile_texture_rect_->top -= 96;
		else
			projectile_texture_rect_->top += 96;
		projectile_.setTextureRect(*projectile_texture_rect_);
		animation_time_ = 500.f;
	}
	else
		animation_time_ -= 1.f;
}

bool Projectile::Move()
{
	if (this != nullptr)
	{
		if (movement_speed_ <= curr_movement_speed_)
		{
			projectile_.move(0.5f, 0);
			curr_movement_speed_ = 0.f;
			return true;
		}
		else
			curr_movement_speed_ += 50.f;
		return false;
	}
}

void Projectile::RenderProjectile(sf::RenderWindow * renwind)
{
	renwind->draw(projectile_);
}

void Projectile::InitProjectile()
{
	projectile_texture_.loadFromFile("Resources/Textures/lasertexturesheet.png");
	projectile_texture_rect_ = new sf::IntRect(0, 0, 92, 92);
	animation_time_ = 500.f;
	projectile_.setTexture(projectile_texture_);
	projectile_.setTextureRect(*projectile_texture_rect_);
	animation_direction_ = false;

}
