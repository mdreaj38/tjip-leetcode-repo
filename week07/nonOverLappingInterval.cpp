// TC: Nlog(N)
// MC: O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
		
		int remove = 0, lastEnd = intervals[0][1];

		for(int i = 1; i<intervals.size(); ++i){
			int curStart = intervals[i][0];
			int curEnd = intervals[i][1];
			
			if(curStart<lastEnd){
				lastEnd = min(lastEnd, curEnd);
				remove++;	
		
			}else {
				lastEnd = curEnd;
			}
		}

		return remove;
    }
};
