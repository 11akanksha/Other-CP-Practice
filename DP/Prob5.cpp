// Ques: Ninja's Training.
// Solution:

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // using tabulation:
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    // if we have only one day:
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
    
    // iterating on each day:
    for(int day=1;day<n;++day){
        // iterating over the last:
        for(int last = 0;last<4;++last){
            // we want to compute:
            dp[day][last] = 0;
            // iterating on all tasks:
            for(int task = 0; task<3;++task){
                if(task!=last){
                   int pts = points[day][task] + dp[day-1][task];
                   dp[day][last] = max(dp[day][last],pts);
                }
            }
        }
    }
    return dp[n-1][3];
}
