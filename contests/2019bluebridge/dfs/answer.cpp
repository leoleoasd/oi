#include <iostream>
#define NUM 5
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
typedef node *nodePtr;
#define MAXN 10010

int front[MAXN] = {0};
int medium[MAXN] = {0};

nodePtr buildTree(int fl, int ml, int size){
    if(size <= 0) return nullptr;
    int lsize = 0;
    while(medium[ml + lsize] != front[fl]){
        lsize++;
    }
    int rsize = size-lsize-1;
    auto n = new node;
    n->data = front[fl];
    n->left = buildTree(fl+1,ml,lsize);
    n->right = buildTree(fl+lsize+1,ml+lsize+1,rsize);
    return n;
}

void dfs(nodePtr root){
    if(root == nullptr){
        return;
    }
    dfs(root->left);
    dfs(root->right);
    cout<<root->data<<" ";
}

void freeTree(nodePtr root){
    if(root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main(){
    int t;
    int n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; ++ i){
            cin>>front[i];
        }
        for(int i = 0; i < n; ++ i){
            cin>>medium[i];
        }
        nodePtr root = buildTree(0,0,n);
        dfs(root);
        freeTree(root);
        cout<<endl;
    }
    return 0;
}