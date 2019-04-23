#pragma once
class Playeer
{
private:
	float x, y;

public:
	float w, h, dx, dy, speed;
	bool life;
	int dir, playerScore, moneyScore, health;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	FloatRect rect;


	Playeer(String F, float X, float Y, float W, float H)
	{
		dx = 0;dy = 0;speed = 0;dir = 0; playerScore = 0; moneyScore = 0; health = 100;
		x = X; y = Y;
		rect = FloatRect(x, y, 104.0, 117.0);
		life = true;
		File = F;
		w = W; h = H;
		image.loadFromFile("images/" + File);
		image.createMaskFromColor(Color(0, 0, 0));//"hero.png" и получится запись идентичная image.loadFromFile("images/hero/png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, w, h));// IntRect - приведение типов

	}

	~Playeer();


	FloatRect getRect()
	{
		return FloatRect(x, y, w, h);
	}

	void update(float time)
	{
		switch (dir)
		{
		case 0: dx = speed; dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: dx = 0; dy = speed; break;
		case 3: dx = 0; dy = -speed; break;
		}

		x += dx * time;
		y += dy * time;

		speed = 0;
		sprite.setPosition(x, y);
		interactionWithMap();
		if (health <= 0)
		{
			life = false; speed = 0;
		}
	}

	void setplayercoordinateX(float x)
	{
		this->x = x;
	}

	void setplayercoordinateY(float y)
	{
		this->y = y;
	}

	float getplayercoordinateX()
	{
		return x;
	}


	float getplayercoordinateY()
	{
		return y;
	}


	void interactionWithMap()
	{

		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0')
				{
					if (dy > 0)
					{
						y = i * 32 - h;
					}
					if (dy < 0)
					{
						y = i * 32 + 32;
					}
					if (dx > 0)
					{
						x = j * 32 - w;
					}
					if (dx < 0)
					{
						x = j * 32 + 32;
					}
				}

				if ((TileMap[i][j] == 's') || (TileMap[i][j] == 't') || (TileMap[i][j] == 'o'))
				{
					playerScore++;
					TileMap[i][j] = ' ';
				}

				if (TileMap[i][j] == 'm')
				{
					moneyScore++;
					TileMap[i][j] = ' ';
				}


				if (TileMap[i][j] == 'g')
				{
					health -= 40;
					TileMap[i][j] = ' ';
				}


				if (TileMap[i][j] == 'u')
				{
					health += 20;
					TileMap[i][j] = ' ';
				}

			}
	}

};




Playeer::~Playeer()
{
}
