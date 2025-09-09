class BubbleSort {
public:
    void iterative(vector<int>& arr) { // Time: O(n^2), Space: O(1)
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }

    void recursive(vector<int>& arr, int n) { // Time: O(n^2), Space: O(n)
        if (n == 1) return;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
        recursive(arr, n - 1);
    }
};
