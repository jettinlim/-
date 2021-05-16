#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>

using namespace std;

//Leetcode 1309: Decrypt String from Alphabet to Integer Mapping		8/5/2021		runtime: 4ms,	memory: 6.4mb
string freqAlphabets(string s) {

	//Mapping method
	map<string, char> decrypt;
	int count = 1;
	string result;

	for (char i = 'a'; i <= 'z'; i++) {
		if (i < 'j')
			decrypt[to_string(count++)] = i;
		else
			decrypt[to_string(count++) + '#'] = i;
	}

	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '#') {
			string temp = string(1, s[i - 2]) + string(1, s[i - 1]) + '#';		//avoid ascii
			i -= 2;
			result.insert(0, string(1, decrypt[temp]));
		}
		else
			result.insert(0, string(1, decrypt[string(1, s[i])]));
	}

	return result;
}

string freqAlphabets_v2(string s) {		//8/5/2021		

	string result;

	//ascii method		runtime: 4ms,	memory: 6.4mb
	/*for (int i = 0; i < s.length(); i++) {
		if (i + 2 < s.length() && s[i + 2] == '#') {
			char alp = (s[i] - '0') * 10 + s[i + 1] - '0' + 96;
			i += 2;
			result += alp;
		}
		else {
			char alp = s[i] - '0' + 96;
			result += alp;
		}
	}*/

	//ascii method(without auto iteration)		runtime: 0ms,	memory: 6.1mb, memory complexity: O(N)
	for (int i = 0; i < s.length();) {
		if (i + 2 < s.length() && s[i + 2] == '#') {
			char alp = (s[i] - '0') * 10 + s[i + 1] - '0' + 96;		//to get alphabet from an ascii
			i += 3;
			result += alp;
		}
		else {
			char alp = s[i++] - '0' + 96;
			result += alp;
		}
	}

	return result;
}



int main()
{
	auto t1 = chrono::high_resolution_clock::now();
  
  	string s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";
	cout << freqAlphabets_v2(s);


	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
