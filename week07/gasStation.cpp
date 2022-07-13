// TC: O(N)
// MC: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0, sz = gas.size();

		for(int i = 0; i < sz; ++i){
			totalCost+=gas[i];
			totalCost-=cost[i];		
		}
		
		if(totalCost<0){
			return -1;		
		}
        
		int startIndex = 0;
        int mxShortage = 0, curShortage = 0;
		
		for(int i = 0; i < sz; ++i){
            curShortage+=(cost[i] - gas[i]);
                
            if(curShortage > mxShortage){
                startIndex = i + 1;
                mxShortage = curShortage;
            }
		}

		return startIndex%sz;
    }
};
