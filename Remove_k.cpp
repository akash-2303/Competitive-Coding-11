// Time Complexity: O(n)
// Space Complexity: O(n)
// Did you run the code on Leetcode? Yes

// Approach:
// 1. Use a stack to keep track of the digits in the number.
// 2. Iterate through the digits of the number. For each digit, check if it is smaller than the top of the stack and if we can still remove digits (k > 0).
// 3. If it is smaller, pop the top of the stack and decrement k. Continue this until we can no longer remove digits or the stack is empty.
// 4. Push the current digit onto the stack.
// 5. After iterating through all digits, if k is still greater than 0, pop the top of the stack k times.
// 6. Reverse the stack to get the final result and remove leading zeros.
// 7. If the result is empty, return "0". Otherwise, return the result.

class Solution {
    public:
        string removeKdigits(string num, int k) {
            stack<char> stack;
            stack.push(num[0]);
            for(int i = 1; i < num.size(); i++){
                while(!stack.empty() && k > 0 && num[i] < stack.top()){
                    stack.pop();
                    k--;
                }
                stack.push(num[i]);
            }
            while(k > 0 && !stack.empty()){
                stack.pop();
                k--;
            }
            string res;
            while(!stack.empty()){
                res += stack.top();
                stack.pop();
            }
            reverse(res.begin(), res.end());
            int nonZero = 0;
            while (nonZero < res.size() && res[nonZero] == '0') {
                nonZero++;
            }
            res = res.substr(nonZero);
            return res.empty() ? "0" : res;
        }
    };