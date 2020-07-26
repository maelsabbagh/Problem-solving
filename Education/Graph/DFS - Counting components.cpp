//Counting the numbe of componenets in an undirected unweighted graph
 
 
#include <iostream>
#include <vector>
 
 
using namespace std;
 
const int N = 1e4, M = 2e4;
vector<int>adj[N];
bool vis[N];
 
void DFS(int u)
{
	vis[u] = 1;
	for (int v : adj[u])
	{
		if (!vis[v])
		{
			DFS(v);
		}
	}
}
 
int main()
{
	int c = 0;
	int n, m, u, v;   // undirected graph
	cin >> n >> m;    // n = nodes , m= edges;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			DFS(i);
			c++;
		}
	}
	cout << "components= " << c << endl;
	system("pause");
	return 0;
}