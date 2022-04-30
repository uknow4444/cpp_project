#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Player.h"
class ItemCard;
class Board;

class Zone {
	string name; // ���̸�
	int cost; // ����
	int owner; // ������
			   // 0 = ���尡 ����
			   // 1,2,3,4 �� �÷��̾� ��ȣ �ǹ�
			   // 5 = ���� �Ұ� ��
	int x; // x ��ǥ
	int y; // y ��ǥ
	int dirc; // ���� ĳ���� ���⼺
public:
	Zone(string name = "", int cost = 0, int owner = 0, int x = 0, int y = 0, int dirc = 0);
	virtual ~Zone();
	//������ ������ ����
	int getCost();
	void setCost(int x);
	int getOwner();
	void setOwner(int x);
	string getName();
	void setName(string s);
	virtual void func(Board &b, int n) {} // ��Ÿ���� ������ �Լ� ����

	//price�� ���������� �ڽ�Ŭ�������� ����ϱ� ���� �����Լ� ����
	virtual int getPrice() { return 0; }
	virtual void setPrice(int p) {}
};


// �Ϲ����� ���� Ŭ����
class Land :public Zone {
	//int Bulid_cnt; //�ǹ� ���� ���� ī��Ʈ
	int color; // ���� �� Ÿ��
	int price; // ���� ����
public:
	//������ �Ҹ���
	Land(string name = "", int cost = 0, int x = 0, int y = 0, int dirc = 0, int color = 0);
	~Land();
	//������ ������
	int getColor();
	int getPrice();
	void setPrice(int p);
	//�Լ� ����
};


// �� ������ ���� ���� Ŭ����
class Island : public Zone {
	int visit; // �湮Ƚ��
public:
	//������ �Ҹ���
	Island(string name = "", int cost = 0, int x = 0, int y = 0, int dirc = 0);
	~Island();
	//������ ������
	int getVisit();
	void setVisit(int v);
	//�Լ� ����
};



//���ī�� ���� ���� Ŭ����
class Goldkey :public Zone {
public:
	//������ �Ҹ���
	Goldkey(string name = "Goldkey", int x = 0, int y = 0, int dirc = 0);
	~Goldkey();
	//�Լ� ����
	void func(Board &b, int n); // ī�� �̱� ȣ��
};

//��Ÿ����
class ETC :public Zone {
public:
	ETC(string name = "");
	virtual ~ETC();
};

class Trip : public ETC {
public:
	Trip(string name = "Trip");
	~Trip();
	void func(Board &b, int n);
};
class TAX_O : public ETC {
	int price; // ����ݾ�
public:
	TAX_O(string name = "TAX_O");
	~TAX_O();
	int getPrice();
	void setPrice(int p);
	void func(Board &b, int n);
};
class TAX_I : public ETC {
public:
	TAX_I(string name = "TAX_I");
	~TAX_I();
	void func(Board &b, int n);
};
class Start : public ETC {
public:
	Start(string name = "Start");
	~Start();
	void func(Board &b, int n);
};
class Prison : public ETC {
public:
	Prison(string name = "Prison");
	~Prison();
	void func(Board &b, int n);
};