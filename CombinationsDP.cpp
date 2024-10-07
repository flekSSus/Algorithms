#include <iostream>

long long Comb(int n, int k)
{
    if(k==1)
        return n;
    int arrSize(1+std::min(k,n-k));
    int *arr=new int [arrSize];
    
    for(int i=0;i<arrSize;++i)
        arr[i]=1;
    for(int i=1;i<(n-k)+1;++i)
        for(int j=1;j<arrSize;++j)
        {
            arr[j]+=arr[j-1];
        }
    int result=arr[arrSize-1];
    delete []arr;
    return result;
}

int main()
{
    int n(0);
    int k(0);
    std::cin>>n>>k;
    std::cout<<Comb(n,k);

}
