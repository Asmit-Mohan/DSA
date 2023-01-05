/* Approach 1 Time :- O(N*N) */

int countDistinctSubstrings(string &s)
{
    unordered_set<string>st;
    for (int i = 0; i < s.size(); i++)
    {
        string temp = "";
        for (int j = i; j < s.size(); ++j)
        {
            temp = temp + s[j];
            st.insert(temp);
        }
    }
    return st.size()+1;
}

/* Approach 2 Time :- O(N*N)*/

struct Node
{
    Node * links[26];
  
    bool containsKey(char ch)
    {
       return (links[ch - 'a'] != NULL);
    }

    Node * get(char ch)
    {
       return links[ch - 'a'];
    }

    void put(char ch, Node * node)
    {
       links[ch - 'a'] = node;
    }
};

int countDistinctSubstrings(string & s)
{
    Node * root = new Node();
    int count = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        Node * node = root;
        for (int j = i; j < n; j++)
        {
            if (!node -> containsKey(s[j]))
            {
                node -> put(s[j], new Node());
                count++;
            }
            node = node -> get(s[j]);
        }
    }
    return count + 1;
}


/*
The above approaches makes use of hashing which may lead to memory limit exceeded (MLE) in case of very large strings. 
The approximate space complexity of them is around O(n^3) as there can be n(n+1)/2 substrings which is around O(n^2) and each substring can be at least of 1 length or n length, i.e O(n/2) average case. 
This makes the total space complexity to be O(n^3).

We can improve this using Trie. The idea is to insert the character that are not already present in the Trie. 
And when such addition happens we know that this string is occurring for the first time and thus we print it. 
And if some characters of the string is already present we just move on to the next node without reading them which helps us on saving space.
The time complexity for this approach is O(n^2) similar to previous approach but the space reduces to O(n)*26. 
*/
