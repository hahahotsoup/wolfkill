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
	
	    // ��ʼ����ұ��
	    for (int i = 0; i < totalPlayers; i++) {
	        players[i] = i + 1;
	    }
	
	    // ���������ұ��
	    std::random_shuffle(players.begin(), players.end());
	    
}
void assignRoles(int totalPlayers, RoleAssignment& assignment) {
    

    // ��������ɫ
    assignment.werewolves = rand() % (totalPlayers / 3) + 1;// ������Ϊ������������֮һ����
    assignment.seer = rand() % (totalPlayers / 4) + 1;// Ԥ�Լ���Ϊ���������ķ�֮һ����
    assignment.villagers = totalPlayers - assignment.werewolves - assignment.seer - 2; // ʣ��Ϊ����(Ԥ�����������˺�Ů��)
    assignment.hunter = 1;
    assignment.witch = 1;
	cout<<"���ã�"<<endl<<"����:"<<assignment.werewolves<<endl;
	cout<<"Ԥ�Լ�:"<<assignment.seer<<endl;
	cout<<"����:"<<assignment.villagers<<endl;
	cout<<"����:"<<assignment.hunter<<endl;
	cout<<"Ů��:1"<<endl;
	cout<<"�Ƿ����?(y/n)"<<endl;
	char a;
	cin>>a;
	if(a=='y')
	{
		fenpei(totalPlayers,assignment.werewolves,assignment.seer,assignment.villagers,assignment.hunter,assignment.witch);
	}else
	{
		system("cls");
		RoleAssignment assignment;
		srand(time(0)); // ��ʼ���������
		assignRoles(totalPlayers, assignment);
	}
	
}

int main() {
    int totalPlayers;
    cin>>totalPlayers;//�������
    RoleAssignment assignment;
    srand(time(0)); // ��ʼ���������

    assignRoles(totalPlayers, assignment);

    return 0;
}
