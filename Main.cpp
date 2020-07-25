#include "SFMLINCLUDE.h"
#include "Game.h"
#include "GameOVerScreen.h"
#include"MainMenu.h"
#include "AudioPlayer.h"
int main()
{
	AudioPlayer audioplayer;
	Game game;
	GameOverScreen gm1(game.getRendWin());
	MainMenu mainmenu(game.getRendWin());
	bool gameplay_ongoing = false;
	bool mainmeni = true;
	sf::Clock animation_clock;
	sf::Clock spawn_clock;
	while (game.IsRunning())
	{
		while (mainmeni)
		{
			audioplayer.PlayMainmenuMusic();
			game.PollWindowEvent();
			mainmenu.Update();
			mainmenu.Render();
			gameplay_ongoing = mainmenu.StartGame();
			mainmeni = !mainmenu.StartGame();
		}
		if (gameplay_ongoing)
		{
			audioplayer.StopMainmenuMusic();
			audioplayer.PlayGameplayMusic();
			game.Update();
			game.Render();
			if (game.GameOverCondCheck())
				gameplay_ongoing = false;
		}
		else
		{
			audioplayer.StopGameplayMusic();
			audioplayer.PlayGameOverSound();
			game.PollWindowEvent();
			gm1.UpdateButtons();
			gm1.Render();
			if (gm1.GameRestart())
			{
				gameplay_ongoing = true;
				game.Reset();
			}
			if (gm1.ExitGame())
				game.getRendWin()->close();
		}
	}
	return 0;
}
