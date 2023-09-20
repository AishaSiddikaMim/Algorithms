#include<bits/stdc++.h>

using namespace std;

int a = -(INT_MAX), b;
int vct[10001], array1[10001];

vector<int>graph[10001];

void bfs(int vertices, int b)
{
	vct[vertices] = 1;
	array1[vertices] = b;
	
    if(array1[vertices] > a)
	{
		a = array1[vertices];
		b = vertices;
	}

	for(int destination: graph[vertices])
	{
		if(vct[destination] == 0)
		{
			bfs(destination, array1[vertices] + 1);
		}
	}
}
int main()
{
	int V, E, x, y;
	
    cin >> V >> E;

	while(E--)
	{
		cin >> x >>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	bfs(1, 0);

	a = -1;

	for(int i = 1; i <= V; i++)
    vct[i] = 0;
	bfs(b, 0);

	cout << a <<endl;
	return 0;
}