#pragma once

#include <SFML/Graphics.hpp>

class Ship
{
public:
	virtual void draw(sf::RenderWindow *window) = 0;
	virtual void move(sf::Event *event) = 0;
	virtual void check_err(sf::Sprite sprite) = 0;
	virtual void reset_sprite() = 0;
	virtual bool getErr() = 0;
	virtual float getx() = 0;
	virtual float gety() = 0;
	virtual int getile() = 0;
	virtual int getr() = 0;
	virtual sf::Sprite getsprite() = 0;
};