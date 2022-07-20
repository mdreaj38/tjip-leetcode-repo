// TC: O(MN)
// MC: O(MN)
class Solution {
public:
    static const int WALL = -1;
    static const int GATE = 0;
	static constexpr int dRow[4] = {1, -1, 0, 0};
	static constexpr int dCol[4] = {0, 0, 1, -1};

	int row, col;

	bool isValidCell(int r, int c){
		return r>=0 and r<row and c>=0 and c<col;
	}

	void wallsAndGates(vector<vector<int>>& rooms) {
		row = rooms.size(), col = rooms[0].size();

		queue<pair<int,int>>q;
		
		for(int i = 0; i<row; ++i)
			for(int j = 0; j<col; ++j){
				if(rooms[i][j] == GATE){
					q.push(make_pair(i,j));
				}
			}

		while(!q.empty()){
			int r = q.front().first,
				c = q.front().second;
			q.pop();
			
			for(int i = 0; i < 4; ++i){
				int nextR = r + dRow[i];
				int nextC = c + dCol[i];

				if(!isValidCell(nextR, nextC)){
					continue;
			
				}else if(rooms[nextR][nextC] != WALL and rooms[r][c]+1 < rooms[nextR][nextC]){
					rooms[nextR][nextC] = rooms[r][c]+1;
					q.push(make_pair(nextR, nextC));		
				}
			}
		}	
	}
};
