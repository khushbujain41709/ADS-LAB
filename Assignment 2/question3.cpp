#include<bits/stdc++.h>
using namespace std;
void bin(int n){
    if (n == 0) return;
    bin(n / 2);
    cout<<(n % 2);
}
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    if(num == 0) cout<<0;
    else bin(num);
    return 0;
}
