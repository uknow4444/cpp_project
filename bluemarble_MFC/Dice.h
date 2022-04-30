#pragma once
#include <stdlib.h> // random 쓸라고 함


class Dice {
	int num; // 주사위 숫자 저장
public:
	Dice(); // 생성자 - 시작 시 주사위 숫자 0으로 초기화
	~Dice(); // 소멸자

	int getNum(); // 주사위 숫자 접근자
	void setNum(int x);
	void Roll(); // 주사위 굴리는 함수
	bool operator==(Dice& d);
};
