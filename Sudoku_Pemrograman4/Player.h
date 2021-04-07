#include<iostream>
using namespace std;

class Player
{
private:
	string playerName;
	double playerTime;
	int playerinput;
public:
	void SetPlayerName();
	string GetPlayerName();

	void SetPlayerInput();
	int GetPlayerInput();

	void SetPlayerTime(double);
	double GetPlayerTime();
};


