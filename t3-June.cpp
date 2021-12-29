#include <bits/stdc++.h>
#define rep(i, s, t) for(int i=s;i<=t;i++) // 循环头
using namespace std;

/* 全局变量 */
int n;                   // 猪的数量
queue<char> allCards;    // 牌堆

struct Pig {
/* 属性 */
    int index;            // 当前猪下标
    int hp = 4;           // 血量
    char type;            // 猪的类型: M, Z, F
    char jumpType = '0';    // 跳的类型: Z(忠), F(反), f(MP视角的类反), 0(空), 注意对MP来说针对F更优先于f
    bool arming = false;  // 有无装备
    list<char> cards;     // 手中的牌
/* 方法定义, 这里是完成本题必须的方法, 可以不必多定义了 */
    void jump() { jumpType = type=='F'?'F':'Z'; } // 跳阵营
    bool isJumpItsFriend(Pig* pig) { return pig->type == 'F' ? jumpType == 'F' : jumpType == 'Z'; } // 我跳它朋友了吗?
    Pig* getNextPig();    // 获取存活的下家
    void addCards(int num);// 从牌堆拿牌放到自己手右
    bool del(char c);     // 删掉手里一张牌, 删成功则返回true
    void hurt(Pig* attacker);// 被攻击掉一点血
    bool cost(Pig* attacker, char c);// 被迫消耗手中一张牌, 消耗成功返回true并不减血, 否则减血, 减血到0尝试用桃, 无则死亡, 根据身份对杀者做后续处理
    bool useP();          // 主动使用桃, 满足使用条件就使用, 使用后返回true
    bool useK();          // 主动使用杀, 满足使用条件就使用, 使用后返回true
    bool useF();          // 主动使用决斗, 满足使用条件就使用, 使用后返回true
    bool useN();          // 主动使用南猪入侵, 满足使用条件就使用, 使用后返回true
    bool useW();          // 主动使用万箭齐发, 满足使用条件就使用, 使用后返回true
    bool findJ(Pig* attacker); // 被迫去求无懈可击, 求到则返回true
    bool useJ(Pig* pig);  // 帮某个猪用无懈可击, 用成功返回true
} ps[15];

/* 全局方法 */
bool isGameEnd() { // 一旦达成胜利条件，游戏立刻结束
    if (ps[0].hp <= 0) return true; // 反猪的胜利条件：杀死主猪
    // 主猪和忠猪的胜利条件：杀死所有反猪
    rep(i, 1, n-1)
        if (ps[i].type == 'F' && ps[i].hp > 0)
            return false;
    return true;
}
int cnt = 0;
void judgeGameEnd() {
    if (isGameEnd()) {
        printf(ps[0].hp > 0 ? "MP\n" : "FP\n");
        rep(i, 0, n-1) {
            if (ps[i].hp <= 0) {
                printf("DEAD\n");
            } else {
                for (list<char>::iterator it = ps[i].cards.begin(); it != ps[i].cards.end(); it++)
                    printf(it==ps[i].cards.end()?"%c":"%c ", *it);
                printf("\n");
            }
        }
        exit(0);
    }
}

void solve() {
    ps[0].jump();
    while (true) {
        rep(i, 0, n-1) {
            if (ps[i].hp <= 0) continue;
            ps[i].addCards(2);
            bool usedK = false;
            for (list<char>::iterator it = ps[i].cards.begin(); it != ps[i].cards.end(); it++) {
                bool used = false;
                char c = *it;
                it = ps[i].cards.erase(it);
                switch (c) {
                    case 'P': used = ps[i].useP(); break;
                    case 'K': if (!usedK || ps[i].arming) used = usedK = ps[i].useK(); break;
                    case 'F': used = ps[i].useF(); break;
                    case 'N': used = ps[i].useN(); break;
                    case 'W': used = ps[i].useW(); break;
                    case 'Z': ps[i].arming = used = true; break;
                }
                if (used) it = --ps[i].cards.begin();
                else it = ps[i].cards.insert(it, c);
                if (ps[i].hp <= 0) break;
            }
        }
    }
}
/* 主控方法 */
int main() {
    // Input
    int m; scanf("%d%d", &n, &m);
    char s[5];
    rep(i, 0, n-1) {
        ps[i].index = i;
        scanf("%s", s), ps[i].type = s[0];
        rep(j, 1, 4) scanf("%s", s), ps[i].cards.push_back(s[0]);
    }
    while(m--) scanf("%s", s), allCards.push(s[0]);
    // To solve
    solve();
}

Pig* Pig::getNextPig() {
    int nxt = (index + 1) % n;
    while (ps[nxt].hp <= 0) {
        nxt = (nxt+1) % n;
    }
    return &ps[nxt];
}

// 摸牌阶段，摸2张牌
void Pig::addCards(int num) {
    rep(i,1,num) {
        cards.push_back(allCards.front());
        allCards.pop();
    }
}

bool Pig::useP() {
    if (hp < 4) {
        hp ++;
        return true;
    }
    return false;
}

