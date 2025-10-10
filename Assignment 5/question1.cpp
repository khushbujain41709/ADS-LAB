#include<iostream>
#include<stack>
#include<vector>
using namespace std;
bool isBalanced(string& s){
    stack<char> st;
    for(int i = 0; i< s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else if(s[i] == ')' && !st.empty() && st.top() == '('){
            st.pop();
        }
        else if(s[i] == '}' && !st.empty() && st.top() == '{'){
            st.pop();
        }
        else if(s[i] == ']' && !st.empty() && st.top() == '['){
            st.pop();
        }
        else continue;
    }
    return st.empty();
}
int main(){
    string expression = "((A+B)/c";
    bool ans = isBalanced(expression);
    if(ans){
        cout<<"The expression is balanced that is all opening and closing parentheses are paired."<<endl;
    }
    else{
        cout<<"The expression is not balanced that is all opening and closing parentheses are not paired."<<endl;
    }
    return 0;
}