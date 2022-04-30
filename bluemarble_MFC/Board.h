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
	void make_card_deck(); // ī�� ���� ����� �Լ�
	void take(string str,int x,int y);// �μ��� ���� �Լ�
	void zoneclear(int n);//�÷��̾��׾��� �� �ʱ�ȭ
	void isalive(int n);//��� ����ִ°� Ȯ��
};