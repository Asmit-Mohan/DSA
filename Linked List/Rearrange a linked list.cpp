/* Approach:-1 */

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
      if(!head)
      {
          return;
      }
      Node *odd = head;
      Node *even = head->next;
      Node *even_head = head->next;
        
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;        
    }
};

/*Approach:-2 Logic (Divide into two linked list of odd and even then put odd->next=even ie. merging) */
class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if(!head)
        {
        	return head;
        }
        ListNode *end = head;
        int counter = 0;
        while(end->next)
        {    
        	end = end->next;
            counter++;
        }
        
        counter = counter&1?(counter/2)+1:counter/2;
        ListNode *temp = head;
        while(counter--)
        {
            end->next = temp->next;
            temp->next = temp->next->next;
            end->next->next = NULL;
            temp = temp->next;
            end = end->next;
        }
        return head;
    }
};
