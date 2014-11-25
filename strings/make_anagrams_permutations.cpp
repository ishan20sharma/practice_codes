/*
  Build all permutations/anagrams of a string
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void buildAnagrams(string &str,const int &candidate) {
	if(candidate == str.length()) {
		cout << str << endl;
	}

	for(int next = candidate; next < str.length(); ++next) {
		swap(str[candidate], str[next]);
		buildAnagrams(str, candidate+1);
		swap(str[candidate], str[next]);
	}
}

int main() {
	string str = "abcd";
	int candidate = 0;

	buildAnagrams(str, candidate);

	return 0;
}
