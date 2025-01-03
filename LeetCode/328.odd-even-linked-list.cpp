/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (61.69%)
 * Likes:    10284
 * Dislikes: 546
 * Total Accepted:    1.1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered
 * list.
 * 
 * The first node is considered odd, and the second node is even, and so on.
 * 
 * Note that the relative order inside both the even and odd groups should
 * remain as it was in the input.
 * 
 * You must solve the problem in O(1) extra space complexity and O(n) time
 * complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [2,1,3,5,6,4,7]
 * Output: [2,3,6,7,1,5,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the linked list is in the range [0, 10^4].
 * -10^6 <= Node.val <= 10^6
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        else if(head->next == nullptr || head->next->next == nullptr){
            return head;
        }
        
        else{
            ListNode* ref = head;
        // myInput.printLinkedList(ref);
            ListNode* temp = new ListNode(ref->val);
            ListNode* ref1 = temp;
            ref = ref->next->next;
            int count = 1;
            while(ref != nullptr){
                if(count%2){
                    ListNode* n = new ListNode(ref->val);
                    temp->next = n;
                    temp = n;

                }
                count++;
                ref = ref->next;
            }
            count = 1;
            ref = head->next;
            temp->next = ref->next;
            while(ref != nullptr){
                if(count%2){
                    ListNode* n = new ListNode(ref->val);
                    temp->next = n;
                    temp = n;

                }
                count++;
                ref = ref->next;

            }
            return ref1;
        }
        
    }
};
// @lc code=end

