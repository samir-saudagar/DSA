// floor implementation
// Greatest element ≤ target
int floorInSortedArray(const vector<int>& arr, int target) { // Time: O(log n), Space: O(1)
    int low = 0, high = arr.size() - 1, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target) {
            ans = arr[mid]; // possible answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans; // returns -1 if no floor exists
}

// ceil implementation
// Smallest element ≥ target
int ceilInSortedArray(const vector<int>& arr, int target) { // Time: O(log n), Space: O(1)
    int low = 0, high = arr.size() - 1, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = arr[mid]; // possible answer
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans; // returns -1 if no ceil exists
}
