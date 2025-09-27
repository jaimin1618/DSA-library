#include<bits/stdc++.h>
using namespace std;

// ANOTHER SOLUTION OF SAME PROBLEM - for edge case: 1 2 3 5 1 13 3, window=5
vector<long> solve(vector<long>& v, int k) {
    int n = v.size();
    using pp = pair<int, int>;
    priority_queue<pp, vector<pp>, greater<pp>> q;
    
    int i = 0, j = 0;
    vector<long> ans;
    
    while(j < n) {
        while(!q.empty() && q.top().first > v[j]) {
            q.pop();
        }
        q.push({v[j], j});
        
        if(j - i + 1 == k) {
            int mn = q.top().first;
            ans.push_back(mn);
            
            if(mn == v[i]) {
                q.pop();
            }
            
            ++i;
        }
        
        ++j;
    }
    
    return ans;
}


vector<int> maximumOfAllSubarray(vector<int>& v, int k) {
	const int n = v.size();
	list<int> ls;
	vector<int> op;
	int i = 0, j = 0;

	while(j < n) {
		// calculations
		while(!ls.empty() && ls.front() < v[j])
			ls.pop_front();
		ls.push_back(v[j]);


		if(j - i + 1 < k) {
			++j;

		} else if(j - i + 1 == k) {
			// get answer
			int mx = ls.front();
			op.push_back(mx);

			// slide the window ++i
			if(mx ==  v[i]) 
				ls.pop_front();

			++i;
			++j;
		}
	}

	return op;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> ip {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;

	ip.assign({1,3,1,2,0,5});
	k = 3;

	for(auto& el: maximumOfAllSubarray(ip, k))
		cout << el << ' ';

	return 0;
}