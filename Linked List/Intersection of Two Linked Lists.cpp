/* Time :- O(m+n) Space :- O[ min(n,m) --> worst case ] */

class Solution
{
public:
Node* findIntersection(Node* head1, Node* head2)
{
    unordered_set<int>s;
    vector<int>v;
    Node* r1=head1;
    Node* r2=head2;
    
    while(r2!=NULL)
    {
        s.insert(r2->data);
        r2=r2->next;
    }
    while(r1!=NULL)
    {
        if(s.find(r1->data)!=s.end())
        {
            v.push_back(r1->data);
        }
        r1=r1->next;
    }
    Node* ans = new Node(-1);
    Node* res=ans;
    
    for(int i=0;i<v.size();i++)
    {
        Node* temp=new Node(v[i]);
        ans->next=temp;
        ans=ans->next;
    }
    return res->next;
}
};
