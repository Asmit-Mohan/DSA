/* Approach 1 Time :- O(N) Space :- O(N) */

class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
       if(head==NULL)
       { 
           return NULL;
       }
    
       if(head->next==NULL)
       {    
           return new TreeNode(head->val);
       }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while(fast->next && fast->next->next)
    {    
        fast = fast->next->next;
        slow = slow->next;
    }
    
    ListNode *mid = slow->next;
    slow->next = 0;
        
    TreeNode* root = new TreeNode(mid->val);
    root->left =  sortedListToBST(head);
    root->right = sortedListToBST(mid->next);
    return root;
    }
};

/* Approach 2 Time :- O(N) Space :- O(N) + O(N) */

class Solution
{
public:
    TreeNode* solve(vector<int>& nums, int low, int high)
    {
        if(low>=high)
        {
            return NULL; 
        }
        
        int mid=(low+high)/2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=solve(nums,low,mid);
        root->right=solve(nums,mid+1,high);
        return root;
    }
    
    
    TreeNode* sortedListToBST(ListNode* head)
    {
        if(head==NULL)
        {
            return NULL;
        }
        vector<int>nums;
        while(head!=NULL)
        {
            nums.push_back(head->val);
            head=head->next;
        }
        return solve(nums,0,nums.size());
    }
};
