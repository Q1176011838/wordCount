
int characters_sum(sring str)//��Ҫһ���ַ����� ������ֵΪ�ַ����� 
{
	//string str;
    int sum = 0;                            //ͳ���ַ�����
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

