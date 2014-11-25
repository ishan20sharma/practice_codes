#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

/* Sorting Technique */
bool checkAnagramSorting(string &str1, string &str2) {
	/* Anagrams should have equal length */
	if(str1.length() != str2.length())
		return false;

	/* Sort both the strings */
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	/* Compare both the strings */
	for(int i = 0; i < str1.length(); ++i) {
		if(str1[i] != str2[i])
			return false;
	}

	return true;
}

int main() {
	string str1 = "";
	string str2 = "";

	if(checkAnagramSorting(str1, str2))
		cout << "Strings are anagrams" << endl;
	else
		cout << "Strings are not anagrams" << endl;

	return 0;
}
