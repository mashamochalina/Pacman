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
	case 0: missionText = " ������, ����!\n\n �� ���������� ������ � ���������\n ������.\n\n���� ���������� ������� ��� ������,\n ����� ��������� ���.\n\n ��� ���� ������� ����!\n\n ��, ��!\n �������� �������� ������! "; break;
	case 1: missionText = "Mission 1\n\n �� ����� � ������������� ���! \n \n ���� ������ \n���� ����� ���������\n �����������..."; break;

	}

	return missionText;//�-��� ���������� �����
};