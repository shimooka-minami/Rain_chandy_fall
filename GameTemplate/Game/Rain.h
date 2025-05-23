#pragma once
#include "ICreation.h"

class Game;
class Player;

class Rain : public ICreation
{
public:
	Rain();
	~Rain();

	void AddUpdate() override;  //Rain‚ÌUpdate‚Éˆ—‚ğ’Ç‰Á‚Å‚«‚é
	void Add() override; 
	
};

