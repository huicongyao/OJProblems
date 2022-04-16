#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution1{
public:
    int maxArea(vector<int>& height){
        int n = height.size();
        int maxArea = 0;
        int h;
        int step;
        int compare_area = 0;
        for (int i = 0; i < n; i++){
            while ( (i<n) && height[i] == 0) i++;
            if (i >= n) break;
            step = maxArea / height[i];
            for (int j = i+step+1; j < n; j++){
                h = height[i] < height[j] ? height[i] : height[j];
                compare_area = h * (j-i);  
                maxArea = maxArea > compare_area ? maxArea : compare_area;
            }
        }
        return maxArea;
    }
};

// 借鉴官方思路，双指针
// 应该是目前能找到的最简便方法
// 这种思路本质上也是一种递归，对于这种思路能找到最大Area的严格证明值得细琐
class Solution2{
public:
    int maxArea(vector<int> &height){
        int n = height.size();
        int max = 0, compare = 0;
        int i = 0, j = n-1;
        int h;
        while (i < j){
            h = min(height[i], height[j]);
            compare = (j-i)*h;
            max = max > compare ? max : compare;
            if (height[i] > height[j]) j--;
            else i++;
        }
        return max;
    }
};

int main(){
    vector<int> height{0,14,6,2,10,9,4,1,10,3};
    Solution1 s1;
    Solution2 s2;
    cout << s1.maxArea(height) << endl;
    cout << s2.maxArea(height) << endl;
    return 0;
}