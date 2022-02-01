class Solution
{
  public:
  
   Node* solve(Node *head)
   {
        
        Node* prevv = NULL;
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL and fast->next != NULL)
        {
            prevv = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prevv->next = NULL;
        return slow;
    }

    Node *merge(Node *left, Node *right)
    {
        if(left == NULL)
        {
            return right;
        }
        
        if(right== NULL)
        {
            return left;
        }
        
        Node*  ans = new Node(-1);
        Node*  tail = ans;
        
        while(left != NULL and right != NULL)
        {
            if(left->data <= right->data)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail=tail->next;
        }
        
        if(left != NULL)
        {
            tail->next = left;
        }
        else
        {
            tail->next = right;
        }
        
        return ans->next;
    }
    
    Node* mergeSort(Node* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        Node* mid = solve(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);
        return merge(left, right);
    }
};
