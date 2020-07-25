#include "Button.h"

Button::Button()
{
}

Button::Button(sf::Vector2f pos, std::string text)
{ 
	button_.setSize(sf::Vector2f(400, 80));
	button_.setPosition(pos);
	button_.setFillColor(sf::Color(180, 180, 100, 100));
	button_text_.setString(text);
	button_text_.setCharacterSize(30);
	button_text_font_.loadFromFile("Resources/Fonts/mainfont.ttf");
	button_text_.setFont(button_text_font_);
	button_text_.setPosition(button_.getPosition());
}

void Button::MouseHoverEffect(sf::RenderWindow * rendwin)
{
	sf::Vector2f mouse_pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*rendwin));
	if (button_.getGlobalBounds().contains(mouse_pos))
	{
		button_.setFillColor(sf::Color::Blue);
	}
	else
		button_.setFillColor(sf::Color(180, 180, 180, 180));
}

bool Button::isClicked(sf::RenderWindow * rendwin)
{
	sf::Vector2f mouse_pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*rendwin));
	if (button_.getGlobalBounds().contains(mouse_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return true;
	else
	  return false;
}

void Button::Render(sf::RenderWindow * rendwin)
{
	rendwin->draw(button_);
	rendwin->draw(button_text_);
}

void Button::SetPos(sf::Vector2f pos)
{
	button_.setPosition(pos);
	button_text_.setPosition(button_.getPosition());
}
