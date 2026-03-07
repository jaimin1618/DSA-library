#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int> maxH;
    maxH.push(1);
    maxH.push(2);
    maxH.push(3);
    cout << maxH.top() << endl; // prints 3


    priority_queue<int, vector<int>, greater<int>> minH;
    minH.push(1);
    minH.push(2);
    minH.push(3);
    cout << minH.top() << endl; // prints 1
    

    return 0;
}