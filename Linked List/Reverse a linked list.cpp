/* Approach 1 :- Recursive O(N) --> Time and O(N) --> Recursive Space */

class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;  /*always return head of reversed linked list*/
        }
        
        struct Node* newHead = reverseList(head->next);  /*newHead Will Remain Contant ie. always point to end of list*/
        
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
};

/* Approach 2 :- Iterative O(N) --> Time and O(1) --> Constant Space */

class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL)
        {
            Node* temp=curr->next;   /*Always points to next node*/
            curr->next=prev;         /*current node will store references of previous node*/
            prev=curr;               /*prev moves forward*/
            curr=temp;               /*current also moves forward that is why its next was stored in temp earlier.*/
        }
        return prev;
    }
};
