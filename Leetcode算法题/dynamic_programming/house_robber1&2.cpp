#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>

using namespace std;

//Leetcode 198: House Robber		13/5/21			runtme: 0ms, memory: 7.7mb	O(N)
int maxRob(VT& V) {

	int N = V.size();
	VT dp(N);

	if (N == 1)
		return V[0];
	else if (N == 2)
		return max(V[0], V[1]);

	dp[0] = V[0];
	dp[1] = V[1];
	dp[2] = V[2] + V[0];

	for (int i = 3; i < N; ++i)
		dp[i] = V[i] + max(dp[i - 2], dp[i - 3]);

	return max(dp[N - 1], dp[N - 2]);
}

//Leetcode 213: House Robber 2		13/5/21			runtime: 0ms, memory: 8mb	O(N)
int maxRob_2(VT V) {

	int N = V.size();
	VT dp_0(N), dp_1(N);

	if (N == 1)
		return V[0];
	else if (N == 2)
		return max(V[0], V[1]);

	//starting index 0
	dp_0[0] = V[0];
	dp_0[1] = V[1];
	dp_0[2] = V[2] + V[0];

	for (int i = 3; i < N - 1; ++i)
		dp_0[i] = V[i] + max(dp_0[i - 2], dp_0[i - 3]);


	//starting index 1
	dp_1[0] = 0;
	dp_1[1] = V[1];
	dp_1[2] = V[2];

	for (int i = 3; i < N; ++i)
		dp_1[i] = V[i] + max(dp_1[i - 2], dp_1[i - 3]);

	return max(max(dp_0[N - 2], dp_0[N - 3]), max(dp_1[N - 2], dp_1[N - 3]));
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
