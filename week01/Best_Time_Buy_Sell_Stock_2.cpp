int maxProfit(vector<int>& prices) {
	int sz = prices.size();
	int i = 0;
	int profit = 0;

	while(i+1<sz){
		while(i+1<sz){
			if(prices[i]<prices[i+1]) break;
			i++;
		}

		int buyDay  = i;

		while(i+1<sz){
			if(prices[i]>prices[i+1]) break;
			i++;
		}

		int sellDay = i;
		profit+=prices[sellDay]-prices[buyDay];
	}        

	return profit;
}
