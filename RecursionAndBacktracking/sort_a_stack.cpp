// https://www.geeksforgeeks.org/problems/sort-a-stack/1
// n is the number of elements in the stack
class SortedStack {
public:
    stack<int> s;

    void insertSorted(int x, stack<int>& s) { // Time: O(n), Space: O(n)
        if (s.empty() || s.top() <= x) {
            s.push(x);
            return;
        }

        int temp = s.top();
        s.pop();
        insertSorted(x, s);
        s.push(temp);
    }

    void sort() { // Time: O(n^2), Space: O(n)
        if (s.empty()) return;

        int x = s.top();
        s.pop();

        sort();
        insertSorted(x, s);
    }
};
