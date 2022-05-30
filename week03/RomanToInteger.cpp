//TC: O(N)
//MC: O(N)
class Solution {
public:
    int romanToInt(string s) {
      unordered_map<char, int>from;
        from['I']=1;
        from['V']=5;
        from['X']=10;
        from['L']=50;
        from['C']=100;
        from['D']=500;
        from['M']=1000;
        
        int sz = s.length();
        int num = from[s[sz-1]];
        
        for(int i=sz-2;i>=0; i--){
            if(from[s[i]]<from[s[i+1]]){
                num-=from[s[i]];
            }else {
                num+=from[s[i]];
            }
        }
        
        return num;
    }
};
