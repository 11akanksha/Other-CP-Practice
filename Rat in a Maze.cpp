class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        if(m[0][0] == 1) inTheMaze(0,0,m,n,"",ans,visited);
        return ans;
    }
    
    void inTheMaze(int i,int j,vector<vector<int>> &a,int n,string path,vector<string> &ans,vector<vector<bool>> &vis){
        // Base Case:
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        
        // Recursive Cases:
        
        // Down:
        if(i+1<n && !vis[i+1][j] && a[i+1][j] == 1){
            vis[i][j] = true;
            inTheMaze(i+1,j,a,n,path + 'D',ans,vis);
            // backtracking Step:
            vis[i][j] = false;
        }
        
        // Left:
        if(j-1>=0 && !vis[i][j-1] && a[i][j-1] == 1){
            vis[i][j] = true;
            inTheMaze(i,j-1,a,n,path + 'L',ans,vis);
            // backtracking Step:
            vis[i][j] = false;
        }
        
        // Right:
        if(j+1<n && !vis[i][j+1] && a[i][j+1] == 1){
            vis[i][j] = true;
            inTheMaze(i,j+1,a,n,path + 'R',ans,vis);
            // backtracking Step:
            vis[i][j] = false;
        }
        
        // Up:
        if(i-1>=0 && !vis[i-1][j] && a[i-1][j] == 1){
            vis[i][j] = true;
            inTheMaze(i-1,j,a,n,path + 'U',ans,vis);
            // backtracking Step:
            vis[i][j] = false;
        }
        
    }
};
