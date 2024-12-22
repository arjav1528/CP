/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (44.80%)
 * Likes:    32323
 * Dislikes: 6483
 * Total Accepted:    5.2M
 * Total Submissions: 11.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 * 
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
    int countLength(ListNode* head){
        int count = 0;
        while(head != nullptr){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(countLength(l1) >= countLength(l2)){
            ListNode* temp1 = (l1);
            ListNode* temp2 = (l2);
            ListNode* final = temp1;
            int carry = 0;
            while(temp1 != nullptr && temp2 != nullptr){
                temp1->val += (temp2->val) + carry;
                carry = (temp1->val)/10;
                temp1->val %= 10;
                if(temp1->next == nullptr && temp2->next == nullptr && carry!=0){
                    ListNode* h = new ListNode(carry%10);
                    carry = carry/10;
                    temp1->next = h;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            if(temp1!= nullptr){
                while(temp1 != nullptr){
                    temp1->val += carry;
                    carry = (temp1->val)/10;
                    temp1->val %= 10;
                    
                    if((temp1->next == nullptr) && (carry != 0)){
                        ListNode* h = new ListNode((carry%10));
                        carry = carry/10;
                        temp1->next = h;
                    }
                    temp1 = temp1->next;
                }       
            }
            return final;
        
        }
        else{
            ListNode* temp1 = (l2);
            ListNode* temp2 = (l1);
            ListNode* final = temp1;
            int carry = 0;
            while(temp1 != nullptr && temp2 != nullptr){
                temp1->val += (temp2->val) + carry;
                carry = (temp1->val)/10;
                temp1->val %= 10;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            if(temp1!= nullptr){
                while(temp1 != nullptr){
                    temp1->val += carry;
                    carry = (temp1->val)/10;
                    temp1->val %= 10;
                    
                    if((temp1->next == nullptr) && (carry != 0)){
                        ListNode* h = new ListNode((carry%10));
                        carry = carry/10;
                        temp1->next = h;
                    }
                    temp1 = temp1->next;
                }
                
            }
            return final;
        }
    }
};
// @lc code=end

