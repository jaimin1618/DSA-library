#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> t {4, 5, 5, 5, 7, 8, 9};
    cout << lower_bound(t.begin(), t.end(), 5) - t.begin() << endl; // checks for <= 5
    cout << upper_bound(t.begin(), t.end(), 5) - t.begin() << endl; // checks for > 5

    return 0;
}