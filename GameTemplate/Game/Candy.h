#pragma once

#include "ICreation.h"

class Game;

class Candy : public ICreation
{
public:
	Candy();
	~Candy();
	
	void AddUpdate() override;  //Rain��Update�ɏ�����ǉ�
	void Add() override;
};

