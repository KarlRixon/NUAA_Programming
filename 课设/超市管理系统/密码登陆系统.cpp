#include<iostream>
using namespace std;
#include<fstream> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"gdscst.h"
char *getpassw()            //»ñÈ¡ÃÜÂë 
{
	char temp[10],p;
	for(int j=0;j<10;j++)
	{
		temp[j]='\0';
	}
	cout<<"ÇëÊäÈëÃÜÂë£º\n";
	for(int i=0;i<9;i++)
	{
		p=getch();
		if(p=='\r') break;
		temp[i]=p;
	}
	return temp;
}