// TC: O(N)
// MC: O(N)
mt19937 mt(0);
class Solution {
public:
    vector<int>prefixSum;
        
    Solution(vector<int>& w) {
        prefixSum = w;
        
        for(int i = 1; i<w.size(); ++i){
            prefixSum[i]+= prefixSum[i-1];
        }
    }
    
    int pickIndex() {
        int randomNum = getRandomInRange(1, prefixSum.back());
        
        return lower_bound(prefixSum.begin(), prefixSum.end(), randomNum) - prefixSum.begin();
    }
    
    int getRandomInRange(int L, int R){
        return L + (mt() % (R - L + 1)); 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

