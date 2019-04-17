#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
	public:
		FloatRect rect;
			Enemy(Image &image, float X, float Y, int W, int H, String Name) :Entity(image, X, Y, W, H, Name) {
				rect = FloatRect (x, y, 68, 82) ;
				//if (name == "EasyEnemy") {
					sprite.setTextureRect(IntRect(0, 0, w, h));
					dx = 0.1;
				//}
			}

			void checkCollisionWithMap(float Dx, float Dy)
			{
				for (int i = y / 32; i < (y + h) / 32; i++)
					for (int j = x / 32; j < (x + w) / 32; j++)
					{
						if (TileMap[i][j] == '0')
						{
							if (Dy > 0) { y = i * 32 - h; }
							if (Dy < 0) { y = i * 32 + 32; }
							if (Dx > 0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); }
							if (Dx < 0) { x = j * 32 + 32; dx = 0.1; sprite.scale(-1, 1); }
						}
					}
			}

			void update(float time)
			{
				if ((name == "easyEnemy")|| (name == "easyEnemy2")) {

					//moveTimer += time;if (moveTimer>3000){ dx *= -1; moveTimer = 0; }//меняет направление примерно каждые 3 сек
					checkCollisionWithMap(dx, 0);//обрабатываем столкновение по Х
					x += dx * time;
					sprite.setPosition(x + w / 2, y + h / 2); 
					if (health <= 0) { life = false; }
				}

			}
			FloatRect getRect()
			{
				return FloatRect(x, y, w, h);
			}
};






