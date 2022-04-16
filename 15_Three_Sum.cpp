#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len_num = nums.size();
        // 排序，便于进行去重
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < len_num; i++){
            // 去重复
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int k = len_num-1;
            for (int j = i+1; j < len_num; j++){
                // 去重复
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                // 从后向前查找
                while (k > j && nums[k]+nums[j] > target) k--;
                // 这一组i里面没有找到
                if (k == j) break;
                // 如果找到，此时应该都是unique的，加入数组
                if (nums[k]+nums[j] == target)  
                    ans.push_back({nums[i],nums[j],nums[k]});
            }
        }
        return ans;
    }
};