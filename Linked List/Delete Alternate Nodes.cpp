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
