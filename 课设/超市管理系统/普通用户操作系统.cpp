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
	cout<<"�������ѯϵͳ��\n";
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
		cout<<"Ʒ����"<<pgds->name<<endl;
		cout<<"���ۣ�"<<pgds->price<<endl;
		cout<<"���ţ�"<<pgds->num<<endl;
		cout<<"���۶"<<pgds->sale<<endl;
		cout<<"��������"<<pgds->sodnum<<endl;
		cout<<"��棺"<<pgds->stonum<<endl;
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
	cout<<"���������˺ţ�";
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
		cout<<"δ��ѯ�������˺���Ϣ�����س��������������������\n";
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
			cout<<"�˺ţ�"<<pcust->num<<endl;
			cout<<"���֣������Ѷ��"<<pcust->purchase<<endl;
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
			cout<<"�������ǵ���Ҫ�ͻ������Ļ�������Ϊ"<<no<<"��ռ����ȫ���û���ǰ"<<100*(float)no/(float)tot<<"%"<<endl;
			cout<<"��ʵʱ��ע���ǵĻ��ֶһ��"<<endl;
			cout<<"-----------------------------"<<endl;
			return 1; 
		}
	}
	cout<<"ϵͳ�쳣\n";
	infile.close();
	cout<<"-----------------------------"<<endl;
	return 0;
}
void showspecialoffer()
{
	cout<<""<<endl;
}