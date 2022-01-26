class Solution
{
public:
int evalTree(node* root)
{
stack<node*>s;
s.push(root);
while(!s.empty())
{
node* temp = s.top();
s.pop();
if(isExpression(temp->left->data)||isExpression(temp->right->data))
{
s.push(temp);  //adding symbols
if(isExpression(temp->left->data))
{
    s.push(temp->left);  //adding data
}
if(isExpression(temp->right->data))
{
    s.push(temp->right);  //adding data
}
}
else
{
int c=0;
int a = stoi(temp->left->data);
int b = stoi(temp->right->data);
if(temp->data=="+")
{
    c=a+b;
}
else if(temp->data=="-")
{
    c=a-b;
}
else if(temp->data=="*")
{
    c=a*b;
}
else
{
    c=a/b;
}
temp->data = to_string(c);
}
}
return stoi(root->data);
}
};
