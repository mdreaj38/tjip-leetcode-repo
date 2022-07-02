
class Solution {
public:

	// Approch 1
	// TC: log(mn)
	// MC: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int candidateRow = 0, low = 0, high = matrix.size()-1;
		
		while(low <= high){
			int mid = low + (high - low)/2;
				if(matrix[mid][0] > target){
					high = mid-1;
                    
				}else{
					low = mid+1;
                    candidateRow = mid;
				}
		}
        
		return binary_search(matrix[candidateRow].begin(), matrix[candidateRow].end(), target);   
    }

	
	// Approach 2
	// TC: log(m+n)
	// MC: O(1)
	// Using the binary search tree property of this matrix. 
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size(), col = matrix[0].size(), R = 0, C = col - 1;
        
        while(R < row and C>=0){
            if(target == matrix[R][C]){
                return true;
                
            }
            else if(target < matrix[R][C]){
                C--;
                
            }else{
                
                R++;
            }
        }
        
        return false;
    }
};
