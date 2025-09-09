class SelectionSort {
public:
    void iterative(vector<int>& arr) { // Time: O(n^2), Space: O(1)
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) minIdx = j;
            }
            swap(arr[i], arr[minIdx]);
        }
    }

    void recursive(vector<int>& arr, int start) { // Time: O(n^2), Space: O(n)
        int n = arr.size();
        if (start >= n - 1) return;

        int minIdx = start;
        for (int i = start + 1; i < n; i++) {
            if (arr[i] < arr[minIdx]) minIdx = i;
        }
        swap(arr[start], arr[minIdx]);

        recursive(arr, start + 1);
    }
};
