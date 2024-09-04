class Solution {
private:

    // Custom hash function for std::pair<int, int>
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2>& pair) const {
            auto hash1 = std::hash<T1>{}(pair.first);
            auto hash2 = std::hash<T2>{}(pair.second);
            return hash1 ^ hash2; // Combine the two hash values
        }
    };

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        unordered_set<pair<int, int>, pair_hash> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }

        // Define direction vectors: North, East, South, West
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> currentPosition = {0, 0};
        int maxDistanceSquared = 0;
        int currentDirection = 0;  // 0: North, 1: East, 2: South, 3: West

        for (int command : commands) {
            if (command == -1) {
                // Turn right
                currentDirection = (currentDirection + 1) % 4;
                continue;
            }
            if (command == -2) {
                // Turn left
                currentDirection = (currentDirection + 3) % 4;
                continue;
            }

            // Move forward
            vector<int> direction = directions[currentDirection];
            for (int step = 0; step < command; step++) {
                int nextX = currentPosition[0] + direction[0];
                int nextY = currentPosition[1] + direction[1];
                if (obstacleSet.contains({nextX, nextY})) {
                    break;
                }
                
                currentPosition[0] = nextX;
                currentPosition[1] = nextY;
            }

            maxDistanceSquared =
                max(maxDistanceSquared,
                    currentPosition[0] * currentPosition[0] +
                        currentPosition[1] * currentPosition[1]);
        }

        return maxDistanceSquared;
    }
};