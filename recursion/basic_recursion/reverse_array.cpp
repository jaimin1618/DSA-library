#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& v) {
	int n = v.size();
	int begin = 0, end = n - 1;

	while(begin < end) {
		swap(v[begin], v[end]);
		begin++;
		end--;
	}
}

// recursive
void reverseArray(vector<int>& v, int begin, int end) {
	if(begin < end) {
		swap(v[begin], v[end]);
		reverseArray(v, begin + 1, end - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {1, 2, 3, 4, 5};
	reverseArray(v);
	for(auto& el: v)
		cout << el << ' ';

	cout << endl;

	reverseArray(v, 0, v.size() - 1);
	for(auto& el: v)
		cout << el << ' ';



	
	return 0;
}