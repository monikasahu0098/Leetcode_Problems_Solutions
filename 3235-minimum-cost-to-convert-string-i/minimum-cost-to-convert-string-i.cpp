class Solution {
public:
    void FloydWarshall(vector<vector<long long>>& adjMatrix,
                       vector<char>& original,
                       vector<char>& changed,
                       vector<int>& cost) {

        // direct transformations
        for (int i = 0; i < original.size(); i++) {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            adjMatrix[s][t] = min(adjMatrix[s][t], (long long)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (adjMatrix[i][k] < 1e18 && adjMatrix[k][j] < 1e18) {
                        adjMatrix[i][j] = min(adjMatrix[i][j],
                                               adjMatrix[i][k] + adjMatrix[k][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;
        vector<vector<long long>> adjMatrix(26, vector<long long>(26, INF));

        // distance to itself = 0
        for (int i = 0; i < 26; i++) {
            adjMatrix[i][i] = 0;
        }

        FloydWarshall(adjMatrix, original, changed, cost);

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (adjMatrix[s][t] == INF) {
                return -1;
            }
            ans += adjMatrix[s][t];
        }

        return ans;
    }
};
