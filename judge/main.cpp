#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v {1, 2, 3};
    auto b = v.begin();
    cout << *b << endl;

    auto e = v.rbegin();
    cout << *e << endl;



    return 0;
}