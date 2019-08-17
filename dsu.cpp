const int N = 1e5+5;
const int MAX = 1e5+5;
int  p[MAX],siz[MAX];

void makeset(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		p[i] = i;
		siz[i] = 1;
	}
}
int findset(int v)
{
	while(v != p[v])
	{
		v = p[v] = p[p[v]];
	}
	return v;
}
void union_(int a,int b)
{
	a = findset(a);
	b = findset(b);
	if(a != b)
	{
		if(siz[a] < siz[b])
			swap(a,b);
		p[b] = a;
		siz[a] += siz[b];
	}
}