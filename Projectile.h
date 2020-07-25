#pragma once
#include"SFMLINCLUDE.h"

class Projectile
{
private:
	//private vars
	sf::Sprite projectile_;
	sf::Texture projectile_texture_;
	sf::IntRect* projectile_texture_rect_;
	float animation_time_;
	float movement_speed_;
	bool animation_direction_;
	float curr_movement_speed_;

	//private methods
	void InitProjectile();

public:
	//contructors and destructors
	Projectile();
	Projectile(sf::Vector2f& pos, float speed );
	~Projectile();
 
	//public methods
	void AnimateProjectile();
	bool Move();
	inline sf::Sprite& GetProjectileSprite() { return projectile_; };
	void RenderProjectile(sf::RenderWindow* renwind);
};