#pragma once
#include "SFMLINCLUDE.h"
#include"Player.h"
#include"Enemies.h"
#include "Background.h"
#include"Point.h"
#include "Explosion.h"
#include "Interface.h"
#include "AudioPlayer.h"
class Game
{
private:
	// private variables
	sf::RenderWindow* main_window_;
	sf::Event evnt_;
	Player* player;
	Enemies* enemies;
	Background* background_;
	float player_shoot_available_time_;
	std::vector<Point*> points_;
	std::vector<Explosion*> explosions_;
	bool player_ammune_; // when true, player cannot receive demage
	Interface* interface_;
	bool player_laser_available_;
	AudioPlayer SoundEffectPlayer;

public:
	// constructor/destructors
	Game();
	~Game();

	//public methods
	void PollWindowEvent();
	int Update(); // updates the game each frame
	void Render(); // renders the new frame
	bool CollisionDetection(sf::Sprite& s1, sf::Sprite& s2);
	inline bool IsRunning() {return main_window_->isOpen() ? true : false; }
	void SpawnPoint(sf::Vector2f pos); // spawns a light-point when an enemy is killed
	void UpdatePoints(); // animates and deletes expired points
	void SpawnExplosion(sf::Vector2f pos); // spawns explosions when enemies are killed
	void UpdateExplosion(); // animates explosion and deletes it when the animation is done
	bool PlayerEnemySpecificCollision(sf::Sprite& enemy); // a special kind of collision detection for the player which is more accurate
	inline sf::RenderWindow* getRendWin() { return main_window_; }
	bool GameOverCondCheck();
	void Reset(); // resets the stats to start of game state
	int getPlayerPoints();
};