#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <queue>

int main() {
    std::ifstream file("input.txt");
    std::string str;
    int calorieSum = 0;
    std::priority_queue<int> pq;
    while(std::getline(file,str)) {
        if(str.length() == 0) {
            pq.push(calorieSum);
            calorieSum = 0;
        }
        else {
            calorieSum+= std::stoi(str);
        }
    }
    int top3total = 0;
    for(int i=0; i<3; ++i) {
    top3total += pq.top();
    pq.pop();
    }
    std::cout << top3total << std::endl;
    //std::cout << "Hello World!" << std::endl;
    return 0;
}