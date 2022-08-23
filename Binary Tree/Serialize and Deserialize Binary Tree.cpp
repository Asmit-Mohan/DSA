/* Time :- O(N) Space :- O(N) */

class Codec
{
public:
    string serialize(TreeNode* root)
    {
        string tree="";
        if(root==NULL)
        {
            return tree;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL)
            {
                tree+=("#,");
            }
            else
            {
                tree+=(to_string(front->val)+',');
            }
            if(front!=NULL)
            {
                q.push(front->left);
                q.push(front->right);
            }
        }
        cout<<tree<<endl;
        return tree;
    }
    
    TreeNode* deserialize(string data)
    {
        if(data.length()==0)
        {
            return NULL;
        }
        stringstream s(data);
        string str;
        queue<TreeNode*>q;
        
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* front=q.front();
            q.pop();
            
            getline(s,str,',');
            if(str=="#")
            {
                front->left=NULL;
            }
            else
            {
                TreeNode* temp = new TreeNode(stoi(str));
                front->left=temp;
                q.push(temp);
            }
            
            getline(s,str,',');
            if(str=="#")
            {
                front->right=NULL;
            }
            else
            {
                TreeNode* temp = new TreeNode(stoi(str));
                front->right=temp;
                q.push(temp);
            }
        }
        return root;
    }
};
