/* Approach 1 */

class Solution
{
public:
void find(Node* root,int target ,unordered_set<int> &s,bool &ans)
{
    if(root!=NULL)
    {
        find(root->left,target,s,ans);
        if(s.find(target-root->data)!=s.end())
        {
           ans=1;
           return ;
        }
        else
        {
           s.insert(root->data);
        }
        find(root->right,target, s,ans);
    }
}
    int isPairPresent(struct Node *root, int target)
    {
        unordered_set<int> s;
        bool ans=0;
        find(root,target,s,ans);
        return ans;
    }
};

/* Approach 2 */

class Solution
{
public:
    bool findTarget(TreeNode* root, int k)
    {
        
        vector<int> arr;
        inorderFill(root, arr);
        int low = 0;
        int high = arr.size()-1;
        while(low < high)
        {
            if(arr[low] + arr[high] == k)
            {
              return true;
            }
            else if(arr[low]+arr[high] < k)
            {
              low++;
            }
            else
            {
              high--;
            }
        }
        return false;
    }
    
    void inorderFill(TreeNode* root, vector<int>& arr)
    {
        if(root!=NULL)
        {
           inorderFill(root->left, arr);
           arr.push_back(root->val);
           inorderFill(root->right, arr); 
        }
    }
};
