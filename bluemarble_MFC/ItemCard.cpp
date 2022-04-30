#include "stdafx.h"
#include "ItemCard.h"


#include "Player.h"
#include "Board.h"



// ī�帶�� �ڽ��� Ÿ�� �����Ŵ.
ItemCard::ItemCard(int x) {
	this->type = x;
}
ItemCard::~ItemCard() {}

//������ ������ ����
int ItemCard::getType() {
	return this->type;
}
void ItemCard::setType(int x) {
	this->type = x;
}





// �Լ� ����
ItemCard1::ItemCard1() : ItemCard(1) {} // ī�� 1�� ������
ItemCard2::ItemCard2() : ItemCard(2) {} // ī�� 2�� ������
ItemCard3::ItemCard3() : ItemCard(3) {} // ī�� 3�� ������
ItemCard4::ItemCard4() : ItemCard(4) {} // ī�� 4�� ������
ItemCard5::ItemCard5() : ItemCard(5) {} // ī�� 5�� ������
ItemCard6::ItemCard6() : ItemCard(6) {} // ī�� 6�� ������
ItemCard7::ItemCard7() : ItemCard(7) {} // ī�� 7�� ������
ItemCard8::ItemCard8() : ItemCard(8) {} // ī�� 8�� ������
ItemCard9::ItemCard9() : ItemCard(9) {} // ī�� 9�� ������
ItemCard10::ItemCard10() : ItemCard(10) {} // ī�� 10�� ������


ItemCard1::~ItemCard1() {} // ī�� 1�� �Ҹ���
ItemCard2::~ItemCard2() {} // ī�� 2�� �Ҹ���
ItemCard3::~ItemCard3() {} // ī�� 3�� �Ҹ���
ItemCard4::~ItemCard4() {} // ī�� 4�� �Ҹ���
ItemCard5::~ItemCard5() {} // ī�� 5�� �Ҹ���
ItemCard6::~ItemCard6() {} // ī�� 6�� �Ҹ���
ItemCard7::~ItemCard7() {} // ī�� 7�� �Ҹ���
ItemCard8::~ItemCard8() {} // ī�� 8�� �Ҹ���
ItemCard9::~ItemCard9() {} // ī�� 9�� �Ҹ���
ItemCard10::~ItemCard10() {} // ī�� 10�� �Ҹ���

// �� : 1�� �Լ�
void ItemCard1::execute(Board &b, int n) {
}
//�ֻ��� �ѹ� ��~ : 2�� �Լ�
void ItemCard2::execute(Board &b, int n) { 
	// �ֻ��� ���ڸ� ���Ͻ��������ν� �ٽ� ������ ����.
	b.dice[0].setNum(1);
	b.dice[1].setNum(1);
}
//���� �ֿ����~ : 3�� �Լ�
void ItemCard3::execute(Board &b, int n) {
	b.player[n].setMoney(b.player[n].getMoney() + 1000);
}
// ������ �������~ : 4�� �Լ�
void ItemCard4::execute(Board &b, int n) {
	b.player[n].setMoney(b.player[n].getMoney() - 1000);
	b.zone[20]->setPrice(b.zone[20]->getPrice() + 1000);
}
// ��������� �̵�! : 5�� �Լ�  - 38�� ĭ���� �̵�
void ItemCard5::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	if (x > 38)
		x = (40 - x) + 38;
	else
		x = (38 - x);
	b.player[n].setMovecount(x);
}
// �������� �̵�! : 6�� �Լ� - 20�� ĭ���� �̵�
void ItemCard6::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	if (x > 20)
		x = (40 - x) + 20;
	else
		x = (20 - x);
	b.player[n].setMovecount(x);
}
// ��â���� �̵�! : 7�� �Լ� - 39�� ĭ���� �̵�
void ItemCard7::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	x = (39 - x);
	b.player[n].setMovecount(x);
}
// �������� �̵�! : 8�� �Լ� - 10�� ĭ���� �̵�
void ItemCard8::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	if (x > 10)
		x = (40 - x) + 10;
	else
		x = (10 - x);
	b.player[n].setMovecount(x);
}
// ���������� ���� ������ �޽��ϴ�. : 9�� �Լ�
void ItemCard9::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	x = (40 - x);
	b.player[n].setMovecount(x);
}
// ������ ������~ : 10�� �Լ� - 30�� ĭ���� �̵�
void ItemCard10::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	if (x > 30)
		x = (40 - x) + 30;
	else
		x = (30 - x);
	b.player[n].setMovecount(x);
}

