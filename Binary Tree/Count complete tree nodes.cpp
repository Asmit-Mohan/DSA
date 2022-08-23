/* Approach 1 --> Tree Traversal */

/* 

Time Complexity: O(N) --> Reason: We are traversing for every node of the tree

Space Complexity: O(logN) --> Reason: Space is needed for the recursion stack. As it is a complete tree, the height of that stack will always be logN.
    
*/

void traverse(node * curr, int& count)
{
   if (curr == NULL)
   {
      return;
   }
   count++;
   traverse(curr -> left, count);
   traverse(curr -> right, count);
}

/* Approach 2 Using Height Technique */

/* 

Time Complexity: O(log^2 N).

Reason: To find the leftHeight and right Height we need only logN time and in the worst case we will encounter the second case(leftHeight!=rightHeight) for at max logN times, so total time complexity will be O(log N * logN)

Space Complexity: O(logN)

Reason: Space is needed for the recursion stack when calculating height. As it is a complete tree, the height will always be logN.

*/

class Solution 
{
public:
    int countNodes(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;      
        }
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        if(lh == rh)
        {
            return (1<<lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
 
    int findHeightLeft(TreeNode* node)
    {
        int height = 0; 
        while(node)
        {
            height++; 
            node = node->left; 
        }
        return height; 
    }
 
    int findHeightRight(TreeNode* node)
    {
        int height = 0; 
        while(node)
        {
            height++; 
            node = node->right; 
        }
        return height; 
    }
};
