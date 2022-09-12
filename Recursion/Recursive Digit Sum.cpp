/* Approach 1 */

/* Time :- O(logn) Space :- O(logn) */

/* Accoring to problem we can do it as 2+3+2+3+2+3=6+9 or (n*k) means (23*3) = 69 */

long long int solve(long long int num)
{
    if(num<=9)
    {
        return num;
    }
    long long int sum=0;
    while(num>0)
    {
        sum=sum+(num%10);
        num=num/10;
    }
    return solve(sum);
}

int superDigit(string n, int k)
{
	long long int sum=0;
	for(int i=0; i<n.size(); i++)
	{
	    sum = sum + n[i] - '0';
	}
	return solve(sum*k);
}

/* Approach 2 --> Iterative */

long long int solve(long long int n)
{
    int sum = 0;
    while(n > 0 || sum > 9)
    {
        if(n == 0)
        {
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int superDigit(string n, int k)
{
	long long int sum=0;
	for(int i=0; i<n.size(); i++)
	{
	    sum = sum + n[i] - '0';
	}
	return solve(sum*k);
}

/* Approach 3 --> Most Efficient Approach */

long long int solve(long long int n)
{
    if (n == 0)
    {
	return 0;
    }
    return (n % 9 == 0) ? 9 : (n % 9);
}
int superDigit(string n, int k)
{
	long long int sum=0;
	for(int i=0; i<n.size(); i++)
	{
	    sum = sum + n[i] - '0';
	}
	return solve(sum*k);
}
