#pragma once
#include "ICreation.h"

class Game;
class Player;

class Rain : public ICreation
{
public:
	Rain();
	~Rain();

	void AddUpdate() override;  //RainのUpdateに処理を追加できる
	void Add() override; 
	
};

