class Solution
{
public:
Node* segregate(Node *head)
{
   Node* ptr=head;
   int one=0;
   int two=0;
   int zero=0;
   
   while(ptr!=NULL)
   {
       if(ptr->data==0)
       {
           zero++;
       }
       else if(ptr->data==1)
       {
           one++;
       } 
       else
       {
           two++;
       }
       ptr=ptr->next;
   }
   
   ptr=head;
   while(ptr!=NULL)
   {
       if(zero)
       {
           ptr->data=0;
           zero--;
       }
       else if(one)
       {
           ptr->data=1;
           one--;
       }
       else if(two)
       {
           ptr->data=2;
           two--;
       }
       ptr=ptr->next;
   }
   return head;
}
};
