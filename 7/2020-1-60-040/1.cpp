#include <bits/stdc++.h>

using namespace std;

void with_edge(vector<int> array[], int source, int d)
{
    array[source].push_back(d);
    array[d].push_back(source);
}

bool BFS(vector<int> array[], int source, int d, int v,
         int pred[], int dist[])
{
    list<int> queue;
    bool visited[v];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    visited[source] = true;
    dist[source] = 0;
    queue.push_back(source);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();

        for (int i = 0; i < array[u].size(); i++)
        {
            if (visited[array[u][i]] == false)
            {
                visited[array[u][i]] = true;
                dist[array[u][i]] = dist[u] + 1;
                pred[array[u][i]] = u;
                queue.push_back(array[u][i]);

                if (array[u][i] == d)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

void Distance(vector<int> array[], int s, int d, int v)
{
    int pred[v], dist[v];

    vector<int> path;
    int crawl = d;
    path.push_back(crawl);

    while (pred[crawl] != -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    cout<< dist[d];
}

int main()
{
	int V, E;
	int x, y;
	int s, d;

	cin >> V;
	cin >> E;
	V = V + 1;

    vector<int> array[V];

    for (int i = 1; i <= E; i++)
    {
        cin >> x;
        cin >> y;
        with_edge(array, x, y);
    }

    cin >> s;
    cin >> d;

   Distance(array, s, d, V);
   return 0;
}