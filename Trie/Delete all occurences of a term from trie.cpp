struct trie_node
{
    int value;
    trie_node_t *children[ALPHABET_SIZE];
};

class Solution
{
    public:
    void deleteKey(trie_node_t *root, char key[])
    {
        trie_node_t* curr = root;
        for(int i = 0; i < strlen(key); i++)
        {
            curr = curr->children[key[i] - 'a'];
        }
        curr->value = 0;   /* If last node reference of that word becomes False/Zero then there is no existence of that word in trie */
        return;
    }
};
