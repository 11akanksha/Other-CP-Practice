int f(int i,int j,vector<vector<int>> &mat,int m){
    if(j<0 || j>=m) return -1e9;
    if(i==0) return mat[i][j];
    
    // recursive case:
    int up = mat[i][j] + f(i-1,j,mat,m);
    int ld = mat[i][j] + f(i-1,j-1,mat,m);
    int rd = mat[i][j] + f(i-1,j+1,mat,m);
    
    return max(up,max(ld,rd));
}


int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e9;
    for(int i=0;i<m;++i){
        maxi = max(maxi,f(n-1,i,matrix,m));
    }
    return maxi;
}
