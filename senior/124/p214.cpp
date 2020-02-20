#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


int com(string s, int pos, string s2)
{
    int index = pos-1;
    for(int i = s2.length()-1; i >= 0; --i)
    {
        if(s2[i] != s[index--])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int num;
    cin >> num;
    int f[300];
    while(num--)
    {
        f[0] = 0;
        for(int i = 1; i < 300; ++i)
        {
            f[i] = 1000000;
        }
        string s;
        cin >> s;
        int n;
        cin >> n;
        vector<string> v;
        for(int i = 0; i < n; ++i)
        {
            string str;
            cin >> str;
            v.push_back(str);
        }
        for(int i = 1; i <= (int)s.length(); ++i)
        {
            for(int j = 0; j <(int)v.size(); ++j)
            {
                int length = v[j].length();
                if(i < length)
                {
                    continue;
                }
                else if(com(s,i,v[j]))
                {
                    f[i] = min(f[i],f[i-length]+1);
                    //cout << "f[" << i << "]    " << f[i] << endl;
                }
            }
        }
        cout << f[s.length()] << endl;
    }
    return 0;
}