#ifndef HEADER_2048_HEADER
#define HEADER_2048_HEADER

#include<iostream>
#include<Windows.h>
#include<vector>

using namespace std;
#define GRID_NUM 4
#define WIN 2048

// 设置光标的位置
void SetPosition(int, int);

// 布局结构
class Game {
public:
	//检查游戏状态
	int CheckGameStatus();

	//移动一次
	void OneOperator();

	//移动合并
	void Move(int, int);

	//产生随机数字
	void CreateNum();
	//初始化
	void initGame();
	//开始
	void startGame();
	int getScore();
	friend ostream& operator << (ostream& os, vector<vector<int>> board);
	void rotate();
	bool check();
	Game();
	~Game();
private:
	vector<vector<int>> board; // 面板
	int count; // 操作一次的移动合并次数
	bool flag;
	int max_score;
};

void SetPosition(int x, int y);

#endif