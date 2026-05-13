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
void deleteNode(Node* &root, int x) {
	if (root == NULL) return;
	if (x < root->data) deleteNode(root->left, x);
	else if (x > root->data) deleteNode(root->right, x);
	else {
		if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			root = temp;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			root = temp;
		}
		else {
			Node* temp = root->right;
			while (temp->left != NULL) temp = temp->left;
			root->data = temp->data;
			deleteNode(root->right, temp->data);
		}
	}
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
	Node* root = NULL;
    int task;
    while (cin >> task) {
        if (task == 1) {
            int val; cin >> val;
            insert(root, val);
        } else if (task == 2) {
            int val; cin >> val;
            deleteNode(root, val);
        } else if (task == 3) {
            preOrder(root); cout << endl;
        } else if (task == 4) {
            inOrder(root); cout << endl;
        } else if (task == 5) {
            postOrder(root); cout << endl;
        }
    }
	return 0;
}
