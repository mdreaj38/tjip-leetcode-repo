string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size();

        if(!sz) return "";

        int longestPrefLen = INT_MAX;
        for(int i=0; i<sz; ++i){
	        longestPrefLen = min(longestPrefLen, getCommonPrefLength(strs[0], strs[i]));
        }

        string longestPref = "";
        for(int i=0; i<longestPrefLen; ++i){
	        longestPref+= strs[0][i];
        }

        return longestPref;
    }
    
int getCommonPrefLength(string str1, string str2){
	int ans = 0;
        
        for(int i=0; i<min(str1.length(), str2.length()); ++i){
	        if(str1[i]==str2[i]) ans++;
	        else break;
        }
        
        return ans;
}
