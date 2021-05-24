/*#include <bits/stdc++.h>


using namespace std;

struct queueEntry
{
    int v;
    int dist;
};

int minDis(int moves[],int n);

int main()
{
    int t,i,j,n=100,moves[n];

    cin>>t;
    while(t--)
    {
        for(i=1;i<=n;i++)
        {
            moves[i]=i;
        }
        int l,s;
        cin>>l;
        for(i=0;i<l;i++)
        {
            int a,b;
            cin>>a>>b;
            moves[a]=b;
        }
        cin>>s;
        for(i=0;i<s;i++)
        {
            int c,d;
            cin>>c>>d;
            moves[c]=d;
        }
        int ans=-1;
        ans=minDis(moves,n);
        cout<<ans<<endl;
    }

    return 0;
}

int minDis(int moves[],int n)
{
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    queue<queueEntry>q;
    visited[0]=true;
    queueEntry s={0,0};
    q.push(s);
    queueEntry qe;
    while(!q.empty())
    {
        qe=q.front();
        int v=qe.v;

        if(v==n-1)
        {
            break;
        }

        q.pop();
        for(int j=v+1; j<=(v+6) && j<n;++j)
        {
            if(!visited[j])
            {
                queueEntry a;
                a.dist=(qe.dist+1);
                visited[j]=true;
                if(moves[j]!=-1)
                {
                    a.v=moves[j];
                }
                else
                {
                    a.v=j;
                }
                q.push(a);
            }
        }
    }
    return qe.dist;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int N=104;
const int INF=100000000;
int main()
{
	int t;
	cin>>t;
	for(int k=1;k<=t;++k)
	{
		vector<int> graph(N,0);
		vector<bool> mark(N,false);
		int n,m;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			int a,b;
			cin>>a>>b;
			graph[a]=b;
		}
		cin>>m;
		for(int i=0;i<m;++i)
		{
			int a,b;
			cin>>a>>b;
			graph[a]=b;
		}
		queue< pair<int,int> > q;
		int ans=INF;
		q.push(make_pair(1,0));
		mark[1]=true;
		while(!q.empty())
		{
			pair<int,int> p=q.front();
			if(p.first==100)
			{
				ans=p.second;
				break;
			}
			q.pop();
			for(int i=1;i<=6;++i)
			{
				int x=p.first+i;
				if(x>100)
					continue;
				if(mark[x]==false)
				{
					mark[x]=true;
					if(graph[x]==0)
						q.push(make_pair(x,p.second+1));
					else
					{
						x=graph[x];
						mark[x]=true;
						q.push(make_pair(x,p.second+1));
					}
				}
			}

		}
		if(ans==INF)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;

	}
}
