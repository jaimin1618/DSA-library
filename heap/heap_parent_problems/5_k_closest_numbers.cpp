#include<bits/stdc++.h>
using namespace std;

void printv(vector<int>& v) {
	for(int& el: v) 
		cout << el << ' ';
	cout << '\n';
}

/**
 * Find k closest numbers to given X:
 * Find k closest numbers to 7 in below example
 */

vector<int> k_closest_numbers(vector<int>& v, int X, int k) {
	const int n = (int) v.size();
	priority_queue<pair<int, int>> q; // max-Heap
	/**
	 * Why maxHeap?
	 * 
	 * here we want to find K closest elements to given X
	 * So, we do that getting diff with that X. 
	 * 
	 * [5, 6, 7, 8, 9], X = 7
	 * diff = [2, 1, 0, 1, 2]
	 * 
	 * now we want to remove high diff elements, so we want to put
	 * higher diff elements on top and remove if size > k
	 * 
	 * NOTE: 
	 * priority_queue<pair<int,int>> q;
	 * this data structure prioritize p.first element for sorting (putting it on top)
	 * we store X (element itself) in p.second so that we can retrieve when needed
	 * 
	 */

	for(int i = 0; i < n; ++i) {
		int diff = abs(v[i] - X);

		if(diff > 0) {
			auto p = make_pair(diff, v[i]); 
			q.push(p);
		}

		if(q.size() > k) {
			q.pop();
		}
	}

	vector<int> result;
	while(!q.empty()) {
		auto p = q.top();
		result.push_back(p.second);
		q.pop();
	}

	return result;
}

vector<int> kFarthestNumbers(vector<int>& v, int X, int k = 3) {
	// I want to keep numbers with more different & pop() closest numbers -> we require minH
	using pi = pair<int, int>;
	priority_queue<pi, vector<pi>, greater<pi>> minH;

	for(auto& number: v) {
		int diff = abs(number - X);

		if(diff > 0) {
			minH.push({diff, number});
		}


		if(minH.size() > k) {
			minH.pop();
		}
	}

	vector<int> result;
	while(!minH.empty()) {

		result.push_back(minH.top().second);
		minH.pop();
	}

	return result;
}

int main() {
	vector<int> v{5, 6, 7, 8, 9};
	int k = 2;
	int x = 6;
	
	vector<int> closestNumbers = k_closest_numbers(v, x, k);
	cout << "k clostest numbers: "; 
	printv(closestNumbers);

	vector<int> farthestNumbers = kFarthestNumbers(v, x, k);
	cout << "k farthest numbers: "; 
	printv(farthestNumbers);

	return 0;
}

/**
NOTE:
priority_queue<pair<int,int>> q;
this will be default maxHeap with KEY as comparator;
here we have taken difference as comparator for sorting & storing
*/