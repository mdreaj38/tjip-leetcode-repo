// TC: O(MN)
// MC: O(MN)
class Solution {
public:
	static const char DONE = '#';
	static constexpr int dRow[4] = {1, -1, 0, 0};
	static constexpr int dCol[4] = {0, 0, 1, -1};
	int row, col;
    
	bool isValidCell(int r, int c){
		return r>=0 and r<row and c>=0 and c<col;
	}

	void dfs(int r, int c, vector<vector<char>> &grid){
		if(!isValidCell(r, c) or grid[r][c] != '1'){
			return;
		}

		grid[r][c] = DONE;

		for(int i = 0; i < 4; ++i){
			dfs(r + dRow[i], c + dCol[i], grid);		
		}
	}

	int numIslands(vector<vector<char>>& grid) {		
		int countIsland = 0;        
		row = grid.size(), col = grid[0].size();

		for(int i = 0; i < row; ++i){
			for(int j = 0; j < col; ++j){
				if(grid[i][j] == '1'){
					dfs(i, j, grid);
					countIsland++;
				}
			}
		}
		
		return countIsland;
	}
};
