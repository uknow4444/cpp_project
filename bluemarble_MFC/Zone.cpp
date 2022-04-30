
#include "stdafx.h"
#include "Zone.h"



#include "ItemCard.h"
#include "Board.h"


/***********Zone 정의************/
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

//접근자 설정자 정의
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













/*****************Land 정의***********************/

//생성자 소멸자
//Zone(name, cost, owner, x, y, dirc)
//land(name, cost,x,y,dirc,color)
Land::Land(string name, int cost, int x, int y, int dirc, int color) :Zone(name, cost, 0, x, y, dirc) {
	//일반 지역은 주인은 시작 시 무조건 보드
	// 1:빨강, 2:주황, 3:노랑, 4:파랑, 5:보라, 6:청남, 7:분홍, 8:검은색
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

//접근자 설정자
int Land::getColor() { return this->color; }
int Land::getPrice() { return this->price; }
void Land::setPrice(int p) {
	this->price = p;
}















/*****************Island 정의***********************/

//생성자 소멸자
//Zone(name, cost, owner, x, y, dirc)
//Island(name,cost,x,y,dirc)
Island::Island(string name, int cost, int x, int y, int dirc) :Zone(name, cost, 0, x, y, dirc) {
	//관광지 지역 주인은 시작 시 무조건 보드
	this->visit = 0;
}
Island::~Island() {}
//접근자 설정자
int Island::getVisit() { return this->visit; }
void Island::setVisit(int v) {
	this->visit = v;
}















/*****************Goldkey 정의***********************/


//생성자 소멸자
//Zone(name, cost, owner, x, y, dirc)
//Goldkey(name,x,y,dirc)
Goldkey::Goldkey(string name, int x, int y, int dirc) :Zone(name, 0, 5, x, y, dirc) {}
//Goldkey 가격 0, 구매불가 지역(5)이다. 
Goldkey::~Goldkey() {}
//함수 정의
void Goldkey::func(Board &b, int n) { // 카드 뽑기 호출
	if (b.card_deck.size() == 0) { // 뽑을 카드가 없다면
		b.make_card_deck(); // 카드덱을 새로 만든다
	}
	if (b.card_deck.size() > 0) {
		b.player[n].setMycard(b.card_deck.back().getType());
		b.card_deck.pop_back();
	}
}





						
						
						
						
/*****************기타지역 정의***********************/




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
void TAX_O::func(Board &b, int n) { // 모아둔 세금을 얻고 세금 초기화
	b.player[n].setMoney(b.player[n].getMoney() + this->price);
	this->price = 0;
}
void TAX_I::func(Board &b, int n) {
	b.player[n].setMoney(b.player[n].getMoney() - 300); // 돈을 잃는다.
	b.zone[20]->setCost(b.zone[20]->getCost()+300);
}
void Start::func(Board &b, int n) { // 시작땅 지나면 월급
	b.player[n].setMoney(b.player[n].getMoney()+300);
}
void Prison::func(Board &b, int n) {
	b.player[n].setprisoncnt(2);
}