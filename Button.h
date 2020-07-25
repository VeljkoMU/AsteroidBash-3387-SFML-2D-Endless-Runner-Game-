#pragma once
#include "SFMLINCLUDE.h"
#include <string>

class Button
{
private:
	sf::RectangleShape button_;
	sf::Text button_text_;
	sf::Font button_text_font_;

public:
	Button();
	Button(sf::Vector2f pos, std::string text);

	void MouseHoverEffect(sf::RenderWindow* rendwin);
	bool isClicked(sf::RenderWindow* rendwin);
	void Render(sf::RenderWindow* rendwin);
	void SetPos(sf::Vector2f pos);
};
