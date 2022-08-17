/* Approach 1 :- O(N) time and O(1) Space */

class Solution
{
public:
    int getDecimalValue(ListNode* head)
    {
        int size=0;
        int ans=0;
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        size--;
        
        ListNode* ptr = head;
        
        while(ptr!=NULL)
        {
            ans+=(ptr->val)*(int)pow(2,size--);
            ptr=ptr->next;
        }
        return ans;
    }
};

/* Approach 2 :- O(N) time and O(1) Space [ In-Pass Solution ] */

class Solution
{
public:
    int getDecimalValue(ListNode* head)
    {
        int ans = 0;
        while(head != NULL)
        {
            ans <<= 1;              /* Left shift operators are used to multiply by 2 and right shift for division by 2 */
            ans = ans+head->val;
            head = head->next;
        }
        return ans;
    }
};
