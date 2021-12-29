#include<bits/stdc++.h>
using namespace std;

const int maxn=2*1e5+10;
int k,v,d[maxn*4]; // 线段树

void upd(int x,int l,int r){ //x: 节点标号，[l,r]: 维护区间
    if(l==r){ // 根节点
        d[x]=max(d[x],v); // d[x]: 区间内美味度最大的菜品
        return;
    }

    int m=(l+r)/2;
    if(k<=m){ // k：菜品标号
        upd(x*2,l,m); // 更新左孩子
    }else{
        upd(x*2+1,m+1,r); // 更新右孩子
    }

    d[x]=max(d[x*2],d[x*2+1]); // 由于孩子被更新，当前节点也需更新
}

int ask(int x,int l,int r,int p1,int p2){ // [p1,p2]: 查询区间

    if(l==p1&&r==p2){ // 找到
        return d[x];
    }

    int m=(l+r)/2;
    if(p2<=m){ // 要查找的区间在左孩子
        return ask(x*2,l,m,p1,p2);
    }
    else if(p1>m){ // 要查找的区间在右孩子
        return ask(x*2+1,m+1,r,p1,p2);
    }
    else{ // 要查找的区间既包括左孩子，又包括右孩子
        int lch_val=ask(x*2,l,m,p1,m);
        int rch_val=ask(x*2+1,m+1,r,m+1,p2);
        return max(lch_val,rch_val); // 返回左右孩子中大的孩子
    }
}

int main(){
    int m,p;
    scanf("%d%d",&m,&p);

    for(int i=1;i<maxn*4;i++){
        d[i]=0;
    }

    int a=0,n=0;
    for(int i=0;i<m;i++){
        char opt;
        cin>>opt;

        switch (opt)
        {
        case 'A':{
            int t;
            scanf("%d",&t);

            v=(t+a)%p;
            n++;
            k=n;
            upd(1,1,m);
            break;
        }
        case 'Q':{
            int l;
            scanf("%d",&l);

            a=ask(1,1,m,n-l+1,n); // 从当前屏幕中查询
            printf("%d\n",a);
        }
        
        default:
            break;
        }
    }

    return 0;
}