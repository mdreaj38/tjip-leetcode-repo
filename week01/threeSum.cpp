vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();++i){
            if(i and nums[i]==nums[i-1]) continue;
            
            int l = i+1, r= (int)nums.size()-1;
            while(l<r){
                int sum = nums[l]+nums[r]+nums[i];
                if(sum == 0){
                     
                    ans.push_back({nums[l],nums[r],nums[i]});
                    
                    while(l<r and nums[l]==nums[l+1]) l++;
                    l++;
                }
                else if(sum<0) l++;
                else r--;
            }    
        }
        
        return ans;
}
