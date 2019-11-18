#include<iostream>
#include<string.h> 
#include<fstream> 
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm> 
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int>vi;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define fi first
#define se second
#define de(x) cout<<#x<<"="<<x<<endl;
#define dd(x) cout<<#x<<"="<<x<<" " ;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define lowbit(a) ((a)&-(a))
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)


const int N=4e5+5;
int ans_ch = 0,ans_word = 0,ans_line = 0;
string in,out;
int m = 1,n = 10;
vector<string> str; 
vector<pair<string,int>> ans_ph;
bool f =true;
int cnt_ph = 0;
//词频
bool checkCh(char c){
	if(c>='A' && c<='Z' || c>='a' && c<='z' || c<='9' && c>='0')
		return true;
	return false;
}
bool checkWord(string s){
	if((int)s.size()<4)return false;
	for(int i=0;i<4;++i){
		if(s[i]<='9' && s[i]>='0')return false;
	}
	return true;
} 
bool cmp(pair<string,int> a,pair<string,int> b){
	if(a.second!=b.second)
		return a.second>b.second;
	return a.first<b.first;
} 
void count(vector<string> V,int m,int n){
	map<string,int> words,phrase; 
	for(auto line:V){
		int len=(int)line.size();
		vector<string> cur; 
		for(int i=0,j;i<len;){
			j=i;
			string t="";
			while(j<len && (checkCh(line[j])))t+=line[j],j++;
			if(checkWord(t)){
				words[t]++;
				ans_word++;
				cur.push_back(t);
			}
			else{
				for(int k=0;k<(int)cur.size()-m+1;++k){
					string t="";
					int f=0;
					for(int h=k;h<k+m;++h){
					 	if(f)t+=" ";
						t+=cur[h];
						f=1;
					}
					phrase[t]++;
				}
				cur.clear();
			}
			while(j<len && (!checkCh(line[j])))j++;
			i=j;
		}
		for(int k=0;k<(int)cur.size()-m+1;++k){
			string t="";
			int f=0;
			for(int h=k;h<k+m;++h){
				if(f)t+=" ";
				t+=cur[h];
				f=1;
			}
			phrase[t]++;
		}
		cur.clear();
	}
	vector<pair<string,int>> g;
	for(auto it:words){
		g.push_back(make_pair(it.first,it.second));
	}
	sort(g.begin(),g.end(),cmp);	 
	g.clear();
	for(auto it:phrase){
		g.push_back(make_pair(it.first,it.second));	
	}
	sort(g.begin(),g.end(),cmp);
	cnt_ph = min((int)g.size(),n);
	for(int i=0;i<min((int)g.size(),n);++i){
		string now = "";
		now = "<"+g[i].fi+">:"; 
		ans_ph.pb(make_pair(now,g[i].se));
	}
} 
void count_ch(string dir){
	string now;
	ifstream infile;
	infile.open(dir,ios::in);
	while(!infile.eof()){
		getline(infile,now,'\n');
		bool f = false;
		if(now !=""){
			for(int i = 0 ;i<sz(now);++i){
				int dt = now[i];
				if(dt > 32 && dt != 127) f = true;
				if(now[i]<='Z' && now[i] >= 'A')
					now[i]+=32;
			}
			str.push_back(now);
			ans_ch+=sz(now);
		}
		if(f) ans_line++;
		ans_ch++;
	}
	ans_ch--;
	infile.close();
}
void print(){
	ofstream fout;
	fout.open(out,ios::out);
	fout<<"characters: "<<ans_ch<<endl;
	fout<<"words: "<<ans_word<<endl;
	fout<<"lines: "<<ans_line;
	if(sz(ans_ph))fout<<endl; 
	int cur = 0;
	for(auto it:ans_ph){
		fout<<it.fi<<" "<<it.se;
		cur++;
		if(cur != sz(ans_ph))
			fout<<endl;
	}
	fout.close(); 
}
int parse(char *s){
	int len = strlen(s);
	int ans = 0;
	for(int i = 0 ; i < len;++i){
		ans = ans*10 + s[i]-'0';
	}
	return ans;
}
int main(int argc,char *argv[]){
	
	for(int i = 1;i<argc;i+=2){

		if(strcmp(argv[i],"-i")==0){
			in = argv[i+1]; 
		}
		else if(strcmp(argv[i],"-o")==0){
			out = argv[i+1];
		}
		else if(strcmp(argv[i],"-n")==0){
			n = parse(argv[i+1]);
		}
		else if(strcmp(argv[i],"-m")==0){
			m = parse(argv[i+1]);
		}
	}	
	count_ch(in); 
	count(str,m,n);
	print();
	
	return 0;
} 

