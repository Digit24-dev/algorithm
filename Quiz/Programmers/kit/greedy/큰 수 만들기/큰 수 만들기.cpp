#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution1(string number, int k) {
    string ans = "";

    for (int i = 0; i < number.length(); i++)
    {
        if (ans == "") {
            ans += number[i];
            continue;
        }

        while (k > 0 && ans != "" && ans.back() < number[i]) {
            ans.pop_back();
            --k;
        }

        ans += number[i];
    }
    ans = number;
    while (k--)
    {
        ans.pop_back();
    }

	return ans;
}

string solution2(string number, int k) {
    string answer = "";

    int flag = 1;
    while(flag){
        for(int i=1;i<number.length();i++){
            if(number[i-1] < number[i] && k >= 1){
                number.erase(i-1, 1);
                k--;
                if(k == 0)
                    flag = 0;

                break;
            }

            if(i == number.length()-1)
                flag = 0;
        }
    }

    while(k--){
        //number.erase(number.length()-1, 1);
        number.pop_back();
    }

    answer = number;
    return answer;
}

int main() {
	//string param1 = "1000100011"; int k = 5;
	//string param1 = "4177252841";	int k = 4;
    //string param1 = "1231234";	int k = 3;
    string param1 = "333222111"; int k = 3;

	cout << solution2(param1, k) << endl;

 }