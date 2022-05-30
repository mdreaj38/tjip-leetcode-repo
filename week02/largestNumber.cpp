//TC: O(NlogN)
//MC: O(N)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>numString;
        
        for(int i: nums){
            numString.emplace_back(to_string(i));
         }
        
        sort(numString.begin(), numString.end(), [](string a, string b){
                return (a+b)>(b+a);
        });
        
        string largestNum = "";
        for(string num: numString) {
            largestNum+=num;
        }
        
        return (largestNum[0]=='0')?"0": largestNum;
    }
};
