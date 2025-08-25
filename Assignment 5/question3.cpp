#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;
int evaluation(int operand1, int operand2, char operator1){
    if(operator1 == '+'){
        return operand1 + operand2;
    }
    else if(operator1 == '-'){
        return operand1 - operand2;
    }
    else if(operator1 == '*'){
        return operand1 * operand2;
    }
    else if(operator1 == '/'){
        if(operand2 != 0) return operand1 / operand2;
        else return INT_MIN; // indicates divison by zero
    }
}
int main(){
    string expression = "79+4*8/3-";
    stack<int> st;
    for(int i = 0; i<expression.size(); i++){
        if(expression[i] >= 48 && expression[i] <= 57){
            st.push(expression[i] - 48);
        }
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            char operator1 = expression[i];
            st.push(evaluation(op2, op1, operator1)); // order is imp
            // op1 is on top
        }
    }
    cout<<st.top()<<endl;
}