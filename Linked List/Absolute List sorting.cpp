/* Naive Approach Time :- O(N^2) */

class Solution
{
public: 
    void sortList(Node** head)  /*Selection Sort Mechanisms*/
    {
        Node* ptr1=*head;  /*will always main node*/
        Node* ptr2=*head;  /*will iterate from main+1 to end to compare*/
        while(ptr1!=NULL)
        {
            if(ptr1->data>ptr2->data) /*Comparing 1st node with every next node*/
            {
                 swap(ptr1->data,ptr2->data);
            }
            ptr2=ptr2->next;
            if(ptr2==NULL&&ptr1!=NULL) /*if last node ends then again comparision start from 2nd node*/
            {
                ptr2=ptr1->next;
                ptr1=ptr1->next;
            }
        }
    }
};

/* Efficient Approach Time:- O(N) */ 

class Solution
{
public:
    void sortList(Node** head)
    {
       Node* prev = *head;
       Node* curr = *head->next;
    
       while (curr != NULL)
       {
           if (prev->data>curr->data)
           {
               prev->next = curr->next;
               curr->next = *head;
               *head = curr;
               curr = prev;
           }
           else
           {
               prev = curr;
           }
           curr = curr->next;
       }
};
