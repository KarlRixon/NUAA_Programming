/*
    setlocale(LC_TIME,"");
    time_t TIME;
    struct tm *TM;
    char ch[15]；
    time(&TIME);
    TM=gmtime(&TIME);
    strftime(ch,80,"%x",TM);
*/
#include<iostream>
using namespace std;
#include<fstream> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"gdscst.h"

float sumfinrec()
{
	float sum=0;
	fstream infile;
	infile.open("financialrec.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"financialrec file with error\n";
		exit(0);
	}
	finrec *p;
	p=new finrec;
	//infile.read((char *)p,sizeof(finrec));
	//sum+=p->rec;
	while(!infile.eof())
	{
		infile.read((char *)p,sizeof(finrec));
		sum+=p->rec;
	}
	infile.close();
	return sum-p->rec;
}
void financialrec(float money)
{
	finrec *p;
	p=new finrec;
	p->rec=money;                 //对金额赋值
	fstream outfile;
	outfile.open("financialrec.dat",ios::out|ios::binary|ios::app);
	if(outfile.fail())
	{
		cout<<"financialrec file with error\n";
		exit(0);
	}
	setlocale(LC_TIME,"");
    time_t TIME;
    struct tm *TM;
    char ch[15];
    time(&TIME);
    TM=gmtime(&TIME);
    strftime(ch,80,"%x",TM);
	strcpy(p->tm,ch);             //对时间字符数组赋值
	outfile.write((char *)p,sizeof(finrec));
	outfile.close();
}
int showfinrec()
{
	int counter=0,sum=0;
	finrec *p;
	p=new finrec;
	fstream infile;
	infile.open("financialrec.dat",ios::in|ios::binary);
	if(infile.fail())
	{
		cout<<"financialrec file with error\n";
		exit(0);
	}
	while(!infile.eof())
	{
		infile.read((char *)p,sizeof(finrec));
		sum++;
	}
	sum--;
	infile.clear();
	infile.seekg(-(long)sizeof(finrec),ios::end);
	cout.precision(2);
	cout.setf(ios::fixed|ios::showpoint);
	cout<<"-----------------------------"<<endl;
	while(!infile.eof())
	{
		infile.read((char *)p,sizeof(finrec));
		counter++;
		cout<<p->tm<<"\t";
		if(p->rec>0) cout<<"+"<<p->rec<<endl;
		else cout<<p->rec<<endl;
		infile.seekg(-(long)sizeof(finrec)*2,ios::cur);
		if(counter==sum)
		{
			cout<<"显示完毕"<<endl;
			infile.close();
			cout<<"-----------------------------"<<endl;
			return 0;
		}
		else if(counter%20==0&&counter!=sum)
		{
			cout<<"按回车键继续，按任意键退出查看";
			if(getch()!='\r')
			{
				infile.close();
				cout<<"-----------------------------"<<endl;
				return 0;
			}
			else continue;
		}
	}
	infile.close();
	cout<<"-----------------------------"<<endl;
	return 1;
}
