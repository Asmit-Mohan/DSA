/* Time :- O(N) Space :- O(1) */

/* Approach 1 */

void deleteAlt(struct Node *head)
{
   if(head==NULL)
   {
       return;
   }
   else
   {
       Node* temp=head->next;
       if(temp==NULL)
       {
           return;
       }
       else
       {
           head->next=temp->next;
           free(temp);
           deleteAlt(head->next);
       }
   }
}

/* Approach 2 */

void deleteAlt(struct Node *head)
{
   if(head->next==NULL)
   {
       return;
   }
   
   if(head->next->next==NULL)
   {
       head->next=NULL;
   }
   
   struct Node* temp = head;
 
   while(temp->next!=NULL&&temp->next->next!=NULL)
   {
        temp->next=temp->next->next;
        temp=temp->next;
   }
   temp->next=NULL;
}
