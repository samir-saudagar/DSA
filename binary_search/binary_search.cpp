// non recursive binary search implementation
int binarySearchIterative(const vector<int>& arr, int target) { // Time: O(log n), Space: O(1)
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return -1; // not found
}

// recursive binary search implementation
int binarySearchRecursive(const vector<int>& arr, int low, int high, int target) { // Time: O(log n), Space: O(log n) due to recursion stack
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target);
    else
        return binarySearchRecursive(arr, low, mid - 1, target);
}
