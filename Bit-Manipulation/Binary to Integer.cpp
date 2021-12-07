int binarytointeger(string x)
{
	int ans=0,m=1;
	for(int i=x.size()-1; i>=0; i--)
	{
		ans+=(x[i]-'0')*m;
		m<<=1;
	}
	return ans;
}