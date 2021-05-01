int stringtointeger(string x)
{
    int ans = 0, j = 1;
 
    for (int i = x.size() - 1; i >= 0; i--)
    {
        ans += (x[i] - '0') * j;
        j *= 10;
    }
 
    return ans;
}