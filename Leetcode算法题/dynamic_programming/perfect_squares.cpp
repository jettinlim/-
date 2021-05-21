//https://leetcode.com/problems/perfect-squares/
//https://www.youtube.com/watch?v=1xfx6M_GqFk&t=187s

#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>
#include <numeric>

using namespace std;

//Leetcode 279:	Perfect Squares		21/5/21     runtime: 75.51%,	memory: 46.60%,		complexity: O(n)
int numSquares(int n) {

	vector<int> dp(n + 1);
	
	for (int i = 0; i <= n; i++) {
		if (i <= 3)
			dp[i] = i;
		else {
			int _min = n;

			for (int j = 1; j * j <= i; j++) {
				_min = min(dp[i - j * j] + 1, _min);
			}

			dp[i] = _min;
		}
	}

	return dp[n];
}

int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	cout << numSquares(10);

	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
