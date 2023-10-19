#include <iostream>
#include <vector>

int minJumpsToEnd(std::vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
        return 0; // No jumps needed for an empty array or a single element.
    }

    int maxReach = nums[0]; // Maximum index that can be reached.
    int steps = nums[0];    // Steps available at the current position.
    int jumps = 1;          // Number of jumps made so far.

    for (int i = 1; i < n; i++) {
        if (i == n - 1) {
            return jumps; // If we've reached the end, return the number of jumps.
        }

        maxReach = std::max(maxReach, i + nums[i]);

        steps--;

        if (steps == 0) {
            jumps++;
            if (i >= maxReach) {
                return -1; // Cannot reach the end.
            }
            steps = maxReach - i;
        }
    }

    return -1; // If we haven't reached the end.
}

int main() {
    std::vector<int> nums = {2, 3, 1, 1, 4};
    int result = minJumpsToEnd(nums);
    if (result != -1) {
        std::cout << "Minimum number of jumps to reach the end: " << result << std::endl;
    } else {
        std::cout << "Cannot reach the end." << std::endl;
    }

    return 0;
}
