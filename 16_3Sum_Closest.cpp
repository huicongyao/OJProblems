#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
using namespace std;
// 先排序，再遍历，中间去掉一些重复项，对暴力解法进行小幅度优化
class Solution1 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 注意题目的意思应该是元素不能重复
        int closest = nums[0]+nums[1]+nums[2];
        int nums_len = nums.size();
        if (nums_len == 3) return closest;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums_len; i++){
            // 去掉重复的部分
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < nums_len; j++){
                //去掉重复部分
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                for (int k = j+1; k < nums_len; k++){
                    int sum = nums[i] + nums[j] +nums[k];
                    if (abs(sum-target)<abs(closest-target)) closest = sum;
                }
            }
        }
        return closest;
    }
};