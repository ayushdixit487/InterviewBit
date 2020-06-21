// https://www.interviewbit.com/problems/2-sum-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// A shorter and intuitive method. Check out the next two solutions as well.
int Solution::t2Sum(TreeNode* A, int B) {
    // Base Case
    if(!A)return 0;
    
    // Make two stacks for the two different traversals,
    // one from the right side, other from the left.
    stack<TreeNode*> s1, s2;
    TreeNode* temp1 = A, *temp2 = A;
    
    // Take temp1 to the extreme left
    while(temp1){
        s1.push(temp1);
        temp1 = temp1->left;
    }
    
    // and temp2 to extreme right
    while(temp2){
        s2.push(temp2);
        temp2 = temp2->right;
    }
    temp1 = s1.top();
    temp2 = s2.top();
    
    // While we do not traverse the complete tree
    while(temp1 and temp2 and temp1->val < temp2 -> val){
        if(temp1->val + temp2->val == B)return 1;

        if(temp1->val + temp2->val < B){
            // Move Ahead the temp1 pointer
            s1.pop();
            // Check out the preorder traversal using stacks 
            temp1 = temp1->right;
            while(temp1){
                s1.push(temp1);
                temp1 = temp1->left;
            }
            temp1 = s1.top();
        }else{
            // Move ahead the temp2 pointer
            s2.pop();
            // Inverse of preorder traversal using stacks 
            // (not to be confused with postorder traversal)
            temp2 = temp2->left;
            while(temp2){
                s2.push(temp2);
                temp2 = temp2->right;
            }
            temp2 = s2.top();
        }
    }
    return 0;
}
