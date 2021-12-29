#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);
    printf("%d ", a[n-1]);

    if(n&1){ // n为奇数
        cout<<a[n/2]<<" ";
    }else{
        int mid=a[n/2]+a[n/2-1];

        if(mid&1){ // 四舍五入保留一位小数
            printf("%.1f ", (float)mid/2.0);
        }else{
            printf("%d ", mid/2);
        }
    }

    printf("%d", a[0]);
    return 0;
}