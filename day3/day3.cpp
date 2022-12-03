#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>
#include <set>
#include <iterator>
#include <algorithm>

// Make a two sets from the two compartments and then intersect

void checkLetter(int letter, int& score, int multiple) {
    int tempscore = 0;
    if(islower(letter)) {
        tempscore = (letter - 96);
        score+=tempscore;
    }
    else {
        tempscore = (letter - 65 + 27);
        score+= tempscore;
    }
    
}

int main() {
    std::ifstream file("input.txt");
    std::string str;
    std::map<char,int> duplicates;
    int score = 0;
    
    std::set<char> intersect;
    std::set<char> intersect2;
    std::string firstHalf;
    std::string secondHalf;
    while(std::getline(file,str)) {
        
        //firstHalf = str.substr(0,str.length()/2);
        //secondHalf = str.substr(str.length()/2);
        std::getline(file,firstHalf);
        std::getline(file,secondHalf);
        std::set<char> set1(std::begin(str), std::end(str));
        std::set<char> set2(std::begin(firstHalf), std::end(firstHalf));
        std::set<char> set3(std::begin(secondHalf), std::end(secondHalf));
        
        std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                 std::inserter(intersect, intersect.begin()));
        std::set_intersection(intersect.begin(), intersect.end(), set3.begin(), set3.end(),
                 std::inserter(intersect2, intersect2.begin()));
        for(auto it = intersect2.begin(); it !=
                           intersect2.end(); ++it)
        {
            //std::cout << *it << std::endl;
            checkLetter((int)*it,score, 1 );
        }
        set1.clear();
        set2.clear();
        set3.clear();
        intersect.clear();
        intersect2.clear();
        //for(int i =0; i<str.length();++i) {
        //    duplicates[str[i]]++;
        //}
        //for(auto it: duplicates) {
        //    if(it.second > 1)
        //    std::cout << it.first << ", count = " << it.second << std::endl;
        //    checkLetter((int)it.first, score, (int)it.second);
        //}
        //std::cout << "*****" << std::endl;
        //duplicates.clear();
    }
    std::cout << score << std::endl;

    return 0;
}