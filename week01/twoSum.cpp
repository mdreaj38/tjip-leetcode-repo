class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>bucket;

        for(int i=0; i<nums.size(); ++i){
	        if(bucket.count(target-nums[i])) 
		        return {i, bucket[target-nums[i]]};

	        bucket[nums[i]] = i;;
        }

        return {};
    }
};
