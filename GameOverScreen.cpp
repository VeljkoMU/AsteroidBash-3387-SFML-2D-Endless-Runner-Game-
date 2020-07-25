#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(sf::RenderWindow * rendwin)
{
	rendwin_ = rendwin;
	font.loadFromFile("Resources/Fonts/mainfont.ttf");
	game_over_text_.setCharacterSize(100);
	game_over_text_.setFont(font);
	game_over_text_.setPosition(600, 50);
	game_over_text_.setString("GAME  OVER");
	start_ = new Button(sf::Vector2f(400, 200), "Restart Game");
	exit_ = new Button(sf::Vector2f(400, 400), "EXIT");
}

void GameOverScreen::UpdateButtons()
{
	start_->MouseHoverEffect(rendwin_);
	exit_->MouseHoverEffect(rendwin_);

}

void GameOverScreen::Render()
{
	rendwin_->clear();
	rendwin_->draw(game_over_text_);
	start_->Render(rendwin_);
	exit_->Render(rendwin_);
	rendwin_->display();
}


bool GameOverScreen::GameRestart()
{
	return start_->isClicked(rendwin_);
}

bool GameOverScreen::ExitGame()
{
	return exit_->isClicked(rendwin_);
}
