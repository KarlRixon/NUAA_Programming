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

extern float rate;     //�ۿ� 
class goods              //��Ʒ�� 
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
	goods(int &i)                         //���캯�� ���� i����Ʒ 
	{
		stonum-=i;
		sodnum+=i;
		sale+=price*i*rate;
	};
	/*void specialoffer(float rate)        //���� 
	{
		price*=rate; 
	}*/
	goods(char na[],float p,int sn,int nu)   //���캯�� ¼����Ʒ 
	{
		num=nu;
		price=p;
		stonum=sn;
		name=new char[strlen(na)+1];
		strcpy(name,na);
	}
	goods(goods &obj)               //�������캯�� 
	{
		num=obj.getnum();
		name=new char[strlen(obj.getname())+1];
		strcpy(name,obj.getname());
		price=obj.getprice();
		stonum=obj.getstonum();
	}
	int getnum()                    //��ȡ���� 
	{
		return num;
	}
	float getprice()                //��ȡ�۸� 
	{
		return price;
	}
	int getstonum()                 //��ȡ��� 
	{
		return stonum;
	}
	char *getname()                 //��ȡƷ�� 
	{
		return name;
	}
	~goods(){delete []name;}
	static int getsodnum()                 //��ȡ������ 
	{
		return sodnum;
	}
	static float getsale()                 //��ȡ���۶� 
	{
		return sale;
	}
	goods operator += (int newnum)         //���ؽ�������� 
	{
		stonum+=newnum;
		return *this; 
	}
	void show()                        //��ʾ��Ʒ��Ϣ 
	{
		cout<<"��Ʒ���ƣ�\t"<<name<<endl;
		cout<<"��    �ţ�\t"<<num<<endl; 
		cout<<"��Ʒ�۸�\t"<<price<<endl;
		cout<<"��Ʒ��棺\t"<<stonum<<endl; 
	}
	void manshow()                   //������ʾ��ϸ��Ϣ 
	{
		cout<<"��Ʒ���ƣ�\t"<<name<<endl;
		cout<<"��    �ţ�\t"<<num<<endl; 
		cout<<"��Ʒ�۸�\t"<<price<<endl;
		cout<<"��Ʒ��棺\t"<<stonum<<endl;
		cout<<"��Ʒ��������\t"<<sodnum<<endl;
		cout<<"��Ʒ���۶\t"<<sale<<endl;
	}
};
class customer                             //�˿��� 
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
	customer(long n)                //���캯�� �˿ʹ��� 
	{
		num=n;
		totalnum++;
	}
	customer operator += (goods &obj)      //��¼���Ѷ� 
	{
		expenditure+=obj.getprice()*rate; 
	}
	long getnum()                   //��ȡ�˿ʹ��� 
	{
		return num;
	}
	float getexp()                 //��ȡ���Ѷ� 
	{
		return expenditure;
	}
	static long gettotalnum()       //��ȡ�ͻ����� 
	{
		return totalnum;
	}
};
class vip:public customer
{
	float points;
	static long vipnum; 
public:
	vip(int n):customer(n)        //���캯�� ע��vip�û� 
	{
		vipnum++;
	}
	vip operator += (goods &obj)   //��¼���Ѷ���� 
	{
		expenditure+=obj.getprice()*rate;
		points=expenditure;
	}
	float getpoints()               //��ȡ���� 
	{
		return points;
	}
	static long getvipnum()        //��ȡvip�û��� 
	{
		return vipnum;
	}
};
struct cust                        //�˿ͽṹ�� 
{
	char num[12];
	float purchase;
	//long total;
	cust *next;
};
struct gds                         //��Ʒ�ṹ�� 
{
	char name[21];
	float price;
	int num;
	int stonum;
	int sodnum;
	float sale;
	gds *next;
};
struct sal                         //���ۼ�¼�ṹ�� 
{
	char cnum[13];
	long gnum;
	int amount;
	float price;
	sal *next;
};
struct numname                     //����ƥ�������Ʒ�� 
{
	char gname[21];
	int gnum;
	numname *next;
};


#endif