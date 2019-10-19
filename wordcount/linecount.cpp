#include<string>
#include<iostream>
#include<stdio.h>
#include<iostream>
using namespace std;

int lineCount(){
	string str=inFile(); 
		int n=str.size();
		int linecount=1;
		for(int i=0;i<n;i++){
			if(i!=0){
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
		
			/*else{
				for(int j=i;j<n;j++){
					if(str[0]=='\r')
						break;
					if(str[0]==' '){
						for(int k=0;k<n;k++){
							if(str[0]=='\r')
								break;
							if(str[k]!=' '){	
								linecount++;
								break;
							}
						}	
					}
				}
			}*/
		}	
	cout<<linecount;
}
		
int main(){
		lineCount();
	return 0;
}
