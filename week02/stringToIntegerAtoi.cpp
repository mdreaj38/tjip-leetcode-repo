//TC: O(n)
//MC: O(1)
class Solution {
public:
	string trim(string s){
	    string temp ="";
	    int pos = 0;

	    while(pos<s.length() and s[pos]==' ') pos++;

	    if(pos<s.length() and s[pos]=='+' or s[pos]=='-') {
	    	temp+=s[pos++];
        }

	    while(pos<s.length() and isdigit(s[pos])) temp+=s[pos++];

	    return temp;
    }
    
    int myAtoi(string s) {
	    string trimmedString = trim(s);

	    if(!trimmedString.length()) return 0;

	    long long num = 0;
        int sign = 1, pos = 0;;
        
    	if(trimmedString[pos]=='-') {
    	    sign = -1;
	        pos++;
            
        }else if(trimmedString[pos]=='+'){
            pos++;
        }

        while(pos<trimmedString.length() and isdigit(trimmedString[pos])){		
            num*=10;
	        num+=(trimmedString[pos++]-'0');
            
	        if(num*sign>INT_MAX) return INT_MAX;
	        if(num*sign<INT_MIN) return INT_MIN;
        }

        return sign*num;
    }
};
