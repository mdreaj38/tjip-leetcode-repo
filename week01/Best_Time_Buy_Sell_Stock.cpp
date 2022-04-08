int maxProfit(vector<int>& prices) {
	int sz = prices.size();
	int suffMax[sz];

	suffMax[sz-1] = prices[sz-1];

	for(int i=sz-2; i>=0; i--){
		suffMax[i] = max(prices[i], suffMax[i+1];
	}

	int mxProfit=INT_MIN;
	for(int i=0;i+1<sz; ++i{
		mxProfit = max(mxProfit, -prices[i]+suffMax[i+1]);
	}

	return mxProfit;
}
