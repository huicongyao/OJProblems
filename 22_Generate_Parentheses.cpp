#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <climits>
using namespace std;
class Solution1 {
    void backtrack(vector<string> & ans, string &cur, int open, int close, int n) {
        if (cur.size() == n*2){
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            // 优先推入左括号，可以保证不会重复
            cur.push_back('(');
            backtrack(ans, cur, open+1, close, n);
            // pop撤销本次操作，是一个回溯的过程（注意传入的是cur的引用）
            cur.pop_back();
        }
        if (close < open) {
            // 右括号的个数小于左括号的时候，才能推入右
            cur.push_back(')');
            backtrack(ans, cur, open, close+1, n);
            // pop撤销本次操作，是一个回溯的过程（注意传入的是cur的引用）
            cur.pop_back();
        }
    }
    // 对于pop的作用，可以通过画递归树理解。
public:
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        string current;
        backtrack(ans, current, 0, 0, n);
        return ans;
    }
};

int main(){
    Solution1 s1;
    vector<string> ans = s1.generateParenthesis(5);
    for (int i = 0; i < ans.size(); i++){
        cout << "[\"" << ans[i] << "\"]\n";
    }
    cout << endl;
    return 0;
}