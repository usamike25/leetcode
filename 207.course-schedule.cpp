/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution
{
public:
    bool dfs(int course, unordered_map<int, vector<int>> &m, unordered_set<int> &visited){

        //check if visites
        if (visited.find(course) != visited.end())
        {
            return false;
        }
        

        //check if no pre req
        if (m[course].empty())
        {
            return true;
        }

        //check dfs
        visited.insert(course);
        for (int i = 0; i < m[course].size(); i++)
        {
            int nextCourse = m[course][i];
            if (!dfs(nextCourse, m, visited))
            {
                return false;
            }
        }
        m[course].clear();
        visited.erase(course);
        return true;
    }

        bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // map each course to prereq list
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        // all courses along current DFS path
        unordered_set<int> visited;

        for (int course = 0; course < numCourses; course++)
        {
            if (!dfs(course, m, visited))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
