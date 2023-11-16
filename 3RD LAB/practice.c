#include<stdio.h>
 
 int LeftmostBinarySearch(int arr[], int size, int key, int * comparisons){
    int low=0;
    int high = size-1;
    int result=-1;

    while(low<=high){
        int mid = low + (high-low)/2 ;
        *(comparisons)++;

        if (arr[mid]==key){
            result=mid;
            high=mid-1;
        }
        else if(arr[mid]<key) {
            low=mid+1;
        }
        else {
            high = mid- 1;
        }
    }
 }
 int main(){
    int size;
    printf("enter size of an array:");
    scanf("%d",&size);

    int arr[size];
    printf("enter elements of an array:");
    for(int i =0; i<size;i++){
        scanf("%d",&arr[i]);
    }

    int key=0;
    printf("enter key to be searched:");
    scanf("%d",&key);
    int comparisons=0;
    int index = LeftmostBinarySearch(arr,size,key,&comparisons);
    if (index != -1) {
        printf("%d found at index position %d\n", key, index);
        printf("Number of comparisons: %d\n", comparisons);
    } else {
        printf("%d not found in the array\n", key);
    }

    return 0;

    }

