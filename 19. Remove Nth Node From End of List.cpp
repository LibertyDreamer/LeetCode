/*

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

 

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz

  */


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> list;
        ListNode* original_head = head;
        while(head != nullptr)
        {
            list.push_back(head);
            head = head->next;
        }

        if(list.size() == n)
        {
            if(list.size() == 1) return nullptr;
            original_head = original_head->next;
        }else{
            if(n == 1) list[list.size() - n - 1]->next = nullptr;
            else
            list[list.size() - n - 1]->next = list[list.size() - n + 1];
        }

        return original_head;
    }
};
