/****************************************************
* Given an input string s and a pattern p, implement 
* regular expression matching with support for '.' 
* and '*' where:
* '.' Matches any single character.​​​​
* '*' Matches zero or more of the preceding element.
* The matching should cover the entire input string 
* (not partial).
*
* constraints:
* 1. s contains only lowercase English letters.
* 2. p contains only lowercase English letters, '.', and '*'.
* 3. It is guaranteed for each appearance of the character '*', 
*    there will be a previous valid character to match.
*****************************************************/
#include <iostream>
#include <cctype>
#include <vector>
using namespace std;
// 失败的方案，理论上应该是可行的，但是各种情况处理起来太多复杂
// class Solution1 {
// public:
//     bool isMatch(string s, string p) {
//         bool ret = true;
//         int len_s = s.length(), len_p = p.length();
//         int i, j;
//         for (i = 0, j = 0; i < len_s && j < len_p; ){
//             // 都是字母，直接对比
//             if (std::isalpha(s[i]) && std::isalpha(p[j])){
//                 // 发现不匹配，返回false
//                 if (!(s[i] == p[j])) return false;
//                 i++; j++;
//             }
//             // 只有s[i]是字母
//             else if (p[j] == '*' && p[j-1] == '.'){
//                 if (j+1 == len_p) return true;
//                 else {
//                     for (int k = 1; len_p-k != j; k--){
                        
//                     }
//                 }
//             }
//         }

//         return true;

//     }
// };


// 官方动态规划解法
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        // lambda function declaration
        auto matches = [&](int i, int j) {
            // 边界条件，当s长度是零的时候，返回false
            if (i == 0) {
                return false;
            }
            // 只要p中第j个元素是'.'就一定匹配，返回true
            if (p[j - 1] == '.') {
                return true;
            }
            // 返回除去以上两种情况后s[i]和p[j]的比较结果
            return s[i - 1] == p[j - 1];
        };
        // 个人理解，dp形式上类似于将递归写法
        // 额外开辟的空间实现，可能现在题目见的少，后面再理解理解
        // 声明一个(m+1)(n+1)数组
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        // 注意两个空字符串是可以匹配的，但是题目限制s, p的长度至少为1
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            // j从1开始遍历
            for (int j = 1; j <= n; ++j) {
                // p[j-1]是'*'
                if (p[j - 1] == '*') {
                    // 不匹配字符+星号组合
                    // 下面的‘|=’代表或运算的简写，实际上等价于 f[i][j] = (f[i][j] || f[i][j-2])
                    // 两者只要有一个为真，结果为真，这里应该等价于直接把f[i][j-2]的结果赋给f[i][j]
                    // 所以这个或运算也可以不加
                    f[i][j] |= f[i][j - 2]; 
                    // 如果s中第i个元素和p中第j-1个元素匹配，
                    // 下面的‘|=’代表或运算的简写，实际上等价于 f[i][j] = (f[i][j] || f[i-1][j])
                    // 两者只要有一个为真，结果为真
                    // 由于有上一个命令“ f[i][j] |= f[i][j - 2]; ”，以下命令实际上等价于f[i][j] = (f[i-1][j] || f[i][j-2])
                    if (matches(i, j - 1)) f[i][j] |= f[i - 1][j];
                }
                else {
                    // s中第i个与p中第j个匹配，f[i][j] = f[i-1][j-1]
                    // 和上面83行同理，或运算符号可以不加
                    if (matches(i, j)) f[i][j] |= f[i - 1][j - 1];
                }
            }
        }
        return f[m][n];
    }
};

// 某大佬题解，还没有仔细阅读
class Solution3{
public:
    bool isMatch(string s, string p){
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,false));
        dp[0][0] = true;
        // 处理边界条件
        for (int i = 2; i <= n; i++){
            if (p[i-1] == '*') dp[0][i] = dp[0][i-2];
        }
        for ( int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (p[j-1] == "*") 
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2]=='.'));
                else 
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.'); 
            }
        }
        return dp[m][n];
    }
}
int main(){
    string s, p;
    Solution2 solution;
    while ( true ){
        cout << "Input two strings: ";
        cin >> s >> p;
        bool result = solution.isMatch(s, p);
        if (result) cout << "True\n";
        else cout << "False\n";
    }
    return 0;
}