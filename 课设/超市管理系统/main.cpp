#include<iostream>
using namespace std;
#include<fstream> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"gdscst.h"
int goods::sodnum=0;  //销售量 
float goods::sale=0;  //销售额 
long customer::totalnum=0;  //顾客总量 
long vip::vipnum=0;  //会员账号为手机号 
int goods::stonum;  //库存 
float rate=1.00f;  //经理可以更改折扣 
//int spof=0;      //代表当天优惠形式   1:打折 2:买够就送 3:抽奖 0:不优惠
int cashieraccess();  //收银员入口 
int manageraccess();   //经理入口
int customeraccess(); //普通用户入口 
int editfile();        //编辑文件内容 

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
	
	
	gds *pn,*pe;                         //将库存文件信息提取到结构体链表
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
		cout<<"以 (1：收银员 / 2：经理  / 3:普通用户) 身份登录：  ";
		cin>>i;cin.ignore();
	    switch(i)
	    {
		    case 1:cashieraccess();break;
		    case 2:manageraccess();break;
		    case 3:customeraccess();break;
		    default:cout<<"输入错误\n";continue;
	    }
	    break;
	}
	cout<<"按回车键返回登陆界面，按任意键退出系统\n";
	if(getch()=='\r') goto label3;
	else return 0;
}

