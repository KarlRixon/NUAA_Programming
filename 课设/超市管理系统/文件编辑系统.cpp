#include<iostream>
using namespace std;
#include<fstream> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"gdscst.h"

int checkcust();
void checkstock();
void financialrec(float money);

void edfinrec()
{
	float a=0;
	fstream outfile;
	outfile.open("financialrec.dat",ios::binary|ios::out|ios::app);
	if(outfile.fail())
	{
		cout<<"financialrec file with error\n";
		exit(0);
	}
	outfile.close();
	cout<<"-----------------------------"<<endl;
	while(1)
	{
		cout<<"����Ҫ��¼�Ľ�";
		cin>>a;cin.ignore();
		financialrec(a);
		cout<<"�Ƿ������y/n����";
		if(toupper(getch())=='Y') continue;
		break;
	}
	cout<<"�༭�ɹ�"<<endl;
	cout<<"-----------------------------"<<endl;
}
int edvip()
{
	cout<<"-----------------------------"<<endl;
	fstream vip;
	vip.open("VIP.dat",ios::out|ios::app|ios::binary);
	if(vip.fail())
	{
		cout<<"vip file with error\n";
		return 0;
	}
	cust *pcust;
	pcust=new cust;
	pcust->next=NULL;
	while(1)
	{
		cout<<"�����ֻ��ţ�";
		cin.getline(pcust->num,13);
		cout<<"�������Ѷ���֣���";
		cin>>pcust->purchase;cin.ignore();
		vip.write((char *)pcust,sizeof(cust));
		//vip.flush();
		//delete pcust;
		cout<<"���س�������¼�룬�����������\n";
		if(getch()==13) continue;
		else
		{
			cout<<"¼��ɹ�\n\n";
			vip.close();
			cout<<"--------------------"<<endl;
			checkcust();
			return 1;
		}
	}
}
int edord()
{
	cout<<"-----------------------------"<<endl;
	fstream ord;
	ord.open("ORD.dat",ios::out|ios::app|ios::binary);
	if(ord.fail())
	{
		cout<<"ord file with error\n";
		return 0;
	}
	cust *pcust;
	pcust=new cust;
	pcust->next=NULL;
	while(1)
	{
		cout<<"����9λ��ţ�";
		cin.getline(pcust->num,10);
		cout<<"�������Ѷ";
		cin>>pcust->purchase;cin.ignore();
		ord.write((char *)pcust,sizeof(cust));
		ord.flush();
		cout<<"���س�������¼�룬�����������\n";
		if(getch()=='\r') continue;
		else
		{
			cout<<"¼��ɹ�\n\n";
			ord.close();
			cout<<"--------------------"<<endl;
			checkcust();
			return 1;
		}
	}
}
void edstock()
{
	cout<<"-----------------------------"<<endl;
	fstream outfile;
	outfile.open("STOCK.dat",ios::out|ios::app|ios::binary);
	if(outfile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	gds *pgds;
	pgds=new gds;
	pgds->next=NULL;
	while(1)
	{
		cout<<"������Ʒ���ƣ�";
		cin.getline(pgds->name,sizeof(pgds->name));
		cout<<"���뵥�ۣ�";
		cin>>pgds->price;
		cout<<"������룺";
		cin>>pgds->num; 
		cout<<"������������";
		cin>>pgds->sodnum;
		cout<<"�����棺";
		cin>>pgds->stonum;
		cout<<"�������۶";
		cin>>pgds->sale;cin.ignore();
		outfile.write((char *)pgds,sizeof(gds));
		cout<<"���س������������������\n";
		if(getch()=='\r') continue;
		else
		{
			outfile.close();
			cout<<"--------------------"<<endl;
			checkstock();
			break;
		}
	}
}
void edrecpnum()
{
	cout<<"-----------------------------"<<endl;
	fstream outfile;
	outfile.open("recpnum.dat",ios::out|ios::binary);
	if(outfile.fail())
	{
		cout<<"recpnum file with error\n";
		exit(0);
	}
	outfile<<0;
	cout<<"��Ʊ�ų�ʼ���ɹ�"<<endl;
	outfile.close();
	cout<<"-----------------------------"<<endl;
}
int editfile()
{
	int t;char ch;
	while(1)
	{
		cout<<"�Ƿ�����ļ��༭ģʽ��  Y/N\n";
		cin>>ch;cin.ignore();
		if(ch=='y'||ch=='Y') break;
		else if(ch=='n'||ch=='N') return 0;
		else cout<<"�������\n";continue;
	}
	cout<<"�����ļ��༭ϵͳ\n";
	while(1)
	{
		cout<<"ѡ��Ҫ�༭���ļ���\n";
		cout<<"1.VIP.dat\n";
		cout<<"2.ORD.dat\n";
		cout<<"3.STOCK.dat\n";
		cout<<"4.financialrec.dat\n";
		cout<<"5.����\n";
		cout<<"6.recpnum.dat\n"; 
		cout<<"0.�����༭\n";
		cin>>t;cin.ignore();
		switch(t)
		{
			case 1:edvip();break;
			case 2:edord();break;
			case 3:edstock();break;
			case 4:edfinrec();break;
			case 5:system("cls");break;
			case 6:edrecpnum();break;
			case 0:return 1;
			default:cout<<"�������\n";continue;
		}
	}
}