

class Solution {
    private:
    void dfsofgraph(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&res){
        vis[node]=1;
        res.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfsofgraph(it,adj,vis,res);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();
       vector<int>visited(v,0);
        int s=0;
        vector<int>res;
        dfsofgraph(s,adj,visited,res);
        return res;
    }
};