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
void postOrder(Node *root){
	if(root==NULL) return;
	if(root->left) postOrder(root->left);
	if(root->right) postOrder(root->right);
	cout<<root->data<<" ";
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
		postOrder(root);
		cout<<endl;
	}
}
