#include<iostream>
#include <vector>
#include<queue>
#include<set>
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

    //.........................Dijkstra's algorithm......................//
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector <int> dist(V,1e8);
        set<pair<int,int>> s;
        dist[S]=0;
        s.insert({0,S});
        while(!s.empty()){
            auto p=*(s.begin());
            s.erase(s.begin());
            int node=p.second;
            int d=p.first;
            for(auto x:adj[node]){
                int currDis=d+x[1];
                if(dist[x[0]]>currDis){
                    auto f=s.find({dist[x[0]],x[0]});
                    if(f!=s.end()){
                        s.erase({dist[x[0]],x[0]});
                    }
                    dist[x[0]]=currDis;
                    s.insert({dist[x[0]],x[0]});
                }
            }
        }
        return dist;
    }


    //...................Bellman Ford Algorithm.....................//
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto x:edges){
                int src=x[0];
                int dest=x[1];
                int wt=x[2];
                if(dist[src]!=1e8 && dist[dest]>dist[src]+wt){
                    dist[dest]=dist[src]+wt;
                }
            }
        }
        for(auto x:edges){
                int src=x[0];
                int dest=x[1];
                int wt=x[2];
                if(dist[src]!=1e8 && dist[dest]>dist[src]+wt){
                    vector<int> v(1,-1);
                    return v;
                }
            }
            return dist;
    }