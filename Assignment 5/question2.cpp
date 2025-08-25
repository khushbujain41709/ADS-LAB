#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int precedence(char operators){
    if(operators == '/' || operators == '*' || operators == '%'){
        return 2;
    }
    else if(operators == '+' || operators == '-'){
        return 1;
    }
    else return -1;
}
int main(){
    string infix = "a+c/D*9-b/2-g";
    string postfix = "";
    stack<char> operators;
    for(int i = 0 ; i<infix.size(); i++){
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 48 && infix[i] <= 57)){
            postfix.push_back(infix[i]);
        }
        else{
            while(!operators.empty() && precedence(infix[i]) <= precedence(operators.top())){
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(infix[i]);
        }
    }
    while(! operators.empty()){
        postfix.push_back(operators.top());
        operators.pop();
    }
    cout<<postfix<<endl;
}