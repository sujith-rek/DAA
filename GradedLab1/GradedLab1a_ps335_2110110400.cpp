#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void quickSort(int arr[], int low, int high,int size){
    if(low<high){
        int pivot = arr[high];
        int i = low-1;
        for(int j=low;j<=high-1;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        quickSort(arr,low,i,size);
        quickSort(arr,i+2,high,size);
    }
    // printArray(arr,size);
    // cout<<endl;

}


int main(){
    int T,N;
    cout<<"Enter the number of test cases: ";
    cin>>T;

    if (T<0 || T>10){
        cout<<"Invalid number of test cases"<<endl;
        return 0;
    }

    while(T--){
        cout<<"--------------TC "<<T+1<<"----------------"<<endl;
        cout<<"Enter the size of array: ";
        cin>>N;

        if(N<0 || N>1000){
            cout<<"Invalid size of array"<<endl;
            return 0;
        }

        if(N!=0){
            int arr[N];
            cout<<"Enter the elements of array: ";
            for(int i=0;i<N;i++){
                cin>>arr[i];
            }
            quickSort(arr,0,N-1,N);
            cout<<"Sorted array: ";
            printArray(arr,N);
            cout<<endl<<endl;
        }
        else{
            cout<<"Sorted array: "<<endl<<endl;
        }

        
    }
    return 0;
}
