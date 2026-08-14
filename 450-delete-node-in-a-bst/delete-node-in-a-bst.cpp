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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        
       
        if(root->val > key){
            // left 
            root->left = deleteNode(root->left, key);

        }else if(root->val < key){
            // right
            root->right = deleteNode(root->right, key);

        }else{
            // mil gya 
            /// case 1 left null ho
            if(root->left == NULL){
            TreeNode* temp = root->right;
            delete root;
            return temp;
            }

            // case 2 right null ho
            if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // maan lo dono ho
            TreeNode* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }

            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);

        }

        return root;
    }
};