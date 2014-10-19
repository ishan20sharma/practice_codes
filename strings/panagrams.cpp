#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool panagrams(vector<char> &alphabets, string text) {
	if(text.size() < alphabets.size())
		return false;
	/* Convert the text to lowercase letters */
	transform(text.begin(), text.end(), text.begin(), ::tolower);

	/* Sort the text */
	sort(text.begin(), text.end());

	vector<char>::iterator it1 = alphabets.begin();
	string::iterator it2 = text.begin();
	while(it1!=alphabets.end()) {
		while(it2 != text.end()) {
			if(it1 == alphabets.end() -1 && it2 == text.end() -1 && *it1 == *it2) {
				return true;
			}
			else if(*it1 < *it2) {
				return false;
			}
			else if(*it1 > *it2 ) {
				*it2++;
			}
			else {
				it1++;
				it2++;
			}	
		}
		if(it1 != alphabets.end())
		return false;
	}
	return true;
}

int main() {
	vector<char> alphabets;

	//string text = "We promptly judged antique ivory buckles for the next prize";

	string text = "                                             ";
	/* Initialize the vector with lowercase alphabets */
	for(int i=0; i <=25; i++)
		alphabets.push_back(97+i);

	if(panagrams(alphabets,text))
		cout << "panagram" << endl;
	else
		cout << "not a panagram" << endl;
	return 0;
}
