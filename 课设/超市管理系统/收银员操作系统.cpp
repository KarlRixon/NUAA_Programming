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
		case 1:cout<<"Ҽ";break;
		case 2:cout<<"��";break;
		case 3:cout<<"��";break;
		case 4:cout<<"��";break;
		case 5:cout<<"��";break;
		case 6:cout<<"½";break;
		case 7:cout<<"��";break;
		case 8:cout<<"��";break;
		case 9:cout<<"��";break;
		case 0:break;
	}
}
void upper(float sum)                          //����д--------------error
{
	int temp;
	temp=(int)100*(sum-(int)sum);
	if(sum/10000>=1)
	{
		upperfun(sum/10000);
		cout<<"��"; 
	}
	sum=(int)sum%10000;
	if(sum/1000>=1)
	{
		upperfun(sum/1000);
		cout<<"ǧ";
	}
	sum=(int)sum%1000;
	if(sum/100>=1)
	{
		upperfun(sum/100);
		cout<<"��";
	}
	sum=(int)sum%100;
	if(sum/10>=1)
	{
		upperfun(sum/10);
		cout<<"ʰ";
	}
	sum=(int)sum%10;
	if(sum>=1)
	{
		upperfun(sum);
		cout<<"Ԫ";
	}
	else cout<<"Ԫ";
	if((int)temp/10>=1)
	{
		upperfun(temp/10);
		cout<<"��";
	}
	else;
	sum=(int)temp%10;
	if(temp>=1)
	{
		upperfun(temp);
		cout<<"��";
	}
	else;
	//cout<<"��"<<endl;
	cout<<endl;
}
char *trans(long recptnum)                   //����Ʊ��ת��Ϊ�ļ��� 
{
	char temp[15];
	itoa(recptnum,temp,10);
	strcat(temp,".txt");
	return temp;
}
int askrecpnum()                             //��ȡ��Ʊ�� 
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
int searchord(char *cnum)                    //�ж���ͨ�û��˺��Ƿ�ռ�� 
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
int getstonum(int gnum)                 //ͨ�����Ż�ȡ��Ʒ��� 
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
	cout<<"�ִ���\n";                  //��δ�ҵ���Ʒ��Ϣ�򱨴� 
	exit(0);
}
int undo(sal *head)                   //������ų��������е�ĳ����Ʒ 
{
	int gnum;
	sal *p,*pe;
	char ch;
label5:
	while(1)
	{
		p=head->next;
		pe=head;
		cout<<"������ţ�";
		cin>>gnum;
		while(p!=NULL)
		{
			if(p->gnum==gnum)
			{
				pe->next=p->next;
				delete p;
				if(head->next==NULL) return 1;
labely:
				cout<<"�Ƿ����������y/n)";
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
		cout<<"����Ʒδ��ɨ��"<<endl;
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
int searchvip(char *cnum)              //ͨ���˺��ж��Ƿ��иû�Ա 
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
void getnumname(numname *stock)           //�õ�����Ʒ������Ŷ�Ӧ�Ŀ������ 
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
void getstock(gds *stock)                            //�õ�������� 
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

char *namefromstock(long gnum,numname *stock)         //�Ӱ���Ʒ������ŵĿ���������ҳ����Ŷ�Ӧ��Ʒ�� 
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
	cout<<"�ִ���\n";
	exit(0);
}
void printreceipt(sal *head)                          //��ӡСƱ 
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
	cout<<"��ӭ���ٿ�����������"<<endl;
	cout<<"��Ʊ�ţ�"<<recpnum<<endl;
	cout<<"��Ա�˺ţ�"<<p->cnum<<endl;
	cout<<"��ƷС��"<<endl;
	cout<<"Ʒ��\t\t\t����\t���ۣ�Ԫ��\t�ۿۣ�Ԫ��\n";
	cout.precision(2);
	cout.setf(ios::fixed|ios::showpoint);
	while(p!=NULL)
	{
		cout<<namefromstock(p->gnum,stock)<<"\t\t"<<p->amount<<"\t"<<p->price<<"\t\t-"<<p->price*(1-rate)<<endl;
		sum+=p->amount*p->price*rate;
		p=p->next;
	}
	cout<<"���ƣ�\t\t"<<sum<<"Ԫ\n";
	financialrec(sum);                 //�����¼������~~~
	cout<<"����д��";
	upper(sum);
	cout<<"----------------------------------------"<<endl;
	fstream outfile;
	char receiptname[15];
	strcpy(receiptname,trans(recpnum));
	outfile.open(receiptname,ios::out);
	if(outfile.fail())
	{
		cout<<"��Ʊ��¼ʧ��\n";
		exit(0);
	}
	p=head->next;
	outfile<<"�˺ţ�"<<p->cnum<<endl; 
	outfile<<"�ۿۣ�"<<rate<<endl;
	while(p!=NULL)
	{
		outfile<<namefromstock(p->gnum,stock)<<"\t"<<p->amount<<"\t"<<p->price<<endl;
		p=p->next;
	}
	outfile<<"���ƣ�"<<sum<<endl;
	outfile.close();
	cout<<"��Ʊ�ѱ���/";
}

void viprec(char *cnum,sal *head)                       //����VIP�ļ� 
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
	while(pn!=NULL)                                     //---------------------------------��̫����ΪɶҪ�ĳ�pn->next
	{
		infile.write((char *)pn,sizeof(cust));
		pn=pn->next;
	}
	infile.close();
	cout<<"���ּ�¼�޸ĳɹ�/";
}
void ordrec(sal *head)                 //�޸���ͨ�û��ļ� 
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
		cout<<"��������˺ţ�";
		cin.getline(cnum,10); 
		if(!searchord(cnum))
		break;
		cout<<"���˺��Ѵ���"<<endl;
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
	cout<<"��ͨ�û���¼�ɹ�/"<<endl;
}
void salrec(sal *head)                       //����salerec�ļ� 
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
	while(p!=NULL)                                       //------------------------ͬ�ϵ�p->next���� 
	{
		outfile.write((char *)p,sizeof(sal));
		p=p->next;
	}
	outfile.close();
	cout<<"���Ѽ�¼��ӳɹ�/";
}