bool Pig::useK() { // 主动使用杀(已经确定有杀牌), 满足使用条件就使用, 使用后返回true
    // TODO: 补全代码
    switch (type) {
        case 'M': { // // 主猪：对逆时针方向距离为1的已跳反猪使用杀；没有已跳反猪则杀类反猪；再没有就不使用杀
            Pig *pig = getNextPig();
            bool has_F = false;

            for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
                if (nxt->jumpType == 'F') {
                    has_F = true;
                    break;
                }
            }

            if ((pig->jumpType == 'F') || (!has_F && pig->jumpType == 'f')) {
                pig->cost(this, 'D');
                return true;
            }
            break;
        }
        case 'Z': { // 忠猪：对逆时针方向距离为1的已跳反猪使用杀；如果没有，那么就不使用杀；
            Pig *pig = getNextPig();

            if (pig->jumpType == 'F') {
                jump(); // 使用杀后跳忠
                pig->cost(this, 'D');
                return true;
            }
            break;
        }
        case 'F': {
            Pig *pig = getNextPig();

            if (pig->jumpType == 'Z') {
                jump(); // 使用杀后跳反
                pig->cost(this, 'D');
                return true;
            }
            break;
        }
    }
    return false;
}

// 出牌阶段，对除自己以外任意 1 名角色使用，由目标角色先开始，自己和目标角色轮流弃置 1 张杀，首先没有杀可弃的一方受到 1 点伤害，另一方视为此伤害的来源。
bool Pig::useF() { // // 主动使用决斗, 满足使用条件就使用, 使用后返回true
    // TODO: 补全代码
    Pig *pig = NULL;

    switch (type) {
        case 'M': { // 主猪：对逆时针方向能够执行到的第一只已跳反猪表；如果没有，对逆时针方向能够执行到的第一只类反猪表，再没有，那么就不使用决斗；
            Pig *first_F = NULL, *first_f = NULL;

            for (Pig* nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
                if (nxt->jumpType == 'F') {
                    first_F = nxt;
                    break;
                }

                if (first_f == NULL && nxt->jumpType == 'f') {
                    first_f = nxt;
                }
            }

            pig = first_F;
            if (pig == NULL) {
                pig = first_f;
            }
            break;
        }
        case 'Z': {
            for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
                if (nxt->jumpType == 'F') {
                    pig = nxt;
                    break;
                }
            }
            break;
        }
        case 'F': {
            pig = &ps[0];
            break;
        }
    }

    if (pig) {
        jump(); // 使用决斗后跳忠或跳反

        if (!pig->findJ(this)) { // 没有人帮被决斗的猪猪挡刀
            if (type == 'M' && pig->type == 'Z') { // 忠猪不会和主猪决斗，直接扣血
                pig->hurt(this);
                return true;
            }

            while (true) { // 被决斗的猪猪先弃杀，使用决斗的猪猪后弃
                if (!pig->cost(this, 'K')) return true;

                if (!cost(pig, 'K')) return true;
            }
        }
        return true; // 有猪猪使用无懈可击，决斗牌依然使用成功
    }
    return false;
}

// 出牌阶段，对除你以外所有角色使用，按逆时针顺序从使用者下家开始依次结算，除非弃置 1 张杀，否则受到 1 点伤害。
bool Pig::useN() { // 主动使用南猪入侵, 满足使用条件就使用, 使用后返回true
    for (Pig* nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
        // TODO: 补全代码
        if (!nxt->findJ(this)) {
            if (!nxt->cost(this, 'K') && nxt->type == 'M') {
                if (jumpType == '0') {
                    jumpType = 'f'; // 没有跳忠的猪猪对主猪造成了伤害，则该猪猪成为类反猪
                }
            }
        }
    }
    return true;
}

bool Pig::useW() {
    for (Pig* nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
        // TODO: 补全代码
        if (!nxt->findJ(this)) {
            if (!nxt->cost(this, 'D') && nxt->type == 'M') {
                if (jumpType == '0') {
                    jumpType = 'f';
                }
            }
        }
    }
    return true;
}

// 任何牌被使用后被弃置
bool Pig::del(char c) { // 删掉手里一张牌, 删成功则返回true
    // TODO: 补全代码
    for (list<char>::iterator it = cards.begin(); it != cards.end(); it++) {
        if (*it == c) {
            cards.erase(it);
            return true;
        }
    }
    return false;
}

void Pig::hurt(Pig *attacker) {
    if (--hp == 0) {
        if (this->del('P')) {
            this->useP();
        } else { // 死亡
            judgeGameEnd();
            switch(type) {
                // 反猪死亡时，最后一个伤害来源处（即使是反猪）立即摸 3 张牌
                case 'F': attacker->addCards(3); break;
                // 忠猪死亡时，如果最后一个伤害来源是主猪，那么主猪所有装备牌、手牌被弃置。
                case 'Z': if (attacker->type == 'M') attacker->cards.clear(), attacker->arming=false; break;
            }
        }
    }
}

bool Pig::cost(Pig* attacker, char c) {
    if (this->del(c)) {
        return true;
    }
    hurt(attacker);
    return false;
}

bool Pig::findJ(Pig *attacker) {
    Pig* nxt = attacker;
    do {
        // "找个好心的猪猪帮我挡刀"
        if (this->isJumpItsFriend(nxt) && nxt->del('J')) {
            nxt->jump();
            return !nxt->useJ(this);
        }
        nxt = nxt->getNextPig();
    } while (nxt != attacker);
    return false;
}

bool Pig::useJ(Pig *pig) {
    for (Pig* nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
        // "套娃找找有没有猪猪会阻止我帮别人挡刀"
        if (!this->isJumpItsFriend(nxt) && nxt->del('J')) {
            nxt->jump();
            return !pig->findJ(nxt);
        }
    }
    return false;
}