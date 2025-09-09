class InsertionSort {
public:
    void iterative(vector<int>& arr) { // Time: O(n^2), Space: O(1)
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void recursive(vector<int>& arr, int n) { // Time: O(n^2), Space: O(n)
        if (n <= 1) return;

        recursive(arr, n - 1);

        int last = arr[n - 1];
        int j = n - 2;
        while (j >= 0 && arr[j] > last) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = last;
    }
};
