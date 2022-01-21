class Solution
{
public:
Node* findIntersection(Node* head1, Node* head2)
{
    unordered_set<int>s;
    vector<int>res;
    Node*ptr1 = head1;
    Node*ptr2 = head2;
    while(ptr2!=NULL)
    {
        s.insert(ptr2->data);
        ptr2 = ptr2 -> next;
    }
    while(ptr1!=NULL)
    {
        if(s.find(ptr1->data)!=s.end())
        {
            res.push_back(ptr1->data);
        }
        ptr1=ptr1->next;
    }
    Node* ptr=NULL;
    reverse(res.begin(),res.end());  /*Or Iterate from reverse to avoid this reverse function and reduce time complexity*/
    for(int i=0;i<res.size();i++)
    {
        Node *temp = new Node(res[i]);
        temp->next=ptr;
        ptr=temp;
    }
    return ptr;
}
};
