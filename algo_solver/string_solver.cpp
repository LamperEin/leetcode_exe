#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int strStr(string haystack, string needle) {
    
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

int lengthOfLongestSubstring(string s) {
    if(s.size() < 2) return s.size();
    int maxlen = 1;
    int count = 1;
    bool is_break = false;
    for (int i = 1; i < s.size(); i++) {
        if(s[i-1] != s[i] && !is_break)
            count++;
        else if(s[i-1] == s[i] && !is_break) {
            is_break = true;
            count = 1;
        }
        if(maxlen < count) maxlen = count;
    }

    return maxlen;
}

int main() {
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    cout << lengthOfLongestSubstring(s1) << endl;
    cout << lengthOfLongestSubstring(s2) << endl;
    cout << lengthOfLongestSubstring(s3) << endl;
    return 0;
}