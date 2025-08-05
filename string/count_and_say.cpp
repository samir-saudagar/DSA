// https://leetcode.com/problems/count-and-say?envType=problem-list-v2&envId=string
// n is the input number, m is the length of the output string
class Solution {
public:
    string countAndSay(int n){ // Time Complexity: O(n * m), Space Complexity: O(n)
        string str = "1";
        
        for(int i = 1; i < n; i++){
            string temp = "";
            int count = 1;
            
            for(int j = 0; j < str.size(); j++){
                if(j + 1 < str.size() && str[j] == str[j + 1]) {
                    count++;
                } else {
                    temp += to_string(count);
                    temp += str[j];
                    count = 1;
                }
            }
            
            str = temp;
        }
        
        return str;
    }
};