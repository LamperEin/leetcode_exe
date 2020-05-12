#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <cstring>
#include <limits>

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
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> table;
    if(strs.size() == 0) return ans;
    for(auto s : strs) {
        string t = s;
        sort(t.begin(), t.end());
        table[t].push_back(s);
    }
    for(auto& it : table) 
        ans.push_back(it.second);
    return ans;
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
    return ans;
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


bool isMatch(const char* s, const char* p) {
    if(*p == 0) return *s == 0;
    bool first_match = *s && (*s == *p || *p == '.');
    if(*(p+1) == '*')
        return isMatch(s, p+2) || (first_match && isMatch(++s, p));
    else return first_match && isMatch(++s, ++p);
}

void reverseString(char* s, int l, int r) {
    while(l <= r) {
        swap(s[l++], s[r--]);
    }
}

void leftRotate(char* s, int len, int m) {
    int k = len-m;
    k %= len;
    reverseString(s, 0, k-1);
    reverseString(s, k, len-1);
    reverseString(s, 0, len-1);
}

bool stringContain(string& a, string& b) {
    int hash = 0;
    for(int i = 0; i < a.length(); ++i) {
        hash |= (1 << (a[i]-'A'));
    }
    for(int i = 0; i < b.length(); ++i) {
        if(hash & (1 << (b[i]-'A')) == 0)
            return false;
    }
    return true;
}

// the helper function for longestContinueCharacter
int countCharacter(string& s, int& cnt, int& maxlen, int idx) {
    if(idx == s.size())
        return maxlen;
    if(s[idx-1] == s[idx])
        cnt++;
    else {
        maxlen = maxlen < cnt ? cnt: maxlen;
        cnt = 1;
    }
    return countCharacter(s, cnt, maxlen, idx+1);
}

/** 最长连续字符
 *  input: aaaabbcc -> output:4
 */
int longestContinueCharacter(string s) {
    if(s.size() == 0) return 0;
    int maxlen = 1, cnt = 1;
    
    return countCharacter(s, cnt, maxlen, 1);
}

/** leetcode-466 统计重复个数
 *  input: s1="abc", n1=4, s2="ab", n2=2
 *  output: 2
 */
int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    if (n1 == 0) 
        return 0;
    int s1cnt = 0, index = 0, s2cnt = 0;
    // recall 是我们用来找循环节的变量，它是一个哈希映射
    // 我们如何找循环节？假设我们遍历了 s1cnt 个 s1，此时匹配到了第 s2cnt 个 s2 中的第 index 个字符
    // 如果我们之前遍历了 s1cnt' 个 s1 时，匹配到的是第 s2cnt' 个 s2 中同样的第 index 个字符，那么就有循环节了
    // 我们用 (s1cnt', s2cnt', index) 和 (s1cnt, s2cnt, index) 表示两次包含相同 index 的匹配结果
    // 那么哈希映射中的键就是 index，值就是 (s1cnt', s2cnt') 这个二元组
    // 循环节就是；
    //    - 前 s1cnt' 个 s1 包含了 s2cnt' 个 s2
    //    - 以后的每 (s1cnt - s1cnt') 个 s1 包含了 (s2cnt - s2cnt') 个 s2
    // 那么还会剩下 (n1 - s1cnt') % (s1cnt - s1cnt') 个 s1, 我们对这些与 s2 进行暴力匹配
    // 注意 s2 要从第 index 个字符开始匹配
    unordered_map<int, pair<int, int>> recall;
    pair<int, int> pre_loop, in_loop;
    while (true) {
            // 我们多遍历一个 s1，看看能不能找到循环节
        ++s1cnt;
        for (char ch: s1) {
            if (ch == s2[index]) {
                index += 1;
                if (index == s2.size()) {
                    ++s2cnt;
                    index = 0;
                }
            }
        }
        // 还没有找到循环节，所有的 s1 就用完了
        if (s1cnt == n1) 
            return s2cnt / n2;
            // 出现了之前的 index，表示找到了循环节
        if (recall.count(index)) {
            auto [s1cnt_prime, s2cnt_prime] = recall[index];
                // 前 s1cnt' 个 s1 包含了 s2cnt' 个 s2
            pre_loop = {s1cnt_prime, s2cnt_prime};
                // 以后的每 (s1cnt - s1cnt') 个 s1 包含了 (s2cnt - s2cnt') 个 s2
            in_loop = {s1cnt - s1cnt_prime, s2cnt - s2cnt_prime};
            break;
        }
        else {
            recall[index] = {s1cnt, s2cnt};
        }
    }
    // ans 存储的是 S1 包含的 s2 的数量，考虑的之前的 pre_loop 和 in_loop
    int ans = pre_loop.second + (n1 - pre_loop.first) / in_loop.first * in_loop.second;
    // S1 的末尾还剩下一些 s1，我们暴力进行匹配
    int rest = (n1 - pre_loop.first) % in_loop.first;
    for (int i = 0; i < rest; ++i) {
        for (char ch: s1) {
            if (ch == s2[index]) {
                ++index;
                if (index == s2.size()) {
                    ++ans;
                    index = 0;
                }
            }
        }
    }
    // S1 包含 ans 个 s2，那么就包含 ans / n2 个 S2
    return ans / n2;
}

/** leetcode-76 最小覆盖子串
 *  input: S="ADOBECODEBANC", T="ABC"
 *  output:"BANC"
 */
string minWindow(string s, string t) {
    int left = 0, right = 0, n = t.size(), start = 0, minlen = INT_MAX;
    unordered_map<char, int> need;
    unordered_map<char, int> window;
    for(char c : t) need[c]++;

    int match = 0;
    while(right < s.size()) {
        char c1 = s[right];
        if(need.count(c1)) {
            window[c1]++;
            if(window[c1] == need[c1])
                match++;
        }
            right++;
        while(match == need.size()) {
            if(right - left < minlen) {
                minlen = right - left;
                start = left;
            }
            char c2 = s[left];
            if(need.count(c2)) {
                window[c2]--;
                if(window[c2] < need[c2])
                    match--;
            }
            left++;
        }
     }
    return minlen == INT_MAX ? "" : s.substr(start, minlen);
}

/** leetcode-438 找所有字母异位词
 *  @param: two string
 *  @return: all the anagrams start idx in the string s
 */
vector<int> findAnagrams(string s, string t) {
    unordered_map<char, int> need, window;
    for(char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    vector<int> ans;
    while(right < s.size()) {
        char c = s[right];
        right++;

        if(need.count(c)) {
            window[c]++;
            if(window[c] == need[c])
                valid++;
        }

        while(right - left >= t.size()) {

            if(valid == need.size())
                ans.push_back(left);
            char d = s[left];
            left++;

            if(need.count(d)) {
                if(window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    return ans;
}

/** leetcode-647 回文子串
 *  @param: a strign s
 *  @return: the number of palindrome substrings
 */
int countSubstring(string s) {
    // 中心拓展法
    return 0;
}

int main() {

    return 0;
}