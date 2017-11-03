#ifndef gdscst_H
#define gdscst_H

#include<iostream>
using namespace std;
#include<fstream> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

extern float rate;     //折扣 
class goods              //商品类 
{
protected:
	char *name;
	float price;
	int num;
	static int stonum;
	static int sodnum;
	static float sale;
public:
	goods()
	{
		stonum--;
		sodnum++;
		sale+=price*rate;
	}
	goods(int &i)                         //构造函数 出售 i个商品 
	{
		stonum-=i;
		sodnum+=i;
		sale+=price*i*rate;
	};
	/*void specialoffer(float rate)        //打折 
	{
		price*=rate; 
	}*/
	goods(char na[],float p,int sn,int nu)   //构造函数 录入商品 
	{
		num=nu;
		price=p;
		stonum=sn;
		name=new char[strlen(na)+1];
		strcpy(name,na);
	}
	goods(goods &obj)               //拷贝构造函数 
	{
		num=obj.getnum();
		name=new char[strlen(obj.getname())+1];
		strcpy(name,obj.getname());
		price=obj.getprice();
		stonum=obj.getstonum();
	}
	int getnum()                    //获取货号 
	{
		return num;
	}
	float getprice()                //获取价格 
	{
		return price;
	}
	int getstonum()                 //获取库存 
	{
		return stonum;
	}
	char *getname()                 //获取品名 
	{
		return name;
	}
	~goods(){delete []name;}
	static int getsodnum()                 //获取销售量 
	{
		return sodnum;
	}
	static float getsale()                 //获取销售额 
	{
		return sale;
	}
	goods operator += (int newnum)         //重载进货运算符 
	{
		stonum+=newnum;
		return *this; 
	}
	void show()                        //显示商品信息 
	{
		cout<<"商品名称：\t"<<name<<endl;
		cout<<"货    号：\t"<<num<<endl; 
		cout<<"商品价格：\t"<<price<<endl;
		cout<<"商品库存：\t"<<stonum<<endl; 
	}
	void manshow()                   //向经理显示详细信息 
	{
		cout<<"商品名称：\t"<<name<<endl;
		cout<<"货    号：\t"<<num<<endl; 
		cout<<"商品价格：\t"<<price<<endl;
		cout<<"商品库存：\t"<<stonum<<endl;
		cout<<"商品销售量：\t"<<sodnum<<endl;
		cout<<"商品销售额：\t"<<sale<<endl;
	}
};
class customer                             //顾客类 
{
protected:
	long num;
	float expenditure;
	static long totalnum;
public:
	customer()
	{
		totalnum++;
	}
	customer(long n)                //构造函数 顾客代码 
	{
		num=n;
		totalnum++;
	}
	customer operator += (goods &obj)      //记录消费额 
	{
		expenditure+=obj.getprice()*rate; 
	}
	long getnum()                   //获取顾客代码 
	{
		return num;
	}
	float getexp()                 //获取消费额 
	{
		return expenditure;
	}
	static long gettotalnum()       //获取客户总数 
	{
		return totalnum;
	}
};
class vip:public customer
{
	float points;
	static long vipnum; 
public:
	vip(int n):customer(n)        //构造函数 注册vip用户 
	{
		vipnum++;
	}
	vip operator += (goods &obj)   //记录消费额及积分 
	{
		expenditure+=obj.getprice()*rate;
		points=expenditure;
	}
	float getpoints()               //获取积分 
	{
		return points;
	}
	static long getvipnum()        //获取vip用户数 
	{
		return vipnum;
	}
};
struct cust                        //顾客结构体 
{
	char num[12];
	float purchase;
	//long total;
	cust *next;
};
struct gds                         //商品结构体 
{
	char name[21];
	float price;
	int num;
	int stonum;
	int sodnum;
	float sale;
	gds *next;
};
struct sal                         //销售记录结构体 
{
	char cnum[13];
	long gnum;
	int amount;
	float price;
	sal *next;
};
struct numname                     //用于匹配货号与品名 
{
	char gname[21];
	int gnum;
	numname *next;
};


#endif