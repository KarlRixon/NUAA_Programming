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
		cout<<"输入要记录的金额：";
		cin>>a;cin.ignore();
		financialrec(a);
		cout<<"是否继续（y/n）：";
		if(toupper(getch())=='Y') continue;
		break;
	}
	cout<<"编辑成功"<<endl;
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
		cout<<"输入手机号：";
		cin.getline(pcust->num,13);
		cout<<"输入消费额（积分）：";
		cin>>pcust->purchase;cin.ignore();
		vip.write((char *)pcust,sizeof(cust));
		//vip.flush();
		//delete pcust;
		cout<<"按回车键继续录入，按任意键结束\n";
		if(getch()==13) continue;
		else
		{
			cout<<"录入成功\n\n";
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
		cout<<"输入9位编号：";
		cin.getline(pcust->num,10);
		cout<<"输入消费额：";
		cin>>pcust->purchase;cin.ignore();
		ord.write((char *)pcust,sizeof(cust));
		ord.flush();
		cout<<"按回车键继续录入，按任意键结束\n";
		if(getch()=='\r') continue;
		else
		{
			cout<<"录入成功\n\n";
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
		cout<<"输入商品名称：";
		cin.getline(pgds->name,sizeof(pgds->name));
		cout<<"输入单价：";
		cin>>pgds->price;
		cout<<"输入代码：";
		cin>>pgds->num; 
		cout<<"输入销售量：";
		cin>>pgds->sodnum;
		cout<<"输入库存：";
		cin>>pgds->stonum;
		cout<<"输入销售额：";
		cin>>pgds->sale;cin.ignore();
		outfile.write((char *)pgds,sizeof(gds));
		cout<<"按回车继续，按任意键结束\n";
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
	cout<<"发票号初始化成功"<<endl;
	outfile.close();
	cout<<"-----------------------------"<<endl;
}
int editfile()
{
	int t;char ch;
	while(1)
	{
		cout<<"是否进入文件编辑模式？  Y/N\n";
		cin>>ch;cin.ignore();
		if(ch=='y'||ch=='Y') break;
		else if(ch=='n'||ch=='N') return 0;
		else cout<<"输入错误\n";continue;
	}
	cout<<"进入文件编辑系统\n";
	while(1)
	{
		cout<<"选择要编辑的文件：\n";
		cout<<"1.VIP.dat\n";
		cout<<"2.ORD.dat\n";
		cout<<"3.STOCK.dat\n";
		cout<<"4.financialrec.dat\n";
		cout<<"5.清屏\n";
		cout<<"6.recpnum.dat\n"; 
		cout<<"0.结束编辑\n";
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
			default:cout<<"输入错误\n";continue;
		}
	}
}