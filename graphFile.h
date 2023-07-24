#include<iostream>
#include <vector>
#include<queue>
using namespace std;


//........................Depth First Search..........................//

void dfshelper(vector<int> adj[], vector<int> &dfs, int src, vector<int> &visited)
{
    dfs.push_back(src);
    visited[src] = 1;
    for (auto x : adj[src])
    {
        if (visited[x] == 0)
        {
            dfshelper(adj, dfs, x, visited);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> dfs;
    vector<int> visited(V, 0);
    dfshelper(adj, dfs, 0, visited);
    return dfs;
}


//.......................Breadth First Search..........................//
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<int> ans;
        vector<int> visited(V,0);
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int topele=q.front();
            q.pop();
            ans.push_back(topele);
            for(auto x:adj[topele]){
                if(visited[x]==0){
                    q.push(x);
                    visited[x]=1;
                }
            }
        }
        return ans;
    }