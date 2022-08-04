#pragma once

class Player;
class Field;

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();
	void CreatePlayer();
	int InputNumber(const char* msg);
private:
	Player* _player;
	Field* _field;
};

