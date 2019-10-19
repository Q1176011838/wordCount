#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void inFile(){
	//读input文件并输入 
	ifstream intFile("input.txt");
	char temp[1024];//存放文件数据的数组 
	intFile.getline(temp,1024,0);//将文件数据读入
	return temp;
}


int main()
{ 
	void inFle();
	
	//统计数据获取 
	int char_num = characters_sum();
	int words_num = WordsCount();
	int lines_num = lineCount();
	int num[100];//单词（词组）出现频数，与word数组相对应 
	string word[100];//单词（词组）数组 
	int n=100;
	
		//写入output文件 
	ofstream outFile("output.txt");
	outFile<<"characters:";
	outFile<<char_num<<endl<<endl<<endl;
	outFile<<"words:";
	outFile<<words_num<<endl<<endl<<endl;
	outFile<<"lines:";
	outFile<<lines_num<<endl<<endl<<endl;
	for(int i=0;i<n;i++)
		outFile<<"<"<< word[i] <<">:"<< num[i]  <<endl<<endl<<endl;
}


