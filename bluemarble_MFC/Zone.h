#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Player.h"
class ItemCard;
class Board;

class Zone {
	string name; // 땅이름
	int cost; // 가격
	int owner; // 주인장
			   // 0 = 보드가 주인
			   // 1,2,3,4 각 플레이어 번호 의미
			   // 5 = 구매 불가 땅
	int x; // x 좌표
	int y; // y 좌표
	int dirc; // 블럭상 캐릭터 방향성
public:
	Zone(string name = "", int cost = 0, int owner = 0, int x = 0, int y = 0, int dirc = 0);
	virtual ~Zone();
	//접근자 설정자 정의
	int getCost();
	void setCost(int x);
	int getOwner();
	void setOwner(int x);
	string getName();
	void setName(string s);
	virtual void func(Board &b, int n) {} // 기타지역 각자의 함수 정의

	//price를 공통적으로 자식클래스에서 사용하기 위해 가상함수 정의
	virtual int getPrice() { return 0; }
	virtual void setPrice(int p) {}
};


// 일반지역 정의 클래스
class Land :public Zone {
	//int Bulid_cnt; //건물 지은 갯수 카운트
	int color; // 지역 색 타입
	int price; // 지급 가격
public:
	//생성자 소멸자
	Land(string name = "", int cost = 0, int x = 0, int y = 0, int dirc = 0, int color = 0);
	~Land();
	//접근자 설정자
	int getColor();
	int getPrice();
	void setPrice(int p);
	//함수 정의
};


// 섬 관광지 지역 정의 클래스
class Island : public Zone {
	int visit; // 방문횟수
public:
	//생성자 소멸자
	Island(string name = "", int cost = 0, int x = 0, int y = 0, int dirc = 0);
	~Island();
	//접근자 설정자
	int getVisit();
	void setVisit(int v);
	//함수 정의
};



//골드카드 지역 정의 클래스
class Goldkey :public Zone {
public:
	//생성자 소멸자
	Goldkey(string name = "Goldkey", int x = 0, int y = 0, int dirc = 0);
	~Goldkey();
	//함수 정의
	void func(Board &b, int n); // 카드 뽑기 호출
};

//기타지역
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
	int price; // 저장금액
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