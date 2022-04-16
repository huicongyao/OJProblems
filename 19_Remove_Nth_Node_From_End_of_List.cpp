#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <climits>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};
// 个人解法，利用vector存储遍历过的节点的指针，这样可以直接一遍遍历删除节点
// 但是没有引入哑节点（或者空头结点），删除的时候需要分类讨论。
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> ptr_node;
        ListNode *p = head;
        while (p){
            // 指针元素推入vector
            ptr_node.push_back(p);
            p = p->next;
        }
        int len_ptr = ptr_node.size();
        // 取前驱节点
        if (len_ptr-n-1 >= 0){
            ListNode *l = ptr_node[len_ptr-n-1];
            ListNode *q = l->next;
            l->next = l->next->next;
        }
        // 如果没有前驱，说明要删除的是head
        else{
            head = head->next;
        }
        return head;
    }
};
// 官方双指针解答，增加了哑结点，处理起来相对更方便
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    for (int i = 0; i < 2; i++) cout << vec[i] << endl;
    cout << 'f' << endl;
    return 0;
}