int f(int i,int j,vector<vector<int>> &g){
    // recursion:
    if(i==0 && j==0) return g[i][j];
    if(i<0 || j<0) return 1e9;
    int up = g[i][j] + f(i,j-1,g);
    int left = g[i][j] + f(i-1,j,g);
    return min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    return f(n-1,m-1,grid);
}
