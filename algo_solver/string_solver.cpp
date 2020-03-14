#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int strStr(string haystack, string needle) {
    
    return 0;
}

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0) return "";
    if(strs.size()==1) return strs[0];
    int len = strs.size(), flag = 1;
    string ref_str = strs[0], res; 
    char ch;
    for (int i = 0; i < ref_str.length()-1; i++) {
        ch = ref_str[i];
        for (int j = 1; j < len; j++) {
            if(strs[j][i] != ch) flag = 0;

        }
        if(flag) res += ch;
        else break;
    }
    return res;
}

string addBinary(string a, string b) {

/*     string s;
	s.reserve(a.size() + b.size());
	int c = 0, i = a.size() - 1, j = b.size() - 1;
	while(i >= 0 || j >= 0 || c == 1)
	{
		c += i >= 0 ? a[i--] - '0' : 0;
		c += j >= 0 ? b[j--] - '0' : 0;
		s.push_back((c & 1) + '0');
		c >>= 1;
	}
	reverse(s.begin(), s.end());
	return s; */
    string res;
    int j = b.length()-1, i = a.length()-1, carry = 0;
    while (!(i < 0 && j < 0)) {
        int a1, b1;
        i < 0 ? a1 = 0: a1 = a[i--] - '0';
        j < 0 ? b1 = 0: b1 = b[j--] - '0';
        if(a1+b1+carry <= 1) {
            res.insert(0, to_string(a1+b1+carry));
            carry = 0;
        }    
        else { 
            res.insert(0, to_string((a1+b1+carry)%2)); 
            carry = 1;
        }
    }
    if (carry == 1) res.insert(0, "1");
    return res;
}

bool isValid(string s) {
    if(s[0] == '\0') return true;
    stack<char> left_brackets;
    bool is_valid = true;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            left_brackets.push(s[i]);
        else if(!left_brackets.empty()) {
            if(s[i] == '}' && left_brackets.top() == '{')
                left_brackets.pop();
            else if (s[i] == ']' && left_brackets.top() == '[')
                left_brackets.pop();
            else if (s[i] == ')' && left_brackets.top() == '(')
                left_brackets.pop();
            else {
                is_valid = false;
                break;
            }
        } else {
            is_valid = false;
        }
    }
    if(left_brackets.empty() && is_valid == true)
        return true;
    return false;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;


    return res;
}

int lengthOfLongestSubstring(string s) {
    int res;

    return res;
}

string longestPalindrome(string s) {

}

so9tring gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) return "";
    return str1.substr(0, __gcd((int)str1.length(), (int)str2.length())); 
}

int main() {
    string str1 = "ABCABC", str2 = "ABC";
    cout << gcdOfStrings(str1, str2) << endl;
    string str3 = "ABABAB", str4 = "ABAB";
    cout << gcdOfStrings(str3, str4) << endl;
    str1 = "LEET", str2 = "CODE";
    cout << gcdOfStrings(str1, str2) << endl;
    return 0;
}