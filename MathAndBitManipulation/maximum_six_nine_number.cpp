// https://leetcode.com/problems/maximum-69-number?envType=daily-question&envId=2025-08-16
// string based approach
class Solution {
public:
    int maximum69Number (int num) { // Time: O(n), Space: O(n)
        string str = to_string(num);
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '6'){
                str[i] = '9';
                break;
            }
        }
        return stoi(str);
    }
};

// math based approach
class Solution {
public:
    int maximum69Number (int num) { // Time: O(log n), Space: O(1)
        int original = num;
        int pos = -1, index = 0;
        int temp = num;

        // find the leftmost 6
        while (temp > 0) {
            if (temp % 10 == 6) pos = index;
            temp /= 10;
            index++;
        }

        if (pos != -1) {
            num += 3 * pow(10, pos);
        }

        return num;
    }
};
