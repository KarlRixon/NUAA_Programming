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
	cout<<"输入玩的次数：";
	cin>>t;
	cout<<"用A-L代表每个硬币，输入天平左边 右边硬币和结果（每个字母只能用一次 如 ABCD EFGH even/up/down）："<<endl;
	for(int i=0;i<3;i++) cin>>left[i]>>right[i]>>result[i];
	for(char c='A';c<='L';c++){
		if(isFake(c,true)){
			cout<<c<<"是假币"<<endl;break; 
		}
		else if(isFake(c,false)){
			cout<<c<<"不是假币"<<endl;break;
		}
	}
}
