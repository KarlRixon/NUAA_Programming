#include <iostream>
using namespace std;
int main(){
	int p=0,e=0,i=0;
	cout<<"���������߷���ֵ����ڣ��죩"<<endl;
	cin>>p;
	cout<<"�������̸߷���ֵ����ڣ��죩"<<endl;
	cin>>e;
	cout<<"�������̸߷���ֵ����ڣ��죩"<<endl;
	cin>>i;
	int t=0;
	if(p>e)t=p;
	else t=e;
	if(t<i)t=i;
	for(int j=1;;j++){
		if((t*j)%p==0&&(t*j)%e==0&&(t*j)%i==0){
		cout<<"�۷�״̬����Ϊ"<<t*j<<"��"<<endl;
		break; 
		} 
	}
}
