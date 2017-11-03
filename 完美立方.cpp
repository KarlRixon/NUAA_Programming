#include<iostream>
using namespace std;
int main()
{
	int n=0,a=0,b=0,c=0,d=0;
	cout<<"你想求2到多少的完美立方（即a的立方等于b c d的立方和）：";
	cin>>n;
	for(a=2;a<=n;a++){
		for(b=2;b<=a;b++){
			for(c=2;c<=b;c++){
				for(d=2;d<=c;d++){
					if(a*a*a==b*b*b+c*c*c+d*d*d){
						cout<<a<<"^3="<<b<<"^3+"<<c<<"^3+"<<d<<"^3"<<"\t\t("<<a<<","<<b<<","<<c<<","<<d<<")"<<endl;
					}
				}
			}
		}
	}
}
