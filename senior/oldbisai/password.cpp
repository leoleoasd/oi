#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
#define MAXN 9
string data[MAXN];
int m;
int t[MAXN]={0};
int py = 0;
string& get(int pos){
    return data[pos%m];
}
void cal_next(const char * strKey, int * next, int len){
    int calTimes = 2;
    int frontIndex=0;
    int backIndex = 0;
    
    for (frontIndex = 0; frontIndex < len; frontIndex++)
    {
        next[frontIndex] = 0;
    }
    frontIndex = calTimes-2;
    backIndex = calTimes-1;
    while (calTimes<=len)
    {
        while (frontIndex > 0 && strKey[backIndex] != strKey[frontIndex ])
        {
            if (next[calTimes - 1] != 0)
            {
                next[calTimes-1] = 0;
                backIndex = calTimes-1;
                break;
            }
            frontIndex--;
        }
        if (frontIndex == 0 && strKey[backIndex ] != strKey[0])
        {
            next[calTimes-1] =0;
            calTimes++;
            frontIndex = calTimes-2;
            backIndex = calTimes-1;
        }
        else if (frontIndex == 0 && strKey[backIndex ] == strKey[0])
        {
            next[calTimes - 1] +=1;
            calTimes++;
            frontIndex = calTimes-2;
            backIndex = calTimes-1;
        }
        else
        {
            if (frontIndex > 0 && strKey[backIndex ] == strKey[frontIndex ]) 
            {
                next[calTimes - 1]++;
                backIndex -= 1;
                frontIndex--;
            }
        }
    }
}
int kmp(const char * strText,const char *strKey){
    int *next = new int[strlen(strKey)];
    cal_next(strKey,next,strlen(strKey));
    int textLenght = strlen(strText);
    int keyLenght = strlen(strKey);
    int textIndex = 0;
    int keyIndex = 0;
    int successNums = 0;
    while (textIndex < textLenght)
    {
        while (textIndex <textLenght && strKey[keyIndex] != strText[textIndex])
        {
            if (keyIndex != 0)
            {
                textIndex -= next[keyIndex-1];
                keyIndex = 0;
            }else 
            textIndex++;
        }
        if (textIndex == textLenght )
        {
        }
        else if (strKey[keyIndex] == strText[textIndex])
        {
            keyIndex++;
            textIndex++;
            if (keyIndex == keyLenght)
            {
                keyIndex = 0;
                successNums++;
            }
        }
    }
    return successNums;
}
void read(){
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>data[i];
    }
    for(int i=0;i<m;++i){
        cin>>t[i];
        --t[i];
    }
}
int calcu(string & key){
    string temp;
    for(int i=0;i<m;++i){
        temp += get(t[i]+py);
    }
    cout<<temp<<endl;
    return kmp(temp.c_str(),key.c_str());
}
int main(){
    ios::sync_with_stdio(false);
    read();
    string temp("a");
    cout<<calcu(temp);//solve();
}