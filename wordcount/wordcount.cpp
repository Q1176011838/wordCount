#include<iostream>
#include<string.h> 
#include<fstream> 
#include<stdio.h>
using namespace std;
string command[5]={"no","no","no","no","no"};//创建数组用于保存参数  0 m 1 n 2 i 3 o

void com(int argc,char *argv[]);//返回数组的指针 ,数组包括 m,n,input,output 
string inFile(string name);//需要文件名 返回文件的字符串 
int WordsCount(string txt);//输入文件的字符串数组 ,返回单词的个数 
int lineCount(string str);//返回行数 
int characters_sum(string str);//需要一个字符数组 ，返回值为字符个数 
int main(int argc,char *argv[]){
	
	com(argc,argv);	
	
	string files =  inFile(command[2]);
	//统计数据获取
	int char_num = characters_sum(files);
	int words_num = WordsCount(files);
	int lines_num = lineCount(files);
	int num[100];//单词（词组）出现频数，与word数组相对应 
	string word[100];//单词（词组）数组 
	int n=100;
	
	char buf[20];
	strcpy(buf, command[3].c_str());
		//写入output文件 
	ofstream outFile(buf);
	outFile<<"characters:";
	outFile<<char_num<<endl<<endl<<endl;
	outFile<<"words:";
	outFile<<words_num<<endl<<endl<<endl;
	outFile<<"lines:";
	outFile<<lines_num<<endl<<endl<<endl;
	for(int i=0;i<n;i++)
		outFile<<"<"<< word[i] <<">:"<< num[i]  <<endl<<endl<<endl;
		
	
	return 0;
} 

string inFile(string name){
	//读input文件并输入 
	char names[20];
	strcpy(names, name.c_str());
	ifstream intFile(names);
	char temp[100000];//存放文件数据的数组 
	intFile.getline(temp,1024,0);//将文件数据读入
	name = temp;
	return name;
}
void com(int argc,char *argv[])
{
	int m=0,n=0;
	int i;
	for(i=0;i<argc;i++)
	{
		if(strcmp(argv[i],"-m")==0)//判断参数
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
 } 


int characters_sum(string str)//需要一个字符数组 ，返回值为字符个数 
{
	//string str;
    int sum = 0;                            //统计字符个数
    //getline(cin,str);
    //str="Monday Tuesday Wednesday Thursday\nFriday";
    int a = str.size();
    
    for(int i=0; i<a; i++)
    {
    	if(str[i]>=0x00&&str[i]<=0x80)
    	{
    		sum++;
    	}
    }    	
	return sum;
}

int WordsCount(string txt)//输入文件的字符串数组 
{
	char str[1024];
	strcpy(str,txt.c_str());
	int i = 0;
//	input();
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
    return num;//返回单词个数 
} 

int lineCount(string str){
		int n=str.size();
		
		int linecount=0;
		int temp=0;
	if(str[0]!=' '&&str[0]!='\n'){
		linecount++;
	}
	
	else if(str[0]==' '){
		for(int i=0;i<n;i++){
			if(str[i]=='\n'){
				//cout<<i<<"*"<<endl;
				int j=i;
				for(;j>0;j--){
					//cout<<"______"<<endl;
					if(str[j]!=' '&&str[j]!='\n'){
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
		    if(str[i]=='\n'){
				for(int j=i+1;j<n;j++){
					if(str[j]=='\n')
						break;
					if(str[j]!='\n'&&str[j]!=' '){
						linecount++;
						break;
					}
				}
			}
	}
	return linecount;
}
