#include <bits/stdc++.h>
using namespace std;

struct SC{
    int score, roll_cnt, run_cnt;
    string grade, last_date, last_time, sex;
}typedef SC;

map<string, SC> mp;

int run_test(string time, string sex) {
    string m_str = "", s_str = "";
    int i;

    for (i = 0; time[i] != '\''; i++) {
        m_str += time[i];
    }

    for (i++; i < time.length(); i++) {
        s_str += time[i];
    }

    int m = stoi(m_str), s = stoi(s_str);

    if (sex == "M") {
        if (m < 12) return 20;

        if (m == 12) {
            if (s <= 30)
                return 20;
            return 18;
        }

        if (m == 13) {
            if (s == 0) return 18;
            if (s <= 30) return 16;
            return 14;
        }

        if (m == 14) {
            if (s == 0) return 14;
            if (s <= 30) return 12;
            return 10;
        }

        if (m == 15) {
            if (s <= 10) return 10;
            if (s <= 50) return 8;
            return 6;
        }

        if (m == 16) {
            if (s <= 30)
                return 6;
            return 4;
        }

        if (m == 17) {
            if (s <= 10)
                return 4;
            return 2;
        }

        if (m == 18) {
            if (s == 0)
                return 2;
            return 0;
        }

        return 0;
    }

    else if (sex == "F") {
        if (m < 6) return 20;

        if (m == 6) {
            if (s <= 40) return 20;
            if (s <= 57) return 18;
            return 16;
        }

        if (m == 7) {
            if (s <= 14) return 16;
            if (s <= 31) return 14;
            if (s <= 50) return 12;
            return 10;
        }

        if (m == 8) {
            if (s <= 5) return 10;
            if (s <= 20) return 8;
            if (s <= 35) return 6;
            if (s <= 50) return 4;
            return 2;
        }

        if (m == 9) {
            if (s == 0)
                return 2;
            return 0;
        }

        return 0;
    }

    else {
        if (m > 4) return 0;

        if (m == 4) {
            if (s > 30)
                return 0;
            return 1;
        }

        return 1;
    }
}

int time_toi(string time) {
    string str_hh = time.substr(0, 2), str_mm = time.substr(3, 2), str_ss = time.substr(6, 2);
    int h = stoi(str_hh), m = stoi(str_mm), s = stoi(str_ss);
    return h * 3600 + m * 60 + s;
}

bool check_speed(string start_time, string end_time, float distance) {
    int start = time_toi(start_time);
    int end = time_toi(end_time);

    float speed = distance * 1000.0 / (end - start);

    if (speed < 2 || speed > 5)
        return false;
    return true;
}

bool check_date(string id, string date, string start_time) {
    if (mp[id].last_date == "") return true;

    int start_year = stoi(date.substr(0, 4));
    int start_month = stoi(date.substr(4, 2));
    int start_day = stoi(date.substr(6, 2));

    int last_year = stoi(mp[id].last_date.substr(0, 4));
    int last_month = stoi(mp[id].last_date.substr(4, 2));
    int last_day = stoi(mp[id].last_date.substr(6, 2));

    if (last_year < start_year) return true;

    if (last_month < start_month) return true;

    if (last_day < start_day) return true;

    int last = time_toi(mp[id].last_time), start = time_toi(start_time);

    if (start - last < 21600)
        return false;
    return true;
}

int run_daily(int run_cnt) {
    if (run_cnt >= 21) return 10;
    if (run_cnt >= 19) return 9;
    if (run_cnt >= 17) return 8;
    if (run_cnt >= 14) return 7;
    if (run_cnt >= 11) return 6;
    if (run_cnt >= 7) return 4;
    if (run_cnt >= 3) return 2;
    return 0;
}

int daily(int total_cnt) {
    if (total_cnt >= 18) return 5;
    if (total_cnt >= 15) return 4;
    if (total_cnt >= 12) return 3;
    if (total_cnt >= 9) return 2;
    if (total_cnt >= 6) return 1;
    return 0;
}

string score_to_grade(int score) {
    if (score >= 95) return "A";
    if (score >= 90) return "A-";
    if (score >= 85) return "B+";
    if (score >= 80) return "B";
    if (score >= 77) return "B-";
    if (score >= 73) return "C+";
    if (score >= 70) return "C";
    if (score >= 67) return "C-";
    if (score >= 63) return "D+";
    if (score >= 60) return "D";
    return "F";
}

int main()
{
    // ios::sync_with_stdio(false);

    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string id, sex, time, isPass;
        int special_score, daily_score, cnt;

        cin >> id >> sex >> special_score >> time >> isPass >> daily_score >> cnt;

        int run_test_score = run_test(time, sex);
        mp[id].score += special_score + run_test_score + daily_score;
        mp[id].roll_cnt = cnt;
        mp[id].sex = sex;

        if (isPass == "P") {
            mp[id].score += 10;
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string date, id, start_time, end_time, stop_time;
        float distance;
        int step;

        cin >> date >> id >> start_time >> end_time >> distance >> stop_time >> step;

        if (mp[id].sex == "M") {
            if (distance < 3) continue;
        }
        else {
            if (distance < 1.5) continue;
        }

        if (!check_speed(start_time, end_time, distance)) continue;

        if (!run_test(stop_time, "T")) continue;

        if (distance * 1000.0 / step > 1.5) continue;

        if (!check_date(id, date, start_time)) continue;

        mp[id].run_cnt++;
        mp[id].last_date = date;
        mp[id].last_time = end_time;
    }

    for (auto& x:mp) {
        int run_daily_score = run_daily(x.second.run_cnt);
        int daily_score = daily(x.second.run_cnt + x.second.roll_cnt);

        x.second.score += run_daily_score + daily_score;
        x.second.grade = score_to_grade(x.second.score);

        cout << x.first << " " << x.second.score << " " << x.second.grade << endl;
    }

    return 0;
}