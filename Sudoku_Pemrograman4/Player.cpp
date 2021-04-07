#include "Player.h"
void Player::SetPlayerName()
{
	cout << "Please Enter your name:\t";
	cin >> playerName;
}

string Player::GetPlayerName()
{
	return playerName;
}

void Player::SetPlayerInput()
{
	cout << "Please insert your answer:\t";
	cin >> playerinput;
}

int Player::GetPlayerInput()
{
	return playerinput;
}

void Player::SetPlayerTime(double x)
{
	playerTime = x;
}

double Player::GetPlayerTime()
{
	return playerTime;
}



