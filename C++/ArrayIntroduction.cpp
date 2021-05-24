#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i,N,a[10001];
    cin>>N;

    for(i=0;i<N;i++)
    {
        cin>>a[i];
    }
    for(i=N-1;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;


    return 0;
}
