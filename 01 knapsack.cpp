int f(int idx,int W,vector<int> &wt, vector<int> &val){
    if(idx == 0){
        if(wt[0] <= W) return val[0];
        return 0;
    }
    
    int nt = 0 + f(idx-1,W,wt,val);
    int t = 0;
    if(wt[idx] <= W) t = val[idx] + f(idx-1,W-wt[idx],wt,val);
    
    return max(t,nt);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return f(n-1,maxWeight,weight,value);
}
