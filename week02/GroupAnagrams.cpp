//TC:O(NK), N = input vector size, K=max string length
// MC: O(NK)
class Solution {
public:
    string hash(vector<int>v){
        string temp="";
        for(int i: v) temp+=to_string(i)+"#";
        
        return temp;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagram;
		
		for(auto str: strs){
			vector<int>freq(26, 0);
			
			for(char ch: str) freq[ch-'a']++;
			
            string key = hash(freq);
            anagram[key].push_back(str);
		}
			
		for(auto [key, value]: anagram){
			ans.emplace_back(value);
		}

		return ans;
    }
};
