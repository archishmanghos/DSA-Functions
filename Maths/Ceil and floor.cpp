int flooor(int n,int k)
{
    if(n%k == 0 || n >= 0)
    	return n/k;
    return (n/k)-1;
}
 
int ceiil(int n,int k)
{
    return flooor(n+k-1,k);
}