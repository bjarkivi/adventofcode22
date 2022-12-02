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
    std::cout << pq.top() << std::endl;
    //std::cout << "Hello World!" << std::endl;
    return 0;
}