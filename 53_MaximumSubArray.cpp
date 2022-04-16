#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int nums_len = nums.size();
        if (nums_len == 1) return nums[0];
        int Max_Sum = nums[0];
        int This_Sum = 0;
        for (int i = 0; i < nums_len; i++){
            This_Sum += nums[i];
            Max_Sum = max(This_Sum, Max_Sum);
            This_Sum = max(This_Sum, 0);
        }

        return Max_Sum;
    }
};
int main(){
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution1 s1;
    ofstream outfile;
    outfile.open("Q53.txt");
    outfile << s1.maxSubArray(nums) << endl;
    outfile.close();
    return 0;
}