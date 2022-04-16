#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
// specification for atoi
/************************************************************************************
* int atoi (const char * str);
* Convert string to integer
* Parses the C-string str interpreting its content as an integral number, 
* which is returned as a value of type int.
*
* The function first discards as many whitespace characters (as in isspace) 
* as necessary until the first non-whitespace character is found. Then, starting 
* from this character, takes an optional initial plus or minus sign followed by 
* as many base-10 digits as possible, and interprets them as a numerical value.
*
* The string can contain additional characters after those that form the integral 
* number, which are ignored and have no effect on the behavior of this function.
*
* If the first sequence of non-whitespace characters in str is not a valid integral 
* number, or if no such sequence exists because either str is empty or it contains only 
* whitespace characters, no conversion is performed and zero is returned.
**************************************************************************************/
using namespace std;
class Solution1{
public:
    int myAtoi(string s) {
        long limitation = 2147483648;
        int s_length = s.size();
        int i = 0, flag = 1;    // flag 标记正负，默认为+
        int ret = 0;
        long temp = 0;
        for (;s[i] == ' '; i++);    // 除去空格
        if (s[i] == '-'){
            flag = -1;
            i++;
        }
        else if (s[i] == '+')
            i++;
        while (i < s_length){
            int num = s[i]-48;
            if (num < 0 || num > 9)
                break;
            temp = temp * 10 + num;
            temp = temp > limitation ? limitation : temp;
            i++;
        }
        temp *= flag;
        temp = temp >= limitation ? limitation-1 : temp;
        ret = temp;
        return ret;
    }
};

// 以下是LC官方题解，利用自动机原理
class Automaton {
    // 不声明visibility, 默认为pravite
    string state = "start";
    // 哈希map
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        // 对应不同状态返回不同的数
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution2 {
public:
    int myAtoi(string str) {
        // 再函数内部声明一个自动机
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};
int main(){
    ofstream outfile;
    outfile.open("Q8.txt");
    string s;
    Solution1 so;
    int i = 1;
    while (getline(cin, s)){
        if (s == "q") break;
        int num1 = so.myAtoi(s);
        char buffer[200];
        strcpy(buffer,s.c_str());
        int num2 = atoi(buffer);
        outfile << "The " << i++ << "th input times" << endl;
        outfile << "Input string: " << s << endl;
        outfile << "num1 = " << num1 << endl;
        outfile << "num2 = " << num2 << endl;
        if (num1 == num2)
            cout << "true" << endl;
        else 
            cout << "false" << endl;
    }
    return 0;
}