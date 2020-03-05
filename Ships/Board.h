#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Board
{
public:
	Board();

	void markOnBoard(int x, int y, int dir, int ile);
	void markOnBoard(int x, int y);
	void getboard();

	int getboard_part(int x, int y);
	int getmark();
	void markminus();

	void draw(sf::RenderWindow *window);

private:
	sf::Texture _t1;
	sf::Texture _t2;

	sf::Sprite _sprites[11][11];
	int _tab[11][11];
	int _mark;
};

