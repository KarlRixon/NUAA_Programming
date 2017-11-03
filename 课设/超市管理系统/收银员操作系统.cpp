#include<iostream>
using namespace std;
#include<fstream> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"gdscst.h"

int checkrecp();
int searchstock(int gnum);
void financialrec(float money);

void upperfun(float sum)
{
	switch((int)sum)
	{
		case 1:cout<<"壹";break;
		case 2:cout<<"贰";break;
		case 3:cout<<"叁";break;
		case 4:cout<<"肆";break;
		case 5:cout<<"伍";break;
		case 6:cout<<"陆";break;
		case 7:cout<<"柒";break;
		case 8:cout<<"扒";break;
		case 9:cout<<"玖";break;
		case 0:break;
	}
}
void upper(float sum)                          //金额大写--------------error
{
	int temp;
	temp=(int)100*(sum-(int)sum);
	if(sum/10000>=1)
	{
		upperfun(sum/10000);
		cout<<"万"; 
	}
	sum=(int)sum%10000;
	if(sum/1000>=1)
	{
		upperfun(sum/1000);
		cout<<"千";
	}
	sum=(int)sum%1000;
	if(sum/100>=1)
	{
		upperfun(sum/100);
		cout<<"百";
	}
	sum=(int)sum%100;
	if(sum/10>=1)
	{
		upperfun(sum/10);
		cout<<"拾";
	}
	sum=(int)sum%10;
	if(sum>=1)
	{
		upperfun(sum);
		cout<<"元";
	}
	else cout<<"元";
	if((int)temp/10>=1)
	{
		upperfun(temp/10);
		cout<<"角";
	}
	else;
	sum=(int)temp%10;
	if(temp>=1)
	{
		upperfun(temp);
		cout<<"分";
	}
	else;
	//cout<<"整"<<endl;
	cout<<endl;
}
char *trans(long recptnum)                   //将发票号转换为文件名 
{
	char temp[15];
	itoa(recptnum,temp,10);
	strcat(temp,".txt");
	return temp;
}
int askrecpnum()                             //获取发票号 
{
	int recpnum=0;
	recpnum=checkrecp();
	fstream infile;
	infile.open("recpnum.dat",ios::out|ios::binary);
	if(infile.fail())
	{
		cout<<"recpnum file with error\n";
		exit(0);
	}
	++recpnum;
	//infile.close();
	//infile.open("recpnum.dat",ios::out|ios::binary);
	//if(infile.fail())
	//{
	//	cout<<"recpnum file with error\n";
	//	exit(0);
	//}
	//infile.clear();
	//infile.seekp(0L,ios::beg);
	infile<<recpnum;
	//infile.clear();
	infile.close();
	return recpnum;
}
int searchord(char *cnum)                    //判断普通用户账号是否被占用 
{
	fstream infile;
	infile.open("ORD.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"ord file with error\n";
		exit(0);
	}
	cust *pcust;
	pcust=new cust;
	pcust->next=NULL;
	while(!infile.eof())
	{
		infile.read((char *)pcust,sizeof(cust));
		if((pcust->num,cnum)==0)
		return 1;
	}
	infile.close();
	return 0;
}
int getstonum(int gnum)                 //通过货号获取商品库存 
{
	fstream infile;
	infile.open("STOCK.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	gds *pg;
	pg=new gds;
	while(!infile.eof())
	{
		infile.read((char *)pg,sizeof(gds));
		if(pg->num=gnum)
		{
			return pg->stonum;
		}
	}
	infile.close();
	cout<<"粗错鸟\n";                  //若未找到商品信息则报错 
	exit(0);
}
int undo(sal *head)                   //输入货号撤销链表中的某个商品 
{
	int gnum;
	sal *p,*pe;
	char ch;
label5:
	while(1)
	{
		p=head->next;
		pe=head;
		cout<<"输入货号：";
		cin>>gnum;
		while(p!=NULL)
		{
			if(p->gnum==gnum)
			{
				pe->next=p->next;
				delete p;
				if(head->next==NULL) return 1;
labely:
				cout<<"是否继续撤销（y/n)";
				ch=getch();
				if(toupper(ch)=='Y')
				{
					goto label5;
				}
				else
				{
					return 1;
				}
			}
			pe=p;
			p=p->next;
		}
		cout<<"该商品未被扫码"<<endl;
		goto labely;
	}
}
void putprice(sal *head)
{
	fstream infile;
	infile.open("STOCK.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"stock file with error\n"<<endl;
		exit(0);
	}
	gds *pgds;
	pgds=new gds;
	pgds->next=NULL;
	sal *psal;
	psal=new sal;
	psal->next=NULL;
	psal=head->next;
	while(psal!=NULL)
	{
		while(!infile.eof())
		{
			infile.read((char *)pgds,sizeof(gds));
			if(psal->gnum==pgds->num)
			{
				psal->price=pgds->price;
				break;
			}
		}
		psal=psal->next;
		infile.seekg(0L,ios::beg);
	}
	infile.close();
}
int searchvip(char *cnum)              //通过账号判断是否有该会员 
{
	fstream infile;
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
		if(strcmp(pcust->num,cnum)==0)
		{
			infile.close();
			return 1;
		}
	}
	infile.close();
	return 0;
}
void getnumname(numname *stock)           //得到包含品名与货号对应的库存链表 
{
	fstream infile;
	infile.open("STOCK.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	numname *pn,*pe;
	pe=stock;
	gds *p;
	p=new gds;
	while(!infile.eof())
	{
		infile.read((char *)p,sizeof(gds));
		pn=new numname;
		pn->gnum=p->num;
		strcpy(pn->gname,p->name);
		pn->next=NULL;
		pe->next=pn;
		pe=pn;
	}
	infile.close();
	//---------------------------------
	/*pn=stock->next;
	while(pn!=NULL)
	{
		cout<<pn->gname<<endl;
		pn=pn->next;
	}
	system("pause"); */
}
void getstock(gds *stock)                            //得到库存链表 
{
	fstream infile;
	infile.open("STOCK.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	gds *pn,*pe;
	pn=new gds;
	pe=stock;
	while(!infile.eof())
	{
		infile.read((char *)pn,sizeof(gds));
		if(pn->num<0)
		{
			break;
		}
		pn->next=NULL;
		pe->next=pn;
		pe=pn;
		pn=new gds;
	}
	infile.close();
	delete pn;
	//-----------------
	/*pn=stock->next;
	while(pn!=NULL)
	{
		cout<<pn->name<<endl;
		pn=pn->next;
	}
	system("pause");*/
}

char *namefromstock(long gnum,numname *stock)         //从包含品名与货号的库存链表中找出货号对应的品名 
{
	numname *p;
	p=stock->next;
	while(p!=NULL)
	{
		if(p->gnum==gnum)
		{
			return p->gname;
		}
		p=p->next;
	}
	cout<<"粗错鸟\n";
	exit(0);
}
void printreceipt(sal *head)                          //打印小票 
{
	long recpnum=0;
	recpnum=askrecpnum();
	sal *p;
	float sum=0;
	numname *stock;
	stock=new numname;
	stock->next=NULL;
	getnumname(stock);
	p=head->next;
	cout<<endl;
	cout<<"---------------------"<<endl;
	cout<<"欢迎光临卡尔连锁超市"<<endl;
	cout<<"发票号："<<recpnum<<endl;
	cout<<"会员账号："<<p->cnum<<endl;
	cout<<"商品小计"<<endl;
	cout<<"品名\t\t\t数量\t单价（元）\t折扣（元）\n";
	cout.precision(2);
	cout.setf(ios::fixed|ios::showpoint);
	while(p!=NULL)
	{
		cout<<namefromstock(p->gnum,stock)<<"\t\t"<<p->amount<<"\t"<<p->price<<"\t\t-"<<p->price*(1-rate)<<endl;
		sum+=p->amount*p->price*rate;
		p=p->next;
	}
	cout<<"共计：\t\t"<<sum<<"元\n";
	financialrec(sum);                 //财务记录在这里~~~
	cout<<"金额大写：";
	upper(sum);
	cout<<"----------------------------------------"<<endl;
	fstream outfile;
	char receiptname[15];
	strcpy(receiptname,trans(recpnum));
	outfile.open(receiptname,ios::out);
	if(outfile.fail())
	{
		cout<<"发票记录失败\n";
		exit(0);
	}
	p=head->next;
	outfile<<"账号："<<p->cnum<<endl; 
	outfile<<"折扣："<<rate<<endl;
	while(p!=NULL)
	{
		outfile<<namefromstock(p->gnum,stock)<<"\t"<<p->amount<<"\t"<<p->price<<endl;
		p=p->next;
	}
	outfile<<"共计："<<sum<<endl;
	outfile.close();
	cout<<"发票已保存/";
}

void viprec(char *cnum,sal *head)                       //更改VIP文件 
{
	fstream infile;
	infile.open("VIP.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"vip file with error\n";
		exit(0);
	}
	sal *p;
	float sum=0;
	p=head->next;
	while(p!=NULL)
	{
		sum+=p->amount*p->price*rate;
		p=p->next;
	}
	cust *pn,*viphead,*pe;
	viphead=new  cust;
	viphead->next=NULL;
	pe=viphead;
	pn=new cust;
	pn->next=NULL;
	infile.read((char *)pn,sizeof(cust));
	pn->next=NULL;
	if(strcmp(pn->num,cnum)==0)
	{
		pn->purchase+=sum;
	}
	pe->next=pn;
	pe=pn;
	pe->next=NULL;
	pn=new cust;
	infile.read((char *)pn,sizeof(cust));
	pn->next=NULL;
	while(pn->purchase>=0)
	{
		if(strcmp(pn->num,cnum)==0)
		{
			pn->purchase+=sum;
		}
		pe->next=pn;
		pe=pn;
		pe->next=NULL;
		pn=new cust;
		infile.read((char *)pn,sizeof(cust));
		pn->next=NULL;
	}
	infile.clear( );
	infile.close();
	infile.open("VIP.dat",ios::out|ios::binary);
	if(infile.fail())
	{
		cout<<"vip file with error\n";
		exit(0);
	}
	pn=viphead->next;
	while(pn!=NULL)                                     //---------------------------------不太明白为啥要改成pn->next
	{
		infile.write((char *)pn,sizeof(cust));
		pn=pn->next;
	}
	infile.close();
	cout<<"积分记录修改成功/";
}
void ordrec(sal *head)                 //修改普通用户文件 
{
	fstream infile;
	infile.open("ORD.dat",ios::out|ios::app|ios::binary);
	if(infile.fail())
	{
		cout<<"ord file with error\n";
		exit(0);
	}
	sal *p;
	float sum=0;
	p=head->next;
	while(p!=NULL)
	{
		sum+=p->amount*p->price*rate;
		p=p->next;
	}
	cust *pcust;
	pcust=new cust;
	pcust->next=NULL;
	pcust->purchase=sum;
	char cnum[10];
	while(1)
	{
		cout<<"输入随机账号：";
		cin.getline(cnum,10); 
		if(!searchord(cnum))
		break;
		cout<<"该账号已存在"<<endl;
	}
	p=head;
	while(p!=NULL)
	{
		strcpy(p->cnum,cnum);
		p=p->next;
	}
	strcpy(pcust->num,cnum);
	infile.write((char *)pcust,sizeof(cust));
	infile.close();
	cout<<"普通用户记录成功/"<<endl;
}
void salrec(sal *head)                       //更改salerec文件 
{
	fstream outfile;
	outfile.open("SALEREC.dat",ios::out|ios::app|ios::binary);
	if(outfile.fail())
	{
		cout<<"salerec file with error\n";
		exit(0);
	}
	sal *p;
	p=head->next;
	while(p!=NULL)                                       //------------------------同上的p->next问题 
	{
		outfile.write((char *)p,sizeof(sal));
		p=p->next;
	}
	outfile.close();
	cout<<"消费记录添加成功/";
}

void stockrec(sal *head)                     //更改stock文件 ----------------------------有bug 
{
	gds *stock,*ps;
	stock=ps=NULL;
	stock=new gds;
	stock->next=NULL;
	getstock(stock);
	ps=stock->next;
	sal *p=NULL;
	p=head->next;
	goods g,a;
	while(p!=NULL)
	{
		while(ps!=NULL)
		{
			if(ps->num==p->gnum)
			{
				goods g(ps->name,ps->price,ps->stonum,ps->num,ps->sale,ps->sodnum);
				goods a(p->amount,p->price);
				ps->sodnum=g.getsodnum();
				ps->stonum=g.getstonum();
				//ps->sale+=p->amount*p->price*rate;
				ps->sale=g.getsale();
				break;                                       //-----------------------bug
			}
			else ps=ps->next;
		}
		ps=stock->next;
		p=p->next;
	}
	fstream outfile;
	outfile.open("STOCK.dat",ios::out|ios::binary);
	//outfile.clear();
	//outfile.seekp(0L,ios::beg);
	if(outfile.fail())
	{
		cout<<"stock file with error\n";
		exit(0);
	}
	ps=stock->next;
	while(ps!=NULL)
	{
		//cout<<ps->name<<endl<<ps->num<<endl<<ps->price<<endl<<ps->sale<<endl;
		outfile.write((char *)ps,sizeof(gds));
		ps=ps->next;
	}
	outfile.close();
	cout<<"库存更改成功\n";
}
int vipaccess()                                       //对会员进行收银 
{
	char cnum[14];
	cout<<"输入会员账号：";
	cin.getline(cnum,13);
	if(!searchvip(cnum))
	{
		cout<<"查询不到会员信息\n";
		return 0;
	}
	cout<<"开始扫码\n";
	sal *pn,*pe,*head;
	//pn=new sal;
	//pn->next=NULL;
	head=new sal;
	head->next=NULL;
	pe=head;
	while(1)
	{
		pn=new sal;
		cout<<"输入货号：";
		cin>>pn->gnum;
		if(!searchstock(pn->gnum))
		{
			cout<<"输入错误，没有该商品\n";
			goto labelx;
			//continue;
		}
		cout<<"输入数量：";
		cin>>pn->amount;cin.ignore();
		if(pn->amount<=0||pn->amount>getstonum(pn->gnum))
		{
			cout<<"输入错误\n";
			goto labelx;
			//continue;
		}
		strcpy(pn->cnum,cnum);
		pn->next=NULL;
		pe->next=pn;
		pe=pn;
		//pe->next=NULL;
labelx:
		cout<<"按回车继续扫码，按任意键结束\n";
		if(getch()=='\r') continue;
		else break;
	}
	cout<<"是否撤销某商品 Y/N ：";
	if(toupper(getch())=='Y')
	{
		undo(head);
	}
	if(head->next==NULL)
	{
		cout<<"您没有要买的商品，请从检查门通过\n";
		goto label4;
	}
	cout<<endl;
	putprice(head);                               //向链表添加单价信息
	//cout<<"putprice check/"; 
	printreceipt(head);                           //打印小票 
	//cout<<"printreceipt check/";
	viprec(cnum,head);                            //修改各个文件 
	//cout<<"viprec check/";
	salrec(head);
	//cout<<"salrec check/";
	//financialrec(head);                           //财务记录
	stockrec(head);
	//cout<<"stockrec check"<<endl;
label4:
	return 0;
}
int ordaccess()                                    //对非会员进行收银 
{
	float temp;
	temp=rate;                                     //非会员不享受优惠
	rate=1; 
	cout<<"开始扫码\n";
	sal *pn,*pe,*head;
	//pn=new sal;
	//pn->next=NULL;
	head=new sal;
	head->next=NULL;
	pe=head;
	while(1)
	{
		pn=new sal;
		cout<<"输入货号：";
		cin>>pn->gnum;
		if(!searchstock(pn->gnum))
		{
			cout<<"输入错误，没有该商品\n";
			goto labelz;
			//continue;
		}
		cout<<"输入数量：";
		cin>>pn->amount;cin.ignore();
		if(pn->amount<=0||pn->amount>getstonum(pn->gnum))
		{
			cout<<"输入错误"<<endl;
			goto labelz;
			//continue;
		}
		//strcpy(pn->cnum,cnum);
		pn->next=NULL;
		pe->next=pn;
		pe=pn;
		//pe->next=NULL;
		//pn=new sal;
labelz:
		cout<<"按回车继续扫码，按任意键结束"<<endl;
		if(getch()=='\r') continue;
		else break;
	}
	cout<<"是否撤销某商品 Y/N ：";
	if(toupper(getch())=='Y')
	{
		undo(head);
	}
	if(head->next==NULL)
	{
		cout<<"您没有要买的商品，请从检查门通过\n";
		return 0;
	}
	//char cnum[10];
	cout<<endl;
	putprice(head);
	ordrec(head);
	printreceipt(head);
	salrec(head);
	stockrec(head);
	rate=temp;                                   //恢复折扣
	return 1;
}
void registeraccess()
{
	char cnum[14];
	cout<<"请微信扫描二维码关注卡尔超市公众号："<<endl;
	cout<<"\t|* *** **|"<<endl;
	cout<<"\t|** * ***|"<<endl;
	cout<<"\t| **** **|"<<endl;
	cout<<"\t|** *****|"<<endl;
	cout<<"\t|**** ***|"<<endl;
	getch();
	while(1)
	{
		cout<<"请输入手机号："<<endl;
		cin.getline(cnum,13);
		if(searchvip(cnum))
		{
			cout<<"该账号已存在"<<endl;
			continue;
		}
		break;
	}
	fstream outfile;
	outfile.open("VIP.dat",ios::out|ios::app|ios::binary);
	if(outfile.fail())
	{
		cout<<"vip file with error\n";
		exit(0);
	}
	cust *pcust;
	pcust=new cust;
	pcust->next=NULL;
	pcust->purchase=0;
	strcpy(pcust->num,cnum);
	outfile.write((char *)pcust,sizeof(cust));
	outfile.close();
	cout<<"会员注册成功"<<endl;
}