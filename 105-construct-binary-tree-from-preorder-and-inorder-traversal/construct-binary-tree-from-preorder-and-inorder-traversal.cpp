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
TreeNode* buildTreePreIn(vector<int>& preorder, int ps, int pl,
            vector<int>& inorder, int is, int il, map<int,int>& mpp ){
            // basecase 
            if(is > il || ps > pl) return NULL;
            TreeNode* root = new TreeNode(preorder[ps]);
            int inRoot = mpp[preorder[ps]];
            int left = inRoot - is;

            root->left = buildTreePreIn(preorder, ps+1 , ps + left,
            inorder,is,inRoot - 1, mpp);

            root->right = buildTreePreIn(preorder, ps + left + 1, pl,
            inorder, inRoot + 1,il, mpp);

            return root;
            }
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size()){
            return NULL;
        }
        map<int,int>mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        return buildTreePreIn(preorder, 0, preorder.size() - 1,
        inorder, 0, inorder.size() -1 , mpp);

    }
};