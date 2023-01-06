struct Node
{
	Node *links[26];
	bool flag = false;
	
	bool containKey(char ch)
	{
		 return (links[ch - 'a'] != NULL);
	}
	
	void put(char ch, Node *node)
	{
		 links[ch - 'a'] = node;
	}
	
	Node *get(char ch)
	{
		 return links[ch - 'a'];
	}
	
	void setEnd()
	{
		 flag = true;
	}
	
	bool isEnd()
	{
		 return flag;
	}
};

class Trie
{
    private:
    Node* root;

    public:
    Trie()
    {
       root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
               node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
};

class Solution
{
    public:
    bool solve(string s,Trie trie)
    {
        int size=s.size();
        if(size==0) 
        {
           return true;
        }
        for(int i=1;i<=size;i++)
        {
           if(trie.search(s.substr(0,i)) && solve(s.substr(i,size-i),trie))
           {
               return true;
           }
       }
       return false;
    }

    int wordBreak(string A, vector<string> &B)
    {
       Trie trie;
       for(int i=0;i<B.size();i++)
       {
           trie.insert(B[i]);
       }
       return solve(A,trie);
    }
};
