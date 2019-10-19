#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
char str[1000];
int i = 0;

void input()
{
	while((str[i]=getchar())!='\n')
	{
		i++;
	}
	i++;
	if((str[i]=getchar())=='\n')
	{
		str[i]='\0';
		return;
	}
	else input();
}
int main()
{
	int i = 0;
	input();
	int num=0;
    num++;
    if((str[0]>='a'&&str[0]<='z')||(str[0]>='A'&&str[0]<='Z'))
	{
		for(int j = 1;j < 4;j++)
		{
			if(str[j] < 'A'|| (str[j] > 'Z'&& str[j] < 'a')|| str[j] >'z' || str[j]==' '||str[j] == '\n' )
			{
				num--;
				break;	   					
			}
		}
	}
	else
		num--;
    for(i = 0; str[i]!='\0'; i++)
    {
        if(str[i] == ' '||str[i] == '\n')
        {
            num++;
            if(str[i+1]>='a'&&str[i+1]<='z'||str[i+1]>='A'&&str[i+1]<='Z')
	    	{
	    		for(int j = 1;j < 4;j++)
	    		{
	   				if(str[i+j]<'A'||(str[i+j]>'Z'&&str[i+j] < 'a')||str[i+j]>'z'||str[i+j]==' '||str[i+j] == '\n' )
	   				{
	   					num--;
	   					break;	   					
					}
				}
			}
			else
				num--;
        }
    }
    cout<<"words:"<<num<<endl;
    return 0;
} 
