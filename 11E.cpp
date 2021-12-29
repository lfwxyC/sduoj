#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int a[n+1],b[m+1],f[n+1][m+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j]=0;
        }
    }

    // f[i][j]: a[1:i]和b[1:j]的最长公共上升子序列
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                f[i][j]=f[i-1][j-1]+1;
            }else{
                f[i][j]=max(f[i][j-1],f[i-1][j]);
            }
        }
    }

    printf("%d",f[n][m]);
    return 0;
}