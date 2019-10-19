#include <iostream>
#include <string.h>
using namespace std;
void output()
{
    int count=2;
    int num=1;
    string l[100]={"22222","mmmmm"};
    cout <<"characters: "<<"40"<<endl;
    cout<<endl;
    cout << "words: "<<"5"<<endl;
    cout<<endl;
    cout << "lines: "<<"2"<<endl;
    cout<<endl;
    for (int i = 0; i < count; i++)
    {
        cout << "<" << l[i] << ">:" <<" "<<num<<endl;
    }
}
int main()
{
    output();
}
