#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool isVariable = false;
    string value;
    char op = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

static void skipSpaces(const string& s, int& i) {
    while (i < (int)s.size() && s[i] == ' ') {
        ++i;
    }
}

static Node* parseExpression(const string& s, int& i);

static Node* parseFactor(const string& s, int& i) {
    skipSpaces(s, i);
    if (i < (int)s.size() && s[i] == '(') {
        ++i;
        Node* node = parseExpression(s, i);
        skipSpaces(s, i);
        if (i < (int)s.size() && s[i] == ')') {
            ++i;
        }
        return node;
    }

    string token;
    while (i < (int)s.size() && isupper(static_cast<unsigned char>(s[i]))) {
        token += s[i];
        ++i;
    }

    Node* node = new Node();
    node->isVariable = true;
    node->value = token;
    return node;
}

static Node* makeOperatorNode(char op, Node* left, Node* right) {
    Node* node = new Node();
    node->isVariable = false;
    node->op = op;
    node->left = left;
    node->right = right;
    return node;
}

static Node* parseExpression(const string& s, int& i) {
    Node* left = parseFactor(s, i);

    while (true) {
        skipSpaces(s, i);
        if (i >= (int)s.size() || s[i] == ')') {
            break;
        }

        char op = s[i];
        if (op != '+' && op != '-') {
            break;
        }
        ++i;

        Node* right = parseFactor(s, i);
        left = makeOperatorNode(op, left, right);
    }

    return left;
}

static string buildExpression(const Node* node, char parentOp = 0, bool isRightChild = false) {
    if (node->isVariable) {
        return node->value;
    }

    string left = buildExpression(node->left, node->op, false);
    string right = buildExpression(node->right, node->op, true);

    string result = left + node->op + right;
    if (parentOp == '-' && isRightChild) {
        return '(' + result + ')';
    }
    return result;
}

static void deleteTree(Node* node) {
    if (!node) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

static string removeUnnecessaryBracketsAndSpaces(const string& s) {
    int i = 0;
    Node* root = parseExpression(s, i);
    string result = buildExpression(root);
    deleteTree(root);
    return result;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--){
        string s;
        getline(cin, s);
        cout << removeUnnecessaryBracketsAndSpaces(s) << '\n';
    }
    return 0;
}