#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'

vector<string> data11[70]{
    {
        "impossible"
    },
    {
        "impossible"
    },
    {
        "impossible"
    },
    {
        "impossible"
    },
    {
        "ABBC",
        "ABBC",
        "AACC",
        "DDDD",
    },
    {
        "XXXTr",
        "XTTTr",
        "XTErr",
        "mmEEr",
        "mmmEE"
    },
    {
        "ABBBBC",
        "ADBCCC",
        "ADBCCE",
        "ADEEEE",
        "ADEFFF",
        "ADDFFF",
    },
    {
        "abbbcdd",
        "aebcccd",
        "aebcccd",
        "aebfddd",
        "aebffff",
        "aeggggf",
        "aeegggf",
    },
    {
        "ABBBBBCC",
        "ADBBBFFC",
        "ADFFFFFC",
        "ADFECCCC",
        "ADEEEEHH",
        "ADGEEEHH",
        "ADGGGGHH",
        "ADDGGGHH",
    },
    {
        "ABBBBBBCC",
        "ADBBBECCC",
        "ADEEEECCC",
        "ADEEEEFCF",
        "ADGHHFFFF",
        "ADGHHHFFF",
        "ADGHHHIII",
        "ADGGGHIII",
        "ADDGGGIII",
    },
    {
        "AEEEEEGGGG",
        "ABEFFFGGGG",
        "ABEFFFFGGH",
        "ABEFFFIIIH",
        "ABEJJJIIHH",
        "ABEJJJIIHH",
        "ABJJJJIIHH",
        "ABDDDDDIHH",
        "ABDDDDDCCC",
        "ABBCCCCCCC"
    }
};

int jd,n;
char fh;
char ls[70][5];
void add()
{
    if(fh=='9')fh='a';
    else if(fh=='z')fh='A';
    else fh++;
}
void gz3()
{
    for(int i=0;i<n-1;i++)ls[i][0]=fh;
    ls[jd][1]=fh;
    add();
    ls[n-1][0]=fh;
    for(int i=jd+1;i<n;i++)ls[i][1]=fh;
    for(int i=n-1,j=0;j<jd;i--,j++)ls[i][2]=fh;
    add();
    for(int i=0;i<jd;i++)ls[i][1]=fh;
    for(int i=0;i<n-jd;i++)ls[i][2]=fh;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)cout<<ls[j][i];
        cout<<'\n';
    }
    add();
    jd++;
}
void gz4()
{
    for(int i=0;i<n-1;i++)ls[i][0]=fh;
    ls[jd][1]=fh;
    add();
    ls[n-1][0]=fh;
    for(int i=jd+1;i<n;i++)ls[i][1]=fh;
    ls[n-1][2]=fh;
    for(int i=0,j=n-1;i<jd-1;i++,j--)ls[j][3]=fh;
    add();
    for(int i=0;i<jd;i++)ls[i][1]=fh;
    ls[0][2]=fh;
    for(int i=0;i<n-jd-1;i++)ls[i][3]=fh;
    add();
    for(int i=1;i<n-1;i++)ls[i][2]=fh;
    for(int i=n-jd-1;i<n-jd+1;i++)ls[i][3]=fh;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)cout<<ls[j][i];
        cout<<'\n';
    }
    jd++;
}

void solve(){
    cin>>n;
    if(n > 10){
        jd=1;fh='0';
        if(n<=3)
        {
            cout<<"impossible\n";
            return;
        }
        if(n%3==0)
        {
            for(int t=n;t!=0;t-=3)gz3();
        }
        else if(n%3==1)
        {
            for(int i=0;i<n;i++)cout<<fh;
            cout<<'\n';
            add();
            for(int t=n-1;t!=0;t-=3)gz3();
        }
        else if(n%3==2)
        {
            for(int i=0;i<n;i++)cout<<fh;
            cout<<'\n';
            add();
            for(int t=n-5;t!=0;t-=3)gz3();
            gz4();
        }
    } else {
        for(auto &i: data11[n]){
            cout<<i<<endl;
        }
    }

}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}