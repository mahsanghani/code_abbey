#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>

using namespace std;

class Solution {
    public:
    bool bipartiteMatch(const vector<vector<int>>& grid, int u, vector<bool> visited, vector<int>& girls) {
        int m = grid.size();
        int n = grid[0].size();
        for (int v=0; v<n; v++) {
            if (grid[u][v] && !visited[v]) {
                visited[v] = true;
                if (girls[v]<0 || bipartiteMatch(grid,girls[v],visited,girls)) {
                    girls[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    int maximumInvitations(vector<vector<int>>& grid) {
        int matches = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> girls(n,-1);

        for (int u=0; u<m; u++) {
            vector<bool> visited(n,false);
            if (bipartiteMatch(grid,u,visited,girls)) {
                matches++;
            }
        }
        return matches;
    }
};