//TC:O(N)
//MC: O(N)
class DetectSquares {
public:
	unordered_map<long long, int> points;
	int BASE = 1000000007;

    DetectSquares() {
        points.clear();
    }
    
    void add(vector<int> point) {
		points[hash(point[0], point[1])]++;
    }
    
    int count(vector<int> point) {
		int cnt = 0;
        for(auto &[key,value]:points){
			int x1 = point[0], y1 = point[1];
			int x2 = key/BASE, y2 = key%BASE;
			
			if(x1==x2 or abs(x1-x2)!=abs(y1-y2)) continue;

			if(points.count(hash(x1,y2)) and points.count(hash(x2,y1)))
				cnt+=(value*points[hash(x1,y2)]*points[hash(x2, y1)]);	
		}

		return cnt;
    }
	
	long long hash(int x, int y){
		return 1LL*x*BASE+y;	
	}
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

