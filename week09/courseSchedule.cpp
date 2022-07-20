// TC: O(V+E)
// MC: O(V)
class Solution {
public:
    bool hasCycle(int s, int visit[], vector<int>graph[]){
        visit[s] = 1;
        
        for(int i:graph[s]){
            if(visit[i] == 1){
                return true;
            }
            if(!visit[i] and hasCycle(i, visit, graph)){
                return true;
            }
        }
        visit[s] = 2;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>graph[numCourses];
        int visit[numCourses];
        fill(visit, visit + numCourses, 0);

        for(auto subjects: prerequisites){
            graph[subjects[1]].emplace_back(subjects[0]);
        }    

        for(int i = 0; i<numCourses; ++i){
            if(!visit[i] and hasCycle(i, visit, graph)){
                return false;
            }
        }
        
        return true;
    }
};
