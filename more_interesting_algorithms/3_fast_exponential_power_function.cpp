#include<bits/stdc++.h>
using namespace std;
const long long MOD = (long long) 10e9 + 7;

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int countGoodNumbers(long long n) {
        // use fast exponentiation to calculate x^y % mod
        auto quickmul = [](int x, long long y) -> int {
            int ret = 1, mul = x;
            while (y > 0) {
                if (y % 2 == 1) {
                    ret = (long long)ret * mul % mod;
                }
                mul = (long long)mul * mul % mod;
                y /= 2;
            }
            return ret;
        };

        return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
    }
};

// FAST MODULAR EXPONENTIAL function - function to calculate X^Y % MOD
int 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << power(2, 2) << endl;
	cout << power(2, 3) << endl;
	
	return 0;
}