// Time Complexity: O(n)
// Space Complexity: O(n)
// Did you run the code on Leetcode? Yes

// Approach:
// 1. Use a stack to keep track of the numbers in the expression.
// 2. Iterate through the tokens in the expression. For each token, check if it is an operator (+, -, *, /) or a number.
// 3. If it is an operator, pop the top two numbers from the stack and apply the operator to them. Push the result back onto the stack.
// 4. If it is a number, convert it to an integer and push it onto the stack.
// 5. After iterating through all tokens, the result will be the only number left in the stack.

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> st;
            for(auto i : tokens){
                // string a = tokens[i];
                if(i == "+" || i == "-" || i == "*" || i == "/"){
                    int val = 0;
                    int second = st.top(); //check
                    st.pop();
                    int first = st.top();
                    st.pop();
                    if(i == "+"){
                        val = first + second;
                    }
                    else if(i == "-"){
                        val = first - second;
                    }
                    else if(i == "*"){
                        val = first * second;
                    }else{
                        val = first / second;
                    }
                    st.push(val);
                }else{
                    // i = int(i);
                    st.push(stoi(i));
                }
            }
            return st.top();
        }
            
    };