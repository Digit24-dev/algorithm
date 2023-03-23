#include <string>
#include <iostream>

using namespace std;

int power(int score, int n){
	int sum = 1;
	while(n--){
		sum *= score;
	}
	return sum;
}

int solution(string dartResult) {
    int answer = 0;
    bool flag = false;
    int round = 1;
    int score[4];
    
    for(int i=0; i<dartResult.size(); ++i){
        string temp = &dartResult[i];
        
        if(flag){
            flag = false;
            continue;
        }
        
        try{
            int score_bucket = stoi(temp);
            if(score_bucket == 10)
                flag = true;
            score[round++] = score_bucket;
        }catch(exception e){
            //throw
        }
        
        switch(dartResult[i]){
            case 'S':
                break;
            case 'D':
                score[round-1] = power(score[round-1], 2);
                break;
            case 'T':
                score[round-1] = power(score[round-1], 3);
                break;
            case '*':
                if(round == 2)
                    score[round-1] *= 2;
                else{
                	score[round-1] *= 2;
                	score[round-2] *= 2;
				}
                break;
            case '#':
                score[round-1] *= -1;
                break;
            default:
                break;
        }
    }
    for(int i=1; i<4; ++i){
    	answer += score[i];
    	cout << score[i] << " ";
	}
    cout << endl;
    
    return answer;
}

int main(){
	cout << power(2, 4) << endl;
	cout << solution("1S2D*3T");
	
	return 0;
}



// string stream 사용 코드 
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    stringstream ss(dartResult);

    int sum[3] = { 0, 0, 0 };
    int options[3] = { 1, 1, 1 };
    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;

        ss >> score;

        bonus = ss.get();
        option = ss.get();

        if (option != '*' && option != '#') {
            ss.unget();
        }

        switch (bonus) {
        case 'S':
            sum[i] += pow(score, 1);
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option) {
        case '*':
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
            break;
        case '#':
            options[i] = -options[i];
            break;
        default:
            break;
        }
    }

    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}

// vector 사용 코드
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    vector<int> v;
    for(int i = 0, s = 0; i < dartResult.size(); ++i) {
        if(dartResult[i] >= '0' && dartResult[i] <= '9')
            s = s * 10 + dartResult[i] - '0';
        else if(dartResult[i] == 'S') v.push_back(s), s = 0;
        else if(dartResult[i] == 'D') v.push_back(s * s), s = 0;
        else if(dartResult[i] == 'T') v.push_back(s * s * s), s = 0;
        else if(dartResult[i] == '*') {
            if(v.size() > 1) v.back() *= 2, v[v.size() - 2] *= 2;
            else v.back() *= 2;
        } else v.back() = -v.back();

    }
    int ans = 0;
    for(int i = 0; i < v.size(); ++i) ans += v[i];
    return ans;
}
