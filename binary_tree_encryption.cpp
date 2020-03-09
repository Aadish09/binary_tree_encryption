#include <stdio.h>
#include <bits/stdc++.h> 
#include<string>
#include<queue>
using namespace std;
class Node {
    public:
    char data;
    Node* left;
    Node * right;
};
char * level_1_e(string s,char*arr,char *arr1 ){
    
    
    strcpy(arr, s.c_str());
    
    for(int i=0;i<s.length();i+=2){
        int a=int(arr[i])+i+2;
        int b=int(arr[i+1])+i+1;
        arr1[i]=char(a);
        arr1[i+1]=char(b);
        
    }
    return arr1;
}
Node * make_tree(char *arr1){
    
    int n= sizeof(arr1)/sizeof(arr1[0]);
    queue<Node*> q;
    Node*t=NULL;
    int k=0;
    while(k<n){
    if(q.empty()){
        t= new Node;
        t->data=arr1[k++];
        t->left=NULL;
        t->right=NULL;
        q.push(t);
    }
    else{
    while(!q.empty()){
        Node * p = q.front();
        q.pop();
        Node * l= new Node;
        
        if(k<n){
        l->data=arr1[k++];
        l->left=NULL;
        l->right=NULL;
        p->left=l;
        q.push(l);}
        Node * m= new Node;
        if(k<n){
        m->data=arr1[k++];
        m->left=NULL;
        m->right=NULL;
        p->right=m;
        q.push(m);}
    }
    }
    }
    
    return t;
    
}
void preorder(Node *root1,Node* root2, int lvl) 
{ 
    if (root1 == NULL || root2==NULL) 
        return; 

    if (lvl%2 == 0) 
        swap(root1->data, root2->data); 
    preorder(root1->left, root2->right, lvl+1); 
    preorder(root1->right, root2->left, lvl+1); 
} 

Node* reverseAlternate(Node *root) 
{ Node*t=root;
   preorder(root->left, root->right, 0); 
   return t;
} 
string level2_d(char * arr,char * arr2){
    string s="";
    
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i+=2){
        arr2[i]=char(int(arr[i])-(i+2));
        arr2[i+1]=char(int(arr[i+1])-(i+1));
    }
    
    for(int i=0;i<n;i++){
        s=s+arr2[i];
    }
    return s;
}
string get_string(Node* root) 
{ string s="";
    if (root == NULL) 
        return NULL; 
    queue<Node*> n; 
    n.push(root); 
    while (!n.empty()) { 
        s=s+n.front()->data; 
        if (n.front()->left != NULL) 
            n.push(n.front()->left); 
        if (n.front()->right != NULL) 
            n.push(n.front()->right); 
        n.pop(); 
    } 
    
    return s;
}


int main()
{   
    string s;
    cout<<"Enter the word you want to encrypt :";
    getline(cin,s);
    if(s.length()%2!=0){s.push_back(' ');}
    int l=s.length();
    char arr[s.length()+1];
    char arr1[s.length()+1];
    char arr2[s.length()+1];
    // cout<<"Without :"<<get_string(make_tree(level_1_e(s,arr,arr1)))<<endl;
    string cypher = get_string(reverseAlternate(make_tree(level_1_e(s,arr,arr1))));
    cout<<"The cypher text is :"<<cypher;
    strcpy(arr, cypher.c_str());
    cout<<endl;
    
    strcpy(arr, get_string(reverseAlternate(make_tree(arr))).c_str());
    
    string plainText= level2_d(arr,arr2);
    cout<<"The plain text is :"<<plainText;
    return 0;
}





