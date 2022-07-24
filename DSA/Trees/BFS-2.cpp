//
// Created by Ahsan Ghani on 2022-07-23.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> bfs_traversal;
    vector<bool> vis(V, false);
    for(int i=0; i<V; ++i)
    {
        if(!vis[i])
        {
            queue<int> queue;
            vis[i] = true;
            queue.push(i);
            while(!queue.empty())
            {
                int g_node = queue.front();
                queue.pop();
                bfs_traversal.push_back(g_node);
                for(auto it : adj[g_node])
                {
                    if(!vis[it])
                    {
                        vis[it] = true;
                        queue.push(it);
                    }
                }
            }
        }
    }
    return bfs_traversal;
}