

#include "stdafx.h"
#include "Player.h"
#include "Board.h"
#include "Zone.h"

Player::Player(int money) {
	this->posx = 790;
	this->posy = 620;
	this->x = 0;
	this->y = 0;
	this->money = money;;
	this->prisoncnt = -1; // �⺻ �� -1
	this->alive = true;
	position = 0;
	for (int i = 0; i < 9; i++) {
		color_cnt[i] = 0;
	}
}
Player::~Player() {}

//������ ������ ����
int Player::getdiex() {
	return this->diex;
}
int Player::getdiey() {
	return this->diey;
}
void Player::setdiexy(int x,int y) {
	this->diex = x;
	this->diey = y;
}
int Player::getPosx() {
	return this->posx;
}
int Player::getPosy() {
	return this->posy;
}
void Player::setPos(int x,int y) {
	this->posx = x;
	this->posy = y;
}
void Player::setprisoncnt(int n) {
	this->prisoncnt = n;
}
int Player::getprisoncnt() {
	return this->prisoncnt;
}
void Player::setAlive(bool x) {
	this->alive = x;
}
bool Player::getAlive() {
	return this->alive;
}
int Player::getposition() {
	return this->position;
}
void Player::setposition(int x) {
	this->position = x;
}

int Player::getMoney() {
	return this->money;
}
void Player::setMoney(int x) {
	this->money = x;
}
ItemCard Player::getMycard() {
	return *(this->mycard);
}
void Player::setMycard(int c) {
	if (c == 1)
		this->mycard = new ItemCard1();
	if (c == 2)
		this->mycard = new ItemCard2();
	if (c == 3)
		this->mycard = new ItemCard3();
	if (c == 4)
		this->mycard = new ItemCard4();
	if (c == 5)
		this->mycard = new ItemCard5();
	if (c == 6)
		this->mycard = new ItemCard6();
	if (c == 7)
		this->mycard = new ItemCard7();
	if (c == 8)
		this->mycard = new ItemCard8();
	if (c == 9)
		this->mycard = new ItemCard9();
	if (c == 10)
		this->mycard = new ItemCard10();
}
int Player::getColor(int index) {
	// 1:����, 2:��Ȳ, 3:���, 4:�Ķ�, 5:����, 6:û��, 7:��ȫ, 8:������
	return this->color_cnt[index];
}
void Player::setColor(int index, bool check) {
	// 1:����, 2:��Ȳ, 3:���, 4:�Ķ�, 5:����, 6:û��, 7:��ȫ, 8:������
	if (check == true) this->color_cnt[index]++;
	else this->color_cnt[index]--;
}
void Player::addZone(Zone z) { // ������ ����
	this->myland.push_back(z);
}

void Player::setposp(int x,int y) {
	this->x = x;
	this->y = y;
}
int Player::getx() {
	return this->x;
}
int Player::gety() {
	return this->y;
}

int Player::getMylandlength() { // ���� ���� ���� ��ȯ
	return this->myland.size();
}
Zone Player::getMyland(int n) { // ���� ���� ��ȯ
	return this->myland[n];
}
int Player::getMovecount() {
	return this->move_count;
}
void Player::setMovecount(int x) {
	this->move_count = x;
}
void Player::eraseland(int x) {
	this->myland.erase(this->myland.begin() + x );
}
//execute �����Լ�
void Player::mycardexe(Board &b, int n) {
	this->mycard->execute(b,n);
}