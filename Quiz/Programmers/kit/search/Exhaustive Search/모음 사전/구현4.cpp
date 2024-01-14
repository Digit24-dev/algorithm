#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void add_words(vector<string>& curr, string base, int length_remaining){
    if(length_remaining == 0)return; 
    else{
        curr.push_back(base+"A"s);add_words(curr,base+"A"s,--length_remaining);
        curr.push_back(base+"E"s);add_words(curr,base+"E"s,length_remaining);
        curr.push_back(base+"I"s);add_words(curr,base+"I"s,length_remaining);
        curr.push_back(base+"O"s);add_words(curr,base+"O"s,length_remaining);
        curr.push_back(base+"U"s);add_words(curr,base+"U"s,length_remaining);
    }
}

int solution(string word) {
    vector<string> allwords;
    add_words(allwords,""s,5);
    sort(allwords.begin(),allwords.end());
    auto it = find(allwords.cbegin(),allwords.cend(),word);
    return it-allwords.begin()+1;
}