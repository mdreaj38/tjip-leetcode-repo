//TC: log(N),
//MC: O(N)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int>track;

		for(auto interval: intervals){
			track[interval[0]]++;
			track[interval[1]]--;		
		}

		int curMeetingCnt = 0, maxMeetingCnt = 0;
		for(auto mp: track){
            curMeetingCnt+=mp.second;
			maxMeetingCnt = max(maxMeetingCnt, curMeetingCnt);		
		}

		return maxMeetingCnt;
    }
};
