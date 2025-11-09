// User function Template for C++

class Solution {
  public:
    // Function to calculate the minimum number of rotations
    // needed to convert one number R into another number D (digit by digit).
    int rotationCount(long long R, long long D) {
        // 'count' will store the total minimum rotations required
        int count = 0;

        // Loop continues until both numbers still have digits left
        while(R > 0 && D > 0) {
            // Extract the last digit of R
            int remainder1 = R % 10;

            // Extract the last digit of D
            int remainder2 = D % 10;

            // Difference between digits
            int diff = abs(remainder1 - remainder2);

            // Why min(diff, 10 - diff)?
            // -> Digits are arranged in a circular way (0 to 9).
            // -> To change one digit to another, you can rotate forward or backward.
            // Example:
            // remainder1 = 2, remainder2 = 9
            // diff = |2 - 9| = 7
            // But if you rotate backward: 2 -> 1 -> 0 -> 9 → only 3 steps!
            // So, we take the minimum of (direct difference) and (10 - difference).
            count += min(diff, 10 - diff);

            // Remove the last digit of R and D by dividing by 10
            R = R / 10;
            D = D / 10;
        }

        // Return total minimum rotations required
        return count;
    }
};
