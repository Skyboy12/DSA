#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void insert(Node* &root,int x){
	if(root==NULL){
        root = new Node(x); return;
	}
    if(root->data > x) insert(root->left,x);
    if(root->data < x) insert(root->right,x);
}
void NRL(Node *root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	if(root->right) NRL(root->right);
	if(root->left) NRL(root->left);
}
main(){
	int t,n,i,a[1005];
	cin>>t;
	while(t--){
		Node* root = NULL;
		cin>>n;
		for(i=1;i<=n;i++){
			cin >> a[i];
			insert(root,a[i]);
		}
		NRL(root);
		cout<<endl;
	}
}
