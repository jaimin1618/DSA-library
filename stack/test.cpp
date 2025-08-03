#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int> maxH;

    maxH.push(1);
    maxH.push(2);
    maxH.push(3);
    cout << maxH.top() << endl;
    maxH.pop();
    cout << maxH.top() << endl;

    return 0;
}