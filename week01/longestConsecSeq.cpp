int longestConsecutive(vector<int>& nums) {
        unordered_set<int>bucket(nums.begin(), nums.end());
        
        int maxLength = 0;
        int curLength = 0;
        
        for(int num: nums){
            if(!bucket.count(num-1)){
                int curNum = num;
                curLength = 0;
                
                while(bucket.count(curNum++)){
                    curLength++;
                    maxLength = max(maxLength, curLength);
                }
                
            }
        }
        
	return maxLength;
}
