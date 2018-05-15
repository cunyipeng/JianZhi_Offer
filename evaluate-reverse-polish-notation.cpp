class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        for(auto token : tokens)
        {
            if(token == "+" || token == "-" || token == "*" || token == "/")
            {
                int a, b, res;
                b = stack.top();
                stack.pop();
                a = stack.top();
                stack.pop();
                if(token  == "+")
                    res = a + b;
                if(token == "-")
                    res = a - b;
                if(token == "*")
                    res = a * b;
                if(token == "/")
                    res = a / b;
                stack.push(res);
            }
            else
            {
                stringstream ss;
                ss << token;
                int tmp;
                ss >> tmp;
                stack.push(tmp);
            }
        }
        return stack.top();
    }
};
