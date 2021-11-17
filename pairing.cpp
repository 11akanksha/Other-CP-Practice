//Uses DSU:
#include <iostream>
#include <list>
using namespace std;

//Using path compression optimisation in find function
//and union by rank in union function makes the TC = O(1) approx.
class Graph
{
    list<pair<int, int>> l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int x, int y)
    {
        l.push_back(make_pair(x, y));
    }

    int findSet(int i, int *parent)
    {
        if (parent[i] == -1)
        {
            return i;
        }
        //Path Compression Optimisation:
        return parent[i] = findSet(parent[i], parent);
    }

    void unionSet(int x, int y, int *parent, int *rank)
    {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        //Union by rank
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    int pairing()
    {
        int *parent = new int[V];
        int *rank = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        for (auto edge : l)
        {
            int a = edge.first;
            int b = edge.second;

            int S1 = findSet(a, parent);
            int S2 = findSet(b, parent);

            unionSet(S1, S2, parent, rank);
        }
        int ans = 0;
        for (int i = 0; i < V; i++)
        {
            ans += V - rank[findSet(i, parent)];
        }

        delete[] parent;
        delete[] rank;
        return ans / 2;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << g.pairing() << endl;
    return 0;
}

//i/p:
5 3
0 1
1 4
2 3
//O/p:
6
