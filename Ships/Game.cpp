#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Aim.h"
#include "Ship.h"
#include "Ship2x1.h"
#include "Ship3x1.h"
#include "Ship4x1.h"
#include "Ship5x1.h"
#include <memory>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

queue < std::unique_ptr < Ship > > QP1;
queue < std::unique_ptr < Ship > > QP2;
vector < sf::Texture > ttt;
vector < std::pair < sf::Sprite, int > > P1;
vector < std::pair < sf::Sprite, int > > P2;

enum GameState
{
	P1_ustawia,
	tmp1,
	P2_ustawia,
	tmp2,
	tura_P1,
	tmp3,
	tura_P2,
	tmp4,
	P1_won,
	tmp5,
	P2_won,
};

Game::Game()
{

}


void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(352, 352), "Ships");

	sf::Font cs;
	cs.loadFromFile("Font/ComicSans.ttf");
	sf::Text text, text2, text3;
	text.setFont(cs);
	text2.setFont(cs);
	text3.setFont(cs);
	text.setString("ABCDEFGHIJ");
	text2.setString("1\n2\n3\n4\n5\n6\n7\n8\n9\n10");
	text.setLetterSpacing(4.5);
	text2.setLineSpacing(0.75);
	text.move(37.0, 0.0);
	text2.move(0.0, 32.0);
	text.setCharacterSize(30);
	text2.setCharacterSize(30);
	text3.setCharacterSize(60);
	text.setFillColor(sf::Color::White);
	text2.setFillColor(sf::Color::White);
	text3.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text2.setStyle(sf::Text::Bold);
	text3.setStyle(sf::Text::Bold);



	sf::Vertex line[] =
	{
		//Horizontal Grid
		sf::Vertex(sf::Vector2f(32, 0), sf::Color::White),
		sf::Vertex(sf::Vector2f(32, 352), sf::Color::White),
		sf::Vertex(sf::Vector2f(64, 0), sf::Color::White),
		sf::Vertex(sf::Vector2f(64, 352), sf::Color::White),
		sf::Vertex(sf::Vector2f(96, 0), sf::Color::White),
		sf::Vertex(sf::Vector2f(96, 352), sf::Color::White),
		sf::Vertex(sf::Vector2f(128, 0), sf::Color::White),
		sf::Vertex(sf::Vector2f(128, 352), sf::Color::White),
		sf::Vertex(sf::Vector2f(160, 0), sf::Color::White),
		sf::Vertex(sf::Vector2f(160, 352), sf::Color::White),
		sf::Vertex(sf::Vector2f(192, 0), sf::Color::White),
		sf::Vertex(sf::Vector2f(192, 352), sf::Color::White),
		sf::Vertex(sf::Vector2f(224, 0), sf::Color::White),
		sf::Vertex(sf::Vector2f(224, 352), sf::Color::White),
		sf::Vertex(sf::Vector2f(256, 0), sf::Color::White),
		sf::Vertex(sf::Vector2f(256, 352), sf::Color::White),
		sf::Vertex(sf::Vector2f(288, 0), sf::Color::White),
		sf::Vertex(sf::Vector2f(288, 352), sf::Color::White),
		sf::Vertex(sf::Vector2f(320, 0), sf::Color::White),
		sf::Vertex(sf::Vector2f(320, 352), sf::Color::White),
		//Vertical Grid
		sf::Vertex(sf::Vector2f(0, 32), sf::Color::White),
		sf::Vertex(sf::Vector2f(352, 32), sf::Color::White),
		sf::Vertex(sf::Vector2f(0, 64), sf::Color::White),
		sf::Vertex(sf::Vector2f(352, 64), sf::Color::White),
		sf::Vertex(sf::Vector2f(0, 96), sf::Color::White),
		sf::Vertex(sf::Vector2f(352, 96), sf::Color::White),
		sf::Vertex(sf::Vector2f(0, 128), sf::Color::White),
		sf::Vertex(sf::Vector2f(352, 128), sf::Color::White),
		sf::Vertex(sf::Vector2f(0, 160), sf::Color::White),
		sf::Vertex(sf::Vector2f(352, 160), sf::Color::White),
		sf::Vertex(sf::Vector2f(0, 192), sf::Color::White),
		sf::Vertex(sf::Vector2f(352, 192), sf::Color::White),
		sf::Vertex(sf::Vector2f(0, 224), sf::Color::White),
		sf::Vertex(sf::Vector2f(352, 224), sf::Color::White),
		sf::Vertex(sf::Vector2f(0, 256), sf::Color::White),
		sf::Vertex(sf::Vector2f(352, 256), sf::Color::White),
		sf::Vertex(sf::Vector2f(0, 288), sf::Color::White),
		sf::Vertex(sf::Vector2f(352, 288), sf::Color::White),
		sf::Vertex(sf::Vector2f(0, 320), sf::Color::White),
		sf::Vertex(sf::Vector2f(352, 320), sf::Color::White)
	};

	sf::Texture t1;
	t1.loadFromFile("Graphics/transparent.png");
	sf::Sprite tmp1, tmp2, tmp3, tmp4;
	tmp1.setTexture(t1);
	tmp2.setTexture(t1);
	tmp3.setTexture(t1);
	tmp4.setTexture(t1);
	tmp1.setTextureRect(sf::IntRect(0, 0, 31, 400));
	tmp2.setTextureRect(sf::IntRect(0, 0, 31, 400));
	tmp3.setTextureRect(sf::IntRect(0, 0, 400, 31));
	tmp4.setTextureRect(sf::IntRect(0, 0, 400, 31));
	tmp2.setPosition(352, 0);
	tmp4.setPosition(0, 352);

	for (int i = 0; i <= 6; i++)
	{
		ttt.push_back(t1);
	}
	ttt[0].loadFromFile("Graphics/PatrolBoat2.png");
	ttt[1].loadFromFile("Graphics/PatrolBoat2.png");
	ttt[2].loadFromFile("Graphics/PatrolBoat2.png");
	ttt[3].loadFromFile("Graphics/Cruiser2.png");
	ttt[4].loadFromFile("Graphics/Battleship2.png");
	ttt[5].loadFromFile("Graphics/AircraftCarrier2.png");
	/////////////////////////////////////////////////////////

	int gamestate = GameState::P1_ustawia;
	Board board1, board2;
	Aim aim;


	QP1.push(std::unique_ptr < Ship >(new Ship5x1)); // a taki debug odjeba³em jak zapomne to wywalasz to
	QP2.push(std::unique_ptr < Ship >(new Ship5x1)); // a to co na dole odkomêtuj ;) 

	/*
	QP1.push( std::unique_ptr < Ship > ( new Ship5x1 ));
	QP1.push( std::unique_ptr < Ship > ( new Ship4x1 ));
	QP1.push( std::unique_ptr < Ship > ( new Ship4x1 ));
	QP1.push( std::unique_ptr < Ship > ( new Ship3x1 ));
	QP1.push( std::unique_ptr < Ship > ( new Ship3x1 ));
	QP1.push( std::unique_ptr < Ship > ( new Ship3x1 ));
	QP1.push( std::unique_ptr < Ship > ( new Ship2x1 ));
	QP1.push( std::unique_ptr < Ship > ( new Ship2x1 ));
	QP1.push( std::unique_ptr < Ship > ( new Ship2x1 ));
	QP1.push( std::unique_ptr < Ship > ( new Ship2x1 ));

	QP2.push( std::unique_ptr < Ship > ( new Ship5x1 ));
	QP2.push( std::unique_ptr < Ship > ( new Ship4x1 ));
	QP2.push( std::unique_ptr < Ship > ( new Ship4x1 ));
	QP2.push( std::unique_ptr < Ship > ( new Ship3x1 ));
	QP2.push( std::unique_ptr < Ship > ( new Ship3x1 ));
	QP2.push( std::unique_ptr < Ship > ( new Ship3x1 ));
	QP2.push( std::unique_ptr < Ship > ( new Ship2x1 ));
	QP2.push( std::unique_ptr < Ship > ( new Ship2x1 ));
	QP2.push( std::unique_ptr < Ship > ( new Ship2x1 ));
	QP2.push( std::unique_ptr < Ship > ( new Ship2x1 ));
	*/

	window.setFramerateLimit(30);
	/////////////////////////////////////////////////////////

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Enter)
				{
					if (gamestate == GameState::P1_ustawia)
					{
						if (QP1.front()->getErr() == 0)
						{
							board1.markOnBoard((int)QP1.front()->gety(), (int)QP1.front()->getx(), QP1.front()->getr(), QP1.front()->getile());

							P1.push_back(std::make_pair(QP1.front()->getsprite(), QP1.front()->getile()));
							P1[P1.size() - 1].first.setTexture(ttt[P1[P1.size() - 1].second]);

							QP1.pop();
							if (QP1.size() == 0)
							{
								gamestate = GameState::tmp1;
								//board1.getboard();
							}
						}
					}

					if (gamestate == GameState::P2_ustawia)
					{
						if (QP2.front()->getErr() == 0)
						{
							board2.markOnBoard((int)QP2.front()->gety(), (int)QP2.front()->getx(), QP2.front()->getr(), QP2.front()->getile());

							P2.push_back(std::make_pair(QP2.front()->getsprite(), QP2.front()->getile()));
							P2[P2.size() - 1].first.setTexture(ttt[P2[P2.size() - 1].second]);

							QP2.pop();
							if (QP2.size() == 0)
							{
								gamestate = GameState::tmp2;
								//board2.getboard();
							}
						}
					}

					if (gamestate == GameState::tura_P1)
					{
						if (board2.getboard_part(aim.gety(), aim.getx()) != 2)
						{
							if (board2.getboard_part(aim.gety(), aim.getx()) == 1)
							{
								board2.markminus();
								if (board2.getmark() == 0)
								{
									gamestate = GameState::tmp4;
								}
								else
								{
									gamestate = GameState::tmp2;
								}
							}
							else
							{
								gamestate = GameState::tmp3;
							}
							board2.markOnBoard(aim.gety(), aim.getx());
						}
					}

					if (gamestate == GameState::tura_P2)
					{
						cout << aim.getx() << " " << aim.gety() << endl;
						if (board1.getboard_part(aim.gety(), aim.getx()) != 2)
						{
							if (board1.getboard_part(aim.gety(), aim.getx()) == 1)
							{
								board1.markminus();
								if (board1.getmark() == 0)
								{
									gamestate = GameState::tmp5;
								}
								else
								{
									gamestate = GameState::tmp3;
								}
							}
							else
							{
								gamestate = GameState::tmp2;
							}
							board1.markOnBoard(aim.gety(), aim.getx());
						}
					}


				}
			}


			if (gamestate == GameState::P1_ustawia)
			{
				QP1.front()->move(&event);
			}
			if (gamestate == GameState::P2_ustawia)
			{
				QP2.front()->move(&event);
			}
			if (gamestate == GameState::tura_P1 || gamestate == GameState::tura_P2)
			{
				aim.move(&event);
			}
		}

		if (gamestate == GameState::P1_ustawia)
		{
			QP1.front()->reset_sprite();

			QP1.front()->check_err(tmp1);
			QP1.front()->check_err(tmp2);
			QP1.front()->check_err(tmp3);
			QP1.front()->check_err(tmp4);

			for (unsigned int i = 0; i < P1.size(); i++)
			{
				QP1.front()->check_err(P1[i].first);
			}
		}

		if (gamestate == GameState::P2_ustawia)
		{
			QP2.front()->reset_sprite();

			QP2.front()->check_err(tmp1);
			QP2.front()->check_err(tmp2);
			QP2.front()->check_err(tmp3);
			QP2.front()->check_err(tmp4);

			for (unsigned int i = 0; i < P2.size(); i++)
			{
				QP2.front()->check_err(P2[i].first);
			}
		}

		window.clear(sf::Color::Blue);

		window.draw(line, 44, sf::Lines);
		window.draw(text);
		window.draw(text2);

		if (gamestate == GameState::P1_ustawia)
		{
			QP1.front()->draw(&window);

			for (unsigned int i = 0; i < P1.size(); i++)
			{
				window.draw(P1[i].first);
			}
		}

		if (gamestate == GameState::P2_ustawia)
		{
			QP2.front()->draw(&window);

			for (unsigned int i = 0; i < P2.size(); i++)
			{
				window.draw(P2[i].first);
			}
		}

		if (gamestate == GameState::tura_P1)
		{
			board2.draw(&window);
		}

		if (gamestate == GameState::tura_P2)
		{
			board1.draw(&window);
		}

		if (gamestate == GameState::tura_P1 || gamestate == GameState::tura_P2)
		{
			//cout << "Xd " << endl;
			aim.draw(&window);
		}

		if (gamestate == GameState::P1_won)
		{
			board2.draw(&window);
			window.draw(text3);
		}

		if (gamestate == GameState::P2_won)
		{
			board1.draw(&window);
			window.draw(text3);
		}

		window.display();

		if (gamestate == GameState::tmp1)
		{
			gamestate = GameState::P2_ustawia;
		}
		if (gamestate == GameState::tmp2)
		{
			aim.reset();
			gamestate = GameState::tura_P1;
		}
		if (gamestate == GameState::tmp3)
		{
			aim.reset();
			gamestate = GameState::tura_P2;
		}
		if (gamestate == GameState::tmp4)
		{
			text3.setString("P1 WON");
			text3.setPosition(352 / 2 - text3.getGlobalBounds().width / 2, 352 / 2 - text3.getGlobalBounds().height / 2);
			gamestate = GameState::P1_won;
		}
		if (gamestate == GameState::tmp5)
		{
			text3.setString("P2_WON");
			text3.setPosition(352 / 2 - text3.getGlobalBounds().width / 2, 352 / 2 - text3.getGlobalBounds().height / 2);
			gamestate = GameState::P2_won;
		}
	}

	/////////////////////////////////////////////////////////
}
