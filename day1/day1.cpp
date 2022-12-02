#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    ifstream file("input.txt",ios::in);
    int maxsum = -1;
    if (file.good())
    {
        int sum =0;
        int num;
        string str;
        while(getline(file, str)) 
        {
            istringstream ss(str);
            if (ss>>num){
                sum += num;
            }
            else {
                maxsum = max(sum, maxsum);
                sum = 0;

            }
        }
        cout<<maxsum<<endl;
    }
    return 0;

}