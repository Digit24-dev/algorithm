#include <string>
#include <set>
#include <utility>
#include <cmath>
using namespace std;
constexpr int size_x{5}; constexpr int size_y{5};
int solution(string dirs) {
    set<set<pair<int,int> > > walked_path;
    pair<int,int> pos{0,0},dest;
    for(char cmd : dirs){
        switch(cmd){
            case 'U': dest = {pos.first,pos.second+1}; break;
            case 'D': dest = {pos.first,pos.second-1}; break;
            case 'R': dest = {pos.first+1,pos.second}; break;
            case 'L': dest = {pos.first-1,pos.second}; break;
        }
        if(abs(dest.first)<=size_x && abs(dest.second)<=size_y ){
            walked_path.insert({pos,dest}); pos=dest;
        }
    }
    return walked_path.size();
}