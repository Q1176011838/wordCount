#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void inFile(){
	//��input�ļ������� 
	ifstream intFile("input.txt");
	char temp[1024];//����ļ����ݵ����� 
	intFile.getline(temp,1024,0);//���ļ����ݶ���
	return temp;
}


int main()
{ 
	void inFle();
	
	//ͳ�����ݻ�ȡ 
	int char_num = characters_sum();
	int words_num = WordsCount();
	int lines_num = lineCount();
	int num[100];//���ʣ����飩����Ƶ������word�������Ӧ 
	string word[100];//���ʣ����飩���� 
	int n=100;
	
		//д��output�ļ� 
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


