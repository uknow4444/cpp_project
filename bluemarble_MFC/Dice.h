#pragma once
#include <stdlib.h> // random ����� ��


class Dice {
	int num; // �ֻ��� ���� ����
public:
	Dice(); // ������ - ���� �� �ֻ��� ���� 0���� �ʱ�ȭ
	~Dice(); // �Ҹ���

	int getNum(); // �ֻ��� ���� ������
	void setNum(int x);
	void Roll(); // �ֻ��� ������ �Լ�
	bool operator==(Dice& d);
};
