#include <stdio.h>
#include <stdlib.h>

int nums[] = {1,2,3,4,5,6,7,8,9,10,11};

//nums 数组的长度 targat 搜索的数 left最左一个数 right最后一个数
int binarySearch(int *nums ,int target,int left,int right){
    if(target > right) return -1;
    int mid = (left+right)/2;
    if(nums[mid] == target) return nums[mid];
    if(nums[mid] > target){
        return binarySearch(nums ,target,mid-1,right);
    }else{
        return binarySearch(nums,target,left,mid+1);
    }
}

//nums 数组 numsSzie数组大小 targat 搜索的数
int search(int * nums,int numsSzie,int targat){
    return binarySearch(nums,targat,0,numsSzie-1);
}

int main(){
    printf("%d",binarySearch(nums,6,1,11));
    system("pause");
    return 0;
}