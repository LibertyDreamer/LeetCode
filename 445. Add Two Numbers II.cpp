/*

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]

 

Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.

 

Follow up: Could you solve it without reversing the input lists?

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> list1, list2;

        while(l1 != nullptr){
            list1.push(l1->val);
            l1 = l1->next;
        }

        while(l2 != nullptr){
            list2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* previous = nullptr;
        while(!list1.empty() or !list2.empty()){
            int sum = 0;
            if(!list1.empty())
            {
                sum += list1.top();
                list1.pop();
            }

            if(!list2.empty())
            {
                sum += list2.top();
                list2.pop();
            }

            sum += carry;
            carry = sum / 10;
            sum %= 10;


            ListNode* new_node = new ListNode(sum);
            new_node->next = previous;

            previous = new_node;
            
        }

        if(carry != 0) {
            ListNode* new_node = new ListNode(carry);
            new_node->next = previous;

            previous = new_node;
        }

        return previous;
    }
};

