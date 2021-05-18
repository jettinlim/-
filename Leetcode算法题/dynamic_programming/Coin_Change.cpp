#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>

using namespace std;

//Leetcode 322: Coin Change		14/5/21			runtime: 56ms,	memory: 14.4mb
int coinChange(vector<int>& coins, int amount) {

	vector<int> dp(amount + 1);

	dp[0] = 0;

	for (int i = 1; i <= amount; ++i) {

		int min = amount + 1;
		for (int n : coins) {
			if (i - n >= 0 && dp[i - n] < min) {
				min = dp[i - n] + 1;
			}
		}

		dp[i] = min;
	}

	return dp[amount];
}

int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	vector<int> v = { 1,2,5 };
	cout << coinChange(v, 11);


	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
