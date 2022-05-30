//TC: O(n)
//MC: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if(!s.length()) return 0;

		int maxLen = 0, freq[128];
		fill(freq, freq+128, 0);
		
		for(int R=0, L=0; R<s.length(); ++R){
			char ch = s[R];
			freq[ch]++;

			if(freq[ch]>1){
				while(L<R and freq[ch]>1) {
					freq[s[L++]]--;
				}
			}

			maxLen = max(maxLen, R-L+1);
		}
		
		return maxLen;
    }
};
