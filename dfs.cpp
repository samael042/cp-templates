vector<int> G[N];
int n,m;
bool vis[N];

void dfs(int v)
{
	vis[v] = true;
	for(auto i : G[v])
	{
		if(!vis[i])
		{
			dfs(v);
		}
	}
}