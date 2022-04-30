#pragma once


class Board;
class Player;
class ItemCard {
	int type; // 카드의 타입을 저장
public:
	ItemCard(int x = 0); // 디폴트 매개변수 0로 타입 초기화
	virtual ~ItemCard();
	//접근자 설정자 정의
	int getType();
	void setType(int x);
	//함수 정의
	virtual void execute(Board &b, int n) {}
};

class ItemCard1 : public ItemCard {
public:
	ItemCard1();
	~ItemCard1();
	void execute(Board &b, int n);
};
class ItemCard2 : public ItemCard {
public:
	ItemCard2();
	~ItemCard2();
	void execute(Board &b, int n);
};
class ItemCard3 : public ItemCard {
public:
	ItemCard3();
	~ItemCard3();
	void execute(Board &b, int n);
};
class ItemCard4 : public ItemCard {
public:
	ItemCard4();
	~ItemCard4();
	void execute(Board &b, int n);
};
class ItemCard5 : public ItemCard {
public:
	ItemCard5();
	~ItemCard5();
	void execute(Board &b, int n);
};
class ItemCard6 : public ItemCard {
public:
	ItemCard6();
	~ItemCard6();
	void execute(Board &b, int n);
};
class ItemCard7 : public ItemCard {
public:
	ItemCard7();
	~ItemCard7();
	void execute(Board &b, int n);
};
class ItemCard8 : public ItemCard {
public:
	ItemCard8();
	~ItemCard8();
	void execute(Board &b, int n);
};
class ItemCard9 : public ItemCard {
public:
	ItemCard9();
	~ItemCard9();
	void execute(Board &b, int n);
};
class ItemCard10 : public ItemCard {
public:
	ItemCard10();
	~ItemCard10();
	void execute(Board &b, int n);
};