#pragma once
#include "ICreation.h"

class Game;
class Player;

class Rain : public ICreation
{
public:
	Rain();
	~Rain();

	void AddUpdate() override;  //Rain��Update�ɏ�����ǉ��ł���
	void Add() override; 
	
};

