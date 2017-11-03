#include<iostream>
using namespace std;
#include<fstream> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"gdscst.h"

int checkttvip();

void getviplist(cust *head)
{
	fstream infile;
	infile.open("VIP.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"vip file with error"<<endl;
		exit(0);
	}
	cust *pn,*pe;
	pn=new cust;
	pn->next=NULL;
	pe=head;
	while(!infile.eof())
	{
		infile.read((char *)pn,sizeof(cust));
		pn->next=NULL;
		pe->next=pn;
		pe=pn;
		pn=new cust;
	}
	infile.close();
}
void checkstock()
{
	cout<<"-----------------------------"<<endl;
	cout<<"进入库存查询系统：\n";
	fstream infile;
	infile.open("STOCK.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"stocck file with error\n";
		exit(0);
	}
	gds *pgds;
	pgds=new gds;
	infile.read((char *)pgds,sizeof(gds));
	while(!infile.eof())
	{
		cout<<"品名："<<pgds->name<<endl;
		cout<<"单价："<<pgds->price<<endl;
		cout<<"货号："<<pgds->num<<endl;
		cout<<"销售额："<<pgds->sale<<endl;
		cout<<"销售量："<<pgds->sodnum<<endl;
		cout<<"库存："<<pgds->stonum<<endl;
		cout<<endl;
		infile.read((char *)pgds,sizeof(gds));  
	}
	infile.close();
	cout<<"---------------------------"<<endl; 
}
int checkpoints()
{
	cout<<"---------------------------"<<endl;
	char num[14];
	fstream infile;
	infile.open("VIP.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"vip file with error\n";
		exit(0);
	}
	cust *pcust;
	pcust=new cust;
	int flag=0;
label:
	cout<<"输入您的账号：";
	cin.getline(num,13);
	while(!infile.eof())
	{
		infile.read((char *)pcust,sizeof(cust));
		if(strcmp(num,pcust->num)==0)
		{
			flag=1;break;
		}
	}
	if(flag==0)
	{
		cout<<"未查询到您的账号信息，按回车键继续，按任意键返回\n";
		if(getch()=='\r') 
		goto label;
		else
		{
			infile.close();
			cout<<"-----------------------------"<<endl;
			return 0;
		}
	}
	infile.seekg(0L,ios::beg);  
	while(!infile.eof())
	{
		infile.read((char *)pcust,sizeof(cust));
		if(strcmp(pcust->num,num)==0)
		{
			cout<<"账号："<<pcust->num<<endl;
			cout<<"积分（总消费额）："<<pcust->purchase<<endl;
			infile.close();
			int no=1,tot=0;
			float percent=0;
			tot=checkttvip();
			cust *head,*p;
			head=new cust;
			head->next=NULL;
			getviplist(head);
			p=head->next;
			while(p!=NULL)
			{
				if(p->purchase>pcust->purchase)
				{
					no++;
				}
				p=p->next;
			}
			cout<<"您是我们的重要客户，您的积分排名为"<<no<<"，占到了全部用户的前"<<100*(float)no/(float)tot<<"%"<<endl;
			cout<<"请实时关注我们的积分兑换活动"<<endl;
			cout<<"-----------------------------"<<endl;
			return 1; 
		}
	}
	cout<<"系统异常\n";
	infile.close();
	cout<<"-----------------------------"<<endl;
	return 0;
}
void showspecialoffer()
{
	cout<<""<<endl;
}