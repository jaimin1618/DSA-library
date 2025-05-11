#include<bits/stdc++.h>
using namespace std;

void printNameNTimes(string s, int n) {
	if(n == 0)
		return; 

	cout << s << endl;
	printNameNTimes(s, n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	printNameNTimes("Jaimin Chokhawala", 10);
	
	return 0;
}