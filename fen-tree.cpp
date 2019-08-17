struct BIT{
	int N;
	vector<int> bit;
	void init(int n)
	{
		N = n;
		bit.assign(n+1,0);
	}
	void update(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] += val;
			idx += idx&(-idx);
		}
	}

	int pref(int idx)
	{
		int ans = 0;
		while(idx > 0)
		{
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}
	
	int query(int l, int r)
		return pref(r)-pref(l-1);
};