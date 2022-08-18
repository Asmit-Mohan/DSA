/* Naive Approach Time :- O[N*K*log(n*k)] Space :- (n*k) */

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

/* Efficient Approach Time :- O(k*logk) Space :- O(k) */

#define pair pair<int,Node*>

class Solution
{
  public:
    Node * mergeKLists(Node *arr[], int k)
    {
        priority_queue<pair,vector<pair>,greater<pair>>pq;
        
        for(int i=0;i<k;i++)
        {
            pq.push({arr[i]->data,arr[i]});
        }
        
        Node* ans = new Node(-1);
        Node* res = ans;
        
        while(!pq.empty())
        {
            int   data  = pq.top().first;
            Node* temp  = pq.top().second;
            pq.pop();
            
            ans->next = temp;
            ans=ans->next;
            
            if(temp->next!=NULL)
            {
                pq.push({temp->next->data,temp->next});
            }
        }
        return res->next;
    }
};
