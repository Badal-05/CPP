#include <bits/stdc++.h>
using namespace std;
struct Vertex
{
    int h;
    int eflow;
};
int v, e;
int **cap, **flow;
struct Vertex *vert;
int getactivenode(int source, int sink)
{
    for (int i = 1; i < v - 1; i++) // consider only the intermediate nodes excluding source & sink
    {
        if (vert[i].eflow > 0) // eflow node
        {
            for (int j = 0; j < v; j++)
            {
                if (cap[i][j] != 0 || flow[i][j] != 0) // check both cap[][] & flow[][] to find the neighbors
                {
                    if (cap[i][j] != flow[i][j]) // check if there is residual capacity
                        return i;
                }
            }
        }
    }
    return -1;
}
void preflow(int s)
{
    vert[s].h = v;
    for (int i = 0; i < v; i++)
    {
        if (i != s && cap[s][i] != 0)
        {
            flow[s][i] = cap[s][i];
            flow[i][s] = -cap[s][i];
            vert[i].eflow += cap[s][i];
        }
    }
}
bool push(int u)
{
    for (int i = 0; i < v; i++)
    {
        if (cap[u][i] != 0 || flow[u][i] != 0)
        {
            if (flow[u][i] == cap[u][i])
                continue;
            if (vert[u].h > vert[i].h)
            { // minimum of residual capacity[u][i] and eflow(u)
                int Flow = cap[u][i] - flow[u][i] < vert[u].eflow ? cap[u][i] - flow[u][i] : vert[u].eflow;
                vert[u].eflow -= Flow;
                vert[i].eflow += Flow;
                flow[u][i] += Flow;
                flow[i][u] -= Flow;
                return true;
            }
        }
    }
    return false;
}
void relabel(int u)
{
    int minh = INT_MAX;
    for (int i = 0; i < v; i++)
    {
        if (cap[u][i] != 0 || flow[u][i] != 0)
        {
            if (cap[u][i] == flow[u][i])
                continue;
            if (vert[i].h < minh) // at the end of loop, height of least height node is considered
            {
                minh = vert[i].h;
                vert[u].h = minh + 1;
            }
        }
    }
}
int maxFlow(int source, int sink)
{
    preflow(source);
    cout << "\nInitial capacity\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << cap[i][j] << " ";
        cout << "\n";
    }
    int u = getactivenode(source, sink);
    while (u !=
           -1)
    {
        if (!push(u))
            relabel(u);
        u = getactivenode(source, sink);
    }
    return vert[sink].eflow;
}
int main()
{
    cout << "Enter no. of vertices: ";
    cin >> v;
    // v=6;
    cout << "Enter no. of edges: ";
    cin >> e;
    // e=10;
    vert = new Vertex[v];
    cap = new int *[v];
    for (int i = 0; i < v; i++)
        cap[i] = new int[v];
    flow = new int *[v];
    for (int i = 0; i < v; i++)
        flow[i] = new int[v];

    cout << "Enter edges and their capacity \n";
    for (int i = 0; i < v; i++)
    {
        vert[i].h = 0;
        vert[i].eflow = 0;
        for (int j = 0; j < v; j++)
        {
            flow[i][j] = 0;
            cap[i][j] = 0;
        }
    }
    int x, y, c;
    for (int i = 0; i < e; i++)
    {
        cout<<"Enter the edge: ";
        cin >> x >> y ;
        cout<<"Enter the capacity: ";
        cin >> c;
        cap[x][y] = c;
    }
    /* cap[0][1]=1;
    cap[0][2]=100;
    cap[1][2]=100;
    cap[2][1]=1
   ;
    cap[1][3]=100;
    cap[2][3]=1;
    */
    cout << "Enter source and sink \n";
    int source, sink;
    cin >> source >> sink;
    cout << "The max flow is : " << maxFlow(source, sink);
    cout << "\nfinal flow\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << flow[i][j] << " ";
        cout << "\n";
    }
}