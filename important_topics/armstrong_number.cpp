#include<bits/stdc++.h>
using namespace std;

int isArmstrong(int num) {
	int temp = num;
	int len = 1 + log10(num);
	int result = 0;

	while(num > 0) {
		int digit = num % 10;
		result += (int)pow(digit, len);
		num /= 10;
	}

	return result == temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout << isArmstrong(371) << endl;
	cout << isArmstrong(1) << endl;
	cout << isArmstrong(10) << endl;
	
	return 0;
}