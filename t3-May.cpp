#include<bits/stdc++.h>
using namespace std;

int row,col;
vector<string> txt; // 每一行的内容

void enter(){ // 换行
    string old_row = txt[row];
    string new_row1 = old_row.substr(0,col);
    string new_row2 = old_row.substr(col,old_row.length()-col);

    txt[row] = new_row1;
    txt.insert(txt.begin() + row + 1,new_row2);
}

void erase_sel(int rec_row,int rec_col){ // 删除选中内容
    int sta_row = rec_row,sta_col = rec_col,des_row = row,des_col = col;
             
    if(rec_row == row){ // 只选中了一行
        if(rec_col > col){
            swap(sta_col,des_col);
        }
        txt[row].erase(txt[row].begin() + sta_col,txt[row].begin() + des_col);
    }
    else{ // 选中了多行
        if(rec_row > row){
            swap(sta_row,des_row);
            swap(sta_col,des_col);
        }
        
        txt[sta_row].erase(txt[sta_row].begin() + sta_col,txt[sta_row].end());
        txt[des_row].erase(txt[des_row].begin(),txt[des_row].begin() + des_col);
        txt[sta_row] += txt[des_row];
        txt.erase(txt.begin() + sta_row + 1,txt.begin() + des_row + 1);
    }
    row = sta_row,col = sta_col;
}

