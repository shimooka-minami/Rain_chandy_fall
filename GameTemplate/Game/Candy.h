#pragma once

#include "ICreation.h"

class Game;

class Candy : public ICreation
{
public:
	Candy();
	~Candy();
	
	void AddUpdate() override;  //Rain‚ÌUpdate‚Éˆ—‚ğ’Ç‰Á
	void Add() override;
};

