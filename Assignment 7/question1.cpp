#include<bits/stdc++.h>
using namespace std;
// We don't do dearching in heaps
class minHeap{
    public:
    vector<int> heap;
    int getMin(){
        if(heap.size() == 0){
            cout<<"Heap is Empty!"<<endl;
            return INT_MAX;
        }
        else{
            return heap[0];
        }
    }
    void heapifyDown(int idx){
        int left = 2*idx + 1;
        int right = 2*idx + 2;
        int smallest = idx; // assumed
        if(left < heap.size() && heap[left] < heap[smallest]){
            smallest = left;
        }
        if(right < heap.size() && heap[right] < heap[smallest]){
            smallest = right;
        }
        if(smallest != idx){
            swap(heap[smallest], heap[idx]);
            heapifyDown(smallest);
        }
    }
    void heapifyUp(int idx){
        int parent = (idx-1)/2;
        if(heap[parent] > heap[idx]){
            swap(heap[parent] , heap[idx]);
            heapifyUp(parent);
        }
    }
    void insert(int val){
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }
    int deleteMin(){ 
        // we can't delete any other element except minimum element from heap
        if(heap.size() == 0){
            cout<<"Heap is Empty!"<<endl;
            return INT_MAX;
        }
        int popped_element = heap[0];
        swap(heap[0], heap[heap.size() -1]);
        heap.pop_back();
        heapifyDown(0);
        return popped_element;
    }
    int heapSize(){
        return heap.size();
    }
    bool isHeapEmpty(){
        return heap.size() == 0;
    }
    void displayHeap(){
        for(int i = 0; i<heap.size(); i++){
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    cout<<"Name : Khushbu Jain"<<endl;
    cout<<"Roll Number : 23115047"<<endl;
    cout<<"Performed on : 13th October 2025"<<endl;
    minHeap m;
    m.insert(46);
    m.insert(47);
    m.insert(26);
    m.insert(35);
    m.insert(48);
    m.displayHeap();
    cout<<m.deleteMin()<<endl;
    cout<<m.getMin()<<endl;
    m.displayHeap();
    return 0;
}