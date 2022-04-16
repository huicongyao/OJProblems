#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> digit_to_letter {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jki"},
            {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
        };
        int len = digits.size();
        int len_ans = 1;
        for (int i = 0; i < len; i++)
            len_ans *= digit_to_letter[digits[i]].size();
        vector<string> ans(len_ans);
        if (len == 0) return ans;
        int length = len_ans;

        // 第一个for循环对字母组合的位数进行循环
        for (int i = 0; i < len; i++){
            // 第二个for对每个元素每一轮家的字母进行循环
            // 下面这种添加方法可以保证，遍历所有可能的序列
            // 具体的数学原理，自行分析
            int size = digit_to_letter[digits[i]].size();
            length = length / size;
            for (int j = 0; j < len_ans; j++){
                int k = (int)(j/length)%size;
                ans[j] += digit_to_letter[digits[i]][k];
            }
        }
        return ans;
    }
};
int main(){
    string digits = "2";
    Solution s;
    vector<string> ans = s.letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << "  ";
    }
    cout << endl;
    return 0;
}