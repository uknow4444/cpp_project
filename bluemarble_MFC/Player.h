#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "ItemCard.h"
class Board;
class Zone;
class Player {
	vector<Zone> myland; // 소지땅
	int color_cnt[9];
	// 0:관광지(초록), 1:빨강, 2:주황, 3:노랑, 4:파랑, 5:보라, 6:청남, 7:분홍, 8:검은색
	bool alive;//게임오버인지 확인
	int position;//최대39까지 판도는거 검사용
	int posx,posy; // 현재 배열상 좌표
	int x, y;//차례설정할때 필요한 좌표
	int money; // 소지금
	int prisoncnt;//감옥 들어갔을 때 2로바뀌고 0이되었을 때 탈출
	ItemCard *mycard; // 아이템카드
	int move_count; // 이동거리
	int diex, diey;//죽을 때 그려주는 x,y좌표
public:
	Player(int money = 0);
	~Player();
	//접근자 설정자 정의
	int getdiex();
	int getdiey();
	void setdiexy(int x,int y);
	int getPosx();
	int getPosy();
	void setPos(int x,int y);
	void setposition(int x);
	void setposp(int x,int y);
	int getx();
	int gety();
	int getposition();
	int getMoney();
	void setMoney(int x);
	void setprisoncnt(int n);
	int getprisoncnt();
	void setAlive(bool x);
	bool getAlive();
	ItemCard getMycard();
	void setMycard(int c);
	int getColor(int index);
	void setColor(int index, bool check);
	void addZone(Zone z); // 소유지 추가
	int getMylandlength(); // 소유 땅의 개수 반환
	Zone getMyland(int n); // 소유 땅을 반환, n은 index
	int getMovecount();
	void setMovecount(int x);
	void eraseland(int x);

	void mycardexe(Board &b, int n);
};
