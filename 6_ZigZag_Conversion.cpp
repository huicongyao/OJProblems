// zigzag conversion The string "PAYPALISHIRING" is written in a zigzag pattern
// on a given number of rows like this: (you may want to display this pattern
// in a fixed font for better legibility)
#include <iostream>
#include <string>
using namespace std;
class Solution1{
public:
    string convert(string s, int numRows){
        if(numRows <= 1)    return s;
        int len = s.size();
        // 循环的间隔 k
        int k = 2*numRows-2;
        string ret;
        int i = 0;
        while (i < numRows){
            int j = 0;
            while (i+j<len){
                ret += s[i+j];
                if (i > 0 && i < numRows-1 && k-i+j<len)
                    ret += s[k-i+j];
                j += k;
            }
            i++;
        }
        return ret;
    }
};
int main(){
    string s = "PAYPALISHIRING";
    Solution1 so;
    cout << "s = " << s << endl;
    cout << so.convert(s,3) << endl;
    return 0;
}