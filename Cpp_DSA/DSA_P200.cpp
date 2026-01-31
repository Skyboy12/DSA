#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& a, int left, int mid, int right){
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right){
        if (a[i] <= a[j]){
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid){
        temp[k++] = a[i++];
    }
    while (j <= right){
        temp[k++] = a[j++];
    }
    for (int i = 0; i < k; i++){
        a[left + i] = temp[i];
    }
}

void merge_sort(vector<int>& a, int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        merge_sort(arr, 0, n - 1);
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}