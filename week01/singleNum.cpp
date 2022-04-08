int singleNumber(vector<int>& nums) {
        int missingNum=0;
        for(int num:nums){
            missingNum^=num;
        }
        
        return missingNum;
}
