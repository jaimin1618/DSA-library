#include<bits/stdc++.h>
using namespace std;

// remember: 
// minH -> minimum element on top
// maxH -> maximum element on top simple. 

// One thing you need to remember comparator for minH/maxH are different. 

class MinHeapCompare {
public:
	bool operator()(int a, int b) {
		// it's a > b --> that could be quite confusing. 
		return a > b;
	}
};

class MaxHeapCompare {
public: 
	bool operator()(int a, int b) {
		return a < b;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<int, vector<int>, MinHeapCompare> minH;
	priority_queue<int, vector<int>, MaxHeapCompare> maxH;

	minH.push(1);
	minH.push(2);
	cout << minH.top() << endl; // 1

	maxH.push(1);
	maxH.push(2);
	cout << maxH.top() << endl; // 2 working! 
	

	return 0;
}