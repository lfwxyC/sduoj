#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    int s[m],client[m][k]; // s[]:���˵���ʱ�� ,client[][]:����ϲ�������� 
    vector<int> t(n); // �����õ�ʱ�� 
    vector<vector<int> > ingredient(n,vector<int>(k)); // ������� 
    
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }

    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d",&x);

		// ��ʼ��������ϣ�0��ʾû�и����� 
		for(int j=0;j<k;j++){
			ingredient[i][j]=0;
		}

		// �е�������1 
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

		// �Ӻ���ǰ�����棬��һ������������j��Ϊ��˿͵���ʱ������� 
        for( j=tsize-1;j>=0;j--){
            int kk;

            // �жϵ�j�����Ƿ��������� 
			for(kk=0;kk<k;kk++){
				// ֻ�й˿�Ҫ�����û�иõ���ʱ���������� 
                if(client[i][kk]&&ingredient[j][kk]==0){
                    break;
                }
            }

			// �����������������Ȳ�ɾ���� 
            if (kk >= k)
            {
                printf("%d\n", s[i] - t[j]);
                t.erase(t.begin()+j);
                ingredient.erase(ingredient.begin()+j);
                break;
            }
        }
		
		// û�������������� 
        if (j < 0)
        {
            printf("Angry\n");
        }
    }

    return 0;
}
