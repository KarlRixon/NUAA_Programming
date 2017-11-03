#include<iostream>
using namespace std;
#include<fstream> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"gdscst.h"
char *getpassw();
void checkstock();
void goodsin();
void checkprofit();
int newgds();
void setrate();
int checkcust();
void checksalerec();
int checkreceipt();
int sortpoints();
int showfinrec();

int manageraccess()                  //经理登陆界面 
{
	char *pass;
	while(1)
	{
		//pass=getpassw();
	    if(strcmp(getpassw(),"manager")==0)
	    {
		    cout<<"welcome to supermarket system,dear manager\n";break;
    	}
	    else
	    {
	    	cout<<"password error"<<endl;
	    }
	}
	Sleep(1000);
	int m;
	system("cls");
	while(1)
	{
		cout<<"-----menu:\n";
		cout<<"-----1.查看库存\n";
		cout<<"-----2.进货系统\n";
		cout<<"-----3.运营情况统计\n";
		cout<<"-----4.商品信息录入\n";
		cout<<"-----5.设置折扣\n";
		cout<<"-----6.查看用户信息\n";
		cout<<"-----7.查看销售记录\n";
		cout<<"-----8.查看发票\n";
		cout<<"-----9.查看积分排名\n";
		cout<<"-----10.查看财务记录\n";
		cout<<"-----11.退出系统\n"; 
		cout<<"-----12.清屏\n";
		cout<<"-----13.退出登录"<<endl; 
		cin>>m;cin.ignore();
		switch(m)
		{
			case 1:checkstock();break;
			case 2:goodsin();break;
			case 3:checkprofit();break;
			case 4:newgds();break;
			case 5:setrate();break;
			case 6:checkcust();break;
			case 7:checksalerec();break;
			case 8:checkreceipt();break;
			case 9:sortpoints();break;
			case 10:showfinrec();break;
			case 11:exit(0);
			case 12:system("cls");break;
			case 13:return 0;
			default:cout<<"输入错误"<<endl;continue;
		}
	}
}