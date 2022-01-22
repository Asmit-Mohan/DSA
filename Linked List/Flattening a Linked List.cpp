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
