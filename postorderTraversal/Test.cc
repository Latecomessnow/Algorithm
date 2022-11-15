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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            // 当左路节点从栈中出来，表示左路节点已经访问完了
            TreeNode* top = st.top();
            // 栈顶节点的右子树为空或者上一次访问的是top右子树的根节点，就可以直接访问
            // 否则，子问题访问top右子树
            if (top->right == nullptr || top->right == prev)
            {
                v.push_back(top->val);
                // 记录上一次已经访问的节点
                prev = top;
                st.pop();
            }
            // 子问题访问右子树
            else 
                cur = top->right;
        }
        return v;
    }
};