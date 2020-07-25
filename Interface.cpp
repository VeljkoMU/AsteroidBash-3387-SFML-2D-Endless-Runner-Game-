#include "Interface.h"
# include <string>
Interface::Interface()
{
	font_.loadFromFile("Resources/Fonts/mainfont.ttf");
	InitText();
}

void Interface::InitText()
{
	current_player_life_text_.setFont(font_);
	current_player_points_text_.setFont(font_);
	laser_available_text_.setFont(font_);
	current_player_life_text_.setString("Life: 100");
	current_player_points_text_.setString("Points: 0");
	laser_available_text_.setString("Laser Available");
//	laser_available_text_.setColor(sf::Color::Red);
	laser_available_text_.setPosition(85, 10);
	laser_available_text_.setCharacterSize(20);
	current_player_life_text_.setPosition(450, 10);
	current_player_life_text_.setCharacterSize(20);
	current_player_points_text_.setPosition(310, 10);
	current_player_points_text_.setCharacterSize(20);
}

void Interface::setLife(int newlife)
{
	current_player_life_text_.setString("Life: "+ std::to_string(newlife));
}

void Interface::setPoints(int newpoints)
{
	current_player_points_text_.setString("Points: " + std::to_string(newpoints));
}

void Interface::changeAvailability(bool isavailable)
{
	if (isavailable)
		laser_available_text_.setString("Laser Available");
	else
		laser_available_text_.setString("Laser Not Available");
}

void Interface::Render(sf::RenderWindow * renderwin)
{
	renderwin->draw(current_player_life_text_);
	renderwin->draw(current_player_points_text_);
	renderwin->draw(laser_available_text_);
}
