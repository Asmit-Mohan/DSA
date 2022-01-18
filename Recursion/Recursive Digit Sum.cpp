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

/*Accoring to problem we can do it as 2+3+2+3+2+3=6+9 or (n*k) means (23*3) = 69*/
