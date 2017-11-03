#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main(){
    char a[101],b[101];
    bool end=false;
    scanf("%s",&a);
    scanf("%s",&b);
    int i=0;
    while(i<100){
        i++;
        if(a[i-1]==b[0]){
            int k=i-1;
            for(int j=0;;j++){
                if(b[j]=='\0') break;
                if(a[k]!=b[j]){
                    end=false;
                    break;
                }
                else end=true;
                k++;
            }
            if(end==true){
                cout<<i;
                exit(0);
            }
        }
    }
    if(end==false) cout<<"нч";
    return 0;
}
