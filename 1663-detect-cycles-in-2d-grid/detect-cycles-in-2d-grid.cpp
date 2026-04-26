class Solution {
public:
    bool dfs(vector<vector<char>> &g, int i ,int j ,int pi ,int pj ,vector<vector<int>> &vis){
        int m=g.size();
        int n=g[0].size();
        vis[i][j]=1;
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

        for(auto&x:d){
            int ni=i+x[0],nj=j+x[1];
            if(ni<0||nj<0||ni>=m||nj>=n||g[ni][nj]!=g[i][j]){
                continue;
            }
            if(ni==pi&&nj==pj){
                continue;
            }
            if(vis[ni][nj]){
                return true;
            }
            if(dfs(g,ni,nj,i,j,vis)){
                return true;
            }
        }
        return false;
    }

bool containsCycle(vector<vector<char>>&grid){
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>>vis(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                if(dfs(grid,i,j,-1,-1,vis))return true;
            }
        }
    }
    return false;
}
};