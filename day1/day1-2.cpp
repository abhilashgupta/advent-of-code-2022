// priority_queue<int, std::vector<int>, std::greater<int>>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

int main(){
    ifstream file("input.txt",ios::in);
    priority_queue<int, std::vector<int>, std::greater<int> > pq;
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
                pq.push(sum);
                sum = 0;
            }
            if (pq.size() > 3){
                pq.pop();
            }
        }

        int answer = 0;
        while (!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
        cout<<answer<<endl;
       
    }
    return 0;

}