#pragma once
#include"Projectile.h"

class Player
{
private:
	// private vars
	sf::Texture player_texture_;
	sf::Sprite player_sprite_;
	sf::IntRect* rectSprite;
	sf::CircleShape* player_;
	int p_life_;
	int points_gathered_;
	sf::Vector2f p_pos_;

public:

	//public vars
	Projectile* laser_; // laser_ is a public object becuase the Game class needs access to it

	// constr/destr
	Player();
	Player(int life, sf::Vector2f startpos);
	~Player();

	//public functions
	void InitSprite();
	void setPos(sf::Vector2f pos);
	sf::Vector2f getPos();
	void SetLife(int points);
	int GetLife();
	void SetPoints(int newpoints);
	void RenderPlayer(sf::RenderWindow* r);
	void ShootLaser(); 
	void DeleteLaser(); 
	inline int GetPoints() { return points_gathered_; }
	inline sf::Sprite& GetPlayerSprite() { return player_sprite_; }
};
