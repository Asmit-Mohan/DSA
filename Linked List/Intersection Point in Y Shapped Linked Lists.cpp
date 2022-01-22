/*Approach 1 :- Hashing*/
/*In Taking Space*/

class Solution
{
        public:
        ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
        {
        map<ListNode*,bool>mp;
        ListNode*temp=head1;
        while(temp!=NULL)
        {
            mp[temp]=true;
            temp=temp->next;
        }
        temp=head2;
        while(temp!=NULL)
        {
            if(mp[temp])
            {
                return temp; 
            }
            temp=temp->next;    
        }
        return NULL;
        }
};

/*Approach 2 :- No Space*/
class Solution
{
        public:
        int countNode(ListNode* ptr)
        {
            int count=0;
            while(ptr!=NULL)
            {
                count++;
                ptr=ptr->next;
            }
            return count;
        }
    
        ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
        {
            int count1=countNode(head1);
            int count2=countNode(head2);
            int remain=abs(count1-count2);
            
            if(count1>count2)
            {
                while(remain--)
                {
                    head1=head1->next;
                }
            }
            else
            {
                while(remain--)
                {
                    head2=head2->next;
                }
            }
            while(head1!=head2)
            {
                head1=head1->next;
                head2=head2->next;
            }
            return head1;
        }
};


/*Approach 3 :- Very Short*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *pa = headA, *pb = headB;
        while (pa != pb)
        {
            pa = pa ? pa -> next : headB;
            pb = pb ? pb -> next : headA;
        }
        return pa;
    }
};
