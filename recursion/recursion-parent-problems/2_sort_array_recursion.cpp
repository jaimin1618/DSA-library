#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>& v, int tmp) {
	int n = v.size();

	if(n == 0 || v[n - 1] <= tmp) {
		v.push_back(tmp);
		return;
	}

	int last = v[n - 1];
	v.pop_back();
	insert(v, tmp);
	v.push_back(last);
}

void sort(vector<int>& v) {
	int n = v.size();

	// base condition
	if(n == 1)
		return;

	// hypothesis
	int last = v[n - 1];
	v.pop_back();
	sort(v);

	// indexation
	insert(v, last);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> t1 {5, 1, 0, 2};
	vector<int> t2 {4, 3, 2, 1};
	sort(t1);
	sort(t2);

	for(auto& el: t1)
		cout << el << ' ';
	cout << endl;


	for(auto& el: t2)
		cout << el << ' ';

	
	return 0;
}