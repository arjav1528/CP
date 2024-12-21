/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (60.20%)
 * Likes:    11969
 * Dislikes: 374
 * Total Accepted:    925.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a linked list, return the list after sorting it in
 * ascending order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 5 * 10^4].
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 * 
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
 * (i.e. constant space)?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
        
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1 != nullptr){
            tail->next = l1;
        }
        if(l2 != nullptr){
            tail->next = l2;
        }
        return dummy->next;
    }
};
// @lc code=end

