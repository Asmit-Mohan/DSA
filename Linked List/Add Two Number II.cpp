/* Time :- O(n1+n2) Space :- O(Max(n1,n2)) */

class Solution
{
public:
    ListNode* reverseList(ListNode *head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;   
            curr->next=prev;        
            prev=curr;              
            curr=temp;               
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
       ListNode* head1=l1;
       ListNode* head2=l2;
       ListNode* result = new ListNode(-1);
       ListNode* ans=result;
       
       head1 = reverseList(head1);
       head2 = reverseList(head2);

       int carry=0;
       int res=0;
        
       while(head1!=NULL&&head2!=NULL)
       {
            res=head1->val+head2->val+carry;
            carry=res/10;
            res=res%10;
            ListNode* temp = new ListNode(res);
            ans->next=temp;
            ans=ans->next;
            head1=head1->next;
            head2=head2->next;
       }
        
       while(head1!=NULL)
       {
            res=head1->val+carry;
            carry=res/10;
            res=res%10;
            ListNode* temp = new ListNode(res);
            ans->next=temp;
            ans=ans->next;
            head1=head1->next;
       }
        
       while(head2!=NULL)
       {
            res=head2->val+carry;
            carry=res/10;
            res=res%10;
            ListNode* temp = new ListNode(res);
            ans->next=temp;
            ans=ans->next;
            head2=head2->next;  
       }
       
       if(carry)
       {
            ListNode* temp = new ListNode(carry);
            ans->next=temp;
            ans=ans->next;
       } 
       return reverseList(result->next);    
    }
};
