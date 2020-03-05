#include "Ship3x1.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Ship3x1::Ship3x1()
{
	_texture1.loadFromFile("Graphics/Cruiser2.png");
	_texture2.loadFromFile("Graphics/Cruiser2_wrong.png");
	_sprite.setTexture(_texture1);
	_sprite.setOrigin(16.f, 16.f);
	_x = 1;
	_y = 1;
	_size = 32;

	_r = 0;
	_ile = 3;

	_err = 0;
}

void Ship3x1::draw(sf::RenderWindow *window)
{
	//std::cout << _x << " " << _y << " " << _err << std::endl;
	_sprite.setPosition(_x * _size + 16.f, _y * _size + 16.f);
	window->draw(_sprite);
}

void Ship3x1::move(sf::Event *event)
{
	if (event->type == sf::Event::KeyPressed)
	{
		if (event->key.code == sf::Keyboard::Down)
		{
			if (_y < 10)
			{
				_y = _y + 1;
			}
		}
		else if (event->key.code == sf::Keyboard::Up)
		{
			if (_y > 1)
			{
				_y = _y - 1;
			}
		}
		else if (event->key.code == sf::Keyboard::Left)
		{
			if (_x > 1)
			{
				_x = _x - 1;
			}
		}
		else if (event->key.code == sf::Keyboard::Right)
		{
			if (_x < 10)
			{
				_x = _x + 1;
			}
		}
		else if (event->key.code == sf::Keyboard::LControl)
		{
			_r = _r + 1;
			_r %= 4;
			_sprite.rotate(90.f);
		}
	}
}

void Ship3x1::check_err(sf::Sprite sprite)
{
	sf::Sprite sprite1 = _sprite;
	sprite.setScale(0.9f, 0.9f);
	sprite1.setScale(0.9f, 0.9f);
	sf::Rect <float> r1 = _sprite.getGlobalBounds();
	sf::Rect <float> r2 = sprite.getGlobalBounds();
	if (r1.intersects(r2))
	{
		_sprite.setTexture(_texture2);
		_err = 1;
	}
}

void Ship3x1::reset_sprite()
{
	_sprite.setTexture(_texture1);
	_err = 0;
}

bool Ship3x1::getErr()
{
	return _err;
}

float Ship3x1::getx()
{
	return _x;
}

float Ship3x1::gety()
{
	return _y;
}

int Ship3x1::getile()
{
	return _ile;
}

int Ship3x1::getr()
{
	return _r;
}

sf::Sprite Ship3x1::getsprite()
{
	return _sprite;
}
