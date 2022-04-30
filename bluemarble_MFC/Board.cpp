#include "stdafx.h"
#include "Board.h"
#include "Player.h"

Board::Board(int n) {
	this->turn = 0; // ���� �� �ʱ�ȭ

	for (int i = 0; i < n; i++) {
		player[i].setMoney(2000);
		player[i].setAlive(true);
		player[i].setPos(player[i].getPosx() + (i * 6), player[i].getPosy() + i * 6);
		player[i].setposp(160 + (720 * (i % 2)), 20 + (350 * (i / 2)));//���ʸ����� ��ǥ
		player[i].setdiexy((910 * (i % 2)),  (350 * (i / 2)));//�������� ��ǥ
	}




	//���� ����

	//Zone(name, cost, owner, x, y, dirc)
	//Goldkey(name,x,y,dirc)
	//Island(name,cost,x,y,dirc)
	//land(name, cost,x,y,dirc,color)

	//����
	zone[0] = new Start();
	//1�� ���� - ������ ����
	zone[1] = new Land("�ȵ�", 150, 0, 0, 1, 1); // �ȵ�
	zone[2] = new Goldkey("Goldkey", 0, 0, 1); // ���Ű
	zone[3] = new Land("�ϵ�", 150, 0, 0, 1, 1); // �ϵ�
	zone[4] = new Land("û��", 150, 0, 0, 1, 1); // û��
	zone[5] = new Island("���ֵ�", 300, 0, 0, 1); // ���ֵ�
											//1�� ����- ��Ȳ�� ����
	zone[6] = new Land("����", 180, 0, 0, 1, 2); // ����
	zone[7] = new Goldkey("Goldkey", 0, 0, 1); // ���Ű
	zone[8] = new Land("Ⱦ��", 180, 0, 0, 1, 2); // Ⱦ��
	zone[9] = new Land("����", 180, 0, 0, 1, 2); // ����
	zone[10] = new Prison(); // ����
							 //2�� ���� - ����� ����
	zone[11] = new Land("���", 250, 0, 0, 2, 3); // ���
	zone[12] = new Goldkey("Goldkey", 0, 0, 2); // ���Ű
	zone[13] = new Land("����", 250, 0, 0, 2, 3); // ����
	zone[14] = new Land("�Ⱦ�", 250, 0, 0, 2, 3); // �Ⱦ�
	zone[15] = new Island("�︪��", 300, 0, 0, 2); // �︪��
											 //2�� ���� - �Ķ��� ����
	zone[16] = new Land("��â", 220, 0, 0, 2, 4); // ��â
	zone[17] = new Goldkey("Goldkey", 0, 0, 2); // ���Ű
	zone[18] = new Land("����", 220, 0, 0, 2, 4); // ����
	zone[19] = new Land("����", 220, 0, 0, 2, 4); // ����
	zone[20] = new TAX_O(); // ���� ��� ��
							//3�� ���� - ����� ����
	zone[21] = new Land("����", 200, 0, 0, 3, 5); // ����
	zone[22] = new Goldkey("Goldkey", 0, 0, 3); // ���Ű
	zone[23] = new Land("��õ", 200, 0, 0, 3, 5); // ��õ
	zone[24] = new Land("õ��", 200, 0, 0, 3, 5); // õ��
	zone[25] = new Island("��ȭ��", 300, 0, 0, 3); // ��ȭ��
											 //3�� ���� - û���� ����
	zone[26] = new Land("����", 170, 0, 0, 3, 6); // ����
	zone[27] = new Goldkey("Goldkey", 0, 0, 3); // ���Ű
	zone[28] = new Land("�ӽ�", 170, 0, 0, 3, 6); // �ӽ�
	zone[29] = new Land("����", 170, 0, 0, 3, 6); // ����
	zone[30] = new Trip(); // ����
						   //4�� ���� - ��ȫ�� ����
	zone[31] = new Land("���", 200, 0, 0, 4, 7); // ���
	zone[32] = new Island("����", 300, 0, 0, 4); // ����
	zone[33] = new Land("�λ�", 200, 0, 0, 4, 7); // �λ�
	zone[34] = new Land("�뱸", 200, 0, 0, 4, 7); // �뱸
	zone[35] = new Goldkey("Goldkey", 0, 0, 4); // ���Ű
										 //4�� ���� - ������ ����
	zone[36] = new Land("��õ", 300, 0, 0, 4, 8); // ��õ
	zone[37] = new Land("����", 300, 0, 0, 4, 8); // ����
	zone[38] = new TAX_I(); // ���� ���� ��
	zone[39] = new Land("��â", 300, 0, 0, 4, 8); // ��â

	srand(time(NULL));
	//ī�� �� �����
	//�� �Լ��� 4�徿
	make_card_deck();
}


Board::~Board() {}

// �� �����̴� ���� ���� �Լ�
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
		
		
		if (str==player[x].getMyland(i).getName()) {//�̸��̰����� 
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
//ī�嵦�� �������ִ� �Լ�
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