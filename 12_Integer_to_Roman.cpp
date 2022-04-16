#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;
// 自己的超长代码解法，效率海星，不是很低
class Solution1 {
private:
    string Get(const string & a, const string & b, const string c, const int & num){
        switch (num){
            case 0:
                return ""; break;
            case 1:
                return a;
                break;
            case 2:
                return a+a;
                break;
            case 3:
                return a+a+a;
                break;
            case 4:
                return a+b;
                break;
            case 5:
                return b;
                break;
            case 6:
                return b+a;
                break;
            case 7:
                return b+a+a;
                break;
            case 8:
                return b+a+a+a;
                break;
            case 9:
                return a+c;
                break;
            default:
                return "";
                break;
        }
    }

public:
    string intToRoman(int num) {
        int k;
        int mark = 1;
        string s_ret;
        while (num > 0){
            k = num % 10;
            switch (mark){
                case 1:
                    s_ret = Get("I","V","X",k) + s_ret;
                    break;
                case 2:
                    s_ret = Get("X","L","C",k) + s_ret;
                    break;
                case 3:
                    s_ret = Get("C","D","M",k) + s_ret;
                    break;
                case 4:
                    s_ret = Get("M","","",k) + s_ret;
                    break;
                default:
                    break;     
            }
            num /= 10;
        }
        return s_ret;
    }
};
// 没啥好说的，两个粗暴简单的官方解法

const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

class Solution2 {
public:
    string intToRoman(int num) {
        string roman;
        for (const auto &[value, symbol] : valueSymbols) {
            // value的值从大到小排列，这样子刚好枚举完
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
};

// 直接全部枚举。。。。。
const string thousands[] = {"", "M", "MM", "MMM"};
const string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

class Solution3 {
public:
    string intToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};
int main(){
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    ofstream file_out;
    file_out.open("12Q.txt");
    for (int i = 1; i <= 3999; i++){        
        file_out << s1.intToRoman(i) << "\n";
        file_out << s2.intToRoman(i) << "\n"; 
        file_out << s3.intToRoman(i) << "\n"; 
    }
    file_out.close();
    return 0;
}