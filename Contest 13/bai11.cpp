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
void rightLevelOrder(Node *root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if (curr->right) q.push(curr->right);
        if (curr->left) q.push(curr->left);
    }
}
main(){
	int t,n,i,x;
	cin>>t;
	while(t--){
		Node* root = NULL;
		cin>>n;
		for(i=1;i<=n;i++){
			cin >> x;
			insert(root, x);
		}
		rightLevelOrder(root);
		cout<<endl;
	}
}
