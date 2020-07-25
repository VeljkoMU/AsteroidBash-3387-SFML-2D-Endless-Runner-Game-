#pragma once
#include "SFMLINCLUDE.h"
#include "Button.h"

class MainMenu
{
private:
	Button* start_;
	Button* credits_;
	Button* rules_;
	sf::Text credits_text_;
	sf::Text rules_text_;
	sf::Text title_;
	sf::Font font;
	enum View {Rules,Credits,Main}; // controls which view of the menue if being rendered and upodated for
	View current_view_;
	sf::RenderWindow* rendwin_;

public:
	MainMenu(sf::RenderWindow* rendwin);
	~MainMenu();
	void Update();
	bool StartGame();
	void Render();
};