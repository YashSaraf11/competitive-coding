// URL : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* tree(vector<int>& inorder, int a , int b ,
                   vector<int>& preorder , int x , int y ){
        //base condition to break the recursion
        if( a>b || x>y )
            return nullptr;
        
        /*finding the value of the preorder node in the inorder vector to segregate
            the left child and right child nodes of the current node */
        int lchild=a;
        while(inorder[lchild]!=preorder[x]){
            lchild++;
        }
        
        //creating the root and calling the function recursively for the left and right child
        TreeNode *root = new TreeNode(preorder[x]);
        root->left = tree(inorder,a,lchild-1,preorder,x+1,x+lchild-a);
        root->right= tree(inorder,lchild+1,b,preorder,x+lchild-a+1,y);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //calling the function with boundary of the vector
        return tree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1);        
    }
    
};