/* Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
        unordered_set<int>s;
        Node* ptr=head;
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(ptr!=NULL)
        {
            if(s.find(ptr->data)==s.end())
            {
                s.insert(ptr->data);
                temp->next = new Node(ptr->data);
                temp=temp->next;
            }
            ptr=ptr->next;
        }
        return ans->next;
    }
};
