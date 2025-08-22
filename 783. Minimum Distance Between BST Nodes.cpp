/*
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [2, 100].
    0 <= Node.val <= 105

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        std::queue<TreeNode*> q;

        q.push(root);

        std::vector<int> vec;
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();

            vec.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        std::sort(vec.begin(), vec.end());

        int min = INT_MAX;
        for(int i = 1; i < vec.size(); ++i)
        {
            if(vec[i] - vec[i-1] < min) min = vec[i] - vec[i-1];
        }

        return min;

    }
};
