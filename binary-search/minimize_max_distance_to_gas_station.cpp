// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
// n is the size of stations, k is the number of additional gas stations to be added

class Solution {
  public:
    bool is_possible(vector<int> &arr, int k, int n, double mid){
        int station_count = 0;
        
        for(int i = 0; i < n - 1; ++i) {
            double gap = arr[i + 1] - arr[i];
            station_count += ceil(gap / mid) - 1;
            if(station_count > k) return false; 
        }
        return station_count <= k;
    }
    
    double findSmallestMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        double i = 0.0;
        double j = arr[n - 1] - arr[0];
        
        while(j - i > 1e-4) {
            double mid = i + (j - i) / 2.0;
            
            if(is_possible(arr, k, n, mid)){
                j = mid;
            } else {
                i = mid;
            }
        }
        return j;
    }
};
// Note: observation:
// For any candidate maximum allowed distance 'mid':
// - For each consecutive pair of stations, the gap is arr[i+1] - arr[i].
// - The number of extra stations needed to ensure the gap ≤ mid is ceil(gap / mid) - 1.
// - The total number of extra stations needed is the sum of these values across all gaps.
// If the total extra stations needed is ≤ k, it means 'mid' is feasible and we can try smaller distances (search left half).
// If the total extra stations needed is > k, 'mid' is too small, so we must increase it (search right half).
// The smallest feasible 'mid' after binary search is the answer.
