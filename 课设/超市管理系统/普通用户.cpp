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
		cout<<"-----1.查看库存\n";
		cout<<"-----2.查询积分\n";
		cout<<"-----3.查看优惠\n";
		cout<<"-----4.查看积分兑换活动\n";
		cout<<"-----5.清屏\n";
		cout<<"-----6.退出\n";
		cout<<"-----7.返回登陆系统"<<endl;
		cin>>i;cin.ignore();
		switch(i)
		{
			case 1:checkstock();break;
			case 2:checkpoints();break;
			case 3:cout<<"------||今日全场"<<rate*10<<"折||--------\n";break;
			case 4:showspecialoffer();break;
			case 5:system("cls");break;
			case 6:exit(0);
			case 7:return 0;
			default:cout<<"输入错误\n"<<endl;continue;
		}
	}
}