#include "stdafx.h"
#include "Board.h"
#include "Player.h"

Board::Board(int n) {
	this->turn = 0; // 진행 턴 초기화

	for (int i = 0; i < n; i++) {
		player[i].setMoney(2000);
		player[i].setAlive(true);
		player[i].setPos(player[i].getPosx() + (i * 6), player[i].getPosy() + i * 6);
		player[i].setposp(160 + (720 * (i % 2)), 20 + (350 * (i / 2)));//차례를위한 좌표
		player[i].setdiexy((910 * (i % 2)),  (350 * (i / 2)));//죽음위한 좌표
	}




	//지역 생성

	//Zone(name, cost, owner, x, y, dirc)
	//Goldkey(name,x,y,dirc)
	//Island(name,cost,x,y,dirc)
	//land(name, cost,x,y,dirc,color)

	//시작
	zone[0] = new Start();
	//1번 방향 - 빨간색 정의
	zone[1] = new Land("안동", 150, 0, 0, 1, 1); // 안동
	zone[2] = new Goldkey("Goldkey", 0, 0, 1); // 골드키
	zone[3] = new Land("하동", 150, 0, 0, 1, 1); // 하동
	zone[4] = new Land("청양", 150, 0, 0, 1, 1); // 청양
	zone[5] = new Island("제주도", 300, 0, 0, 1); // 제주도
											//1번 방향- 주황색 정의
	zone[6] = new Land("나주", 180, 0, 0, 1, 2); // 나주
	zone[7] = new Goldkey("Goldkey", 0, 0, 1); // 골드키
	zone[8] = new Land("횡성", 180, 0, 0, 1, 2); // 횡성
	zone[9] = new Land("강릉", 180, 0, 0, 1, 2); // 강릉
	zone[10] = new Prison(); // 감옥
							 //2번 방향 - 노란색 정의
	zone[11] = new Land("담양", 250, 0, 0, 2, 3); // 담양
	zone[12] = new Goldkey("Goldkey", 0, 0, 2); // 골드키
	zone[13] = new Land("포항", 250, 0, 0, 2, 3); // 포항
	zone[14] = new Land("안양", 250, 0, 0, 2, 3); // 안양
	zone[15] = new Island("울릉도", 300, 0, 0, 2); // 울릉도
											 //2번 방향 - 파란색 정의
	zone[16] = new Land("평창", 220, 0, 0, 2, 4); // 평창
	zone[17] = new Goldkey("Goldkey", 0, 0, 2); // 골드키
	zone[18] = new Land("속초", 220, 0, 0, 2, 4); // 속초
	zone[19] = new Land("전주", 220, 0, 0, 2, 4); // 전주
	zone[20] = new TAX_O(); // 세금 얻는 곳
							//3번 방향 - 보라색 정의
	zone[21] = new Land("여수", 200, 0, 0, 3, 5); // 여수
	zone[22] = new Goldkey("Goldkey", 0, 0, 3); // 골드키
	zone[23] = new Land("대천", 200, 0, 0, 3, 5); // 대천
	zone[24] = new Land("천안", 200, 0, 0, 3, 5); // 천안
	zone[25] = new Island("강화도", 300, 0, 0, 3); // 강화도
											 //3번 방향 - 청남색 정의
	zone[26] = new Land("영광", 170, 0, 0, 3, 6); // 영광
	zone[27] = new Goldkey("Goldkey", 0, 0, 3); // 골드키
	zone[28] = new Land("임실", 170, 0, 0, 3, 6); // 임실
	zone[29] = new Land("대전", 170, 0, 0, 3, 6); // 대전
	zone[30] = new Trip(); // 여행
						   //4번 방향 - 분홍색 정의
	zone[31] = new Land("울산", 200, 0, 0, 4, 7); // 울산
	zone[32] = new Island("독도", 300, 0, 0, 4); // 독도
	zone[33] = new Land("부산", 200, 0, 0, 4, 7); // 부산
	zone[34] = new Land("대구", 200, 0, 0, 4, 7); // 대구
	zone[35] = new Goldkey("Goldkey", 0, 0, 4); // 골드키
										 //4번 방향 - 검은색 정의
	zone[36] = new Land("인천", 300, 0, 0, 4, 8); // 인천
	zone[37] = new Land("서울", 300, 0, 0, 4, 8); // 서울
	zone[38] = new TAX_I(); // 세금 내는 곳
	zone[39] = new Land("신창", 300, 0, 0, 4, 8); // 신창

	srand(time(NULL));
	//카드 덱 만들기
	//각 함수별 4장씩
	make_card_deck();
}


Board::~Board() {}

// 말 움직이는 방향 정의 함수
void Board::moveif(int n) {
	int pos = this->player[n].getposition();

	if (pos < 10) {
		this->player[n].setPos(this->player[n].getPosx() - 56, this->player[n].getPosy());
	}
	else if (pos < 20) {
		this->player[n].setPos(this->player[n].getPosx() , this->player[n].getPosy()-56);
	}
	else if (pos < 30) {
		this->player[n].setPos(this->player[n].getPosx() + 56, this->player[n].getPosy());
	}
	else {
		this->player[n].setPos(this->player[n].getPosx(), this->player[n].getPosy() + 56);
	}
	if (pos!=39) {

		this->player[n].setposition(pos+1);
	}
	else {
		this->player[n].setposition(0);
	}
}

void Board::buy(int n) {
	//this->player[n]
}
void  Board::take(string str,int x,int y) {
	
	for (int i = 0; i < player[x].getMylandlength();i++) {
		
		
		if (str==player[x].getMyland(i).getName()) {//이름이같으면 
			player[y].addZone(player[x].getMyland(i));
			player[x].eraseland(i);
		}
	}
	
}
void Board::zoneclear(int n) {
	for (int i = 0; i < player[n].getMylandlength();i++) {
		player[n].getMyland(i).setOwner(0);
	}
	
}

void Board::isalive(int n) {
	
	if (player[n].getMoney() <= 0) {
		player[n].setAlive(false);
	}
	

}
//카드덱을 구성해주는 함수
void Board::make_card_deck() {
	int sub_card_cnt[10] = { 0, };
	for (int i = 0; i < 40; i++) {
		int x = rand() % 10;
		if (sub_card_cnt[x] == 4) {
			i--;
			continue;
		}
		sub_card_cnt[x]++;
		if (x == 0) {
			ItemCard *card = new ItemCard1();
			card_deck.push_back(*card);
		}
		if (x == 1) {
			ItemCard *card = new ItemCard2();
			card_deck.push_back(*card);
		}
		if (x == 2) {
			ItemCard *card = new ItemCard3();
			card_deck.push_back(*card);
		}
		if (x == 3) {
			ItemCard *card = new ItemCard4();
			card_deck.push_back(*card);
		}
		if (x == 4) {
			ItemCard *card = new ItemCard5();
			card_deck.push_back(*card);
		}
		if (x == 5) {
			ItemCard *card = new ItemCard6();
			card_deck.push_back(*card);
		}
		if (x == 6) {
			ItemCard *card = new ItemCard7();
			card_deck.push_back(*card);
		}
		if (x == 7) {
			ItemCard *card = new ItemCard8();
			card_deck.push_back(*card);
		}
		if (x == 8) {
			ItemCard *card = new ItemCard9();
			card_deck.push_back(*card);
		}
		if (x == 9) {
			ItemCard *card = new ItemCard10();
			card_deck.push_back(*card);
		}

	}

}