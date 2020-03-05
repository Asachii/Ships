#include "Board.h"
#include <iostream>

using namespace std;


Board::Board()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			_tab[i][j] = 0;
		}
	}
	_mark = 0;
	
	_t1.loadFromFile("Graphics/miss.png");
	_t2.loadFromFile("Graphics/hit.png");
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			_sprites[i][j].setTexture(_t1);
			_sprites[i][j].setPosition(j * 32.f, i * 32.f);
			_sprites[i][j].setColor(sf::Color(255, 255, 255, 0));
		}
	}
}

void Board::markOnBoard(int x, int y, int dir, int ile)
{
	_mark += ile;
	if (dir == 0)
	{
		for (int i = 0; i < ile; i++)
		{
			_tab[x][y + i] = 1;
		}
	}
	if (dir == 1)
	{
		for (int i = 0; i < ile; i++)
		{
			_tab[x + i][y] = 1;
		}
	}
	if (dir == 2)
	{
		for (int i = 0; i < ile; i++)
		{
			_tab[x][y - i] = 1;
		}
	}
	if (dir == 3)
	{
		for (int i = 0; i < ile; i++)
		{
			_tab[x - i][y] = 1;
		}
	}
}

void Board::markOnBoard(int x, int y)
{
	if (_tab[x][y] == 1)
	{
		_sprites[x][y].setTexture(_t2);
	}
	_sprites[x][y].setColor(sf::Color(255, 255, 255, 255));
	_tab[x][y] = 2;

	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			cout << _tab[i][j] << " ";
		}
		cout << endl;
	}
}

void Board::getboard()
{
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			std::cout << _tab[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int Board::getboard_part(int x, int y)
{
	return _tab[x][y];
}

int Board::getmark()
{
	return _mark;
}

void Board::draw(sf::RenderWindow *window)
{
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			window->draw(_sprites[i][j]);
		}
	}
}

void Board::markminus()
{
	_mark--;
}