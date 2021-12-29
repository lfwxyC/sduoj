#include<bits/stdc++.h>
using namespace std;

#define py printf("Y\n")
#define pn printf("N\n")
#define ll long long

struct file{
    int type; // 0:普通文件，1:目录
    ll fileSize;
    ll ld,lr; // ld: 目录配额，lr: 后代配额
    ll childSize,allSize; // 实际大小
    map<string,file *> child;

    file(int type,ll fileSize=0){
        this->type=type;
        this->fileSize=fileSize;
        ld=lr=0;
        childSize=allSize=0;
    }
    ~file(){
        for(auto &x:child){
            delete x.second;
        }
    }

    bool preQuota(ll fileSize,bool child){ // 预分配配额，判断是否满足
        if(lr && lr<allSize+fileSize){
            return false;
        }

        if(child && ld && ld<childSize+fileSize){
            return false;
        }
        return true;
    }

    void addSize(ll fileSize,bool child){
        allSize+=fileSize;

        if(child){
            childSize+=fileSize;
        }
    }

    bool setSize(ll ld,ll lr){
        if(ld&&childSize>ld){
            return false;
        }

        if(lr&&allSize>lr){
            return false;
        }

        this->ld=ld;
        this->lr=lr;
        return true;
    }
}typedef file;

struct fileSystem{
    file *root;
    vector<string> divPath;
    string name;

    fileSystem(){
        root=new file(1);
    }
    ~fileSystem(){
        delete root;
    }

    void setPath(string path){ // 分割路径
        divPath.clear();
        string tmp="";
        
        for(auto str:path){
            if(str=='/'){
                if(!tmp.empty()){
                    divPath.emplace_back(tmp);
                    tmp="";
                }
            }else{
                tmp+=str;
            }
        }
        name=tmp; // 最后一级目录或文件名记录在name中
    }

    pair<int,file *> findPath(){ // 0: 路径指向普通文件 1：路径指向目录 2：路径不完整 3：路径错误（普通文件下还有文件）
        file *now=root;
        for(auto str:divPath){
            if(!now->child.count(str)){
                return make_pair(2,nullptr);
            }

            if(now->child[str]->type==0){
                return make_pair(3,nullptr);
            }
            now=now->child[str];
        }

        if(name.empty()){ // 路径为根目录
            return make_pair(1,now);
        }

        if(!now->child.count(name)){
            return make_pair(2,nullptr);
        }

        if(now->child[name]->type==1){
            return make_pair(1,now->child[name]);
        }
        return make_pair(0,now->child[name]);
    }

    void erase(ll fileSize){
        file *now=root;
        for(auto str:divPath){
            now->addSize(-fileSize,false);
            now=now->child[str];
        }

        if(now->child[name]->type==0){ // 删除普通文件，需同时更新目录配额和后代配额
            now->addSize(-fileSize,true);
        }
        else{
            now->addSize(-fileSize,false);
        }

        delete now->child[name];
        now->child.erase(name);
    }

    bool create(ll fileSize){ 
        file *now=root;
        // 预分配配额，创建不存在的目录
        for(auto str:divPath){
            if(!now->preQuota(fileSize,false)){
                return false;
            }

            if(!now->child.count(str)){
                now->child[str]=new file(1);
            }
            now=now->child[str];
        }
        if(!now->preQuota(fileSize,true)){
            return false;
        }
        
        // 可以创建，更新配额
        now=root;
        for(auto str:divPath){
            now->addSize(fileSize,false);
            now=now->child[str];
        }

        now->addSize(fileSize,true);
        now->child[name]=new file(0,fileSize);
        return true;
    }
}typedef fileSystem;

int main(){
    int n;
    fileSystem fs;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        char c;
        string path;
        cin>>c>>path;

        fs.setPath(path);
        pair<int,file*> pa=fs.findPath();

        switch (c)
        {
        case 'C':
        {
            ll fileSize;
            scanf("%lld",&fileSize);

            if(pa.first==1||pa.first==3){ // 路径指向目录或路径错误
                pn;
            }
            else if(pa.first==0){ // 已存在，需替换
                ll oldSize=pa.second->fileSize;
                fs.erase(oldSize); // 删除原文件
            
                if(fs.create(fileSize)){ // 替换成功
                    py;
                }
                else{
                    fs.create(oldSize); // 替换失败，重新创建原文件
                    pn;
                }
            }
            else if(pa.first==2){ // 路径不完整，直接创建
                if(fs.create(fileSize)){
                    py;
                }
                else{
                    pn;
                }
            }
            break;
        }
        case 'R':
        {
            if(pa.first==0){ // 普通文件
                fs.erase(pa.second->fileSize);
            }
            else if(pa.first==1){ // 目录
                fs.erase(pa.second->allSize);
            }
            py;
            break;
        }
        case 'Q':{
            ll ld,lr;
            scanf("%lld%lld",&ld,&lr);
            
            if(pa.first!=1){ // 只有目录可以修改配额
                pn;
            }
            else{
                if(pa.second->setSize(ld,lr)){
                    py;
                }
                else{
                    pn;
                }
            }
            break;
        }
        default:
            break;
        }
    }
    return 0;
}