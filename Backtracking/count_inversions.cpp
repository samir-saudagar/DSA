// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
  public:
    int merge(vector<int> &arr, int st, int mid, int end) { // Time: O(n), Space: O(n)
        vector<int> temp;
        int i = st, j = mid + 1, invCount = 0;
        
        while(i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
                invCount += mid - i + 1;
            }
        }
        
        while(i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j <= end) {
            temp.push_back(arr[j]);
            j++;
        }
        
        for (int k = 0; k < temp.size(); k++) {
            arr[k + st] = temp[k];
        }
        
        return invCount;
    }
    
    int mergeSort(vector<int> &arr, int st, int end) { // Time: O(n log n), Space: O(n)
        if (st < end) {
            int mid = st + (end - st) / 2;
            
            int leftInvCount = mergeSort(arr, st, mid);
            int rightInvCount = mergeSort(arr, mid + 1, end);
            int invCount = merge(arr, st, mid, end);
            
            return invCount + leftInvCount + rightInvCount;
        }
        
        return 0;
    }
    
    int inversionCount(vector<int> &arr) { // Time: O(n log n), Space: O(n)
        
        return mergeSort(arr, 0, arr.size() - 1);
    }
};