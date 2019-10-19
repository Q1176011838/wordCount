#include<iostream>
using namestringspace std;
string* com(int argc,char *argv[])
{
	string command[5]={"no"};
	int m=0,n=0;
	int i;
	for(i=0;i<argc;i++)
	{
		if(strcmp(argv[i],"-m")==0)
		{
			i++;
			command[0]=argv[i];
		}
		if(strcmp(argv[i],"-n")==0)
		{
			i++;
			command[1]=argv[i];
		}
		if(strcmp(argv[i],"-i")==0)
		{
			i++;
			command[2]=argv[i];
		}
		if(strcmp(argv[i],"-o")==0)
		{
			i++;
			command[3]=argv[i];
		}
	}
	return command;
 } 


int main(int argc,char argv[]){
	
	return 0;
}
