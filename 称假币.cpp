#include<iostream>
#include<cstring>
using namespace std;

char right[3][7];
char left[3][7];
char result[3][7];

bool isFake(char c,bool light){
	for(int i=0;i<3;i++){
		char *pright,*pleft;
		if(light){
			pleft=left[i];
			pright=right[i];
		}
		else{
			pleft=right[i];
			pright=left[i];
		}
		switch(result[i][0]){
			case 'u':
				if(strchr(pright,c)==NULL){
					return false;
				}break;
			case 'e':
				if(strchr(pleft,c)||strchr(pright,c)){
					return false;
				}break;
			case 'd':
				if(strchr(pleft,c)==NULL){
					return false;
				}break;
		}
	}
	return true;
}

int main(){
	int t=0;
	cout<<"������Ĵ�����";
	cin>>t;
	cout<<"��A-L����ÿ��Ӳ�ң�������ƽ��� �ұ�Ӳ�Һͽ����ÿ����ĸֻ����һ�� �� ABCD EFGH even/up/down����"<<endl;
	for(int i=0;i<3;i++) cin>>left[i]>>right[i]>>result[i];
	for(char c='A';c<='L';c++){
		if(isFake(c,true)){
			cout<<c<<"�Ǽٱ�"<<endl;break; 
		}
		else if(isFake(c,false)){
			cout<<c<<"���Ǽٱ�"<<endl;break;
		}
	}
}
