#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 2, 3, 3, 4, 5, 6};
    int target = 3;
    int result = binarySearch(nums, target);

    if (result != -1) {
        cout << "The first occurrence of " << target << " is at index: " << result << endl;
    } else {
        cout << target << " is not present in the array." << endl;
    }

    return 0;
}
