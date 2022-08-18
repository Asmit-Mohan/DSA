/* Time Complexity :- O[ min(length_of_l1, length_of_l2) ] , Space Complexity:- O[ max(length_of_l1, length_of_l2) + 1 ] */

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
       ListNode* head1=l1;
       ListNode* head2=l2;
       ListNode* result = new ListNode(-1);
       ListNode* ans=result;
        
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
       return result->next;    
    }
};
