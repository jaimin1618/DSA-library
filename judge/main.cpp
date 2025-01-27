#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& v, int key) {
    int n = v.size();
    int L = 0, R = n - 1, mid = -1;
    int lb = -1;

    while(L <= R) {
        mid = L + (R - L) / 1;

        if(v[mid] == key) {
            lb = mid;
            R = mid - 1;
        } else if(v[mid] > key) {
            R = mid - 1;
        } else if(v[mid] < key) {
            L = mid + 1;
        }
    }

    return lb;
}

int upperBound(vector<int>& v, int key) {
    int n = v.size();
    int L = 0, R = n - 1, mid = -1;
    int ub = -1;

    while(L <= R) {
        mid = L + (R - L) / 2;

        if(v[mid] == key) {
            ub = mid;
            L = mid + 1;
        } else if(v[mid] > key) {
            R = mid - 1;
        } else if(v[mid] < key) {
            L = mid + 1;
        }
    }

    return ub;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v {2, 4, 10, 10, 10, 14, 20};
    cout << lowerBound(v, 10) << endl;
    cout << upperBound(v, 10) << endl;
    cout << "occurence: " << upperBound(v, 10) - lowerBound(v, 10) + 1 << endl;
    
    return 0;
}