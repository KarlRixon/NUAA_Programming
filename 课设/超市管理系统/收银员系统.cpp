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
int vipaccess();
int ordaccess();
void registeraccess();

int displaygoods()
{
	system("notepad 超市价格表.txt");
	return 1;
}
int cashieraccess()
{
	char *pass;int i;char ch;
	while(1)
	{
		//pass=getpassw();
	    if(strcmp(getpassw(),"cashier")==0)
	    {
		    cout<<"welcome to supermarket system,dear cashier\n";break;
    	}
	    else
	    {
	    	cout<<"password error"<<endl;
	    }
	}
	Sleep(1000);
	int m;
	system("cls");
	cout<<"开始工作\n\n";
label2:
	cout<<"1.会员登陆 2.非会员消费 3.注册会员 4.打开（超市价格表.txt）文件\n";
	cin>>i;cin.ignore();
	switch(i)
	{
		case 1:vipaccess();break;
		case 2:ordaccess();break;
		case 3:registeraccess();break;
		case 4:displaygoods();break;
		default:cout<<"输入错误"<<endl;goto label2;
	}
	cout<<"-----------------------------"<<endl;
	cout<<"\n按c键清屏"<<endl<<"按回车键继续收银"<<endl<<"按任意键退出登录\n";
	cout<<"-----------------------------"<<endl;
	ch=getch();
	if(ch=='\r')
	{
		cout<<endl;
		goto label2;
	}
	else if(toupper(ch)=='C')
	{
		system("cls");
		goto label2;
	}
	cout<<endl;
	return 0;
}