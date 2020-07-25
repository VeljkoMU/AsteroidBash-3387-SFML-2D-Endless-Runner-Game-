#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow * rendwin)
{
	rendwin_ = rendwin;
	current_view_ = View::Main;
	start_ = new Button(sf::Vector2f(400, 100), "Start Game");
	rules_ = new Button(sf::Vector2f(400, 210), "How to play");
	credits_ = new Button(sf::Vector2f(400, 320), "Credits");
	font.loadFromFile("Resources/Fonts/mainfont.ttf");
	credits_text_.setCharacterSize(35);
	credits_text_.setFont(font);
	credits_text_.setPosition(200, 50);
	credits_text_.setString("Game Design and Development : Veljko Mijovic Uskovic \n Art Contributors: www.pinclipart.com \n Audio: jobro, Tim Palumbo, PatrickLieberkind ");
	rules_text_.setCharacterSize(25);
	rules_text_.setFont(font);
	rules_text_.setPosition(50, 50);
	rules_text_.setString("Control your spaceship using the wasd keys, your goal is to destroy \n as many asteroids as you can, and to avoid the rest. \n To destroy an asteroid \n fire your laser at it by pressing the space button when the indicator \n in the top left of the screen says Laser Available \n when an asteroid is destroyed it will drop a light-point, \n collecting those brings you a higher score, \n GOOD LUCK! ");
	title_.setCharacterSize(50);
	title_.setFont(font);
	title_.setPosition(400, 30);
	title_.setString("Asteroid Bash - 3387 ");
}

MainMenu::~MainMenu()
{
	delete start_;
	delete credits_;
	delete rules_;
}

void MainMenu::Update()
{
	credits_->MouseHoverEffect(rendwin_);
	rules_->MouseHoverEffect(rendwin_);
	start_->MouseHoverEffect(rendwin_);
	if (current_view_ == View::Main)
	{
		rules_->SetPos(sf::Vector2f(400, 210));
		credits_->SetPos(sf::Vector2f(400, 320));
		start_->SetPos(sf::Vector2f(400, 100));
	}
	else
		start_->SetPos(sf::Vector2f(400, 500));

	if (credits_->isClicked(rendwin_))
		current_view_ = View::Credits;
	if (rules_->isClicked(rendwin_))
		current_view_ = View::Rules;
}

bool MainMenu::StartGame()
{
	if (start_->isClicked(rendwin_))
		return true;
	else return false;
}

void MainMenu::Render()
{
	rendwin_->clear();
	if (current_view_ == View::Main)
	{
		rendwin_->draw(title_);
		start_->Render(rendwin_);
		credits_->Render(rendwin_);
		rules_->Render(rendwin_);
	}
	else if (current_view_ == View::Rules)
	{
		rendwin_->draw(rules_text_);
		start_->Render(rendwin_);
	}
	else if (current_view_ == View::Credits)
	{
		rendwin_->draw(credits_text_);
		start_->Render(rendwin_);
	}
	rendwin_->display();
}
