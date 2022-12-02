#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <utility>
using namespace std;

int main(){
    ifstream file("input.txt",ios::in);
    int sum =0;
    cout<<sum<<endl;
    map<char, int> values;
    values['X'] = 1;
    values['Y']= 2;
    values['Z']= 3;

    map<pair<char, char>, int> results;
    results[make_pair('A', 'X')]= 3;
    results[make_pair('A', 'Y')]= 6;
    results[make_pair('A', 'Z')] = 0;
    results[make_pair('B', 'X')]= 0;
    results[make_pair('B', 'Y')] = 3;
    results[make_pair('B', 'Z')]= 6;
    results[make_pair('C', 'X')] = 6;
    results[make_pair('C', 'Y')]= 0;
    results[make_pair('C', 'Z')] = 3;

    if (file.good())
    {
        int sum =0;
        char opposite_player;
        char my_play;
        string str;
        while(getline(file, str)) 
        {
            istringstream ss(str);
            ss>> opposite_player;
            ss>>my_play;
            cout<<opposite_player<<" "<<my_play<<endl;
            sum += values[my_play];
            cout<<values[my_play]<<endl;
            sum += results[make_pair(opposite_player, my_play)];
            cout<<results[make_pair(opposite_player, my_play)]<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;

}