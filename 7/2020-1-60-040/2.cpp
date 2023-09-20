#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
    int V, E;
    cin >> V;
    cin >> E;

    vector<vector<int> > tree;
    vector<int> color;

    bool travel[1000];
    int x, y;

    tree.resize(E);
    color.resize(E , -1);
    memset(travel, 0, sizeof(travel));

    for(int i = 0; i < E; i++)
    {
        tree[i].resize(E);
    }

    for(int i = 0; i < E; i++)
    {
        cin >> x;
        cin >> y;

        x--;
        y--;

        tree[x][y] = 1;
        tree[y][x] = 1;
    }

    bool result;
    color[0] = 1;
    queue <int> p;
    p.push(0);

    while (!p.empty())
    {
        int temp = p.front();
        p.pop();

        for (int i = 0; i < E; i++)
        {
            if (tree[temp][i] && color[i] == -1)
            {
                color[i] = 1 - color[temp];
                p.push(i);
                result = true;
            }

            else if (tree[temp][i] && color[i] == color[temp])
            {
                result = false;
            }
        }
    }

    if(result)
    {
        cout << "YES";
    }

    else
    {
        cout << "NO";
    }

    return 0;
}