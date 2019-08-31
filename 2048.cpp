#include"2048.h"
#include<algorithm>
#include<time.h>
#include <iomanip>
#include<conio.h>
// 矩阵逆时针旋转90度
void Game::rotate() {
	int tmp[GRID_NUM][GRID_NUM] = { 0 };
	for (int i = 0; i < GRID_NUM; ++i) {
		for (int j = 0; j < GRID_NUM; ++j) {
			tmp[i][j] = board[j][GRID_NUM - 1 - i];
		}
	}
	for (int i = 0; i < GRID_NUM; ++i) {
		for (int j = 0; j < GRID_NUM; ++j) {
			board[i][j] = tmp[i][j];
		}
	}
	//cout << "逆时针旋转90度：\n" << board << endl;
}

void Game::Move(int x, int y)
{
	int copy_count = count;

	//左
	for (int j = y - 1; j >= 0; j--) {
		if (board[x][j] == 0)
			swap(board[x][j], board[x][y--]), flag = true;
		else if (board[x][j] == board[x][y]) {
			board[x][j] += board[x][y],
				board[x][y] = 0;
			count--, flag = true;
			if (board[x][j] > max_score)
				max_score = board[x][j];
			break;
		}
		else
			break;
	}
}

void Game::startGame()
{
	system("cls");
	initGame();
	int ch;
	bool al = true;

	while (al) {
		
		if (CheckGameStatus() == -1) {
			break;
		}
		cout << "输入移动方向（0退出）。";
		ch = _getch();
		flag = false;
		switch (ch)
		{
			//键盘上下左右方向键的键码（keyCode）是38、40、37和39
		case 119://上
			rotate();
			OneOperator();
			rotate();
			rotate();
			rotate();
			break;
		case 115: //下
			rotate();
			rotate();
			rotate();
			OneOperator();
			rotate();
			break;
		case 97: // 左
			OneOperator();
			break;
		case 100://右
			rotate();
			rotate();
			OneOperator();
			rotate();
			rotate();
			break;
		case 48:
			al = false;
		default://无效操作
			break;
		}
		CreateNum();
		system("cls");
		cout << board << endl;
		cout << "目前最大分：" << getScore() << endl;
	}
}


Game::Game() {
	board = vector<vector<int>>(GRID_NUM, vector<int>(GRID_NUM, 0));
	count = 0;
	max_score = 0;
}

int Game::getScore() {
	return max_score;
}

Game::~Game()
{
}
ostream& operator << (ostream& os, vector<vector<int>> board) {
	os << "控制：字母均为小写，上下左右分别为：w s a d \n\n";
	for (int i = 0; i < GRID_NUM; i++) {
		for (int j = 0; j < GRID_NUM; j++)
			os << setw(4) << board[i][j] << " ";
		os << endl;
	}

	return os;
}

void Game::CreateNum()
{
	srand(time(NULL));
	if (flag) {
		//创建一个新数字
		vector<vector<int>> temp;
		for (int i = 0; i < GRID_NUM; i++)
			for (int j = 0; j < GRID_NUM; j++)
				if (board[i][j] == 0)
					temp.push_back({ i, j });
		random_shuffle(temp.begin(), temp.end());
		vector<int> num{ 2,2,2,2,4 };
		random_shuffle(num.begin(), num.end());

		vector<int> ni{ 1,1,1,1,2 };
		random_shuffle(ni.begin(), ni.end());

		for (int i = 0; i < ni[0]; i++) {
			vector<int> c = temp.back();
			int x = c[0], y = c[1];
			temp.erase(temp.end() - 1);
			board[x][y] = num.back();
			max_score = max(max_score, num.back());
			num.erase(num.end() - 1);
			count++;
		}
		flag = false;
	}
	else {
		//pass
	}
}

void Game::initGame()
{
	board = vector<vector<int>>(GRID_NUM, vector<int>(GRID_NUM, 0));
	count = 0;
	max_score = 0;
	flag = true;
	CreateNum();
	cout << board << endl;
	cout << "目前最大分：" << getScore() << endl;

}

void SetPosition(int x, int y)
{
	HANDLE winHandle;//句柄
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标位置 
	SetConsoleCursorPosition(winHandle, pos);
}

int Game::CheckGameStatus()
{
	if (count == GRID_NUM * GRID_NUM && flag == false) {

		if (check()) {

			cout << "Game over" << endl;
			return -1;
		}
	}
	if (max_score == WIN) {
		cout << "Game Win!!!" << endl;
		return -1;
	}
	return 0;
}



bool Game::check()
{
	cout << "进入检测状态：\n" << endl;
	if (board[0][0] == board[1][0] ||
		board[0][0] == board[0][1])
		return false;

	if (board[0][GRID_NUM - 1] == board[0][GRID_NUM - 2] ||
		board[0][GRID_NUM - 1] == board[1][GRID_NUM - 1])
		return false;


	if (board[GRID_NUM - 1][0] == board[GRID_NUM - 2][0] ||
		board[GRID_NUM - 1][0] == board[GRID_NUM - 1][1])
		return false;

	if (board[GRID_NUM - 1][GRID_NUM - 1] == board[GRID_NUM - 2][GRID_NUM - 1] ||
		board[GRID_NUM - 1][GRID_NUM - 1] == board[GRID_NUM - 1][GRID_NUM - 2])
		return false;

	for (int i = 1; i < GRID_NUM - 1; i++)
		for (int j = 1; j < GRID_NUM - 1; j++) {
			if (board[i][j] == board[i - 1][j] ||
				board[i][j] == board[i + 1][j] ||
				board[i][j] == board[i][j + 1] ||
				board[i][j] == board
				[i][j - 1])
				return false;
		}


	return true;
}


void Game::OneOperator()
{
	for (int i = 0; i < GRID_NUM; i++) {
		for (int j = 0; j < GRID_NUM; j++) {
			if (board[i][j] != 0)
				Move(i, j);
		}
	}

}