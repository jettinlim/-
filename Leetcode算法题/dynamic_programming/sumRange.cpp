#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>

using namespace std;

//Leetcode 303: Range Sum Query - Immutable		17/5/21			
int sumRange(int left, int right) {
	vector<int> NumArray = { -2, 0, 3, -5, 2, -1 };
  
  //create a memory to store previous result
	vector<int> dp(NumArray.size());

	dp[0] = NumArray[0];
  
  //Store subproblems
	for (int i = 1; i < NumArray.size(); i++)
		dp[i] = NumArray[i] + dp[i - 1];
  
  //result in memory index minus starting index
	return dp[right] - (left > 0 ? dp[left-1] : 0);
}

int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	vector<int> v = { 1,2,5 };
	cout << sumRange(3, 5);


	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
