#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    stack<pair<string,string>> s;
    int a[11],sum[11],cnt=0,maxPower=0,loopCnt=0,endCnt=0,minus=-2;
    int total[11];
    bool flag=true;
    
    for(int i=0;i<11;i++){
        a[i]=0;
        sum[i]=0;
        total[i]=0;
    }

    while(cin>>str)
    {
        if(str=="LOOP"||str=="OP"){ // 入栈 
            string c;
            cin>>c;
            
            if(str=="LOOP"){
            	// 外层循环里面嵌套并列的循环 
            	if(endCnt&&flag){
            		// 将上一个循环的结果放入sum中保存，清空a 
            		for(int i=0;i<11;i++){
            			sum[i]+=a[i];
            			a[i]=0;
					}
					
					minus=loopCnt-endCnt; // 记录并列的循环的位置 
					flag=false;
				}
            	
            	loopCnt++;
			}
            
            if(c=="n"){
                cnt++; // n的幂次+1 
                maxPower=cnt;
            }
            s.push(make_pair(str,c));
        }
        
        else if(str=="END"){ // 弹栈 
        	endCnt++;
        	
            while(!s.empty()&&s.top().first=="OP"){ // 弹出所有OP，直到遇到LOOP停止 
            	int num=stoi(s.top().second);
                a[cnt]+=num; // OP进行的次数即为cnt次方的系数 
                s.pop();
            }

            if(!s.empty()&&s.top().first=="LOOP"){
                if(s.top().second!="n"){
                	for(int i=0;i<11;i++){
                		int num=stoi(s.top().second);
                		a[i]*=num; // 每一层乘上LOOP的次数 
					}
                }

                else{
                    cnt--; // 幂次-1 
                }
                s.pop();
            }

			if(loopCnt-endCnt==minus){ // 并列的循环结束，把sum中保存的结果放到a中，清空sum 
				for(int i=0;i<11;i++){
					a[i]+=sum[i];
					sum[i]=0;
				}
				flag=true;
			}

			else if(loopCnt==endCnt){ // 循环全部结束，把这个循环的结果放入最终结果total中，清空a 
				for(int i=0;i<11;i++){
					total[i]+=a[i];
					a[i]=0;
				}
				
				loopCnt=0;
				endCnt=0;
				minus=-2;
			}

           	if(loopCnt+1==endCnt){ // 出现了与BEGIN匹配的END,计算最终结果total,停止读入 
           		for(int i=0;i<11;i++){
					total[i]+=a[i];
					a[i]=0;
				}
                break;
            }
        }
    }
    
    printf("Runtime = ");

	// 计算需要输出几项 
    int addCnt=0;
    for(int i=0;i<11;i++){
        if(total[i]){
            addCnt++;
        }
    }

	// 运行时间为0 
    if(addCnt==0){
        printf("0\n");
    }

    else{
        for(int i=10;i>=2;i--){
            if(total[i]){
            	// 系数不为1 
                if(total[i]!=1){
                    printf("%d*n^%d",total[i],i);
                }
				// 系数为1 
				else{
                    printf("n^%d",i);
                }

                if(addCnt-1){ // 若后面还有项要输出，则打印"+" 
                    printf("+");
                    addCnt--;
                }
            }
        }
        
        // 幂次为1 
        if(total[1]){
        	if(total[1]!=1){
        		printf("%d*n",total[1]);
			}else{
				printf("n");
			}
		}
		
		if(addCnt-1){
			printf("+");
		}
        
        // 幂次为0 
        if(total[0]){
            printf("%d\n",total[0]);
        }
    } 
    
    return 0;
}
