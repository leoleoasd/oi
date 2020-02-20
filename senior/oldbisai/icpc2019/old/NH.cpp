#include <iostream>
#include <stack>
int main(){
    char t;
    stack<char> s;
    while((t=cin.get()) != EOF){
        if(t == '('){
            s.push(t);
        } else if(t == '{'){
            s.push(t);
        } else if(t == '['){
            s.push(t);
        } else if(t == ')'){
            if(s.size() > 0 and s.top() == '('){
                s.pop();
            }else{
                cout<<"No"<<endl;
                return 0;
            }
        } else if(t == '}'){
            if(s.size() > 0 and s.top() == '{'){
                s.pop();
            }else{
                cout<<"No"<<endl;
                return 0;
            }
        } else if(t == ']'){
            if(s.size() > 0 and s.top() == '['){
                s.pop();
            }else{
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}