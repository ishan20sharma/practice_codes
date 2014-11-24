#include<iostream>
#include<string>
#include<vector>


using namespace std;

/* Builds the partial match table */
void buildTable(vector<int> &table, string &pattern) {
	int pos = 2; /* The current position we are computing in 'table' */
	int candidate = 0; /* the zero-based index in 'pattern' of the next character of the current candidate string */

	table[1] = 0;

	while(pos < pattern.length()) {
		/* first case: the substring continues */
		if(pattern[pos-1] == pattern[candidate]) {
			candidate++;
			table[pos] = candidate;
			pos++;
		}
		/* second case: it doesn't, but we can fall back */
		else if(candidate > 0) {
			candidate = table[candidate];
			//candidate--;
		}
		/* third case: we have run out of candidates.  Note cnd = 0 */
		else {
			table[pos] = 0;
			pos++;
		}
	}

	/* Print Partial match table */
	cout << "Partial Match table is :" << endl;
	for(vector<int>::iterator it = table.begin(); it != table.end(); ++it)
		cout << *it << " | ";

	cout << endl;
}

void kmpSearch(string &text, string &pattern, const vector<int> &table) {
	int m = 0; /* Beginning index of current match int 'text' */
	int i = 0; /* The position of the current character in 'pattern' */
	vector<int> matches; /* Starting indexes in 'text' where 'pattern' matches */

	while(m + i < text.length()) {
		if(text[m + i] == pattern[i]) {
			/* Complete pattern matched */
			if(i == pattern.length() - 1) {
				matches.push_back(m);	
				m = m + i + 1;
				i = 0;
			}
			/* Partial pattern match */
			else {
				i++;
			}
		}
		else {
			if(table[i] > -1) {
				m = m + i - table[i];
				i = table[i];
			}
			else {
				i = 0;
				m++;
			}		
		}
	}
	
	/* Print the beginning indexes in 'text' where 'pattern' matches */ 
	cout << "The matches are: " << endl;
	for(vector<int>::iterator it = matches.begin(); it != matches.end(); ++it) {
		cout << *it << endl;
	}
	cout << endl;
}	


int main() {
	string text = "AABAACAADAABAAABAA";
	string pattern =  "AABA";
	vector<int> table(pattern.size(), -1); /* Partial match table */

	buildTable(table, pattern); /* Build partial match table */

	kmpSearch(text, pattern, table); /* KMP search operation */

	return 0;
}
