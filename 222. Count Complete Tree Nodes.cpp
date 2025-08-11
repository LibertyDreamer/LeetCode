/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:

Input: root = []
Output: 0

Example 3:

Input: root = [1]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [0, 5 * 104].
    0 <= Node.val <= 5 * 104
    The tree is guaranteed to be complete.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int most_leftside_node(TreeNode* x) {
        int deep = 0;
        while (x) {
            deep++;
            x = x->left;
        }
        return deep;
    }

public:
    int countNodes(TreeNode* root) {
        int left_deep, right_deep;
        int size = 0;

        while (root){
            left_deep = most_leftside_node(root->left);
            right_deep = most_leftside_node(root->right);

            if (right_deep < left_deep) {
                root = root->left;
                size += (1 << right_deep);
            } else if (right_deep == left_deep){
                root = root->right;
                size += (1 << left_deep);
            }
        }

        return size;
    }
};

