#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"2048.h"

using namespace std;

class A {};
class B : public virtual A {};
class C : public virtual A {};
class D : public B, public C {};

class E {
public:
	virtual void f() {};
	int a;
	char b;
	double c;
};

class myless {
public:
	bool operator () (const int &a, const int &b) {
		return a < b;
	}
};

ostream & operator<<(ostream& os, vector<int> v) {
	for (auto iter = v.cbegin(); iter != v.cend(); iter++)
		os << *iter << " ";
	return os;
}
int main(int argc, char *argv[])
{
	Game g;
	while (1) {
		string msg;
		cout << "Y 开始 N 退出 目标:2048 :";
		cin >> msg;
		if (msg == "N") {
			exit(0);
		}
		if (msg == "Y")
			g.startGame();
	}
	cout << endl;
}