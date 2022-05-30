//TC:O(N^2)
//MC: O(N)
class Solution {
public:
	long long BASE = 1000000007;
    
	long long getSerializeNumber(int x, int y){
	    return 1LL*x*BASE+y;
    }
    
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<long long, int>lookUp;

        for(auto point: points){
        	lookUp[getSerializeNumber(point[0], point[1])] = 1;
        }

        int minArea = INT_MAX;
        for(int i=0; i<points.size(); ++i){
        	for(int j=i+1; j<points.size();++j){
            	int x1 = points[i][0], y1 = points[i][1];
            	int x2 = points[j][0], y2 = points[j][1];
                
                if(x1==x2 or y1==y2) continue;
                
            	if(lookUp.count(getSerializeNumber(x1,y2)) and lookUp.count(getSerializeNumber(x2,y1))){            
	    	        minArea = min(minArea, abs(y1-y2)*abs(x1-x2));
                }
            }
        }

        return (minArea==INT_MAX)?0:minArea;
    }
};
