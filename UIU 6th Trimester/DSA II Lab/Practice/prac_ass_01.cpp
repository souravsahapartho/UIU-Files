#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Period
{
    int sum;
    int sm;
    int em;
};


Period Findcross(vector<int> a, int low, int mid, int high)
{
    int left_sum=0;
    int left_idx=-1;
    for(int i=mid; i>=low; i--)
    {
        if(a[i]>0)
        {
            left_sum++;
            left_idx=i;
        }
        else
        {
            break;
        }
    }

    int right_sum=0;
    int right_idx=-1;
    for(int j=mid+1; j<=high; j++)
    {
        if(a[i]>0)
        {
            right_sum++;
            right_idx=j;
        }
        else
        {
            break;
        }
    }

        if(left_idx!=-1 && right_idx!=-1)
    {
        return
        {
            left_length+right_length, left_idx+1,right_idx+1};
    }
    else if(left_idx!=-1)
    {
        return
        {
            left_length,left_idx+1,left_idx+left_length};
    }
    else if(right_idx!=-1)
    {
        return
        {
            right_length, right_idx-right_length,right_idx+1};
    }
    else
    {
        return {0,-1,-1};
    }
}

Period FindPeriod(vector<int> &arr, int low, int high)
{
    if(low==high)
    {
        if(arr[low]>0)
        {
            return(1,low+1,low+1);
        }
        else
        {
            return (0,-1,-1);
        }
    }
        int mid=low+(high-low)/2;

    Period left_result=FindPeriod(arr,low,mid);
    Period right_result=FindPeriod(arr,mid+1,high);
    Period cross_result=Findcross(profits,low,mid,high);

    if(left_result.length>=right_result.length && left_result.length>=crs_result.length){
        return left_result;
    }
    else if(right_result.length>=left_result.length && right_result.length>=crs_result.length){
        return right_result;
    }
    else{
       return cross_result;
    }
}


int main()
{
    vector<int> arr= {3,-1,9,-2,4,3,1,-5,3,2};
