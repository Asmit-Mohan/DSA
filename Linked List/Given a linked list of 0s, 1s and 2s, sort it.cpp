/* Approach 1 Time :- O(N) Space :- O(1) [In One Pass Solution] */

class Solution
{
    public:
    Node* segregate(struct Node *head)
    {
        if (head ==NULL|| (head->next)==NULL)
        {
            return head;
        }
         
        Node* zeroD = new Node(0); 
        Node* oneD  = new Node(0); 
        Node* twoD  = new Node(0); 
      
        Node* zero = zeroD;
        Node *one  = oneD;
        Node *two  = twoD; 
        Node* curr = head; 
        
        while (curr)
        { 
            if (curr->data == 0)
            { 
                zero->next = curr; 
                zero = zero->next;
            }
            else if (curr->data == 1)
            { 
                one->next = curr; 
                one = one->next; 
            } 
            else
            { 
                two->next = curr; 
                two = two->next;
            }
            curr = curr->next; 
        } 
    
        if(oneD->next)
        {
            zero->next = (oneD->next);    
        }
        else
        {
            zero->next = (twoD->next);
        }
        
        one->next = twoD->next; 
        two->next = NULL; 
        head = zeroD->next;
        
        delete zeroD; 
        delete oneD; 
        delete twoD;
        return head;
    }
};


/* Approach 2 Time :- O(N) Space :- O(1) */

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
