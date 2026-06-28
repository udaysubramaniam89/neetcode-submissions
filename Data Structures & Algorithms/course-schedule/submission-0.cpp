class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(vector<int>& prereq : prerequisites){
            int course = prereq[0];
            int pre = prereq[1];

            graph[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int course = 0; course < numCourses; course++){
            if(indegree[course] == 0){
                q.push(course);
            }
        }

        int coursesTaken = 0;

        while(!q.empty()){
            int course = q.front();
            q.pop();
            coursesTaken++;

            for(int nextCourse : graph[course]){
                indegree[nextCourse]--;

                if(indegree[nextCourse] == 0){
                    q.push(nextCourse);
                }
            }
        }
        return coursesTaken == numCourses;
    }
};
