#include<iostream>
using namespace std;
#include<fstream> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"gdscst.h"

void checkstock();
int checkpoints();
void showspecialoffer();

int customeraccess()
{
	int i;
	system("cls");
	cout<<"welcome to supermarket system,dear customer\n";
	while(1)
	{
		cout<<"-----menu:\n";
		cout<<"-----1.�鿴���\n";
		cout<<"-----2.��ѯ����\n";
		cout<<"-----3.�鿴�Ż�\n";
		cout<<"-----4.�鿴���ֶһ��\n";
		cout<<"-----5.����\n";
		cout<<"-----6.�˳�\n";
		cout<<"-----7.���ص�½ϵͳ"<<endl;
		cin>>i;cin.ignore();
		switch(i)
		{
			case 1:checkstock();break;
			case 2:checkpoints();break;
			case 3:cout<<"------||����ȫ��"<<rate*10<<"��||--------\n";break;
			case 4:showspecialoffer();break;
			case 5:system("cls");break;
			case 6:exit(0);
			case 7:return 0;
			default:cout<<"�������\n"<<endl;continue;
		}
	}
}