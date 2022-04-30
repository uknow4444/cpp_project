#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "ItemCard.h"
class Board;
class Zone;
class Player {
	vector<Zone> myland; // ������
	int color_cnt[9];
	// 0:������(�ʷ�), 1:����, 2:��Ȳ, 3:���, 4:�Ķ�, 5:����, 6:û��, 7:��ȫ, 8:������
	bool alive;//���ӿ������� Ȯ��
	int position;//�ִ�39���� �ǵ��°� �˻��
	int posx,posy; // ���� �迭�� ��ǥ
	int x, y;//���ʼ����Ҷ� �ʿ��� ��ǥ
	int money; // ������
	int prisoncnt;//���� ���� �� 2�ιٲ�� 0�̵Ǿ��� �� Ż��
	ItemCard *mycard; // ������ī��
	int move_count; // �̵��Ÿ�
	int diex, diey;//���� �� �׷��ִ� x,y��ǥ
public:
	Player(int money = 0);
	~Player();
	//������ ������ ����
	int getdiex();
	int getdiey();
	void setdiexy(int x,int y);
	int getPosx();
	int getPosy();
	void setPos(int x,int y);
	void setposition(int x);
	void setposp(int x,int y);
	int getx();
	int gety();
	int getposition();
	int getMoney();
	void setMoney(int x);
	void setprisoncnt(int n);
	int getprisoncnt();
	void setAlive(bool x);
	bool getAlive();
	ItemCard getMycard();
	void setMycard(int c);
	int getColor(int index);
	void setColor(int index, bool check);
	void addZone(Zone z); // ������ �߰�
	int getMylandlength(); // ���� ���� ���� ��ȯ
	Zone getMyland(int n); // ���� ���� ��ȯ, n�� index
	int getMovecount();
	void setMovecount(int x);
	void eraseland(int x);

	void mycardexe(Board &b, int n);
};
