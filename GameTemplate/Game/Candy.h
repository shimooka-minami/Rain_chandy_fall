#pragma once

#include "ICreation.h"

class Game;

class Candy : public ICreation
{
public:
	Candy();
	~Candy();
	
	void AddUpdate() override;  //RainのUpdateに処理を追加
	void Add() override;
};

