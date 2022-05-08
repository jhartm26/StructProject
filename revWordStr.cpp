//C++ program to reverse a string by words
//By: Jacob Hartmann
#include <iostream>
#include <string>

using namespace std;

//Function used to reverse a string from index lhs to rhs
void reverse(string& s, int lhs, int rhs) {
	while (lhs < rhs) {
		//Swap characters at lhs and rhs
		swap(s[lhs], s[rhs]);
		lhs++;
		rhs--;
	}
}

//Function to reverse the given string
string reverseString(string str) {
	//Add space at the end so that the last word is also reversed
	str.insert(str.end(), ' ');
	int n = str.length();
	int j = 0;

	//Find spaces and reverse all words before that
	for (int i = 0; i < n; i++) {
		//If a space is encountered
		if (str[i] == ' ') {
			//Function call to our custom reverse function()
			reverse(str, j, i - 1);
			//Update the starting index for next word to reverse
			j = i + 1;
		}
	}
	//Remove spaces from the end of the word that we appended
	str.pop_back();
	//Reverse the whole string
	reverse(str, 0, str.length() - 1);
	//Return the reversed string
	return str;
}

//Driver code
int main() {
	string str = "I will reverse in C++";
	//Function call
	string rev = reverseString(str);
	//Print the reversed string
	cout << rev;
	return 0;
}
