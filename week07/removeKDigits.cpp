// TC: O(N), N = length of num
// MC: O(N)
class Solution {
public:
    string removeKdigits(string num, int k) {
        int sz = num.size();
        stack<char>digits;
        
        for(int i=0; i<sz; ++i)
		{
			while(k and !digits.empty() and digits.top()>num[i])
				{	
					digits.pop();
					k--;
				}
			digits.push(num[i]);
		}
        
		while(k and !digits.empty())
		{
			digits.pop();
			k--;
		}
		
		if(digits.empty()) return "0";
		
		string ans = "";
		while(!digits.empty())
		{
			ans.push_back(digits.top());
			digits.pop();
		}
        
		while(!ans.empty() and ans.back()=='0')
		{
			ans.pop_back();
		}
        
		reverse(ans.begin(), ans.end());
		
		return ans.empty()? "0": ans;
    }
};
