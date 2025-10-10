#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& v, int starting_index , int ending_index){
    int n = v.size();
    int pivot = v[ending_index];
    int i = starting_index - 1;
    for(int j = starting_index; j<ending_index; j++){
        if(pivot > v[j]){ // bade element ko ignore krke aage jao
            i++;
            swap(v[i], v[j]); 
        }
    }
    swap(v[ending_index], v[i+1]);
    return i+1;
}
// Quickselect function to find Kth largest
int quickSelect(vector<int>& v, int low, int high, int k){
    if(low <= high){
        int pivotIndex = partition(v, low, high);
        int rightCount = v.size() - pivotIndex; // how many elements >= pivot
        if(rightCount == k){
            return v[pivotIndex]; // found Kth largest
        }
        else if(rightCount > k){
            return quickSelect(v, pivotIndex + 1, high, k); // go right
        }
        else{
            return quickSelect(v, low, pivotIndex - 1, k - rightCount); // go left
        }
    }
    return -1; // should not reach here if k is valid
}
int main(){
    int n, k;
    cout<<"Name : Khushbu Jain"<<endl;
    cout<<"Performed on 6th October 2025"<<endl;
    cout<<"Roll Number : 23115047"<<endl;
    cout<<"Enter number of elements : ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter elements of vector : ";
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout<<"Enter value of K : ";
    cin>>k;
    if(k < 1 || k > n){
        cout<<"Invalid K!"<<endl;
        return 0;
    }
    int res = quickSelect(v, 0, n - 1, k);
    cout<<k<<"th largest element is: "<<res<<endl;
    return 0;
}
