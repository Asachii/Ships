#include "Aim.h"



Aim::Aim()
{
	_x = 1;
	_y = 1;
	_texture.loadFromFile("Graphics/Aim1.png");
	_sprite.setTexture(_texture);
}


void Aim::draw(sf::RenderWindow *window)
{
	_sprite.setPosition(_x * 32, _y * 32);
	window->draw(_sprite);
}

void Aim::move(sf::Event *event)
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
	}
}

float Aim::getx()
{
	return _x;
}

float Aim::gety()
{
	return _y;
}

void Aim::reset()
{
	_x = 1;
	_y = 1;
}
