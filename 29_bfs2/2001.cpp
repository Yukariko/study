#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int a[14];
int b[101];
int adj[101][101];
bool visit[1<<14][101];
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	memset(b, -1, sizeof(b));
	for(int i=0; i < K; i++)
	{
		scanf("%d", &a[i]);
		b[a[i]] = i;
	}

	for(int i=0; i < M; i++)
	{
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u][v] = c;
		adj[v][u] = c;
	}

	queue<pair<int, pair<int, int>>> bfs;
	visit[0][1] = true;
	bfs.push({0, {0, 1}});
	int ans = 0;
	while(!bfs.empty())
	{
		int mask = bfs.front().first;
		int num = bfs.front().second.first;
		int here = bfs.front().second.second;
		bfs.pop();

		if(here == 1)
		{
			ans = max(ans, num);
		}

		if(b[here] != -1 && (mask & (1 << b[here])) == 0)
		{
			int nmask = mask | (1 << b[here]);
			if(visit[nmask][here])
				continue;
			visit[nmask][here] = true;
			bfs.push({nmask, {num + 1, here}});
		}

		for(int there=1; there <= N; there++)
		{
			if(adj[here][there] >= num && visit[mask][there] == false)
			{
				visit[mask][there] = true;
				bfs.push({mask, {num, there}});
			}
		}
	}
	printf("%d", ans);
	return 0;
}
