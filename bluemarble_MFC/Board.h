#pragma once
#include "Dice.h"

#include "Zone.h"
class player;

class Board {
	
public:
	int turn;
	Zone *zone[40];
	Dice dice[2];
	Player player[4];
	vector<ItemCard> card_deck;
	Board(int n=4);
	~Board();
	void moveif(int n);
	void buy(int n);
	void make_card_deck(); // 카드 덱을 만드는 함수
	void take(string str,int x,int y);// 인수를 위한 함수
	void zoneclear(int n);//플레이어죽었을 때 초기화
	void isalive(int n);//사람 살아있는거 확인
};