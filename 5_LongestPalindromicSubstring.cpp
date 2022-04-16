#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
class Solution1{
private:
    // 这是一个判断是否是回文字串的函数，如果是，返回当前长度
    int is_palindromic(const std::string & s, int start, int end){
        for (int j = 0; j <= (end-start)/2; j++){
            if (s[start+j] != s[end-j])
                return -1;
        }
        return end-start+1;
    }
public:
    std::string longestPalindrome(std::string s){
        int i, j;
        const int n = s.size();
        int Max_index = 0, Max_Length = 1;  // 
        int begin, end;
        // 初始化数组
        int size[n];
        for (int i = 0; i < n; i++)
            size[i] = 0;
        if (n == 1)
        return s;
        for (i = 0; i < n; i++){
            for (j = i+Max_Length; j < n; j++){ 
                // 至少要从Max_Length开始找起（因为此时长度至少为j-i+1=Max_Length+1）
                // <= Max_Length的长度没有必要做判断
                if (is_palindromic(s, i, j) != -1){
                    Max_index = i;
                    Max_Length = j-i+1;
                }
            }
        }
        return s.substr(Max_index, Max_Length);
    }
};

// 下面这个官方解法和我自己的思想差不多，
class Solution2 {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }
        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
int main(){
    std::string s =  "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycs"
    "afogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusng"
    "kbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcaf"
    "ctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgid"
    "gcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrt"
    "cwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorka"
    "sebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypi"
    "cgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlm"
    "tmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjn"
    "civhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkc"
    "xknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspm"
    "fumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzra"
    "vzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldauc"
    "wruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinik"
    "zzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";

    // std::cout << s << std::endl;
    Solution1 s1;
    Solution2 s2;
    std::cout << s1.longestPalindrome(s) << std::endl;
    std::cout << s2.longestPalindrome(s) << std::endl;
    return 0;
}