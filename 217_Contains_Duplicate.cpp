#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

// 解法1，先排序再查重
class Solution1 {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        for (auto p = nums.begin(); p != nums.end(); p++){
            auto q = p+1;
            if (q != nums.end() && *q == *p) return true;

        }
        return false;
    }
};

// 解法2，哈希表
class Solution2 {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::map<int, int> imap;
        int key = 0;
        for (std::vector<int>::iterator p = nums.begin(); p != nums.end(); p++){
            if (imap.find(*p) != imap.end())
                return true;    // 返回真，说明找到了
            imap[*p] = key++;
        }
        return false;
    }
};
// 实际上这题用set更合适
class Solution3 {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};
int main(){
    std::vector<int> nums{1,1,1,3,3,4,3,2,4,2};
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    std::cout << s1.containsDuplicate(nums) << std::endl;
    std::cout << s2.containsDuplicate(nums) << std::endl;
    std::cout << s3.containsDuplicate(nums) << std::endl;
    return 0;
}   