void find(vector<string> &v,string str){ // 查找字符串出现次数
    int cnt = 0;

    for(auto& x:v){
        int x_size= x.length();
        int str_size = str.length();

        for(int i = 0;i < x_size; i++){
            if(i + str_size > x_size){
                break;
            }

            string cmp = x.substr(i,str_size);
            if(str == cmp){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

void count(vector<string> &v){ // 输出总字数
    int cnt = 0;

    for(auto& x:v){
        for(int i = 0;i < x.length(); i++){
            if(x[i] != ' '){ // 跳过空格
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false);
    //freopen("25.in","r",stdin);
    //freopen("a.out","w",stdout);

    int n;
    int rec_row = 0,rec_col = 0; // 记录点
    int shf = -1; // 粘滞键,开始时粘滞功能默认为关闭状态
    bool sel = false; // 选中状态

    vector<string> pst; // 粘贴板
    vector<string> slc; // 选中内容

    row = 0,col = 0; // 光标所在行列
    txt.emplace_back("");
    cin >> n;

    for(int j = 0;j < n; j++){
        string s,str,c;
        cin >> s;
        
        if(s == "MOVE"){ // 光标移动
            sel = false; // 退出选中状态
            cin >> str;

            if(str == "Home"){ // 把光标移动到当前行的开头
                col = 0;
            }
            else if(str == "End"){ // 把光标移动到当前行的末尾
                int row_size = txt[row].length();
                col = row_size;
            }
            else if(str == "Up"){ // 光标移动到上一行的相同列
                if(row == 0) continue; // 若当前为第一行，则不进行任何操作

                int last_size = txt[row - 1].length();
                if(last_size < col){ // 若上一行的列数小于当前光标的列数，则将光标移动到上一行的末尾
                    col = last_size;
                }
                row--;
            }
            else if(str == "Down"){ // 光标移动到下一行的相同列
                int last_row = txt.size() - 1;

                if(row == last_row) continue; // 若当前为最后一行，则不进行任何操作

                int next_size = txt[row + 1].length();
                if(next_size < col){ // 若下一行的列数小于当前光标的列数，则将光标移动到下一行的末尾
                    col = next_size;
                }
                row++;
            }
            else if(str == "Left"){ // 光标左移一位
                if(row == 0 && col == 0) continue; // 若当前光标位于记事本开始，则不进行任何操作

                if(col == 0){ // 若当前光标处于某一行的开头，则将光标移动到上一行的末尾
                    int last_size = txt[row - 1].length();
                    
                    row--;
                    col = last_size;
                }
                else{
                    col--;
                }
            }
            else if(str == "Right"){ // 光标右移一位
                int last_row = txt.size() - 1;
                int last_col = txt[row].length();

                if(row == last_row && col == last_col) continue; // 若当前光标位于记事本末尾，则不进行任何操作

                if(col == last_col){ // 若当前光标处于某一行的末尾，则将光标移动到下一行的开头
                    row++;
                    col = 0;
                }
                else{
                    col++;
                }
            } 
        }
        else if(s == "INSERT"){ // 输入
            if(sel == true){ // 将选中内容替换为输入内容
                sel = false; // 退出选中状态
                erase_sel(rec_row,rec_col); // 先删除选中内容再插入输入内容
            }

            cin >> str;
            if(str == "Char"){ // 在当前光标后插入一个字符
                cin >> c;

                txt[row].insert(col,c);
                col++; // 此时光标在插入的字符之后
            }
            else if(str == "Enter"){ // 输入换行符，并进行换行
                enter();
                row++;
                col = 0;
            }
            else if(str == "Space"){ // 输入空格
                txt[row].insert(col," ");
                col++;
            }
            else if(str == "Paste"){ // 在当前光标后，插入粘贴板中的内容
                if(pst.empty()) continue; // 若粘贴板中无内容，则忽略当前操作

                if(pst.size() == 1){ // 插入一行
                    txt[row].insert(col,pst[0]);
                    col += pst[0].length();
                }
                else{ // 插入多行
                    enter(); // 换行，此时光标尚未移动
                    txt[row] += pst[0];

                    int pst_row = row + 1;
                    int tmp = pst.size() - 1;

                    for(int i = 1;i < tmp; i++){
                        txt.insert(txt.begin() + pst_row,pst[i]);
                        pst_row++;
                    }
                    txt[pst_row] = pst[tmp] + txt[pst_row];

                    row += tmp;
                    col = pst[tmp].length();
                }
            }
        }
        else if(s == "REMOVE"){
            cin >> str;

            if(sel == true){ // 删除当前选中内容
                sel = false; // 退出选中状态
                erase_sel(rec_row,rec_col);
            }
            else{
                if(str == "Del"){ // 删除当前光标位置之后的一个字符
                    int last_row = txt.size() - 1;
                    int last_col = txt[row].length();

                    if(row == last_row && col == last_col) continue; // 若当前光标在文件末尾，则忽略当前操作

                    if(col == last_col){ // 若该字符为换行符，则当前行与下一行合并为一行
                        txt[row] += txt[row + 1];
                        txt.erase(txt.begin() + row + 1);
                    }
                    else{
                        txt[row].erase(txt[row].begin() + col);
                    }
                }
                else if(str == "Backspace"){ // 删除当前光标位置之前的一个字符
                    if(row == 0 && col == 0) continue; // 若当前光标在文件开头，则忽略当前操作

                    if(col == 0){ // 若该字符为换行符，则当前行与上一行合并为一行
                        col = txt[row - 1].length();
                        txt[row - 1] += txt[row];
                        txt.erase(txt.begin() + row);
                        row--;
                    }
                    else{
                        txt[row].erase(txt[row].begin() + col - 1);
                        col--;
                    }
                }
            }
        }
        else if(s == "SHIFT"){
            shf *= -1; // 若当前为启动状态，则关闭；若当前为关闭状态，则启动

            if(shf == 1){ // 粘滞功能启动时，记录当前的光标位置为 记录点
                // 粘滞功能启动后，直到功能关闭前，不会对记事本进行除光标移动外的任何操作
                if(sel == true){ // 若再次启动粘滞功能：退出选中状态，但保留上一次选中字段的 记录点 作为当前记录点
                    sel = false;
                }
                else{
                    rec_row = row, rec_col = col;
                }
            }
            else if(rec_row != row || rec_col != col){ // 粘滞功能关闭时，若此时的光标位置与 记录点 的位置不同，则进入选中状态
                sel = true;
                slc.clear();
                
                int sta_row = rec_row,sta_col = rec_col,des_row = row,des_col = col;
                
                // 保存选中的内容
                if(rec_row == row){
                    if(rec_col > col){
                        swap(sta_col,des_col);
                    }

                    string slc_row = txt[row].substr(sta_col, des_col - sta_col);
                    slc.emplace_back(slc_row);
                }
                else{
                    if(rec_row > row){
                        swap(sta_row,des_row);
                        swap(sta_col,des_col);
                    }

                    string slc_row = txt[sta_row].substr(sta_col,txt[sta_row].length() - sta_col);
                    slc.emplace_back(slc_row);

                    for(int i = sta_row + 1; i < des_row; i++){
                        slc.emplace_back(txt[i]);
                    }

                    slc_row = txt[des_row].substr(0,des_col);
                    slc.emplace_back(slc_row);
                }
            }
        }
        else if(s == "FIND"){
            cin >> str;

            if(sel == true){ // 若当前处于选中状态：查找输入字符串在选中字段中的出现次数并输出; 在操作后仍然保持选中状态
                find(slc,str);
            }
            else{ // 否则：查找输入字符串在当前记事本中的出现次数并输出
                find(txt,str);
            }
        }
        else if(s == "COUNT"){
            if(sel == true){ // 若当前处于选中状态：输出当前选中字段中的可见字符（不包括空格与换行符）的数量
                count(slc);
            }
            else{ // 否则：输出当前文档中可见字符（不包括空格与换行符）的数量
                count(txt);
            }
        }
        else if(s == "COPY"){
            if(sel == true){ // 若当前处于选中状态：复制选中字段到粘贴板；
                pst = slc;
            }
            else{
                if(txt[row] != ""){ //若当前行不为空：复制当前行的内容（不包括换行符）到粘贴板
                    pst.clear();
                    pst.emplace_back(txt[row]); 
                }
            }
        }
        else if(s == "PRINT"){ // 输出当前的记事本中的全部内容，并在之后输出一个换行符
            for(auto& x:txt){
                for(int i = 0;i <x.length(); i++){
                    cout << x[i];
                }
                cout << endl;
            }
        }
    }

    return 0;
}