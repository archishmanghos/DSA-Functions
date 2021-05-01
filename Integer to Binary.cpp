string integertobinary(int x)
{
	string ans="";
	while(x>0)
	{
		ans+=(x%2)+'0';
		x>>=1;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}