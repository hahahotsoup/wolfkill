#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<algorithm>
using namespace std;
struct RoleAssignment {
	int werewolves;
	int seer;
	int villagers;
	int hunter;
	int witch;
};
struct play {
	int number;
	string job;
} player[100];
bool cmp(play a, play b) {
	return a.number < b.number;
}
void fenpei(int totalPlayers, int a, int b, int c, int d, int e) {
	for (int i = 1; i <= totalPlayers; i++) {
		player[i].number = i ;
	}
	// 随机打乱玩家编号
	std::random_shuffle(player + 1, player + totalPlayers + 1);
	for (int i = 1; i <= a; i++) {
		player[i].job = "wolf";
	}
	for (int i = a + 1; i <= a + b; i++) {
		player[i].job = "seer";
	}
	for (int i = a + b + 1; i <= a + b + c; i++) {
		player[i].job = "villager";
	}
	for (int i = a + b + c + 1; i <= a + b + c + d; i++) {
		player[i].job = "hunter";
	}
	for (int i = a + b + c +d + 1; i <= a + b + c + d+e; i++) {
		player[i].job = "whith";
	}
	sort(player + 1, player + totalPlayers + 1, cmp);
	for (int i = 1; i <= totalPlayers; i++) {
		cout << player[i].number << " " << player[i].job << endl;
	}
}
void assignRoles(int totalPlayers, RoleAssignment& assignment) {


	// 随机分配角色
	assignment.werewolves = rand() % (totalPlayers / 3) + 1;// 狼人数为总人数的三分之一以内
	assignment.seer = rand() % (totalPlayers / 4) + 1;// 预言家数为总人数的四分之一以内
	int shengyu = totalPlayers - assignment.werewolves - assignment.seer;
	assignment.villagers = shengyu / 3+1 ; // 剩余为村民(预留两个给猎人和女巫)
	assignment.hunter = assignment.villagers;
	assignment.witch = shengyu - assignment.villagers - assignment.hunter;
	cout << "配置：" << endl << "狼人:" << assignment.werewolves << endl;
	cout << "预言家:" << assignment.seer << endl;
	cout << "村民:" << assignment.villagers << endl;
	cout << "猎人:" << assignment.hunter << endl;
	cout << "女巫:" << assignment.witch<<endl;
	cout << "是否合适?(y/n)" << endl;
	char a;
	cin >> a;
	if (a == 'y') {
		fenpei(totalPlayers, assignment.werewolves, assignment.seer, assignment.villagers, assignment.hunter, assignment.witch);
	} else {
		system("cls");
		RoleAssignment assignment;
		srand(time(0)); // 初始化随机种子
		assignRoles(totalPlayers, assignment);
	}

}

int main() {
	int totalPlayers;
	cin >> totalPlayers; //玩家数量
	RoleAssignment assignment;
	srand(time(0)); // 初始化随机种子

	assignRoles(totalPlayers, assignment);

	return 0;
}
