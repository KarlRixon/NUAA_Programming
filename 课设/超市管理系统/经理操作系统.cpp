#include<iostream>
using namespace std;
#include<fstream> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"gdscst.h"

void financialrec(float money);
float sumfinrec();

int sortpoints()                                     //�������� 
{
	cout<<"-----------------------------"<<endl;
	fstream infile;
	infile.open("VIP.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"vip file with error\n";
		exit(0);
	}
	cust *head,*pn,*p1,*p2;
	head=new cust;
	pn=new cust;
	head->next=NULL;
	pn->next=NULL;
	p1=head;
	p2=head->next;
	//cout<<"check"<<endl;system("pause");
	infile.read((char *)pn,sizeof(cust));
	pn->next=NULL;
	head->next=pn;
	pn=new cust;
	infile.read((char *)pn,sizeof(cust));
	pn->next=NULL;
	//cout<<"check"<<endl;system("pause");
	while(!infile.eof())
	{
		p1=head;
		p2=head->next;
		while(1)                                          //----------------------------------------------------------------
		{
			if(p2==NULL)
			{
				p1->next=pn;
				pn->next=p2;
				pn=new cust;
				infile.read((char *)pn,sizeof(cust));
				pn->next=NULL;
				break;
			}
			else if(pn->purchase>=p2->purchase)
			{
				p1->next=pn;
				pn->next=p2;
				pn=new cust;
				infile.read((char *)pn,sizeof(cust));
				pn->next=NULL;
				break;
			}
			else if(pn->purchase<p2->purchase&&p2!=NULL)
			{
				p1=p2;
				p2=p2->next;
			}
		}
	}
	infile.close();
	//cout<<"check"<<endl;system("pause");
	pn=head->next;
	int num=1;
	while(pn!=NULL)
	{
		cout<<num<<"\t�˺ţ�"<<pn->num<<"\t���֣�"<<pn->purchase<<endl;
		pn=pn->next;
		num++;
		if(num%20==0)
		{
			cout<<"���س�������ʾ����������˳��鿴"<<endl;
			if(getch()=='\r')
			{
				continue;
			}
			else
			{
				cout<<"-----------------------------"<<endl;
				return 0;
			}
		}
	}
	cout<<"��ʾ���"<<endl;
	cout<<"-----------------------------"<<endl;
	return 1;
}
int checkreceipt()                                    //�鿴��Ʊ��¼ 
{
	cout<<"-----------------------------"<<endl;
	int recpnum=0;
	int n=0;
	fstream infile;
	infile.open("recpnum.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"recpnum file with error\n";
		exit(0);
	}
	infile>>recpnum;
	while(1)
	{
		cout<<"���뷢Ʊ�ţ�";
		cin>>n;
		if(n>recpnum||n<=0)
		{
			cout<<"�������"<<endl;
			//continue;
			return 0;
		}
		else break;
	}
	infile.close();
	char filename[15],line[101];
	itoa(n,filename,10);
	strcat(filename,".txt");
	infile.open(filename,ios::in);
	//system("notepad filename.txt");
	infile.clear();
	cout<<"-----------------------------"<<endl;
	while(!infile.eof())
	{
		infile.getline(line,100);
		cout<<line<<endl;
	}
	infile.close();
	cout<<"-----------------------------"<<endl;
	cout<<"-----------------------------"<<endl;
	return 1;
}
int checkrecp()                          //��ȡ��Ʊ������������� 
{
	int recpnum=0;
	fstream infile;
	infile.open("recpnum.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"recpnum file with error\n";
		exit(0);
	}
	infile>>recpnum;
	infile.close();
	return recpnum;
}
int stocknum()                            //��ÿ����Ʒ����
{
	fstream infile;
	infile.open("STOCK.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	int sum=0;
	gds *pgds;
	pgds=new gds;
	pgds->next=NULL;
	while(!infile.eof())
	{
		infile.read((char *)pgds,sizeof(gds));
		sum++;
	}
	return sum-1;
}
int searchstock(char *name)                  //ͨ��Ʒ���ж��Ƿ���ڸ���Ʒ 
{
	fstream infile;
	infile.open("STOCK.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	gds *pgds;
	pgds=new gds;
	while(!infile.eof())
	{
		infile.read((char *)pgds,sizeof(gds));
		if(strcmp(pgds->name,name)==0)
		return 1;
	}
	return 0;
}
int searchstock(int num)                          //ͨ�������ж��Ƿ���ڸ���Ʒ 
{
	fstream infile;
	infile.open("STOCK.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	gds *pgds;
	pgds=new gds;
	while(!infile.eof())
	{
		infile.read((char *)pgds,sizeof(gds));
		if(pgds->num==num)
		return 1;
	}
	return 0;
}
int checkttord()                               //�õ���ͨ�û����� 
{
	fstream infile;int total=0;
	infile.open("ORD.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"ord file with error\n";
		exit(0);
	}
	cust *pcust;
	pcust=new cust;
	while(!infile.eof())
	{
		infile.read((char *)pcust,sizeof(cust));
		total++;
	}
	infile.close();
	return total-1;
}
int checkttvip()                             //�õ���Ա���� 
{
	fstream infile;int total=0;
	infile.open("VIP.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"vip file with error\n";
		exit(0);
	}
	cust *pcust;
	pcust=new cust;
	while(!infile.eof())
	{
		infile.read((char *)pcust,sizeof(cust));
		total++;
	}
	infile.close();
	return total-1;
}
int newgds()                               //¼����Ʒ��Ϣ 
{
	cout<<"-----------------------------"<<endl;
	cout<<"��ʼ¼����Ʒ��Ϣ\n";
	fstream outfile;
	outfile.open("STOCK.dat",ios::out|ios::app|ios::binary);
	if(outfile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	gds *pgds;
	pgds=new gds;
	cout<<"������Ʒ���ƣ�";
	cin.getline(pgds->name,sizeof(pgds->name));
	if(searchstock(pgds->name))
	{
			cout<<"��������и���Ʒ\n";return 0;
	}
	cout<<"���뵥�ۣ�";
	cin>>pgds->price;
	while(1)
	{
		cout<<"������ţ�";
		cin>>pgds->num;
		if(searchstock(pgds->num))
		{
			cout<<"�û����ѱ�ռ��\n";
		}
		else break;
	}
	pgds->sodnum=0;
	cout<<"�����棺";
	cin>>pgds->stonum;cin.ignore();
	financialrec(-(float)pgds->stonum*pgds->price*0.6);      //0.6 ������Ʒ����Ϊ�ۼ۵� 60 %
	pgds->sale=0;
	outfile.write((char *)pgds,sizeof(gds));
	outfile.close();
	cout<<"¼��ɹ�\n";
	cout<<"-----------------------------"<<endl;
	return 1;
}
void goodsin()                           //���� 
{
	cout<<"-----------------------------"<<endl;
	char name[21];int amount;
	while(1)
	{
		cout<<"������Ҫ��������Ʒ��";
		cin.getline(name,21);
		if(searchstock(name)) break;
		else
		{
			cout<<"�������\n";
		}
	}
	cout<<"�������������";
	cin>>amount;
	fstream infile;
	infile.open("STOCK.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	gds *pn,*head,*pe;
	head=new gds;
	pn=new gds;
	infile.read((char *)pn,sizeof(gds));
	if(strcmp(pn->name,name)==0)
	{
		pn->stonum+=amount;
		financialrec(-(float)amount*pn->price*0.6);      //0.6 ������Ʒ����Ϊ�ۼ۵� 60 %
		//cout<<"yes"<<pn->stonum;system("pause");
	}
	pn->next=NULL;
	pe=head->next=pn;
	pe=pn;
	pn=new gds;
	while(!infile.eof())
	{
		infile.read((char *)pn,sizeof(gds));
		pn->next=NULL;
		if(strcmp(pn->name,name)==0)
		{
			pn->stonum+=amount;
			financialrec(-(float)amount*pn->price*0.6);      //0.6 ������Ʒ����Ϊ�ۼ۵� 60 %
			//cout<<"yes";system("pause");
		}
		pe->next=pn;
		pe=pn;
		pn=new gds;
	}
	infile.close();
	pn=head->next;
	fstream outfile;
	outfile.open("STOCK.dat",ios::out|ios::binary);
	if(outfile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	while(pn->next!=NULL)                                //-------ΪɶҪ��->next 
	{
		outfile.write((char *)pn,sizeof(gds));
		pn=pn->next;
	}
	outfile.close();
	cout<<"�����ɹ�\n";
	cout<<"-----------------------------"<<endl;
}
void checkprofit()                            //ͳ���û����������۶��Ʒ�� 
{
	cout<<"-----------------------------"<<endl;
	cout<<"��Ӫ���ͳ����...\n";
	fstream infile;
	float sum=0;
	int ordcust,vipcust;
	ordcust=checkttord();
	vipcust=checkttvip();
	infile.open("STOCK.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	cout<<"��ͨ�˿�������"<<ordcust<<"��\n";
	cout<<"vip�û�������"<<vipcust<<"��\n";
	cout<<"���û�����"<<ordcust+vipcust<<"��\n";
	cout<<"��Ʒ������"<<stocknum()<<endl;
	cout<<"���״�����"<<checkrecp()<<endl;
	cout<<"������"<<sumfinrec()<<"Ԫ"<<endl;
	gds *pgds;
	pgds=new gds;
	while(!infile.eof())
	{
		infile.read((char *)pgds,sizeof(gds));
		sum+=pgds->sale;
	}
	cout<<"�����۶"<<sum<<"Ԫ\n";
	infile.close();
	cout<<"-----------------------------"<<endl;
}
void setrate()
{
	cout<<"-----------------------------"<<endl;
	float rat;
	cout<<"��ǰ�ۿۣ�"<<rate*10<<endl;
	cout<<"�����ۿۣ�";
	cin>>rat;cin.ignore();
	rate=rat/10;
	cout<<"�ۿ����óɹ�\n\n";
	cout<<"-----------------------------"<<endl;
}
int checkcust()
{
	cout<<"-----------------------------"<<endl;
	fstream infile;
	while(1)
	{
		cout<<"ѡ��Ҫ�鿴���û����ͣ���Ա V / ��ͨ�û� O )��";
		char ch;
		ch=getch();
		if(ch=='v'||ch=='V')
		{
			infile.open("VIP.dat",ios::in|ios::binary);
			if(infile.fail())
			{
				cout<<"vip file with error\n";
				return 0;
			}
			break;
		}
		else if(ch=='o'||ch=='O')
		{
			infile.open("ORD.dat",ios::in|ios::binary);
			if(infile.fail())
			{
				cout<<"ord file with error\n";
				return 0;
			}
			break;
		}
		else
		{
			continue;
		}
	}
	int counter=0;
	cust *pcust=NULL;
	pcust=new cust;
	pcust->next=NULL;
	infile.read((char *)pcust,sizeof(cust));
	counter++;
	while(!infile.eof())
	{
		cout<<endl;
		cout<<counter<<"\t"<<"�˺ţ�"<<pcust->num<<"\t"<<"���Ѷ"<<pcust->purchase<<"Ԫ"<<endl;
		infile.read((char *)pcust,sizeof(cust));
		counter++;
		if(counter%30==0)
		{
			cout<<"���س�����������������˳�\n";
			if(getch()=='\r') continue;
			else
			{
				break;
			}
		}
	}
	cout<<"\n�û���ʾ���\n\n";
	infile.close();
	cout<<"-----------------------------"<<endl;
}
void checksalerec()                                    //------------------------------------bug
{
	cout<<"-----------------------------"<<endl;
	fstream infile;
	infile.open("SALEREC.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"salerec file with error\n";
		exit(0);
	}
	sal *psal;
	int counter=0;
	int sum=0;
	psal=new sal;
	infile.read((char *)psal,sizeof(sal));
	sum++;
	while(!infile.eof())
	{
		infile.read((char *)psal,sizeof(sal));
		sum++;
	}
	sum--;
	infile.clear();
	/*infile.seekg(0L,ios::beg);
	while(!infile.eof())
	{
		infile.read((char *)psal,sizeof(sal));
		cout<<counter<<"�˿��˺ţ�"<<psal->cnum<<"\t���ţ�"<<psal->gnum<<"\t���ۣ�"<<psal->price<<"\t������"<<psal->amount<<endl;
	}
	system("pause");*/
	infile.seekg(-(long)sizeof(sal),ios::end);
	while(1)
	{

		infile.read((char *)psal,sizeof(sal));
		counter++;
		cout<<counter<<"�˿��˺ţ�"<<psal->cnum<<"\t���ţ�"<<psal->gnum<<"\t���ۣ�"<<psal->price<<"\t������"<<psal->amount<<endl;
		if(counter==sum)
		{
			cout<<"\nȫ��������\n\n";
			cout<<"-----------------------------"<<endl;
			break;
		}
		if(counter%20==0)
		{
			cout<<"���س����鿴���࣬��������˳��鿴\n";
			if(getch()=='\r');
			else
			{
				cout<<"�˳��鿴"<<endl;
				cout<<"-----------------------------"<<endl;
				break;
			}
		}
		infile.clear();
		infile.seekg(-(long)(sizeof(sal)*2),ios::cur);
	}
	//cout<<"sum="<<sum<<"\tcounter="<<counter<<endl;
	infile.close();
}