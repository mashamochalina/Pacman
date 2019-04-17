#pragma once
#include <string>
int getCurrentMission(int x)
{
	int mission = 0;
	if ((x > 0) && (x < 1000)) { mission = 0; } 
	if (x > 1300) { mission = 1; } 
	return mission;
}


std::string getTextMission(int currentMission) {

	std::string missionText = " ";

	switch (currentMission)
	{
	case 0: missionText = " Привет, Друг!\n\n Ты находишься сейчас в секретной\n Пещере.\n\nТебе необходимо собрать все фрукты,\n Чтобы набраться сил.\n\n Нас ждет сложный путь!\n\n Ах, да!\n Опасайся ядовитых цветов! "; break;
	case 1: missionText = "Mission 1\n\n Ты попал в закалдованный лес! \n \n этом уровне \nтебе стоит опасаться\n ппППизраков..."; break;

	}

	return missionText;//ф-ция возвращает текст
};