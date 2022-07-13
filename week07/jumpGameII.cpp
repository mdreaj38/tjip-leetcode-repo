// TC: O(n)
// MC: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int nxtJumpStart = 0, 
			farthest = 0, 
			jumpCnt = 0;

		for(int i = 0; i + 1<nums.size(); ++i){
			farthest = max(farthest, nums[i]+i);
			
			if(i == nxtJumpStart){
				jumpCnt++;
				nxtJumpStart = farthest;			
			}
		}

		return jumpCnt;
    }
};
