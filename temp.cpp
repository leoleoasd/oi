#include<iostream>
using namespace std;
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
int main()
{
    int t;
    for(cin>>t;t>0;t--)
    {
        cin>>n;
        jd=1;fh='0';
        if(n<=3)
        {
            cout<<"impossible\n";
            continue;
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
    }
}