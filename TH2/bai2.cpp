#include <bits/stdc++.h>

using namespace std;

struct Token {
    string typeOperator;
    long long value;
    bool isOperator;
};

vector<Token> getOperatorsAndOperands(const string& s){
    vector<Token> res;
    string temp;
    istringstream iss(s);
    while (iss >> temp){
        Token t;
        if (temp == "+" || temp == "-" || temp == "*" || temp == "/"){
            t.isOperator = true;
            t.value = 0;
            t.typeOperator = temp;
        } else {
            t.isOperator = false;
            t.value = stoll(temp);
            t.typeOperator = "";
        }
        res.push_back(t);
    }
    return res;
}

long long evaluatePrefix(const vector<Token>& tokens){
    stack<long long> st;
    for (int i = static_cast<int>(tokens.size()) - 1; i >= 0; --i){
        const Token& token = tokens[i];
        if (!token.isOperator) {
            st.push(token.value);
        } else {
            if (st.size() < 2) {
                return 0;
            }
            long long a = st.top(); st.pop();
            long long b = st.top(); st.pop();
            long long res = 0;
            if (token.typeOperator == "+") {
                res = a + b;
            } else if (token.typeOperator == "-") {
                res = a - b;
            } else if (token.typeOperator == "*") {
                res = a * b;
            } else {
                res = a / b;
            }
            st.push(res);
        }
    }
    return st.empty() ? 0 : st.top();
}


int main(){
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--){
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string s;
        getline(cin, s);
        vector<Token> tokens = getOperatorsAndOperands(s);
        long long result = evaluatePrefix(tokens);
        cout << result << endl;
    }
    return 0;
}