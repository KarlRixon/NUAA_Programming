#include<iostream>
using namespace std;
#include<fstream> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"gdscst.h"
int goods::sodnum=0;  //������ 
float goods::sale=0;  //���۶� 
long customer::totalnum=0;  //�˿����� 
long vip::vipnum=0;  //��Ա�˺�Ϊ�ֻ��� 
int goods::stonum;  //��� 
float rate=1.00f;  //������Ը����ۿ� 
//int spof=0;      //�������Ż���ʽ   1:���� 2:�򹻾��� 3:�齱 0:���Ż�
int cashieraccess();  //����Ա��� 
int manageraccess();   //�������
int customeraccess(); //��ͨ�û���� 
int editfile();        //�༭�ļ����� 

int main()
{
	editfile();
	/*fstream vip;
	fstream ord;
	fstream salerec;
	fstream stock;
	vip.open("VIP.dat",ios::in|ios::out|ios::binary);
	ord.open("ORD.dat",ios::in|ios::binary);
	salerec.open("SALERAC.dat",ios::out|ios::app|ios::binary);
	stock.open("STOCK.dat",ios::in|ios::out|ios::binary);
	if(vip.fail()||ord.fail()||salerec.fail()||stock.fail())
	{
		cout<<"file with error\n";
		vip.close();
		ord.close();
		salerec.close();
		stock.close();
		exit(0);
	}
	
	cust *pcust;pcust=new cust;pcust->next=NULL;
	gds *pgds;pgds=new gds;pgds->next=NULL;
	sal *psal;psal=new sal;psal->next=NULL;
	
	
	gds *pn,*pe;                         //������ļ���Ϣ��ȡ���ṹ������
	pn=pe=NULL;
	pn=new gds;
	stock.read((char *)&pn,sizeof(gds));
	pe=pgds->next=pn;
	pn=new gds;
	while(!stock.eof())
	{
		stock.read((char *)&pn,sizeof(gds));
		pe->next=pn;
		pe=pn;
		pn=new gds;
	}
	pe=NULL;*/
	
	
	int i;
label3:
	while(1)
	{
		cout<<"�� (1������Ա / 2������  / 3:��ͨ�û�) ��ݵ�¼��  ";
		cin>>i;cin.ignore();
	    switch(i)
	    {
		    case 1:cashieraccess();break;
		    case 2:manageraccess();break;
		    case 3:customeraccess();break;
		    default:cout<<"�������\n";continue;
	    }
	    break;
	}
	cout<<"���س������ص�½���棬��������˳�ϵͳ\n";
	if(getch()=='\r') goto label3;
	else return 0;
}

