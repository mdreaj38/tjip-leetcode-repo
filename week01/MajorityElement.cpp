int majorityElement(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int sz = nums.size();

	return nums[sz/2];
}
