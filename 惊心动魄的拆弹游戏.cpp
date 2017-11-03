#include<iostream>
using namespace std;
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int main()
{
	int n,c;n=clock();
	srand((unsigned)time(NULL));
	int r,p;r=rand()%3+1;
	while(c-n<10000)
	{
		c=clock();
		system("cls");
		cout<<"1:----------------------------------\n";
		cout<<"2:----------------------------------\n";
		cout<<"3:----------------------------------\n";
		cout<<"this is a timeboom\nwhich rope to cut\n";
		cout<<(10000-(c-n))/100<<endl;
		if(p=kbhit())
		{
			if(p==r)
	        {
		        cout<<"thank god you survived!\n";
		        exit(0);
    	    }
    	    else break;
    	}
	}
	cout<<"BOOM!!!\nhahahahaha you lose \nyou're dead!";
	while(1)
	{
		system("color 4F");
		Sleep(10);
		system("color 8E");
	}
}
