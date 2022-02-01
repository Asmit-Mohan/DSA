void sort012(int a[], int n)
{
    int one=0;
    int two=0;
    int zero=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            zero++;
        }
        else if(a[i]==1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }
    int i=0;
    while(zero--)
    {
        a[i++]=0;
    }
    while(one--)
    {
         a[i++]=1;
    }
    while(two--)
    {
         a[i++]=2;
    }
}
