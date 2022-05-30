//TC: NlogN
//MC: N
class Solution {
public:
    bool isIsomorphic(string s, string t, int flag = 0) {
        unordered_map<char, char> from;
        
		for(int i =0;i <s.length(); ++i){
	        if(from.count(s[i]) and from[s[i]]!=t[i])
	        	return false;

	        from[s[i]] = t[i];
        }
        
        if(!flag) return isIsomorphic(t, s, 1);

        return true;
    }
};
