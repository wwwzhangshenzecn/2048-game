#ifndef HEADER_2048_HEADER
#define HEADER_2048_HEADER

#include<iostream>
#include<Windows.h>
#include<vector>

using namespace std;
#define GRID_NUM 4
#define WIN 2048

// ���ù���λ��
void SetPosition(int, int);

// ���ֽṹ
class Game {
public:
	//�����Ϸ״̬
	int CheckGameStatus();

	//�ƶ�һ��
	void OneOperator();

	//�ƶ��ϲ�
	void Move(int, int);

	//�����������
	void CreateNum();
	//��ʼ��
	void initGame();
	//��ʼ
	void startGame();
	int getScore();
	friend ostream& operator << (ostream& os, vector<vector<int>> board);
	void rotate();
	bool check();
	Game();
	~Game();
private:
	vector<vector<int>> board; // ���
	int count; // ����һ�ε��ƶ��ϲ�����
	bool flag;
	int max_score;
};

void SetPosition(int x, int y);

#endif