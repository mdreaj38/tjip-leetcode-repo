class Solution {
public:
    bool isValid(string s) {
        stack<char>openPar;

        for(char chr:s){
    	    if(openPar.empty() or chr=='(' or chr=='{' or chr=='[')
    	    	openPar.push(chr);
    	    else{
    	    	char temp = openPar.top();
		if(chr!=getCloseBracket(temp)) 
			return false;
			
		openPar.pop();
            }
        }

        return openPar.empty();        
    }

    char getCloseBracket(char ch){
    	if(ch=='(') return ')';
    	if(ch=='{') return '}';
	    
        return ']';
    }
};
