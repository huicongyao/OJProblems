#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <climits>
using namespace std;
// 朴素解法小幅优化，会超时。。。
class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int nums_len = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums_len; i++){
            if (i>0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < nums_len; j++){
                if (j>i+1 && nums[j] == nums[j-1]) continue;
                for (int k = j+1; k < nums_len; k++){
                    if (k > j+1 && nums[k] == nums[k-1]) continue;
                    for (int l = k+1; l < nums_len; l++){
                        if (l>k+1 && nums[l] == nums[l-1]) continue;
                        long sum = (long)nums[i]+(long)nums[j]+(long)nums[k]+(long)nums[l];
                        if (sum > INT_MAX || sum < INT_MIN) continue;
                        if (sum == target)
                            ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    }
                }
            }
        }
        return ans;
    }
};
// 官方给的解法，emm。。。
class Solution2 {
public:
    vector<vector<int>> foutSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        if (nums.size() < 4)
            return quadruplets;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length - 3; i++){
            // 去重复
            if (i > 0 && nums[i] == nums[i-1]) continue;
            // 最小的四个数和都大于taget时，直接出循环
            if ((long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            // 如果最大的数都小于target，跳过这个i
            if ((long)nums[i] + nums[length-3] + nums[length-2] + nums[length-1] < target) continue;
            for (int j = i+1; j < length - 2; j++){
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] > target) break;
                if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) continue;
                for (int j = i + 1; j < length - 2; j++){
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                    if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                    if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) continue;
                    // 前两的循环用遍历加上去重复和剪枝，后两个用双指针代替，充分降低复杂度
                    int left = j + 1, right = length - 1;
                    while (left < right){
                        int sum = nums[i] + nums[j] + nums[left] + nums[right];
                        if (sum == target) {
                            quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                            // 去重复
                            while (left < right && nums[left] == nums[left+1]) left++;
                            left++;
                            // 去重复
                            while (left < right && nums[right] == nums[right-1]) right--;
                            right--;
                        } else if (sum < target) left++;
                        else right--;
                    }
                    
                }
            }
        }
        return quadruplets;
    }
};



int main(){
    Solution1 s1;
    vector<int> nums{1,0,-1,-2,2};
    int target = 0;
    // cout << s1.fourSum(nums,target) << endl;
    return 0;
}