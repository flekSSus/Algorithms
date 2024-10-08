#include <iostream>
#include<vector>

const int MOD(1000000007);

long long compute(long long*arr_fact,long long*arr_revFact, int n, int k)
{
    return arr_fact[n]*arr_revFact[k]%MOD*arr_revFact[n-k]%MOD;
}

long long binary_degree(long long base, long long index)
{
    if(!index)
        return 1;
    if(index==1)
        return base;
    long long tmp(binary_degree(base,index>>1));
    if((index & 1)==0)
        return (tmp%MOD)*(tmp%MOD)%MOD;
    return (tmp%MOD)*(tmp%MOD)%MOD*base%MOD;
}

void fact(long long*arr_fact, int n)
{
    arr_fact[0]=1;
    arr_fact[1]=1;
    for(int i=2;i<n+1;++i)
        arr_fact[i]=arr_fact[i-1]%MOD*i%MOD;

}
void reverse_fact(long long * arr_revFact,int k)
{
    arr_revFact[0]=1;
    arr_revFact[1]=1;
    for(int i=2;i<k+1;++i)
        arr_revFact[i]=binary_degree(i,MOD-2)*arr_revFact[i-1]%MOD;

}
int main ()
{
    int n(0),k(0);
    std::cin>>n>>k;

    long long *arr_fact=new long long [n+1];
    long long * arr_revFact= new long long[n+1];

    fact(arr_fact,n);
    reverse_fact(arr_revFact,n);

    std::cout<<compute(arr_fact,arr_revFact,n,k);

    delete []arr_fact;
    delete []arr_revFact;

}
