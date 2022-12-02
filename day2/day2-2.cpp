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
    values['A'] = 1; //rock
    values['B']= 2; //paper
    values['C']= 3; //scissor
    values['X'] = 0; //rock
    values['Y']= 3; //paper
    values['Z']= 6; //scissor

    map<pair<char, char>, char> results;
    results[make_pair('A', 'X')]= 'C';
    results[make_pair('A', 'Y')]= 'A';
    results[make_pair('A', 'Z')] = 'B';
    results[make_pair('B', 'X')]= 'A';
    results[make_pair('B', 'Y')] = 'B';
    results[make_pair('B', 'Z')]= 'C';
    results[make_pair('C', 'X')] = 'B';
    results[make_pair('C', 'Y')]= 'C';
    results[make_pair('C', 'Z')] = 'A';

    if (file.good())
    {
        int sum =0;
        char opposite_player;
        char exp_result;
        string str;
        while(getline(file, str)) 
        {
            istringstream ss(str);
            ss>> opposite_player;
            ss>>exp_result;
            cout<<opposite_player<<" "<<exp_result<<endl;
            char myplay = results[make_pair(opposite_player, exp_result)];
            cout<<myplay<<" "<<values[myplay]<<endl;
            cout<<exp_result<<" "<<values[exp_result]<<endl;
            sum += values[myplay];
            sum += values[exp_result];
        }
        cout<<sum<<endl;
    }
    return 0;

}