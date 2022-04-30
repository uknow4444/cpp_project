#include "stdafx.h"
#include "Dice.h"


Dice::Dice() {
	srand(time(NULL)); // �õ� �ʱ�ȭ�� ��ü�� �ֱ�
	this->num = 0;
}
Dice::~Dice() {}


void Dice::setNum(int x) {
	this->num = x;
}

int Dice::getNum() { // �ֻ��� ���� ������
	return this->num;
}
void Dice::Roll() { // �ֻ��� ������ �Լ�
	this->num = (rand() % 6) + 1; // 1~6 ���� �̱�
}

//�� �ֻ��� ���ڰ� �Ȱ��ٸ� true
bool Dice::operator==(Dice& d) {
	if (this->num == d.num) return true;
	return false;
}