class Solution {
public:
    void findPerm(int idx,vector<int> &nums,vector<vector<int>> &ans){
            if(idx == nums.size()){
                ans.push_back(nums);
                return;
            }
            
            for(int i = idx; i<nums.size(); ++i){
                swap(nums[idx],nums[i]);
                findPerm(idx+1,nums,ans);
                swap(nums[idx],nums[i]);
            }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPerm(0,nums,ans);
        return ans;
    }
};