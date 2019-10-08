#include<iostream>
#include<string>
using namespace std;

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

int kmp(string text,string pattern,int* pie = 0){
    bool flag = false;
    if(pie == 0){
        pie = pre_kmp(pattern);
        flag = true;
    }
	int matched_pos=0;
	for(int current=0; current< text.length(); current++)
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
    if(flag)
        delete pie;
    return -1;
}
int q;
string cxq,visitor;
int main(){
    ios::sync_with_stdio(false);
    cin>>cxq>>q;
    int* p = pre_kmp(cxq);
    while(q--){
        cin>>visitor;
        if(cxq.size() > visitor.size()){
            if(kmp(cxq, visitor) != -1){
                cout<<"my child!"<<endl;
                continue;
            }
            cout<<"oh, child!"<<endl;
            continue;
        }
        if(cxq.size() < visitor.size()){
            if(kmp(visitor,cxq,p) != -1){
                cout<<"my teacher!"<<endl;
                continue;
            }
            cout<<"senior!"<<endl;
            continue;
        }
        if(cxq == visitor){
            cout<<"jntm!"<<endl;
            continue;
        }
        cout<<"friend!"<<endl;
        continue;
    }
    return 0;
}