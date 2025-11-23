#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct Subarray
{
    int sum,low,high;
};

Subarray MaxCrossingSum(vector<int>& a, int low, int mid, int high)
{
    int bestSum = -1;
    int bestStart = -1;


    for (int s= mid-2; s<=mid; s++)
    {
        if (s>= low && s+2<=high)
        {
            int cur = a[s] + a[s+1] + a[s+2];
            if (cur>bestSum)
            {
                bestSum = cur;
                bestStart = s;
            }
        }
    }
    Subarray crs;
    crs.sum = bestSum;
    crs.low = bestStart;
    crs.high = bestStart + 2;
    return crs;
}


Subarray FindPeriod(vector<int> a,int low,int high)
{
    if(low == high)
    {
        Subarray m;
        m.low = low,m.high = high,m.sum = a[low];
        return m;
    }
    int mid = (low+high)/2;

    Subarray left = FindPeriod(a, low,mid);
    Subarray right= FindPeriod(a,mid+1,high );
    Subarray crs = MaxCrossingSum(a, low, mid, high);
    if(left.sum >= right.sum && left.sum >= crs.sum) return left;
    else if(right.sum>=left.sum && right.sum>=crs.sum) return right;
    else return crs;

}


int main()
{

    vector<int> arr= {28,31,29,34,30,33,27,35,32};
    int n = arr.size();

    Subarray sub = FindPeriod(arr,0,n-1);
    int sum = sub.sum;
    int low = sub.low;
    int high =sub.high;

    cout << "Highest Total Temperature: "<< sum << endl;
    cout << "\nMax 3 consecutive days: "<< endl;

    for(int i=low; i<=high ; i++)
    {
        cout << arr[i] ;
        cout<<", ";
    }


}
