#include<iostream>
using namespace std;
#include<time.h>
#include <stdlib.h>
int main()
{
	srand((unsigned)time(NULL));
    char character1[21],character2[21],character3[21];int n,v1,v2,adj1,adj2,res;
    label_1:
    cout<<"几人故事 1/2/3 :";cin>>n;cin.ignore();
    switch(n)
    {
    	case 3:cout<<"主人公3：";cin.getline(character3,21);
    	case 2:cout<<"主人公2：";cin.getline(character2,21);
    	case 1:cout<<"主人公1：";cin.getline(character1,21);break;
    	default:cout<<"输入错误\n";goto label_1;
	}
	if(n==2) goto label_2;
	else if(n==3) goto label_3;
	adj1=rand()%10+1;res=rand()%5+1;
	switch(adj1)
	{
		case 1:cout<<"愤怒的";break;
		case 2:cout<<"高冷的";break;
		case 3:cout<<"生无可恋的";break;
		case 4:cout<<"烂醉的";break;
		case 5:cout<<"发情的";break;
		case 6:cout<<"痴呆的";break;
		case 7:cout<<"天真的";break;
		case 8:cout<<"五味杂陈的";break;
		case 9:cout<<"富得流油的";break;
		case 10:cout<<"聪明绝顶的"; break;
	}
	cout<<character1;v1=rand()%7+1;
	switch(v1)
	{
		case 1:cout<<"持刀表白";break;
		case 2:cout<<"在公共场合开车";break;
		case 3:cout<<"去抢银行";break;
		case 4:cout<<"玩农药开黑";break;
		case 5:cout<<"在宿舍裸奔";break;
		case 6:cout<<"回老家放炮";break;
		case 7:cout<<"放了一分钟的响屁";break; 
	}
	cout<<"结果";
	switch(res)
	{
		case 1:cout<<"半路掉沟";break; 
		case 2:cout<<"被FBI逮捕";break; 
		case 3:cout<<"遇见了外星人";break; 
		case 4:cout<<"笑死了";break; 
		case 5:cout<<"获得了超能力";break; 
	}
	cout<<endl;
	system("pause");goto label_1;
	label_2:
	v1=rand()%5+1;v2=rand()%7+1;res=rand()%5+1;
	adj1=rand()%10+1;
	cout<<character1;
	switch(v1)
	{
		case 1:cout<<"眼睁睁地看见";break; 
		case 2:cout<<"偷听到";break; 
		case 3:cout<<"夜里梦见";break; 
		case 4:cout<<"听妈妈说";break; 
		case 5:cout<<"胡思乱想着"; break; 
	}
	switch(adj1)
	{
		case 1:cout<<"愤怒的";break;
		case 2:cout<<"高冷的";break;
		case 3:cout<<"生无可恋的";break;
		case 4:cout<<"烂醉的";break;
		case 5:cout<<"发情的";break;
		case 6:cout<<"痴呆的";break;
		case 7:cout<<"天真的";break;
		case 8:cout<<"五味杂陈的";break;
		case 9:cout<<"富得流油的";break;
		case 10:cout<<"聪明绝顶的"; break;
	}
	cout<<character2;
	switch(v2)
	{
		case 1:cout<<"持刀表白";break;
		case 2:cout<<"在公共场合开车";break;
		case 3:cout<<"去抢银行";break;
		case 4:cout<<"玩农药开黑";break;
		case 5:cout<<"在宿舍裸奔";break;
		case 6:cout<<"回老家放炮";break;
		case 7:cout<<"放了一分钟的响屁";break; 
	}
	cout<<"结果";
	switch(res)
	{
		case 1:cout<<"半路掉沟";break; 
		case 2:cout<<"被FBI逮捕";break; 
		case 3:cout<<"遇见了外星人";break; 
		case 4:cout<<"笑死了";break; 
		case 5:cout<<"获得了超能力";break; 
	}
	cout<<endl;
	system("pause");goto label_1;
	label_3:
	v1=rand()%5+1;v2=rand()%7+1;res=rand()%5+1;
	adj1=rand()%10+1;adj2=rand()%10+1;
	cout<<character1;
	switch(v1)
	{
		case 1:cout<<"眼睁睁地看见";break;
		case 2:cout<<"偷听到";break;
		case 3:cout<<"夜里梦见";break;
		case 4:cout<<"听妈妈说";break;
		case 5:cout<<"胡思乱想着"; break;
	}
	switch(adj1)
	{
		case 1:cout<<"愤怒的";break;
		case 2:cout<<"高冷的";break;
		case 3:cout<<"生无可恋的";break;
		case 4:cout<<"烂醉的";break;
		case 5:cout<<"发情的";break;
		case 6:cout<<"痴呆的";break;
		case 7:cout<<"天真的";break;
		case 8:cout<<"五味杂陈的";break;
		case 9:cout<<"富得流油的";break;
		case 10:cout<<"聪明绝顶的"; break;
	}
	cout<<character2<<"和";
	switch(adj2)
	{
		case 1:cout<<"愤怒的";break;
		case 2:cout<<"高冷的";break;
		case 3:cout<<"生无可恋的";break;
		case 4:cout<<"烂醉的";break;
		case 5:cout<<"发情的";break;
		case 6:cout<<"痴呆的";break;
		case 7:cout<<"天真的";break;
		case 8:cout<<"五味杂陈的";break;
		case 9:cout<<"富得流油的";break;
		case 10:cout<<"聪明绝顶的"; break;
	}
	cout<<character3;
	switch(v2)
	{
		case 1:cout<<"持刀表白";break;
		case 2:cout<<"在公共场合开车";break;
		case 3:cout<<"去抢银行";break;
		case 4:cout<<"玩农药开黑";break;
		case 5:cout<<"在宿舍裸奔";break;
		case 6:cout<<"回老家放炮";break;
		case 7:cout<<"放了一分钟的响屁";break; 
	}
	cout<<"结果";
	switch(res)
	{
		case 1:cout<<"半路掉沟";break; 
		case 2:cout<<"被FBI逮捕";break; 
		case 3:cout<<"遇见了外星人";break; 
		case 4:cout<<"笑死了";break; 
		case 5:cout<<"获得了超能力";break; 
	}
	cout<<endl;
	system("pause");
	goto label_1;
}

