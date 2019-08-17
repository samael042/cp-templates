const int MAXN = 1e3+5;
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int h,w;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
//0 based indexing
bool valid(int x, int y)
{	
	if(x >= 0 and x < h and y >= 0 and y < w)return true;
	return false;
}

void bfs2d(pair<int,int> z)
{
    queue<pair<int,int>> q;
    q.push(z);
    while(!q.empty())
    {
    	auto now = q.front();
    	int x = now.first, y = now.second;
    	vis[x][y] = true;
    	for(int i = 0; i < 4; i++)	
    	{
    		int nx = x+dx[i],ny = y+dy[i];
    		if(valid(nx,ny) and !vis[nx][ny])
    		{
    			q.push({nx,ny});
    		}
    	}
    }
}
