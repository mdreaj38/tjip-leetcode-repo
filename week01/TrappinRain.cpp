int trap(vector<int>& height) {
	int l = 0;
	int r = height.size()-1;
	
	int LeftMax = 0, RightMax = 0;
	int totalArea = 0;	
	while(l<r){
		LeftMax = max(LeftMax, height[l]);
		RightMax=max(RightMax, height[r]);
		
		if(height[l]>height[r]){
			totalArea += (RightMax-height[r--]);	
		}else{
			totalArea +=(LeftMax-height[l++]);
		}
	}
	
	return totalArea;        
}
