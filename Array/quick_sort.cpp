class QuickSort {
public:
    int partition(vector<int> &arr, int low, int high) { // Time: O(n), Space: O(1)
        int pivot = arr[low];   
        int i = low + 1;
        int j = high;

        while (true) {
            while (i <= j && arr[i] <= pivot) i++;
            while (i <= j && arr[j] > pivot) j--;

            if (i <= j) swap(arr[i], arr[j]);
            else break;
        }

        swap(arr[low], arr[j]); 
        return j;
    }

public:
    void quickSort(vector<int> &arr, int low, int high) { // Time: O(n log n), Space: O(log n)
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};
