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

int sortpoints()                                     //积分排序 
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
		cout<<num<<"\t账号："<<pn->num<<"\t积分："<<pn->purchase<<endl;
		pn=pn->next;
		num++;
		if(num%20==0)
		{
			cout<<"按回车继续显示，按任意键退出查看"<<endl;
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
	cout<<"显示完毕"<<endl;
	cout<<"-----------------------------"<<endl;
	return 1;
}
int checkreceipt()                                    //查看发票记录 
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
		cout<<"输入发票号：";
		cin>>n;
		if(n>recpnum||n<=0)
		{
			cout<<"输入错误"<<endl;
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
int checkrecp()                          //获取发票最大数即交易数 
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
int stocknum()                            //获得库存商品种数
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
int searchstock(char *name)                  //通过品名判断是否存在该商品 
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
int searchstock(int num)                          //通过货号判断是否存在该商品 
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
int checkttord()                               //得到普通用户总数 
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
int checkttvip()                             //得到会员总数 
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
int newgds()                               //录入商品信息 
{
	cout<<"-----------------------------"<<endl;
	cout<<"开始录入商品信息\n";
	fstream outfile;
	outfile.open("STOCK.dat",ios::out|ios::app|ios::binary);
	if(outfile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	gds *pgds;
	pgds=new gds;
	cout<<"输入商品名称：";
	cin.getline(pgds->name,sizeof(pgds->name));
	if(searchstock(pgds->name))
	{
			cout<<"库存中已有该商品\n";return 0;
	}
	cout<<"输入单价：";
	cin>>pgds->price;
	while(1)
	{
		cout<<"输入货号：";
		cin>>pgds->num;
		if(searchstock(pgds->num))
		{
			cout<<"该货号已被占用\n";
		}
		else break;
	}
	pgds->sodnum=0;
	cout<<"输入库存：";
	cin>>pgds->stonum;cin.ignore();
	financialrec(-(float)pgds->stonum*pgds->price*0.6);      //0.6 代表商品进价为售价的 60 %
	pgds->sale=0;
	outfile.write((char *)pgds,sizeof(gds));
	outfile.close();
	cout<<"录入成功\n";
	cout<<"-----------------------------"<<endl;
	return 1;
}
void goodsin()                           //进货 
{
	cout<<"-----------------------------"<<endl;
	char name[21];int amount;
	while(1)
	{
		cout<<"输入需要进货的商品：";
		cin.getline(name,21);
		if(searchstock(name)) break;
		else
		{
			cout<<"输入错误\n";
		}
	}
	cout<<"输入进货数量：";
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
		financialrec(-(float)amount*pn->price*0.6);      //0.6 代表商品进价为售价的 60 %
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
			financialrec(-(float)amount*pn->price*0.6);      //0.6 代表商品进价为售价的 60 %
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
	while(pn->next!=NULL)                                //-------为啥要用->next 
	{
		outfile.write((char *)pn,sizeof(gds));
		pn=pn->next;
	}
	outfile.close();
	cout<<"进货成功\n";
	cout<<"-----------------------------"<<endl;
}
void checkprofit()                            //统计用户数、总销售额、商品数 
{
	cout<<"-----------------------------"<<endl;
	cout<<"运营情况统计中...\n";
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
	cout<<"普通顾客数量："<<ordcust<<"人\n";
	cout<<"vip用户数量："<<vipcust<<"人\n";
	cout<<"总用户数："<<ordcust+vipcust<<"人\n";
	cout<<"商品种数："<<stocknum()<<endl;
	cout<<"交易次数："<<checkrecp()<<endl;
	cout<<"净利润："<<sumfinrec()<<"元"<<endl;
	gds *pgds;
	pgds=new gds;
	while(!infile.eof())
	{
		infile.read((char *)pgds,sizeof(gds));
		sum+=pgds->sale;
	}
	cout<<"总销售额："<<sum<<"元\n";
	infile.close();
	cout<<"-----------------------------"<<endl;
}
void setrate()
{
	cout<<"-----------------------------"<<endl;
	float rat;
	cout<<"当前折扣："<<rate*10<<endl;
	cout<<"重置折扣：";
	cin>>rat;cin.ignore();
	rate=rat/10;
	cout<<"折扣设置成功\n\n";
	cout<<"-----------------------------"<<endl;
}
int checkcust()
{
	cout<<"-----------------------------"<<endl;
	fstream infile;
	while(1)
	{
		cout<<"选择要查看的用户类型（会员 V / 普通用户 O )：";
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
		cout<<counter<<"\t"<<"账号："<<pcust->num<<"\t"<<"消费额："<<pcust->purchase<<"元"<<endl;
		infile.read((char *)pcust,sizeof(cust));
		counter++;
		if(counter%30==0)
		{
			cout<<"按回车键继续，按任意键退出\n";
			if(getch()=='\r') continue;
			else
			{
				break;
			}
		}
	}
	cout<<"\n用户显示完毕\n\n";
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
		cout<<counter<<"顾客账号："<<psal->cnum<<"\t货号："<<psal->gnum<<"\t单价："<<psal->price<<"\t数量："<<psal->amount<<endl;
	}
	system("pause");*/
	infile.seekg(-(long)sizeof(sal),ios::end);
	while(1)
	{

		infile.read((char *)psal,sizeof(sal));
		counter++;
		cout<<counter<<"顾客账号："<<psal->cnum<<"\t货号："<<psal->gnum<<"\t单价："<<psal->price<<"\t数量："<<psal->amount<<endl;
		if(counter==sum)
		{
			cout<<"\n全部输出完毕\n\n";
			cout<<"-----------------------------"<<endl;
			break;
		}
		if(counter%20==0)
		{
			cout<<"按回车键查看更多，按任意键退出查看\n";
			if(getch()=='\r');
			else
			{
				cout<<"退出查看"<<endl;
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