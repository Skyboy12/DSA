#include <bits/stdc++.h>

using namespace std;

string fortune_number = "86";

void check_valid_print(){
    if (!(fortune_number.front() == '8' && fortune_number.back() == '6')) return;
    if(fortune_number.find("88") != string::npos) return;
    if(fortune_number.find("6666") != string::npos) return;
    cout << fortune_number << endl;
}

void Solution(int n){
    if (fortune_number.size() == n){
        check_valid_print();
        return;
    }
    fortune_number.push_back('6');
    Solution(n);
    fortune_number.pop_back();
    fortune_number.push_back('8');
    Solution(n);
    fortune_number.pop_back();
}

int main(){
    int n;
    cin >> n;
    Solution(n);
    return 0;
}