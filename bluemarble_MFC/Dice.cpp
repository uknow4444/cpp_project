#include "stdafx.h"
#include "Dice.h"


Dice::Dice() {
	srand(time(NULL)); // 시드 초기화를 객체에 넣기
	this->num = 0;
}
Dice::~Dice() {}


void Dice::setNum(int x) {
	this->num = x;
}

int Dice::getNum() { // 주사위 숫자 접근자
	return this->num;
}
void Dice::Roll() { // 주사위 굴리는 함수
	this->num = (rand() % 6) + 1; // 1~6 까지 뽑기
}

//두 주사위 숫자가 똑같다면 true
bool Dice::operator==(Dice& d) {
	if (this->num == d.num) return true;
	return false;
}