#include "stdafx.h"
#include "ItemCard.h"


#include "Player.h"
#include "Board.h"



// 카드마다 자신의 타입 저장시킴.
ItemCard::ItemCard(int x) {
	this->type = x;
}
ItemCard::~ItemCard() {}

//접근자 설정자 정의
int ItemCard::getType() {
	return this->type;
}
void ItemCard::setType(int x) {
	this->type = x;
}





// 함수 정의
ItemCard1::ItemCard1() : ItemCard(1) {} // 카드 1번 생성자
ItemCard2::ItemCard2() : ItemCard(2) {} // 카드 2번 생성자
ItemCard3::ItemCard3() : ItemCard(3) {} // 카드 3번 생성자
ItemCard4::ItemCard4() : ItemCard(4) {} // 카드 4번 생성자
ItemCard5::ItemCard5() : ItemCard(5) {} // 카드 5번 생성자
ItemCard6::ItemCard6() : ItemCard(6) {} // 카드 6번 생성자
ItemCard7::ItemCard7() : ItemCard(7) {} // 카드 7번 생성자
ItemCard8::ItemCard8() : ItemCard(8) {} // 카드 8번 생성자
ItemCard9::ItemCard9() : ItemCard(9) {} // 카드 9번 생성자
ItemCard10::ItemCard10() : ItemCard(10) {} // 카드 10번 생성자


ItemCard1::~ItemCard1() {} // 카드 1번 소멸자
ItemCard2::~ItemCard2() {} // 카드 2번 소멸자
ItemCard3::~ItemCard3() {} // 카드 3번 소멸자
ItemCard4::~ItemCard4() {} // 카드 4번 소멸자
ItemCard5::~ItemCard5() {} // 카드 5번 소멸자
ItemCard6::~ItemCard6() {} // 카드 6번 소멸자
ItemCard7::~ItemCard7() {} // 카드 7번 소멸자
ItemCard8::~ItemCard8() {} // 카드 8번 소멸자
ItemCard9::~ItemCard9() {} // 카드 9번 소멸자
ItemCard10::~ItemCard10() {} // 카드 10번 소멸자

// 꽝 : 1번 함수
void ItemCard1::execute(Board &b, int n) {
}
//주사위 한번 더~ : 2번 함수
void ItemCard2::execute(Board &b, int n) { 
	// 주사위 숫자를 통일시켜줌으로써 다시 굴리기 가능.
	b.dice[0].setNum(1);
	b.dice[1].setNum(1);
}
//돈을 주웠어요~ : 3번 함수
void ItemCard3::execute(Board &b, int n) {
	b.player[n].setMoney(b.player[n].getMoney() + 1000);
}
// 강도를 만났어요~ : 4번 함수
void ItemCard4::execute(Board &b, int n) {
	b.player[n].setMoney(b.player[n].getMoney() - 1000);
	b.zone[20]->setPrice(b.zone[20]->getPrice() + 1000);
}
// 무법지대로 이동! : 5번 함수  - 38번 칸으로 이동
void ItemCard5::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	if (x > 38)
		x = (40 - x) + 38;
	else
		x = (38 - x);
	b.player[n].setMovecount(x);
}
// 경찰서로 이동! : 6번 함수 - 20번 칸으로 이동
void ItemCard6::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	if (x > 20)
		x = (40 - x) + 20;
	else
		x = (20 - x);
	b.player[n].setMovecount(x);
}
// 신창으로 이동! : 7번 함수 - 39번 칸으로 이동
void ItemCard7::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	x = (39 - x);
	b.player[n].setMovecount(x);
}
// 감옥으로 이동! : 8번 함수 - 10번 칸으로 이동
void ItemCard8::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	if (x > 10)
		x = (40 - x) + 10;
	else
		x = (10 - x);
	b.player[n].setMovecount(x);
}
// 시작점으로 가서 월급을 받습니다. : 9번 함수
void ItemCard9::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	x = (40 - x);
	b.player[n].setMovecount(x);
}
// 여행을 떠나요~ : 10번 함수 - 30번 칸으로 이동
void ItemCard10::execute(Board &b, int n) {
	int x = b.player[n].getposition();
	if (x > 30)
		x = (40 - x) + 30;
	else
		x = (30 - x);
	b.player[n].setMovecount(x);
}

