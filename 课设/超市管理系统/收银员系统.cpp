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
	system("notepad ���м۸��.txt");
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
	cout<<"��ʼ����\n\n";
label2:
	cout<<"1.��Ա��½ 2.�ǻ�Ա���� 3.ע���Ա 4.�򿪣����м۸��.txt���ļ�\n";
	cin>>i;cin.ignore();
	switch(i)
	{
		case 1:vipaccess();break;
		case 2:ordaccess();break;
		case 3:registeraccess();break;
		case 4:displaygoods();break;
		default:cout<<"�������"<<endl;goto label2;
	}
	cout<<"-----------------------------"<<endl;
	cout<<"\n��c������"<<endl<<"���س�����������"<<endl<<"��������˳���¼\n";
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