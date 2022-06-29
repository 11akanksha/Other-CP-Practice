// same ques as in Prob5.cpp but with memoization approach:

int f(int day, int last,vector<vector<int>> &task,vector<vector<int>> &dp){
    if(dp[day][last] != -1) return dp[day][last];
    // base case:
    if(day == 0){
        int maxi = 0;
        for(int i=0;i<3;++i){
            if(i!= last){
                maxi = max(maxi,task[0][i]);
            }
        }
        return maxi;
    }
    // recursive case:
    int maxi = 0;
    for(int i=0;i<3;++i){
        if(i!=last){
            int pts = task[day][i] + f(day-1,i,task,dp);
            maxi = max(maxi,pts);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int> (4,-1));
    return f(n-1,3,points,dp);
}
