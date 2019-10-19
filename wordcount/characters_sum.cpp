
int characters_sum(sring str)//需要一个字符数组 ，返回值为字符个数 
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

