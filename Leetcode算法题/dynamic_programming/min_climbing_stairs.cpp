#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>

using namespace std;


//Leetcode 746: Min Cost Climbing Stairs(Brute Force)		9/5/2021		O(n^2) Bad efficiency
int minCostClimbingStairs(vector<int>& cost, int currentNum = 0, int index = 0) {

	if (index == 0)
		auto it = cost.insert(cost.begin(), 0);

	if (index >= cost.size() - 2)
		return currentNum;
	else
		return currentNum + min(minCostClimbingStairs(cost, cost[index + 1], index + 1), minCostClimbingStairs(cost, cost[index + 2], index + 2));
}

//13/5/2021			runtime: 8ms,	memory: 13.8mb	O(N)

using VT = vector<int>;

int minCostClimbingStairs_v2(VT& A) {

	int N = A.size();
	VT dp(N);
	dp[0] = A[0];
	dp[1] = A[1];

	for (int i = 2; i < N; ++i)
		dp[i] = A[i] + min(dp[i - 1], dp[i - 2]);

	return min(dp[N - 1], dp[N - 2]);
}


int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	vector<int> v = { 1,2,5,7,9 };
	cout << minCostClimbingStairs_v2(v);


	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
