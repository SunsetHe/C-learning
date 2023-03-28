#include <stdio.h>

int binarysearch(int * nums,int target,int left,int right);
int search(int * nums,int numSize,int target);

int main(){

}

int binarysearch(int * nums,int target,int left,int right){
    if (left > right){
        return -1;
    }

    int mid = (left+right)/2;
    if (nums[mid] == target)
    {
        return mid;
    }
    if (nums[mid] == target)
    {
        return binarysearch(nums,target,left,mid);
    }else{
        return binarysearch(nums,target,mid+1,right);
    }
    
}