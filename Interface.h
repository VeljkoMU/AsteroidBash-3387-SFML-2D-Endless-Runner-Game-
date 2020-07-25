#pragma once
#include "SFMLINCLUDE.h"

class Interface
{
private:
	sf::Font font_;
	sf::Text current_player_life_text_;
	sf::Text current_player_points_text_;
	sf::Text laser_available_text_;

public:
	Interface();
	void InitText();
	void setLife(int newlife);
	void setPoints(int newpoints);
	void changeAvailability(bool isavailable);
	void Render(sf::RenderWindow* renderwin);
};