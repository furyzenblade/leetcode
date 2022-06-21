#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	static string longestPalindrome(string s) {
		string res = "";
		int resLen = 0;

		for (int i = 0; i < s.length(); i++) {
			//odd length
			int l = i, r = i;
			while (l >= 0 && r < s.length() && s[l] == s[r]) { //check if out of bounds and if palindrome
				if ((r - l + 1) > resLen) { //check if length of palindrome is grater than current result
					res = s.substr(l, (r - l) + 1); //update result
					resLen = r - l + 1;
				}
				l -= 1; //expand pointers
				r += 1;
			}

			//even length
			l = i; r = i + 1;
			while (l >= 0 && r < s.length() && s[l] == s[r]) { //same checks
				if ((r - l + 1) > resLen) {
					res = s.substr(l, (r - l) + 1);
					resLen = r - l + 1;
				}
				l -= 1;
				r += 1;
			}
		}
		return res;
	}
};

void main() {
	string s = "cbbd";
	string output = Solution::longestPalindrome(s);
	cout << output << endl;
	return;
}
