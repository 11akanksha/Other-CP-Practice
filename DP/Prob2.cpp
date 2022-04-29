class Solution {
public:
    void findCombi(int idx, int t,vector<int> arr, vector<int> &ds, vector<vector<int>> &ans){
        if(t == 0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx; i<arr.size(); ++i){
            if(i>idx && arr[i] == arr[i-1]) continue;
            if(arr[i] > t) break;
            
            //recursive case:
            ds.push_back(arr[i]);
            findCombi(i+1,t-arr[i],arr,ds,ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        findCombi(0,target,candidates,ds,ans);
        return ans;
    }
};
