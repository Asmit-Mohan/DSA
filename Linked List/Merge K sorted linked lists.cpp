class Solution
{
  public:
    Node * mergeKLists(Node *arr[], int k)
    {
         priority_queue<int,vector<int>,greater<int>>pq;
         for(int i=0;i<k;i++)
         {
             Node* temp=arr[i];
             while(temp!=NULL)
             {
                 pq.push(temp->data);
                 temp=temp->next;
             }
         }
         Node* ans = new Node(0);
         Node* res=ans;
         while(!pq.empty())
         {
             Node* temp=new Node(pq.top());
             pq.pop();
             ans->next=temp;
             ans=ans->next;
         }
         ans->next=NULL;
         return res->next;
    }
};
