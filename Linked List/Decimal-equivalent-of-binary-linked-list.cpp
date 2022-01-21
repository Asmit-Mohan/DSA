/*Approach 1 :- O(N) time and O(N) Space*/

class Solution
{
public:
    int getDecimalValue(ListNode* head)
    {
        ListNode* ptr=head;
        vector<int>v;
        int res=0;
        while(ptr!=NULL)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        int n=v.size();
        int i=0;
        for(int j=n-1;j>=0;j--)
        {
            res=res+(v[j]*pow(2,i));
            i++;
        }
        return res;
    }
};

/*Approach 2 :- Without Vector Little bit time efficient*/

class Solution
{
public:
    int getDecimalValue(ListNode* head)
    {
        int size=0;
        int ans=0;
        ListNode* node = head;
        while(node!=nullptr)
        {
            size++;
            node=node->next;
        }
        size--;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            ans+=(temp->val)*(int)pow(2,size--);
            temp=temp->next;
        }
        return ans;
    }
};

/*Approach 3 :- Constant Space and Time Efficient*/
class Solution
{
public:
    int getDecimalValue(ListNode* head)
    {
        int ans = 0;
        while(head != NULL)
        {
            ans <<= 1;
            ans = ans+head->val;
            head = head->next;
        }
        return ans;
    }
};
