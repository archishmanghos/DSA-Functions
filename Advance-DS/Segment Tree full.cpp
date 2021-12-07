//Building Segment Tree

void build_Segment_Tree(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=A[start];
	}
	else
	{
		int mid=start + (end - start) / 2;
		build_Segment_Tree((2*node),start,mid);
		build_Segment_Tree((2*node+1),mid+1,end);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}

// Update on Segment tree

void update_Segment_Tree(int idx,int val,int node,int start, int end)
{
	if(start==end)
	{
		A[idx]+=val;
		tree[node]+=val;
	}
	else
	{
		int mid=start + (end - start) / 2;
		if(start<=idx&&idx<=mid)
			update_Segment_Tree(idx,val,(2*node),start,mid);
		else
			update_Segment_Tree(idx,val,(2*node+1),mid+1,end);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}

// Query on Segment tree

int query_Segment_Tree(int l, int r,int node,int start,int end)
{
	if(r<start||end<l)
		return 0;
	else if(l<=start&&end<=r)
		return tree[node];
	else
	{
		int mid=start + (end - start) / 2;
		int x1=query_Segment_Tree(l,r,(2*node),start,mid);
		int x2=query_Segment_Tree(l,r,(2*node+1),mid+1,end);
		return (x1+x2);
	}
}

//End of Segment tree