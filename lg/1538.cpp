#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
char numbers[10][5][5] = {
    {
        "  - ",
        " | |",
        "    ",
        " | |",
        "  - "
    },
    {
        "    ",
        "   |",
        "    ",
        "   |",
        "    "
    },
    {
        "  - ",
        "   |",
        "  - ",
        " |  ",
        "  - "
    },
    {
        "  - ",
        "   |",
        "  - ",
        "   |",
        "  - "
    },
    {
        "    ",
        " | |",
        "  - ",
        "   |",
        "    "
    },
    {
        "  - ",
        " |  ",
        "  - ",
        "   |",
        "  - "
    },
    {
        "  - ",
        " |  ",
        "  - ",
        " | |",
        "  - "
    },
    {
        "  - ",
        "   |",
        "    ",
        "   |",
        "    "
    },
    {
        "  - ",
        " | |",
        "  - ",
        " | |",
        "  - "
    },
    {
        "  - ",
        " | |",
        "  - ",
        "   |",
        "  - "
    }
};
int size = 0;
string input;
int data[300] = {0};
int length = 0;
int now = 0;
int main(){
    cin>>size>>input;
    length = input.size();
    for(int i=0;i<length;++i){
        data[i] = input[i] - '0';
    }
    // 输出第一行
    for(int i = 0;i < length; ++i){
        now = data[i];
        i != 0 && cout<<numbers[now][0][0];
        cout<<numbers[now][0][1];
        for(int j = 0; j < size; ++j){
            cout<<numbers[now][0][2];
        }
        cout<<numbers[now][0][3];
    }
    cout<<endl;
    // 输出上半部分
    for(int asd = 0; asd < size; ++asd){
        for(int i = 0; i < length; ++ i){
            now = data[i];
            i != 0 && cout<<numbers[now][1][0];
            cout<<numbers[now][1][1];
            for(int j = 0; j < size; ++j){
                cout<<numbers[now][1][2];
            }
            cout<<numbers[now][1][3];
        }
        cout<<endl;
    }
    // 输出中间
    for(int i = 0;i < length; ++i){
        now = data[i];
        i != 0 && cout<<numbers[now][2][0];
        cout<<numbers[now][2][1];
        for(int j = 0; j < size; ++j){
            cout<<numbers[now][2][2];
        }
        cout<<numbers[now][2][3];
    }
    cout<<endl;
    // 输出下半部分
    for(int asd = 0; asd < size; ++asd){
        for(int i = 0; i < length; ++ i){
            now = data[i];
            i != 0 && cout<<numbers[now][3][0];
            cout<<numbers[now][3][1];
            for(int j = 0; j < size; ++j){
                cout<<numbers[now][3][2];
            }
            cout<<numbers[now][3][3];
        }
        cout<<endl;
    }
    // 输出中间
    for(int i = 0;i < length; ++i){
        now = data[i];
        i != 0 && cout<<numbers[now][4][0];
        cout<<numbers[now][4][1];
        for(int j = 0; j < size; ++j){
            cout<<numbers[now][4][2];
        }
        cout<<numbers[now][4][3];
    }
    cout<<endl;
    return 0;
}

/**
      --   --        --   --   --   --   --   --
   |    |    | |  | |    |       | |  | |  | |  |
   |    |    | |  | |    |       | |  | |  | |  |
      --   --   --   --   --        --   --
   | |       |    |    | |  |    | |  |    | |  |
   | |       |    |    | |  |    | |  |    | |  |
      --   --        --   --        --   --   --
       --   --        --   --   --   --   --   --
    |    |    | |  | |    |       | |  | |  | |  |
    |    |    | |  | |    |       | |  | |  | |  |
       --   --   --   --   --        --   --
    | |       |    |    | |  |    | |  |    | |  |
    | |       |    |    | |  |    | |  |    | |  |
       --   --        --   --        --   --   --



*/