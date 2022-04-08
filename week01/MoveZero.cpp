void moveZeroes(vector<int>& nums) {
	int pos = 0;
        int curZero=0;
        
        for(int i=0;i<nums.size(); ++i){
            if(!nums[i]) curZero++;
            else {
                swap(nums[i], nums[i-curZero]);
            }
        }
}
