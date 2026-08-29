class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int r1 = source[0];
        int c1 = source[1];

        int r2 = target[0];
        int c2 = target[1];

        // Already at target
        if (r1 == r2 && c1 == c2)
            return 0;

        // Bishop cannot change square color
        if ((r1 + c1) % 2 != (r2 + c2) % 2)
            return -1;

        // Same diagonal
        if (abs(r1 - r2) == abs(c1 - c2))
            return 1;

        // Same color, but different diagonal
        return 2;
    }
};


// Example 1:

// Input: source = [8,1], target = [1,8]

// Output: 1

// Explanation:

// ​​​​​​​

// A single diagonal move takes the bishop straight from (8, 1) to (1, 8).

// Example 2:

// Input: source = [4,2], target = [1,3]

// Output: 2

// Explanation:



// The bishop moves from (4, 2) to (3, 1), then from (3, 1) to (1, 3), reaching the target in 2 moves.

// Example 3:

// Input: source = [1,1], target = [3,4]

// Output: -1