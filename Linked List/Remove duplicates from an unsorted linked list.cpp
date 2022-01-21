class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
        unordered_set<int>s;
        vector<int>v;
        Node* ptr=head;
        while(ptr!=NULL)
        {
            if(s.find(ptr->data)==s.end())
            {
                s.insert(ptr->data);
                v.push_back(ptr->data);
            }
            ptr=ptr->next;
        }
        
        Node* p=NULL;
        for(int i=v.size()-1;i>=0;i--)
        {
            Node* temp = new Node(v[i]);
            temp->next=p;
            p=temp;
        }
        return p;
    }
};
