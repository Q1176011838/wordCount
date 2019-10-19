#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int lineCount(){
	string str="\rfgsdfgsdg\rhgdfhh\rgfdsbgfd";  //inFile()调用输入函数返回值 
		int n=str.size();
		int linecount=0;
		int temp=0;
	if(str[0]!=' '&&str[0]!='\r'){
		linecount++;
	}
	
	else if(str[0]==' '){
		for(int i=0;i<n;i++){
			if(str[i]=='\r'){
				//cout<<i<<"*"<<endl;
				int j=i;
				for(;j>0;j--){
					//cout<<"______"<<endl;
					if(str[j]!=' '&&str[j]!='\r'){
						//cout<<j<<"$"<<endl;
						linecount++;
						goto stop;
					}
				}
				if(j==0){
					goto stop;
				}
			}
		}
	}

	stop:for(int i=0;i<n;i++){
		    if(str[i]=='\r'){
				for(int j=i+1;j<n;j++){
					if(str[j]=='\r')
						break;
					if(str[j]!='\r'&&str[j]!=' '){
						linecount++;
						break;
					}
				}
			}
	}
	return linecount;
}
		
int main(){
	lineCount();
	return 0;
}
