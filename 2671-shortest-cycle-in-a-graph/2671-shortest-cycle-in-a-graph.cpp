class Solution {
public:
    int shortestCycle(int numVertices, vector<int> graph[]){
        int minCycleLen = INT_MAX;
        for (int srcVertex = 0; srcVertex < numVertices; srcVertex++) {
            
            vector<int> distances(numVertices, (int)(1e9));
            
            vector<int> parent(numVertices, -1);
            distances[srcVertex] = 0;
            queue<int> vertexQueue;
            vertexQueue.push(srcVertex);
            while (!vertexQueue.empty()) {
                int currVertex = vertexQueue.front();
                vertexQueue.pop();

                for (int childVertex : graph[currVertex]) {
                    if (distances[childVertex] == (int)(1e9)) {
                        distances[childVertex] = 1 + distances[currVertex];
                        parent[childVertex] = currVertex;

                        vertexQueue.push(childVertex);
                    }

                    else if (parent[currVertex] != childVertex and parent[childVertex] != currVertex)
                        minCycleLen = min(minCycleLen, distances[currVertex] + distances[childVertex] + 1);
                }
            }
        }

        if (minCycleLen == INT_MAX)
            return -1;
        else
            return minCycleLen;
    }

    int findShortestCycle(int numVertices, vector<vector<int>>& edges) {
        vector<int> adjList[numVertices];
        for(auto edge: edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        return shortestCycle(numVertices, adjList);
    }
};