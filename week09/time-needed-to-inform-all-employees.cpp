// TC: O(N + E), where N and E = total number of nodes and edges
// MC: O(H), where H = height of tree
class Solution {
public:
	vector<vector<int>>adjList;

	int findMinTime(int root, vector<int> &informTime){
		int maxTime = 0;

		for(int i : adjList[root]){
			maxTime = max(maxTime, findMinTime(i, informTime));
		}

		return maxTime + informTime[root];
	}

	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adjList.clear();
		adjList.resize(n);

		for(int i = 0; i < n; ++i){
			if(manager[i] != -1){
				adjList[manager[i]].emplace_back(i);			
			}
		}

		return findMinTime(headID, informTime);
	}
};
