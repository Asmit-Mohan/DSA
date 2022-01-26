class Solution
{
  public:
    int canRepresentBST(int preorder[], int N)  /*Next Greater element approach using stack*/
    {
    stack<int> st;
    int root = INT_MIN;
    for (int i=0; i < N; i++)
    {
        while (!st.empty() && preorder[i] > st.top())
        {
            root = st.top();
            st.pop();
        }
        if (preorder[i] < root)
        {
            return 0;
        }
        st.push(preorder[i]);
    }
       return 1;     
    }
};
