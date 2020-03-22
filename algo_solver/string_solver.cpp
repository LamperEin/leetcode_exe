#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>

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

int lengthOfLongestSubstring(string s) {
    int maxlen = 0;
    int curlen = 0;
    map<char, int> table;
    int idx = 0;
    while(idx < s.size()) {
        if(table.find(s[idx]) != table.end())
            curlen = max(curlen, table[s[idx]]+1);
        table[s[idx++]] = idx;
        maxlen = max(idx-curlen, maxlen);
    }
    return maxlen;
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

int longestPalindrome(string s) {
    unordered_map<char, int> count;
    int ans = 0;
    for (char c : s)
        ++count[c];
    for (auto p : count) {
        int v = p.second;
        ans += v / 2 * 2;
        if (v % 2 == 1 and ans % 2 == 0)
            ++ans;
    }

}

string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) return "";
    return str1.substr(0, __gcd((int)str1.length(), (int)str2.length())); 
}

string compressString(string S) {
    if(S.size() <= 1) return S;
    string ans;
    int cnt = 0, len = S.size();
    int i = 0, j = 1;
    while(i < len ) {
        if(S[i] == S[j])
            ++j;
        else if(S[i] != S[j] || j == len) {
            ans += S[i] + to_string(j-i);
            ++j;
            i = j - 1;
        }
    }
    if(ans.size() >= len) return S;
    return ans;
}

int countCharacters(vector<string>& words, string chars) {
    unordered_map<char, int> chars_cnt;
    for (char c : chars)
        ++chars_cnt[c];
    int ans = 0;
    for (string word : words) {
        unordered_map<char, int> word_cnt;
        for (char c : word)
            ++word_cnt[c];
        bool is_ans = true;
        for (char c : word){
            if (chars_cnt[c] < word_cnt[c]) {
                is_ans = false;
                break;
            }
            if (is_ans)
                ans += word.size();
        }
    }
    return ans;
}

string reverseLeftWords(string s, int n) {
    return s.substr(n)+s.substr(0, n);
}

string reverseStr(string s) {
    int i = 0, j = s.size()-1;
    while(i < j) swap(s[i++], s[j--]);
    return s;
}

string reverseWords(string s) {
    int k = 0, idxr = s.size()-1;
    while(s[k] == ' ') k++;
    while(s[idxr] == ' ') idxr--;
    string tmp = "", ans = "";
    for(int i = k; i <= idxr; i++) {
        if(s[i] != ' ')
            tmp += s[i];
        else {
            while(s[i] == ' ') i++;
            i--;
            ans += reverseStr(tmp);
            ans += " "; tmp = "";
        }
    }
    ans += reverseStr(tmp);
    return reverseStr(ans);
}

char firstUniqChar(string s) {
    unordered_map<char, int> table;
    for(char c : s) {
        table[c]++;
    }
    for(char c : s) {
        if(table[c] == 1) return c;
    }
    return ' ';
}

string minNumber(vector<int>& nums) {
    vector<string> strs;
    string ans;
    for(int num : nums) 
        strs.push_back(to_string(num));
    sort(strs.begin(), strs.end(), [](string& a, string& b){
        return a+b < b+a;
    });
    for(string str : strs)
        ans += str;
    return ans;
}

int main() {
   //string s = "HG[3|B[2|CA]]F";
    //string s;
    //getline(cin, s);
    //cout << stringUnzip(s) << endl;

    return 0;
}