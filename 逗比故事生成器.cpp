#include<iostream>
using namespace std;
#include<time.h>
#include <stdlib.h>
int main()
{
	srand((unsigned)time(NULL));
    char character1[21],character2[21],character3[21];int n,v1,v2,adj1,adj2,res;
    label_1:
    cout<<"���˹��� 1/2/3 :";cin>>n;cin.ignore();
    switch(n)
    {
    	case 3:cout<<"���˹�3��";cin.getline(character3,21);
    	case 2:cout<<"���˹�2��";cin.getline(character2,21);
    	case 1:cout<<"���˹�1��";cin.getline(character1,21);break;
    	default:cout<<"�������\n";goto label_1;
	}
	if(n==2) goto label_2;
	else if(n==3) goto label_3;
	adj1=rand()%10+1;res=rand()%5+1;
	switch(adj1)
	{
		case 1:cout<<"��ŭ��";break;
		case 2:cout<<"�����";break;
		case 3:cout<<"���޿�����";break;
		case 4:cout<<"�����";break;
		case 5:cout<<"�����";break;
		case 6:cout<<"�մ���";break;
		case 7:cout<<"�����";break;
		case 8:cout<<"��ζ�ӳµ�";break;
		case 9:cout<<"�������͵�";break;
		case 10:cout<<"����������"; break;
	}
	cout<<character1;v1=rand()%7+1;
	switch(v1)
	{
		case 1:cout<<"�ֵ����";break;
		case 2:cout<<"�ڹ������Ͽ���";break;
		case 3:cout<<"ȥ������";break;
		case 4:cout<<"��ũҩ����";break;
		case 5:cout<<"�������㱼";break;
		case 6:cout<<"���ϼҷ���";break;
		case 7:cout<<"����һ���ӵ���ƨ";break; 
	}
	cout<<"���";
	switch(res)
	{
		case 1:cout<<"��·����";break; 
		case 2:cout<<"��FBI����";break; 
		case 3:cout<<"������������";break; 
		case 4:cout<<"Ц����";break; 
		case 5:cout<<"����˳�����";break; 
	}
	cout<<endl;
	system("pause");goto label_1;
	label_2:
	v1=rand()%5+1;v2=rand()%7+1;res=rand()%5+1;
	adj1=rand()%10+1;
	cout<<character1;
	switch(v1)
	{
		case 1:cout<<"�������ؿ���";break; 
		case 2:cout<<"͵����";break; 
		case 3:cout<<"ҹ���μ�";break; 
		case 4:cout<<"������˵";break; 
		case 5:cout<<"��˼������"; break; 
	}
	switch(adj1)
	{
		case 1:cout<<"��ŭ��";break;
		case 2:cout<<"�����";break;
		case 3:cout<<"���޿�����";break;
		case 4:cout<<"�����";break;
		case 5:cout<<"�����";break;
		case 6:cout<<"�մ���";break;
		case 7:cout<<"�����";break;
		case 8:cout<<"��ζ�ӳµ�";break;
		case 9:cout<<"�������͵�";break;
		case 10:cout<<"����������"; break;
	}
	cout<<character2;
	switch(v2)
	{
		case 1:cout<<"�ֵ����";break;
		case 2:cout<<"�ڹ������Ͽ���";break;
		case 3:cout<<"ȥ������";break;
		case 4:cout<<"��ũҩ����";break;
		case 5:cout<<"�������㱼";break;
		case 6:cout<<"���ϼҷ���";break;
		case 7:cout<<"����һ���ӵ���ƨ";break; 
	}
	cout<<"���";
	switch(res)
	{
		case 1:cout<<"��·����";break; 
		case 2:cout<<"��FBI����";break; 
		case 3:cout<<"������������";break; 
		case 4:cout<<"Ц����";break; 
		case 5:cout<<"����˳�����";break; 
	}
	cout<<endl;
	system("pause");goto label_1;
	label_3:
	v1=rand()%5+1;v2=rand()%7+1;res=rand()%5+1;
	adj1=rand()%10+1;adj2=rand()%10+1;
	cout<<character1;
	switch(v1)
	{
		case 1:cout<<"�������ؿ���";break;
		case 2:cout<<"͵����";break;
		case 3:cout<<"ҹ���μ�";break;
		case 4:cout<<"������˵";break;
		case 5:cout<<"��˼������"; break;
	}
	switch(adj1)
	{
		case 1:cout<<"��ŭ��";break;
		case 2:cout<<"�����";break;
		case 3:cout<<"���޿�����";break;
		case 4:cout<<"�����";break;
		case 5:cout<<"�����";break;
		case 6:cout<<"�մ���";break;
		case 7:cout<<"�����";break;
		case 8:cout<<"��ζ�ӳµ�";break;
		case 9:cout<<"�������͵�";break;
		case 10:cout<<"����������"; break;
	}
	cout<<character2<<"��";
	switch(adj2)
	{
		case 1:cout<<"��ŭ��";break;
		case 2:cout<<"�����";break;
		case 3:cout<<"���޿�����";break;
		case 4:cout<<"�����";break;
		case 5:cout<<"�����";break;
		case 6:cout<<"�մ���";break;
		case 7:cout<<"�����";break;
		case 8:cout<<"��ζ�ӳµ�";break;
		case 9:cout<<"�������͵�";break;
		case 10:cout<<"����������"; break;
	}
	cout<<character3;
	switch(v2)
	{
		case 1:cout<<"�ֵ����";break;
		case 2:cout<<"�ڹ������Ͽ���";break;
		case 3:cout<<"ȥ������";break;
		case 4:cout<<"��ũҩ����";break;
		case 5:cout<<"�������㱼";break;
		case 6:cout<<"���ϼҷ���";break;
		case 7:cout<<"����һ���ӵ���ƨ";break; 
	}
	cout<<"���";
	switch(res)
	{
		case 1:cout<<"��·����";break; 
		case 2:cout<<"��FBI����";break; 
		case 3:cout<<"������������";break; 
		case 4:cout<<"Ц����";break; 
		case 5:cout<<"����˳�����";break; 
	}
	cout<<endl;
	system("pause");
	goto label_1;
}

