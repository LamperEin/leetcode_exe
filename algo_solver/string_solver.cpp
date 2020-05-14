#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <climits>

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

<<<<<<< HEAD
int expendAroundCenter(string& s, int left, int right) {
    int l = left;
    int r = right;
    while(l >= 0 && r < s.size() && s[r] == s[l]) {
        l--;
        r++;
    }
    return r-l-1;
}

string longestPalindrome(string s) {
    if(s.size() < 2) return s;
    int len = s.size();
    int max_start = 0;
    int max_end = 0;
    int max_len = 0;

    for(int i = 0; i < len; i++) {
        int len1 = expendAroundCenter(s, i, i);
        int len2 = expendAroundCenter(s, i, i+1);
        max_len = max(max(len1, len2), max_len);
        if(max_len > max_end - max_start+1) {
            max_start = i - (max_len - 1)/2;
            max_end = i + max_len/2;
        }
    }
    
    return s.substr(max_start, max_len);
=======
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

>>>>>>> 84f23360f2eec80ea5f507a0bcbbca3e56f61ca6
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

bool isNumber(string s) {
        //1、从首尾寻找s中不为空格首尾位置，也就是去除首尾空格
    int i=s.find_first_not_of(' ');
    if(i==string::npos)return false;
    int j=s.find_last_not_of(' ');
    s=s.substr(i,j-i+1);
    if(s.empty())return false;

        //2、根据e来划分底数和指数
    int e=s.find('e');

        //3、指数为空，判断底数
    if(e==string::npos)return judgeP(s);

        //4、指数不为空，判断底数和指数
    else return judgeP(s.substr(0,e))&&judgeS(s.substr(e+1));
}

bool judgeP(string s)//判断底数是否合法
{
    bool result=false,point=false;
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        if(s[i]=='+'||s[i]=='-'){//符号位不在第一位，返回false
            if(i!=0)return false;
        }
        else if(s[i]=='.'){
            if(point)return false;//有多个小数点，返回false
            point=true;
        }
        else if(s[i]<'0'||s[i]>'9'){//非纯数字，返回false
            return false;
        }
        else{
            result=true;
        }
     }
    return result;
}

bool judgeS(string s)//判断指数是否合法
{   
    bool result=false;
        //注意指数不能出现小数点，所以出现除符号位的非纯数字表示指数不合法
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='+'||s[i]=='-'){//符号位不在第一位，返回false
            if(i!=0)return false;
        }
        else if(s[i]<'0'||s[i]>'9'){//非纯数字，返回false
            return false;
        }
        else{
            result=true;
        }
    }
    return result;
}

int myAtoi(string str) {
    unsigned long len = str.length();

    int idx = 0;
    while(idx < len && str[idx] == ' ') idx++;
    if (idx == len) return 0;
    int sign = 1;
    if(str[idx] == '+') idx++;
    else if(str[idx] == '-') {
        sign = -1;
        idx++;
    }

    int ans = 0;
    while(idx < len) {
        char cur_char = str[idx];
        if(cur_char < '0' || cur_char > '9') break;

        if(ans > INT_MAX/10 || (ans == INT_MAX/10 && (cur_char - '0') > INT_MAX % 10)) 
            return INT_MAX;
        if(ans < INT_MIN/10 || (ans == INT_MIN/10 && (cur_char - '0') > -(INT_MIN % 10)))
            return INT_MIN;
        ans = ans*10 + sign * (cur_char - '0');
        idx++;
    }
    return ans;
}
int main() {
   //string s = "HG[3|B[2|CA]]F";
    //string s;
    //getline(cin, s);
    //cout << stringUnzip(s) << endl;

    return 0;
}