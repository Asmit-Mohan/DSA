int countNodesinLoop(struct Node *head)
{
        struct Node* slow=head;
        struct Node* fast=head;
        int flag=1;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            return 0; 
        }
        else
        {
             int count=1;
             slow=slow->next;
             while(slow!=fast)
             {
                 slow=slow->next;
                 count++;
             }
             return count;
        }
}


/*Intution behind the code*/

//first find wheather loop exists or not
//if exists then move slow from slow to fast again to count num of nodes as initially both are at same position
