//source: https://www.youtube.com/watch?v=gdt7HQF56OI&t=529s

#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>
#include <numeric>

using namespace std;

//Leetcode 1641: Count Sorted Vowel Strings			18/5/21		runtime: 0ms,	memory: 6.5mb, complexity: O(5n)
int countVowelStrings(int n) {
	
	vector<vector<int>> vowelMatrix;

	vowelMatrix.push_back({ 1,1,1,1,1 });

	for (int i = 1; i < n; i++) {
		vector<int> temp;

		//count from behind(add i-1,j-1 to get the current vector value)
		for (int j = 4; j >= 0; j--) {
			if (j == 4)
				temp.push_back(1);
			else
				temp.insert(temp.begin(), vowelMatrix[i - 1][j] + temp[0]);
		}

		//store the number of valid pair for next pair calculation
		vowelMatrix.push_back(temp);
	}

	return accumulate(vowelMatrix[n-1].begin(), vowelMatrix[n-1].end(), 0);
}

int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	vector<int> v = { 1,2,5 };
	cout << countVowelStrings(33);


	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
