#include <stdio.h>

int binarySearch(int arr[],int low,int high,int item){
    
    if(low > high){
        return -1;
    }

    int mid = (low + high) / 2;

    if(arr[mid] == item){
        return mid;
    }

    if(item < arr[mid]){
        return binarySearch(arr,low,mid-1,item);
    }else{
        return binarySearch(arr,low,mid+1,item);
    }


  }

int main(){
    int arr[6] = {11,10,1,16,17,90};
    int item, n,result;
    n = sizeof(arr)/ sizeof(arr[0]);
    printf("Enter the element do you want to search : ");
    scanf("%d",&item);
    
    result = binarySearch(arr,0,n-1, item);

    if(result != -1){
        printf("%d found at location %d", item, result +1);
    }else{
        printf("%d not found",item);
    }

return 0;
}
