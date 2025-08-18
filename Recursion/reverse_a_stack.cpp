// https://www.geeksforgeeks.org/problems/reverse-a-stack/1
// n is the number of elements in the stack
class Solution {
public:
    void insertReversed(int x, stack<int>& s) { // Time: O(n), Space: O(n)
        if (s.empty()) {
            s.push(x);
            return;
        }

        int temp = s.top();
        s.pop();
        insertReversed(x, s);
        s.push(temp);
    }

    void reverse(stack<int>& s) { // Time: O(n^2), Space: O(n)
        if (s.empty()) return;

        int x = s.top();
        s.pop();

        reverse(s);
        insertReversed(x, s);
    }
};
