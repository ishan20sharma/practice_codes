#include<iostream>
#include<string>

using namespace std;

void reverseString(string &s, int wordBegin,int wordEnd);

void removeWhitespace(string &s) {
	int toRead = 0, toWrite = 0;
	bool preSpace = true;
	
	/* Clear the heading spaces, and reduce multiple spaces between two words to a single space.  */
	for(toRead; toRead < s.size(); toRead++) {
		if(s[toRead] == ' ') {
			/* Checks if this is the first whitespace character encountered */
			if(!preSpace) {
				s[toWrite++] = s[toRead];
				preSpace = true;
			}
		}
		else {
			s[toWrite++] = s[toRead];
			preSpace = false;
		}
	}

	/* Remove trailing whitespaces */
	if(s[toWrite -1] == ' ')
		toWrite--;

	s.erase(toWrite, s.size() - toWrite);
}

void reverseWords(string &s) {
	int index = 0;
	int wordBegin = 0; /* Starting index of a word in a sentence */
	int wordEnd = 0; /* Ending index of a word in a sentence */

	removeWhitespace(s);
	if(s.size() == 0)
		return;
	
	for(index; index < s.size(); ++index) {
		/* Check if the end of the word has been found */
		if(s[index] == ' ') {
			wordEnd = index-1;

			/* Reverse the word found */
			reverseString(s,wordBegin, wordEnd);
		}
		/* Check of beginning of word has been found */
		else if(s[index - 1] == ' ')
			wordBegin = index;
	}

	/* Reverse the last word */
	reverseString(s, wordBegin, s.size()-1);

	/* Reverse the whole sentence */
	reverseString(s, 0, s.size() - 1);
}

void reverseString(string &s, int wordBegin,int wordEnd) {
	char temp;

	for(wordBegin,wordEnd; wordBegin < wordEnd; ++wordBegin, --wordEnd) {
		temp = s[wordBegin];
		s[wordBegin] = s[wordEnd];	
		s[wordEnd] = temp;
	}
}

int main() {
	string sentence = "  This is a test sentence which   I have    to reverse   ";
	cout<< "Original sentence is " << endl << sentence << endl;
	reverseWords(sentence);
	cout << sentence << endl;
	return 0;
}
