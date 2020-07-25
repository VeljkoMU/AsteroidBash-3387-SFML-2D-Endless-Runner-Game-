#pragma once
#include "SFMLINCLUDE.h"
#include "Button.h"

class GameOverScreen
{
private:
	Button* start_;
	Button* exit_;
	sf::Text game_over_text_;
	sf::Font font;
	sf::RenderWindow* rendwin_;

public:
	GameOverScreen(sf::RenderWindow* rendwin);
	void UpdateButtons();
	void Render();
	bool GameRestart();
	bool ExitGame();

};