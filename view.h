#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
sf::View view;
void getplayercoordinateforview(float x, float y)
{ 
	float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края
	view.setCenter(x , y); 
}
void viewmap(float time) { 


	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		view.move(0.1*time, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		view.move(0, 0.1*time);
	}

	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		view.move(-0.1*time, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		view.move(0, -0.1*time);
	}

}

