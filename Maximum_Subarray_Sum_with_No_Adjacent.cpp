#include <iostream>
#include <vector>

using namespace std;

int maxSumNoAdjacent(vector<int>& nums) {
    int n = nums.size();

    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return max(0, nums[0]);
    }

    vector<int> dp(n);

    // Base cases
    dp[0] = max(0, nums[0]);
    dp[1] = max(dp[0], nums[1]);

    for (int i = 2; i < n; i++) {
        // Calculate the maximum sum without adjacent elements
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 4};
    int result = maxSumNoAdjacent(nums);

    cout << "Maximum Subarray Sum with No Adjacent Elements: " << result << endl;

    return 0;
}
