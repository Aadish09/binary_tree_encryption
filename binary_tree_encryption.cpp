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
        arr1[i]=char(int(arr[i])+i+2);
        arr1[i+1]=char(int(arr[i+1])+i+1);
        
    }
   
    return arr1;
}
Node * level_2_e(char *arr1){
    
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
string cypher_text(Node* root) 
{ string s="";
    if (root == NULL) 
        return; 
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
    string cypher = cypher_text(level_2_e(level_1_e(s,arr,arr1)));
    cout<<"The cypher text is :"<<cypher;
    return 0;
}

