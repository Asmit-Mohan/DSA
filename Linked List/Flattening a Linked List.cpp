/* Method :- 1 Time :- O(N*M*log(N)) Space :- O(N) */

#define pair pair<int,Node*>

Node* mergeKLists(vector<Node*>&v, int K)
{
    priority_queue<pair,vector<pair>,greater<pair>>pq;
    Node* ans = new Node(-1);
    Node* res = ans;
        
    for(int i=0;i<K;i++)
    {
        if(v[i]!=NULL)
        {
            pq.push({v[i]->data,v[i]});
        }
    }
        
    while(pq.size())
    {
        int data = pq.top().first;
        Node* temp = pq.top().second;
        pq.pop();
            
        ans->bottom = temp;
        ans=ans->bottom;
            
        if(temp->bottom != NULL)
        {
            pq.push({temp->bottom->data,temp->bottom});
        }
    }
    return res->bottom;
}

Node *flatten(Node *root)
{
   vector<Node*>v;
   Node* curr = root;
   int k=0;
   
   while(curr!=NULL)
   {
       v.push_back(curr);
       curr = curr->next;
       k++;
   }
   return mergeKLists(v,k);
}

/* Method 2 :- Time :- O(N*N*M) Space :- O(N*M) */

Node* merge(Node* a,Node* b)
{
    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }
    
    Node* result;
    
    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom,b);
    }
    else
    {
        result = b;
        result->bottom = merge(a,b->bottom);
    }
    return result;
}

Node *flatten(Node *root)
{
    if(root==NULL||root->next==NULL)
    {
        return root;
    }
    return merge(root,flatten(root->next));   
}

/* Method 3 :- */

Node* merge(Node* head1, Node* head2)  
{  
Node* ptr1=head1;
Node* ptr2=head2;
Node* ans= new Node(0);
Node* head=ans;

while(ptr1!=NULL && ptr2!=NULL)
{
    if(ptr1->data>ptr2->data)
    {
        Node* temp=new Node(ptr2->data);
        ans->bottom=temp;
        ans=ans->bottom;
        ptr2=ptr2->bottom;
    }
    else
    {
        Node* temp=new Node(ptr1->data);
        ans->bottom=temp;
        ans=ans->bottom;
        ptr1=ptr1->bottom;
    }
}

if(ptr1!=NULL)
{
    while(ptr1!=NULL)
    {
        Node* temp=new Node(ptr1->data);
        ans->bottom=temp;
        ans=ans->bottom;
        ptr1=ptr1->bottom;
    }
}
if(ptr2!=NULL)
{
    while(ptr2!=NULL)
    {
        Node* temp=new Node(ptr2->data);
        ans->bottom=temp;
        ans=ans->bottom;
        ptr2=ptr2->bottom;
    }
}

head=head->bottom;  /*Because we started from 0*/
return head;
}  

Node *flatten(Node *root)   /*Pre-requirement merge two sorted list*/
{ 
    if(root==NULL||root->next==NULL)
    {
        return root;
    }
    return merge(root,flatten(root->next));  /*Flattening will be done from right to left ie. first 19&&28 then 19&&10 then 10&&5*/
}
