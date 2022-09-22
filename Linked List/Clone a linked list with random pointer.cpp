/* Approach 1 Time :- O(2*N) ~ O(N)  Space :- O(N) */

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {    
        Node* clone = head;
        unordered_map<Node*, Node*> map;
        
        while(clone!=NULL)
        {
            Node* curr = new Node(clone->val);
            map[clone] = curr;
            clone = clone->next;
        }
        
        Node* res = new Node(-1);
        auto ret = head;
        
        while(head)
        {
            res = map[head];    
            res->random = map[head->random];
            res->next = map[head->next];
            
            res = res->next;
            head = head->next;
        }
        return map[ret];
    }
};

/* Approach 2 Time :- O(3*N) ~ O(N)  Space :- O(1) */

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if(head == NULL)
        {
            return head;
        }
        
        Node* temp = head;
        
        /* Makeing Copy of linked List */
        while(temp != NULL)
        {
            Node* curr = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = curr;
            temp = curr;
        }
        
        temp = head;
        
        /* Setting the random pointer */
        while(temp != NULL)
        {
            if(temp->next != NULL)
            {
                temp->next->random = (temp->random != NULL) ? temp->random->next : NULL;
            }
            temp = temp->next->next;
        }
        
        Node* orig = head;
        Node* copy = head->next;
        Node* curr = copy;
        
        /* separating orignal and copied list */
        while(orig != NULL)
        {
            orig->next = orig->next->next;
            copy->next = (copy->next != NULL) ? copy->next->next : copy->next;
            orig = orig->next;
            copy = copy->next;
        }
        return curr;   
    }
};
