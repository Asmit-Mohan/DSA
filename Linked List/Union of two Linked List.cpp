/* Time :- O[max(Nlogn, Mlogm)]  Space :- O(n+m) */

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set<int>s;
    Node*ptr1 = head1;
    Node*ptr2 = head2;
    
    while(ptr1||ptr2)
    {
        if(ptr1)
        {
            s.insert(ptr1->data);
            ptr1 = ptr1 -> next;
        }
        if(ptr2)
        {
            s.insert(ptr2->data);
            ptr2 = ptr2 -> next;
        }
    }
    
    struct Node* ans = new struct Node(-1);
    struct Node* temp = ans;
    
    for(auto x : s)
    {
        temp -> next = new struct Node(x);
        temp = temp->next;
    }
    return ans->next;;
}
