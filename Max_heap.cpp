#include<iostream>
using namespace std;

//max heapify the array
void heapify(int arr[], int i, int n){
    int largest = i;
    if (i > n/2)
    {
        //it has no children now
        return;
    }
    int left = 2*i;
    if (arr[left] > arr[i])
    {
        //update the largest index
        largest = left;
    }
    if (2*i+1 <= n)
    {
        //if it still has right child
        int right = 2*i+1;
        if (arr[right] > arr[largest])
        {
            //update the largest index again
            largest = right;
        }
    }
    if (largest != i)
    {
        //swap the values
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, largest, n);//recursively call the function
    }
}


int main(){

    int arr[] = {1,2,3,4,5,6};
    
    //use the for loop, from the last one to the first one to max heapify the array
    int length = sizeof(arr)/sizeof(arr[0]);
    for (int i = length/2 - 1; i >= 0; i--)
    {
        heapify(arr, i, length);
    }
    

    //print the results
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout << endl;
    

    return 0;
}