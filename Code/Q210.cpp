#include <vector>
#include <list>

using namespace std;

class node {
public: 
    int index;
    int inDegree;
    vector<int> pointTo;

    node(int index, int inDegree) {
        this->index = index;
        this->inDegree = inDegree;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<node*> courses(numCourses, nullptr);
        for (int i = 0; i < numCourses; i++) {
            courses[i] = new node(i, 0);
        }

        for (vector<int> prerequisite : prerequisites) {
            int from = prerequisite[1], to = prerequisite[0];
            courses[to]->inDegree++;
            courses[from]->pointTo.push_back(to);
        }

        list<node*> zeroInDegrees;
        for (node* ptr : courses) {
            if (!ptr->inDegree) zeroInDegrees.push_back(ptr);
        }  

        vector<int> ret;
        while (zeroInDegrees.size()) {
            node* cur = zeroInDegrees.front();
            zeroInDegrees.pop_front();
            ret.push_back(cur->index);
            for (int to : cur->pointTo) {
                courses[to]->inDegree--;
                if (!courses[to]->inDegree) zeroInDegrees.push_back(courses[to]);
            }
        }

        return ret.size() == numCourses ? ret : vector<int>{};
    }
};