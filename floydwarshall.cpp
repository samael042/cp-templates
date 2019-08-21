const int MAXN = 1e3+5;
int d[MAXN][MAXN];
//set d[i][j] = w(i,j) initially, if there is an edge btw i and j.
//set it as oo otherwise
//d[i][i] = 0 for undirected graphs
void warshall()
{
	for(int i = 0; i < n; i++)
		dp[i][i] = 0; // comment out if the graph is directed
	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}	
}
