long long pow[10005];
long long prefixHash[10005];
int MOD = 1e9+7;
int BASE = 29;

void preProcess(string haystack){
	refixHash[0] = haystack[0]-'a';
	pow[0]=1;
	
	for(int i=1; i<haystack.size(); ++i){
		prefixHash[i] = prefixHash[i-1]*BASE+(haystack[i]-'a');
		prefixHash[i]%=MOD;

		pow[i] = (BASE*pow[i-1])%MOD;
	}
}

// Time Complexity: O(n), Memory Complexity: O(n)
int strStr(string haystack, string needle) {
	int lenHaystack = haystack.size();
	int lenNeedle = needle.size();

	if(!lenNeedle) return 0;
	if(lenNeedle>lenHaystack) return -1;

	preProcess(haystack);

	long long hashNeedle = 0;
	for(int i=0; i<lenNeedle; ++i){
		hashNeedle*=BASE;
		hashNeedle+=(needle[i]-'a');
		hashNeedle%=MOD;
	}

	for(int i=0; i<=(lenHaystack-lenNeedle); ++i){
		if(getRangeHash(i, i+lenNeedle-1) == hashNeedle)
			return i;
	}

        return -1;
}

long long getRangeHash(int L, int R){
	if(!L) return prefixHash[R];

	long long hash = prefixHash[R] - (prefixHash[L-1]*pow[R-L+1])%MOD;

	return (hash+MOD)%MOD;
}
