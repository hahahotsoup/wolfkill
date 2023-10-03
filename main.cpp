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
struct player{
	int number;
	string job;
}a[15];
void fenpei(int totalPlayers,int a,int b,int c,int d,int f)
{
	std::vector<int> players(totalPlayers);
	
	    // 初始化玩家编号
	    for (int i = 0; i < totalPlayers; i++) {
	        players[i] = i + 1;
	    }
	
	    // 随机打乱玩家编号
	    std::random_shuffle(players.begin(), players.end());
	    
}
void assignRoles(int totalPlayers, RoleAssignment& assignment) {
    

    // 随机分配角色
    assignment.werewolves = rand() % (totalPlayers / 3) + 1;// 狼人数为总人数的三分之一以内
    assignment.seer = rand() % (totalPlayers / 4) + 1;// 预言家数为总人数的四分之一以内
    assignment.villagers = totalPlayers - assignment.werewolves - assignment.seer - 2; // 剩余为村民(预留两个给猎人和女巫)
    assignment.hunter = 1;
    assignment.witch = 1;
	cout<<"配置："<<endl<<"狼人:"<<assignment.werewolves<<endl;
	cout<<"预言家:"<<assignment.seer<<endl;
	cout<<"村民:"<<assignment.villagers<<endl;
	cout<<"猎人:"<<assignment.hunter<<endl;
	cout<<"女巫:1"<<endl;
	cout<<"是否合适?(y/n)"<<endl;
	char a;
	cin>>a;
	if(a=='y')
	{
		fenpei(totalPlayers,assignment.werewolves,assignment.seer,assignment.villagers,assignment.hunter,assignment.witch);
	}else
	{
		system("cls");
		RoleAssignment assignment;
		srand(time(0)); // 初始化随机种子
		assignRoles(totalPlayers, assignment);
	}
	
}

int main() {
    int totalPlayers;
    cin>>totalPlayers;//玩家数量
    RoleAssignment assignment;
    srand(time(0)); // 初始化随机种子

    assignRoles(totalPlayers, assignment);

    return 0;
}
