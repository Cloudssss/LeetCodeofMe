#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> ans,sz,dp;
    vector<vector<int>> graph;

    void dfs(int u,int f)
    {
        dp[u]=0;
        sz[u]=1;
        for(auto &v: graph[u])
        {
            if (v==f) continue;
            dfs(v,u);
            dp[u] = dp[u]+dp[v]+sz[v];
            sz[u]=sz[v]+sz[u];
        }
    }

    void dfs2(int u, int f)
    {
        ans[u] = dp[u];
        for(auto &v : graph[u])
        {
            if (v==f) continue;
            int pu = dp[u],pv = dp[v];
            int su = sz[u],sv = sz[v];

            dp[u] = dp[u] - (dp[v]+sz[v]);
            sz[u] = sz[u] - sz[v];

            dp[v] = dp[u] + sz[u] + dp[v];
            sz[v] = sz[u] + sz[v];

            dfs2(v,u);

            dp[u] = pu;
            dp[v] = pv;
            sz[u] = su;
            sz[v] = sv;
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        ans.resize(N);
        sz.resize(N);
        dp.resize(N);
        graph.resize(N,{});

        for (auto &edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        dfs(0,-1);
        dfs2(0,-1);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
