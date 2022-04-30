
#include "stdafx.h"
#include "Zone.h"



#include "ItemCard.h"
#include "Board.h"


/***********Zone ����************/
//Zone(name, cost, owner, x, y, dirc)
Zone::Zone(string name, int cost, int owner, int x, int y, int dirc) {
	this->name = name;
	this->cost = cost;
	this->owner = owner;
	this->x = x;
	this->y = y;
	this->dirc = dirc;
}
Zone::~Zone() {}

//������ ������ ����
int Zone::getCost() {
	return this->cost;
}
void Zone::setCost(int x) {
	this->cost = x;
}
int Zone::getOwner() {
	return this->owner;
}
void Zone::setOwner(int x) {
	this->owner = x;
}
string Zone::getName() {
	return this->name;
}
void Zone::setName(string s) {
	this->name = s;
}













/*****************Land ����***********************/

//������ �Ҹ���
//Zone(name, cost, owner, x, y, dirc)
//land(name, cost,x,y,dirc,color)
Land::Land(string name, int cost, int x, int y, int dirc, int color) :Zone(name, cost, 0, x, y, dirc) {
	//�Ϲ� ������ ������ ���� �� ������ ����
	// 1:����, 2:��Ȳ, 3:���, 4:�Ķ�, 5:����, 6:û��, 7:��ȫ, 8:������
	this->color = color;
	this->price = 0;
}
Land::~Land() {}
ETC::~ETC() {}
Trip::~Trip() {}
TAX_O::~TAX_O() {}
TAX_I::~TAX_I() {}
Start::~Start() {}
Prison::~Prison() {}

//������ ������
int Land::getColor() { return this->color; }
int Land::getPrice() { return this->price; }
void Land::setPrice(int p) {
	this->price = p;
}















/*****************Island ����***********************/

//������ �Ҹ���
//Zone(name, cost, owner, x, y, dirc)
//Island(name,cost,x,y,dirc)
Island::Island(string name, int cost, int x, int y, int dirc) :Zone(name, cost, 0, x, y, dirc) {
	//������ ���� ������ ���� �� ������ ����
	this->visit = 0;
}
Island::~Island() {}
//������ ������
int Island::getVisit() { return this->visit; }
void Island::setVisit(int v) {
	this->visit = v;
}















/*****************Goldkey ����***********************/


//������ �Ҹ���
//Zone(name, cost, owner, x, y, dirc)
//Goldkey(name,x,y,dirc)
Goldkey::Goldkey(string name, int x, int y, int dirc) :Zone(name, 0, 5, x, y, dirc) {}
//Goldkey ���� 0, ���źҰ� ����(5)�̴�. 
Goldkey::~Goldkey() {}
//�Լ� ����
void Goldkey::func(Board &b, int n) { // ī�� �̱� ȣ��
	if (b.card_deck.size() == 0) { // ���� ī�尡 ���ٸ�
		b.make_card_deck(); // ī�嵦�� ���� �����
	}
	if (b.card_deck.size() > 0) {
		b.player[n].setMycard(b.card_deck.back().getType());
		b.card_deck.pop_back();
	}
}





						
						
						
						
/*****************��Ÿ���� ����***********************/




//Zone(name, cost, owner, x, y, dirc)
ETC::ETC(string name): Zone(name, 0, 5, 0, 0, 10) {}
Trip::Trip(string name) : ETC(name) {}
TAX_O::TAX_O(string name) : ETC(name) {
	this->price = 0;
}
int TAX_O::getPrice() {
	return this->price;
}
void TAX_O::setPrice(int p) {
	this->price = p;
}
TAX_I::TAX_I(string name) : ETC(name) {}
Start::Start(string name) : ETC(name) {}
Prison::Prison(string name) : ETC(name) {}


void Trip::func(Board &b, int n) {}
void TAX_O::func(Board &b, int n) { // ��Ƶ� ������ ��� ���� �ʱ�ȭ
	b.player[n].setMoney(b.player[n].getMoney() + this->price);
	this->price = 0;
}
void TAX_I::func(Board &b, int n) {
	b.player[n].setMoney(b.player[n].getMoney() - 300); // ���� �Ҵ´�.
	b.zone[20]->setCost(b.zone[20]->getCost()+300);
}
void Start::func(Board &b, int n) { // ���۶� ������ ����
	b.player[n].setMoney(b.player[n].getMoney()+300);
}
void Prison::func(Board &b, int n) {
	b.player[n].setprisoncnt(2);
}