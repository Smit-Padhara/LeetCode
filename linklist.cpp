#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        auto isSorted = [](const vector<int>& arr) {
            for (int i = 0; i < arr.size() - 1; ++i) {
                if (arr[i] > arr[i + 1]) return false;
            }
            return true;
        };

        while (!isSorted(nums)) {
            int minSum = INT_MAX;
            int minIndex = 0;

            // Find the adjacent pair with minimum sum (leftmost if tie)
            for (int i = 0; i < nums.size() - 1; ++i) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    minIndex = i;
                }
            }

            // Merge the pair
            nums[minIndex] = nums[minIndex] + nums[minIndex + 1];
            nums.erase(nums.begin() + minIndex + 1);
            ++ops;
        }

        return ops;
    }
};