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

int manageraccess()                  //�����½���� 
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
		cout<<"-----1.�鿴���\n";
		cout<<"-----2.����ϵͳ\n";
		cout<<"-----3.��Ӫ���ͳ��\n";
		cout<<"-----4.��Ʒ��Ϣ¼��\n";
		cout<<"-----5.�����ۿ�\n";
		cout<<"-----6.�鿴�û���Ϣ\n";
		cout<<"-----7.�鿴���ۼ�¼\n";
		cout<<"-----8.�鿴��Ʊ\n";
		cout<<"-----9.�鿴��������\n";
		cout<<"-----10.�鿴�����¼\n";
		cout<<"-----11.�˳�ϵͳ\n"; 
		cout<<"-----12.����\n";
		cout<<"-----13.�˳���¼"<<endl; 
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
			default:cout<<"�������"<<endl;continue;
		}
	}
}