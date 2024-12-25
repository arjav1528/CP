/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (39.04%)
 * Likes:    10060
 * Dislikes: 1482
 * Total Accepted:    1.1M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, rotate the list to the right by k
 * places.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 500].
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
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
    ListNode* findNthNode(ListNode* head,int n){
        int count = 1;
        while(head != nullptr){
            if(count == n){
                return head;
            }
            count++;
            head = head->next;
        }
        return head;

    }
    int findLen(ListNode* head){
        int count = 0;
        while(head != nullptr){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k==0){
            return head;
        }
        int len = findLen(head);
        if(k%len == 0){
            return head;
        }
        k = k%len;

        ListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = head;
        ListNode* newLastNode = findNthNode(head,len-k);
        head = newLastNode->next;
        newLastNode->next = nullptr;
        return head;
        

    
        
    }
};
// @lc code=end