void stockrec(sal *head)                     //����stock�ļ� ----------------------------��bug 
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
	cout<<"�����ĳɹ�\n";
}
int vipaccess()                                       //�Ի�Ա�������� 
{
	char cnum[14];
	cout<<"�����Ա�˺ţ�";
	cin.getline(cnum,13);
	if(!searchvip(cnum))
	{
		cout<<"��ѯ������Ա��Ϣ\n";
		return 0;
	}
	cout<<"��ʼɨ��\n";
	sal *pn,*pe,*head;
	//pn=new sal;
	//pn->next=NULL;
	head=new sal;
	head->next=NULL;
	pe=head;
	while(1)
	{
		pn=new sal;
		cout<<"������ţ�";
		cin>>pn->gnum;
		if(!searchstock(pn->gnum))
		{
			cout<<"�������û�и���Ʒ\n";
			goto labelx;
			//continue;
		}
		cout<<"����������";
		cin>>pn->amount;cin.ignore();
		if(pn->amount<=0||pn->amount>getstonum(pn->gnum))
		{
			cout<<"�������\n";
			goto labelx;
			//continue;
		}
		strcpy(pn->cnum,cnum);
		pn->next=NULL;
		pe->next=pn;
		pe=pn;
		//pe->next=NULL;
labelx:
		cout<<"���س�����ɨ�룬�����������\n";
		if(getch()=='\r') continue;
		else break;
	}
	cout<<"�Ƿ���ĳ��Ʒ Y/N ��";
	if(toupper(getch())=='Y')
	{
		undo(head);
	}
	if(head->next==NULL)
	{
		cout<<"��û��Ҫ�����Ʒ����Ӽ����ͨ��\n";
		goto label4;
	}
	cout<<endl;
	putprice(head);                               //��������ӵ�����Ϣ
	//cout<<"putprice check/"; 
	printreceipt(head);                           //��ӡСƱ 
	//cout<<"printreceipt check/";
	viprec(cnum,head);                            //�޸ĸ����ļ� 
	//cout<<"viprec check/";
	salrec(head);
	//cout<<"salrec check/";
	//financialrec(head);                           //�����¼
	stockrec(head);
	//cout<<"stockrec check"<<endl;
label4:
	return 0;
}
int ordaccess()                                    //�Էǻ�Ա�������� 
{
	float temp;
	temp=rate;                                     //�ǻ�Ա�������Ż�
	rate=1; 
	cout<<"��ʼɨ��\n";
	sal *pn,*pe,*head;
	//pn=new sal;
	//pn->next=NULL;
	head=new sal;
	head->next=NULL;
	pe=head;
	while(1)
	{
		pn=new sal;
		cout<<"������ţ�";
		cin>>pn->gnum;
		if(!searchstock(pn->gnum))
		{
			cout<<"�������û�и���Ʒ\n";
			goto labelz;
			//continue;
		}
		cout<<"����������";
		cin>>pn->amount;cin.ignore();
		if(pn->amount<=0||pn->amount>getstonum(pn->gnum))
		{
			cout<<"�������"<<endl;
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
		cout<<"���س�����ɨ�룬�����������"<<endl;
		if(getch()=='\r') continue;
		else break;
	}
	cout<<"�Ƿ���ĳ��Ʒ Y/N ��";
	if(toupper(getch())=='Y')
	{
		undo(head);
	}
	if(head->next==NULL)
	{
		cout<<"��û��Ҫ�����Ʒ����Ӽ����ͨ��\n";
		return 0;
	}
	//char cnum[10];
	cout<<endl;
	putprice(head);
	ordrec(head);
	printreceipt(head);
	salrec(head);
	stockrec(head);
	rate=temp;                                   //�ָ��ۿ�
	return 1;
}
void registeraccess()
{
	char cnum[14];
	cout<<"��΢��ɨ���ά���ע�������й��ںţ�"<<endl;
	cout<<"\t|* *** **|"<<endl;
	cout<<"\t|** * ***|"<<endl;
	cout<<"\t| **** **|"<<endl;
	cout<<"\t|** *****|"<<endl;
	cout<<"\t|**** ***|"<<endl;
	getch();
	while(1)
	{
		cout<<"�������ֻ��ţ�"<<endl;
		cin.getline(cnum,13);
		if(searchvip(cnum))
		{
			cout<<"���˺��Ѵ���"<<endl;
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
	cout<<"��Աע��ɹ�"<<endl;
}