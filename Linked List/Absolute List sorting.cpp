class Solution
{
public: 
    void sortList  /*Selection Sort Mechanisms*/
    {
        Node* ptr1=*head;  /*will always main node*/
        Node* ptr2=*head;  /*will iterate from main+1 to end to compare*/
        while(ptr1!=NULL)
        {
            int x;
            if(ptr1->data>ptr2->data) /*Comparing 1st node with every next node*/
            {
                x=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=x;
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
