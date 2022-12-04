#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>

void parseString(std::string str, int& one, int& two, int& three, int& four) {
    std::size_t delim1 = str.find_first_of("-");
    std::size_t delim2 = str.find_last_of("-");
    std::size_t comma = str.find_last_of(",");
    one = std::stoi(str.substr(0,delim1));
    two = std::stoi(str.substr(delim1+1,(comma-delim1)));
    three = std::stoi(str.substr(comma+1,(delim2-comma)));
    four = std::stoi(str.substr(delim2+1));
}

void findOverlap(const int& one, const int& two, const int& three, const int& four, int& score) {
    auto p1 = std::make_pair(one,two);
    auto p2 = std::make_pair(three,four);

    if(p1.first <= p2.first && p1.second >= p2.first) {
        score++;
    }
    else if(p2.first <= p1.first && p2.second >= p1.first) {
        score++;
    }
        
}

int main() {
    std::ifstream file("input.txt");
    std::string str;
    int fullyContains = 0;
    int zone0_0 ,zone0_1 ,zone1_0 ,zone1_1;
    while(std::getline(file,str)) 
    {
        parseString(str,zone0_0,zone0_1,zone1_0,zone1_1);
        //std::cout << zone0_0 << " " << zone0_1 << " " << zone1_0 << " " << zone1_1 << '\n';
        findOverlap(zone0_0, zone0_1, zone1_0, zone1_1, fullyContains);
    }
    std::cout << fullyContains << std::endl;
    return 0;
}