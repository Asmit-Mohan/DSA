class Solution
{
public:
Node *sortedInsert(Node* head, int data)
{
      Node *ins=new Node(data);
      Node *curr=head;
      if(data<head->data)
      {
          while(curr->next!=head)
          {
              curr=curr->next;
          }
          ins->next=head;
          curr->next=ins;
          return ins;
      }
      else
      {
          while(curr->next->data<data)
          {
              curr=curr->next;
          }
          ins->next=curr->next;
          curr->next=ins;
          return head;
      }
}
};
