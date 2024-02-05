#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

vector<string> split(string str, char delim) {
    stringstream ss(str);
    string buffer;
    vector<string> ret;
    while(getline(ss, buffer, delim))
        ret.push_back(buffer);
    return ret;
}

int trans_ms(string str) {
    vector<string> line = split(str, ':');

    int temp = 0;

    temp += stoi(line[0]) * 60 * 60 * 1000;
    temp += stoi(line[1]) * 60 * 1000;
    temp += stof(line[2]) * 1000;
    
    return temp;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> timeline;

    for (auto& str : lines)
    {
        vector<string> line = split(str, ' ');

        int time_end = trans_ms(line[1]);
        int time_start = time_end - floor(stof(line[2]) * 1000) + 1;
        
        if (time_start < 0) time_start = 0;
        int end_time = time_start + 999;
        timeline.push_back(make_pair(time_start, time_end));
    }

    for (auto& cur : timeline)
    {
        double window_front = cur.first;
        double window_back = cur.second;
        int temp = 0;

        for (auto& slide : timeline)
        {
            if ((window_front <= slide.first && slide.first <= window_front + 999) 
                || (window_front <= slide.second && slide.second <= window_front + 999))
                temp++;
        }
        answer = max(answer, temp);
        temp = 0;

        for (auto& slide : timeline)
        {
            if ((window_back <= slide.first && slide.first <= window_back + 999)
                || (window_back <= slide.second && slide.second <= window_back + 999))
                temp++;
        }
        answer = max(answer, temp);
        temp = 0;

        for (auto& slide : timeline)
        {
            if ((window_front - 999 <= slide.first && slide.first <= window_front)
                || (window_front - 999 <= slide.second && slide.second <= window_front))
                temp++;
        }
        answer = max(answer, temp);
        temp = 0;

        for (auto& slide : timeline)
        {
            if ((window_back - 999 <= slide.first && slide.first <= window_back)
                || (window_back - 999 <= slide.second && slide.second <= window_back))
                temp++;
        }
        answer = max(answer, temp);
    }

    return answer;
}


int main() {

    vector<string> p3 = { 
        "2016-09-15 20:59:57.421 0.351s",
        "2016-09-15 20:59:58.233 1.181s",
        "2016-09-15 20:59:58.299 0.8s",
        "2016-09-15 20:59:58.688 1.041s",
        "2016-09-15 20:59:59.591 1.412s",
        "2016-09-15 21:00:00.464 1.466s",
        "2016-09-15 21:00:00.741 1.581s",
        "2016-09-15 21:00:00.748 2.31s",
        "2016-09-15 21:00:00.966 0.381s",
        "2016-09-15 21:00:02.066 2.62s" 
    };
    vector<string> p2 = {
        "2016-09-15 01:00:04.002 2.0s",
        "2016-09-15 01:00:07.000 2s"
    };
    vector<string> p1 = {
        "2016-09-15 01:00:04.001 2.0s",
        "2016-09-15 01:00:07.000 2s"
    };
    vector<string> p4 = {
        "2016-09-15 01:00:04.001 2.0s",
        "2016-09-15 01:00:07.000 2s"
    };

    cout << solution(p1) << endl;
    cout << solution(p2) << endl;
    cout << solution(p3) << endl;
    cout << solution(p4) << endl;

    return 0;
}