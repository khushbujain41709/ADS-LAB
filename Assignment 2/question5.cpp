#include<iostream>
#include<string>
#include<vector>
using namespace std;
class STACK{
    public:
    int capacity;
    vector<char> res;
    STACK(int size){
        capacity = size;
    }
    void push(string& ans){
        for(int i = 0; i < ans.size(); i++){
            res.push_back(ans[i]);
        }
        pop();
    }
    void pop(){
        int n = res.size();
        int k = n - 1;
        while(k >= 0){
            cout<<res[k]<<" ";
            res.pop_back();
            k--;
        }
        cout<<endl;
    }
};
int main(){
    string s;
    cin >> s;
    string caps = s;
    for(int i = 0; i < s.size(); i++){
        char x = (char)toupper(s[i]);
        caps[i] = x;
    }
    int n = caps.size();
    STACK st(n);
    st.push(caps);
}
