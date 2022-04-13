/* Naive Approach */

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

/* Efficient Approach */

#define pair pair<int, Node*>
class Solution
{
    public:
    Node * mergeKLists(Node *arr[], int K)
    {
           priority_queue<pair, vector<pair>,greater<pair>> pq;
           for(int i=0;i<K;++i)
           {    
               int data = arr[i]->data;
               pq.push({data,arr[i]});
           }
      
           Node* ans= new Node(-1);
           Node* temp = ans;
           while(!pq.empty())
           {
               Node* t = pq.top().second;
               pq.pop();
               temp->next = t;
               temp= temp->next;
               
               if(t->next)
               {
                   pq.push({t->next->data,t->next});
               }
           }
           return ans->next;
     }
};
