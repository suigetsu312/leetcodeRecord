/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 *
 * https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
 *
 * algorithms
 * Easy (73.79%)
 * Likes:    2792
 * Dislikes: 163
 * Total Accepted:    175.2K
 * Total Submissions: 237.4K
 * Testcase Example:  '[1,0,1,0,1,0,1]'
 *
 * You are given the root of a binary tree where each node has a value 0 or 1.
 * Each root-to-leaf path represents a binary number starting with the most
 * significant bit.
 * 
 * 
 * For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent
 * 01101 in binary, which is 13.
 * 
 * 
 * For all leaves in the tree, consider the numbers represented by the path
 * from the root to that leaf. Return the sum of these numbers.
 * 
 * The test cases are generated so that the answer fits in a 32-bits
 * integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,0,1,0,1,0,1]
 * Output: 22
 * Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [0]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * Node.val is 0 or 1.
 * 
 * 
 */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// @lc code=start
 
#include <queue>
using namespace std;
class Solution {

public:
    int dfs(TreeNode* root, int result){
        if(!root){
            return 0;
        }
        result = result<<1 | root->val;
        if(!root->left && !root->right){
            return result;
        }

        return dfs(root->left, result) + dfs(root->right, result);
    }
    int sumRootToLeaf(TreeNode* root) {
        int result = dfs(root, 0);
        return result;
    }
};
// @lc code=end


