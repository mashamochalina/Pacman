
#include <iostream> 
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "mapp.h"
#include "view.h"
#include "mission.h"
#include "Playeer.h"
#include <list>
#include "Entity.h"
#include "Enemy.h";
using namespace sf;

int main()
{

	int i;  

	RenderWindow window(sf::VideoMode(1000, 1000), "Packman");
	view.reset(sf::FloatRect(0, 0, 1000, 1000));

	Font font; 
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 20);
	text.setStyle(Text::Bold);

	Font font1;
	font1.loadFromFile("CyrilicOld.ttf");
	Text text1("", font1, 20);
	text1.setStyle(Text::Bold);

	Font font2;
	font2.loadFromFile("CyrilicOld.ttf");
	Text text2("", font2, 20);
	text2.setStyle(Text::Bold);

	Font font3;
	font3.loadFromFile("CyrilicOld.ttf");
	Text text3("", font3, 20);
	text3.setStyle(Text::Bold);
	text3.setFillColor(sf::Color::Black);

	
	Image easyEnemyImage;
	easyEnemyImage.loadFromFile("images/ghost.png");

	
	const size_t max_size = 4;

	Enemy enemy_arr[max_size] = {    
		
	Enemy (easyEnemyImage, 1350, 650, 68, 82, "easyEnemy"),
	Enemy (easyEnemyImage, 1350, 250, 68, 82, "easyEnemy2"),
	Enemy(easyEnemyImage, 1350, 50, 68, 82, "easyEnemy2"),
	Enemy(easyEnemyImage, 1350, 450, 68, 82, "easyEnemy2"),
	};



	

	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);


	Image quest_image;
	quest_image.loadFromFile("images/missionbg.jpg");
	quest_image.createMaskFromColor(Color(0, 0, 0));
	Texture quest_texture;
	quest_texture.loadFromImage(quest_image);
	Sprite s_quest;
	s_quest.setTexture(quest_texture);
	s_quest.setTextureRect(IntRect(0, 0, 680, 840));  
	s_quest.setScale(0.7f, 0.7f);



	bool showMissionText = true;

	Playeer p("Pacman.png", 34, 34, 104.0, 117.0);


	float CurrentFrame = 0;
	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 500;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


			if (event.type == Event::KeyPressed)
				if ((event.key.code == Keyboard::Tab))
				{

					switch (showMissionText) {

					case true: {
						std::ostringstream playerHealthString;
						playerHealthString << p.health; 
						std::ostringstream task;
						task << getTextMission(getCurrentMission(p.getplayercoordinateX()));
						text3.setString("Здоровье: " + playerHealthString.str() + "\n" + task.str());
						showMissionText = false;
						break;
					}
					case false: {
						text3.setString("");
						showMissionText = true;
						break;
					}
					}
				}
		}

		if (p.life)
		{
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				p.dir = 1; p.speed = 0.1;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(104 * int(CurrentFrame), 0, -105, 117));
				p.sprite.setTextureRect(IntRect(104, 0, -105, 117));
				getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				p.dir = 0; p.speed = 0.1;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(0 * int(CurrentFrame), 0, 103, 117));
				getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				p.dir = 3; p.speed = 0.1;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(104 * int(CurrentFrame), 0, 114, 118));
				p.sprite.setTextureRect(IntRect(104, 0, 114, 118));
				getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				p.dir = 2; p.speed = 0.1;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(225 * int(CurrentFrame), 0, 114, 118));
				p.sprite.setTextureRect(IntRect(225, 0, 114, 118));
				getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
			}

		}
		p.update(time);
		for (int i = 0; i < max_size; i++) {
			enemy_arr[i].update(time);
		}
		window.setView(view);
		window.clear();



		for (int i = 0; i < max_size; i++) 
		{
			if ((enemy_arr[i].getRect().intersects(p.getRect())))
			{

				p.health -= 1;
				

			}

		}

		if ((getCurrentMission(p.getplayercoordinateX())) == 0)
		{
			for (int i = 0; i < HEIGHT_MAP; i++)
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
					if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
					if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
					if ((TileMap[i][j] == 't')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
					if ((TileMap[i][j] == 'o')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
					if ((TileMap[i][j] == 'm')) s_map.setTextureRect(IntRect(160, 0, 32, 32));
					if ((TileMap[i][j] == 'u')) s_map.setTextureRect(IntRect(192, 0, 32, 32));


					s_map.setPosition(j * 32, i * 32);

					window.draw(s_map);
				}
		}

		if ((getCurrentMission(p.getplayercoordinateX())) >= 1)
		{ 
			for (int i = 0; i < HEIGHT_MAP; i++)
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
					if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
					if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(224, 0, 32, 32)); 
					if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
					if ((TileMap[i][j] == 'u')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
					s_map.setPosition(j * 32, i * 32);

					window.draw(s_map);
				}
		}






		std::ostringstream playerScoreString;    
		playerScoreString << p.playerScore;		
		text.setString("Собрано фруктов:" + playerScoreString.str()); 
		text.setPosition(view.getCenter().x - 450, view.getCenter().y - 470);

		std::ostringstream moneyScoreString;
		moneyScoreString << p.moneyScore;
		text1.setString("Собрано монет:" + moneyScoreString.str());
		text1.setPosition(view.getCenter().x - 450, view.getCenter().y - 500);
		

		std::ostringstream healthString;
		healthString << p.health;
		text2.setString("Здоровье:" + healthString.str());
		text2.setPosition(view.getCenter().x - 250, view.getCenter().y - 500); 


		if (!showMissionText) {
			text3.setPosition(view.getCenter().x + 150, view.getCenter().y - 30);//позиция всего этого текстового блока
			s_quest.setPosition(view.getCenter().x + 115, view.getCenter().y - 130);//позиция фона для блока			
			window.draw(s_quest); window.draw(text3);
		}

		window.draw(text1);
		window.draw(text2);
		window.draw(text);
		window.draw(p.sprite);
		for (int i = 0; i < max_size; i++)
		{
			window.draw(enemy_arr[i].sprite);
		}
		window.display();
	}

	return 0;
}