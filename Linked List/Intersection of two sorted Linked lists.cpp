/*Approach 1*/

Node* findIntersection(Node* head1, Node* head2)
{
         set<int>s;
         vector<int>v;
         Node* temp=head2;
         while(temp!=NULL)
         {
             s.insert(temp->data);
             temp=temp->next;
         }
        temp=head1;
         while(temp!=NULL)
         {
             if (s.find(temp->data) != s1.end())
             {
                v.push_back(temp->data);       
             }
             temp=temp->next;
         }
         
Node*p = NULL;
for(int i=v.size()-1;i>=0;i--)
{
    Node* ans = new Node(v[i]);
    ans->next = p;
    p = ans;
}
return p;
}

/*Efficient Approach 2*/

Node* findIntersection(Node* temp1, Node* temp2)
{
    Node* temp = new Node(0);
    Node* ans=temp;
    
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data == temp2->data)
        {
            temp->next=new Node(temp1->data);
            temp=temp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->data > temp2->data)
        {
            temp2 = temp2->next;
        }
        else if(temp2->data > temp1->data)
        {
            temp1 = temp1->next;
        }
    }
    return ans->next;
}
