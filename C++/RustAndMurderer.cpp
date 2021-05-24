#include <bits/stdc++.h>

using namespace std;

map<int,int> adj[200001];
int visited[200001],q[200001],dis[200001];
int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for (int i=0;i<=n;i++)
            adj[i].clear();
        for (int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            adj[a][b]=1;
            adj[b][a]=1;
        }
        int s;
        scanf("%d",&s);
        int be=0,ed=1;
        memset(visited,0,sizeof(visited));
        q[0] = s;
        visited[s] = 1;
        dis[s] = 0;
        while (be<ed)
        {
            for (int i=1;i<=n;i++)
                if (visited[i] == 0 && adj[q[be]][i] != 1)
                {
                    q[ed++] = i;
                    visited[i] = 1;
                    dis[i] = dis[q[be]] + 1;
                }
            if (ed>=n)
                break;
            be++;
        }
        for (int i=1;i<=n;i++)
            if (i!=s)
                printf("%d ",dis[i]);
        printf("\n");
    }
}
