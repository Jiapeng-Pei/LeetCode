#include <string>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool> visited(n, false);
        int endIndex = -1;
        unordered_map<string, vector<int>> genericMap;

        // contruct the graph.
        for (int i = 0; i < n; i++) {
            string word = wordList[i];
            if (word == beginWord) {
                visited[i] = true;
                continue;
            }
            if (word == endWord) endIndex = i;
            for (int j = 0; j < word.size(); j++) {
                string tmpWord = word;
                tmpWord[j] = '*';
                if (genericMap.count(tmpWord)) {
                    genericMap[tmpWord].push_back(i);
                }
                else {
                    genericMap[tmpWord] = vector<int>{i};
                }
            }
        } 


        if (endIndex == -1) return false;
        list<int> deque;
        // -1 represents the beginWord.
        deque.push_back(-1);
        
        int words = 1;
        while (deque.size() && !visited[endIndex]) {
            int size = deque.size();

            for (int i = 0; i < size && !visited[endIndex]; i++) {
                int index = deque.front();
                deque.pop_front();
                string from = index == -1 ? beginWord : wordList[index];

                for (int j = 0; j < from.size() && !visited[endIndex]; j++) {
                    string genericFrom = from;
                    genericFrom[j] = '*';
                    if (genericMap.count(genericFrom)) {
                        for (int to : genericMap[genericFrom]) {
                            if (visited[to]) continue;
                            visited[to] = true;
                            deque.push_back(to);
                        }
                    }
                }
            }

            words++;
        }

        return visited[endIndex] ? words : 0;
    }   
};