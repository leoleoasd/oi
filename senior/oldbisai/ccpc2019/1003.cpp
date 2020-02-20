#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int N = 0, Q = 0;
int l,r,k;
string s;
map<string, vector<int> > saved;
map<string, int *> nexts;
int *pre_kmp(string pattern){
	int size = pattern.size();
	int *pie=new int [size];
	pie[0] = 0;
	int k=0;
	for(int i=1;i<size;i++)
	{
		while(k>0 && pattern[k] != pattern[i] )
		{
			k=pie[k-1];
		}
		if( pattern[k] == pattern[i] )
		{
			k=k+1;
		}
		pie[i]=k;
	}
	
	return pie;
}

int kmp(string text,string pattern,int start){

	int* pie;
    if(nexts[pattern] != NULL){
        //cout<<"命中缓存2";
        pie = nexts[pattern];
    }else{
        pie = pre_kmp(pattern);
        nexts[pattern] = pie;
    }
	int matched_pos=0;
	for(int current=start; current< text.length(); current++)
	{
		while (matched_pos > 0 && pattern[matched_pos] != text[current] )
			matched_pos = pie[matched_pos-1];
			
		if(pattern[matched_pos] == text[current])
			matched_pos = matched_pos+1;
			
		if( matched_pos == (pattern.length()) )
		{
            return current - (pattern.length() -1 );
		}
	}
    delete pie;
    return -1;
}

int solve(){
    string subs = s.substr(l-1,r-l+1);
    if(saved[subs].size() >= k){
        //cout<<"命中缓存";
        return saved[subs][k-1];
    }
    int last;
    if (saved[subs].size() == 0){
        last = 0;
    }else{
        last = saved[subs][saved[subs].size()-1];
    }
    for(register int i = saved[subs].size(); i < k; ++i){
        if(last + r-l+1 > N) return -1;
        last = kmp(s,subs,last);
        //last = s.find(subs, last);
        //cout<<last<<endl;
        if(last == -1){
            saved[subs].push_back(last);
            return -1;
        }
        last += 1;

        saved[subs].push_back(last);
    }
    return last;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        map<string, vector<int> > tt;
        saved = tt;
        cin>>N>>Q;
        cin>>s;
        for(register int i = 0; i < Q; ++ i){
            cin>>l>>r>>k;
            cout<<solve()<<endl;
        }
    }
    return 0;
}