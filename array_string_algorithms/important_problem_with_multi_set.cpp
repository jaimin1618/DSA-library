#include<bits/stdc++.h>
using namespace std;
// link: https://www.hackerrank.com/contests/dsa-decoded-learning-path/challenges/concert-tickets-2/copy-from/1398276383

int main() {
    int n = 5, m = 3;
    vector<int> t {5, 3, 7, 8, 5}; // tickets
    vector<int> customers {4, 8, 3};

    multiset<int> tickets;

    for (int i = 0; i < n; i++) {
    	int h = t[i];
        tickets.insert(h);
    }

    // 5, 3, 7, 8, 5
    // 3, 5, 5, 7, 8
    for(int i = 1; i <= 10; ++i) {
    	auto it = tickets.upper_bound(i); // first element > t
    	cout << i << ": " << *it << " is begin: " << (it == tickets.begin()) << " is end: " << (it == tickets.end()) << endl;
    }
    cout << "\n\n";

    for (int i = 0; i < m; i++) {
        int customer = customers[i];

        auto it = tickets.upper_bound(customer); // first element > t

        if (it == tickets.begin()) {
            cout << -1 << "\n";
        } else {
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
    
    return 0;
}
