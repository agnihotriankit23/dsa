#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

int binarySearch(int arr[],int n,int key){
    int s=0,e=n-1;
    while(s<=e){
        int mid=s +(e-s)/2 ;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            e=mid-1;
        }else{ s=mid+1;}
    }
    return -1;
}

int main(){
    
    int arr[6]={2,4,6,8,12};
    int odd[5]={1,3,8,11,14};   

    int index=binarySearch(arr,6,12);
    cout<<"Element 12 is at postion "<<index<<endl;
     index=binarySearch(odd,5,3);
    cout<<"Element 3 is at postion "<<index<<endl;
    

    // int key;
    // cin>>key; 
    // cout<<binarySearch(arr,n,key);
    return 0;
}