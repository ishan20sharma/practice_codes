/*
    Check if One String is a Rotation of Other String
    If s1 = crazyforcode then the following are some of its rotated versions:
    "forcodecrazy"
    "codecrazyfor"
*/

#include<iostream>
#include<string>


using namespace std;

bool checkRotation(string &str1, string &str2) {
	string str3 = str1 + str1;

	if(str3.find(str2) != string::npos)
		return true;
	else 
		return false;
}

int main() {
	string str1 = "crazyforcode";
	string str2 = "codeforcrazy";

	if(checkRotation(str1, str2))
		cout << "str2 is rotated string" << endl;
	else
		cout << "str2 is not rotated string" << endl;

	return 0;
}
