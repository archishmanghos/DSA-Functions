int BIT[1000], a[1000], n;
void update(int index, int val)
{
      for(; index <= n; index += index&-index)
        BIT[index] += val;
}
int query(int index)
{
     int sum = 0;
     for(; index > 0; index -= index&-index)
        sum += BIT[index];
     return sum;
}