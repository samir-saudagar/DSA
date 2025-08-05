// lower bound implementation
// First element ≥ target
int lowerBound(const vector<int>& arr, int target) { // Time: O(log n), Space: O(1)
    int low = 0, high = arr.size() - 1, ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans; // index of lower bound or arr.size() if not found
}
// upper bound implementation
// First element > target
int upperBound(const vector<int>& arr, int target) { // Time: O(log n), Space: O(1)
    int low = 0, high = arr.size() - 1, ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans; // index of upper bound or arr.size() if not found
}

// lower_bound(arr.begin(), arr.end(), target) - arr.begin() this will give the index of the first occurrence of target
// upper_bound(arr.begin(), arr.end(), target) - arr.begin() this will give the index of the first element greater than target
// output of lower_bound and upper_bound function are iterators, so we need to subtract arr.begin() to get the index
// if lower_bound returns arr.size(), it means target is not present in the array
// if upper_bound returns arr.size(), it means there is no element greater than target in the array
// if you want to find element using lower_bound and upper_bound, you dereference the iterator
// e.g. *lower_bound(arr.begin(), arr.end(), target) , *upper_bound(arr.begin(), arr.end(), target)