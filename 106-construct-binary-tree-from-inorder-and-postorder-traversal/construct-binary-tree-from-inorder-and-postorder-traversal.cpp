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
 TreeNode* buildTreePostIn(vector<int>& inorder,int is, int il,
            vector<int>& postorder, int ps, int pl,
            map<int,int>& mpp ){
                if(is > il || ps > pl) return NULL;
                TreeNode* root = new TreeNode(postorder[pl]); // root = 3
                int inRoot = mpp[postorder[pl]]; // index = 1
                int left = inRoot - is; // left = 1

                root->left = buildTreePostIn(inorder,is,inRoot - 1, // inorder 0-0
                postorder,ps,ps + left - 1  , mpp); // 

                root->right = buildTreePostIn(inorder,inRoot + 1,il,
                postorder,ps + left , pl - 1, mpp);
                return root;
            }
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;

        map<int,int>mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        return buildTreePostIn(inorder, 0, inorder.size() - 1,
        postorder, 0, postorder.size() - 1, mpp);
    }
};