#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"

class Ship2x1 :public Ship
{
public:
	Ship2x1();

	void draw(sf::RenderWindow *window);
	void move(sf::Event *event);
	void check_err(sf::Sprite sprite);
	void reset_sprite();
	bool getErr();
	float getx();
	float gety();
	int getile();
	int getr();
	sf::Sprite getsprite();

private:

	sf::Texture _texture1;
	sf::Texture _texture2;
	sf::Sprite _sprite;
	float _x, _y,_size;

	int _r,_ile;
	bool _err;
};

