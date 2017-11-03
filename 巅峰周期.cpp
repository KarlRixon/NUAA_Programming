#include <iostream>
using namespace std;
int main(){
	int p=0,e=0,i=0;
	cout<<"输入体力高峰出现的周期（天）"<<endl;
	cin>>p;
	cout<<"输入情商高峰出现的周期（天）"<<endl;
	cin>>e;
	cout<<"输入智商高峰出现的周期（天）"<<endl;
	cin>>i;
	int t=0;
	if(p>e)t=p;
	else t=e;
	if(t<i)t=i;
	for(int j=1;;j++){
		if((t*j)%p==0&&(t*j)%e==0&&(t*j)%i==0){
		cout<<"巅峰状态周期为"<<t*j<<"天"<<endl;
		break; 
		} 
	}
}
