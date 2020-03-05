#pragma once

#include <SFML/Graphics.hpp>


class Aim
{
public:
	Aim();

	void draw(sf::RenderWindow *window);
	void move(sf::Event *event);
	int check_err(sf::Sprite sprite);
	float getx();
	float gety();
	void reset();

private:

	sf::Texture _texture;
	sf::Sprite _sprite;
	float _x, _y;
};

