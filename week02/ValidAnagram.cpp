//TC: O(N)
//MC: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        char freq[26];
        fill(freq, freq+26, 0);

        for(char ch: s)
    	    freq[ch-'a']++;

        for(char ch: t)
        	freq[ch-'a']--;

        for(int i=0; i<26; ++i)
          	if(freq[i]) return false;

        return true;
    }
};
