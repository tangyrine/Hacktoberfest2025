#include <bits/stdc++.h>
using namespace std;

int minNumberOfIncreasingSubsequences(vector<int>& nums) {
    vector<int> tails;

    for (int num : nums) {
        // Binary search to find position in tails (for decreasing order)
        int pos = lower_bound(tails.begin(), tails.end(), num, greater<int>()) - tails.begin();
        if (pos == tails.size()) {
            tails.push_back(num);
        } else {
            tails[pos] = num;
        }
    }

    return tails.size(); // Equal to length of longest decreasing subsequence
}

int main() {
    vector<int> nums = {5, 2, 4, 3, 1, 6};
    cout << minNumberOfIncreasingSubsequences(nums) << endl; // Output: 3
    return 0;
}
