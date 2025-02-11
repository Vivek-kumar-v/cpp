#include<iostream>
using namespace std;

class heap {
    public :
    int arr[100];
    int size;
    // constructor 
    heap() {
        arr[0] = -1;
        size = 0;
    }

    // insertion 
    void insert(int val) {
        size++;
        int index = size ;
        arr[index] = val;
        while(index > 1) {
            int parent = index/2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else {
                return ;
            }
        }
    }

    // Printing of Heap
    void print() {
    for(int i = 1 ; i <= size ; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

   // Deletion 
   void deletefromHeap() {
    if(size == 0) {
        cout<<"Nothing to delete "<<endl;
        return ;
    }
    // step 1 : put last element into first index
    arr[1] = arr[size];
    // step 2 : removing last element
    size--;
    // step 3 : take root node to its correct position 
    int i = 1;
    while(i < size) {
        int leftIndex = 2*i;
        int rightIndex = 2*i + 1;
        if(leftIndex < size && arr[i] < arr[leftIndex]) {
            swap(arr[i] , arr[leftIndex]);
            i = leftIndex;
        }
        else if(rightIndex < size && arr[i] < arr[rightIndex]) {
            swap(arr[i] , arr[rightIndex]);
            i = rightIndex;
        }
        else {
            return ;
        }
    }
   }
};

// HEAPIFY ALGORITHM
void heapify(int arr[],int n,int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest] , arr[i]);
        heapify(arr,n,largest);
    }
}


int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletefromHeap();
     h.print();

     int arr[6] = {-1,54,53,55,52,50};
     int n = 5;
     for(int i = n/2;i>0;i--) {
        heapify(arr,n,i);
     }

     cout<<"Printing the array Now"<<endl;
     for(int i=1;i<=n;i++) {
        cout<<arr[i]<<" ";
     }
     cout<<endl;

}

