#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    int s[m],client[m][k]; // s[]:客人到店时间 ,client[][]:客人喜爱的配料 
    vector<int> t(n); // 面做好的时间 
    vector<vector<int> > ingredient(n,vector<int>(k)); // 面的配料 
    
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }

    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d",&x);

		// 初始化面的配料，0表示没有该配料 
		for(int j=0;j<k;j++){
			ingredient[i][j]=0;
		}

		// 有的配料置1 
        for(int j=0;j<x;j++){
            scanf("%d",&y);
        	ingredient[i][y-1]=1;
        }
    }

    for(int i=0;i<m;i++){
        scanf("%d",&s[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int x,y;
        scanf("%d",&x);

        for(int j=0;j<k;j++){
            client[i][j]=0;
        }

        for(int j=0;j<x;j++){
            scanf("%d",&y);
            client[i][y-1]=1;
        }
    }
    
    for(int i=0;i<m;i++){
        int j,tsize=t.size();

		// 从后往前遍历面，第一个满足条件的j即为距顾客到店时间最近的 
        for( j=tsize-1;j>=0;j--){
            int kk;

            // 判断第j碗面是否满足条件 
			for(kk=0;kk<k;kk++){
				// 只有顾客要求而面没有该调料时不满足条件 
                if(client[i][kk]&&ingredient[j][kk]==0){
                    break;
                }
            }

			// 满足条件，输出满意度并删除面 
            if (kk >= k)
            {
                printf("%d\n", s[i] - t[j]);
                t.erase(t.begin()+j);
                ingredient.erase(ingredient.begin()+j);
                break;
            }
        }
		
		// 没有满足条件的面 
        if (j < 0)
        {
            printf("Angry\n");
        }
    }

    return 0;
}
