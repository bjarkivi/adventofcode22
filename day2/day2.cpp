/* Rock paper scissors
Opponent: A = Rock, B = Paper, C=Scissors
Me: X=Rock, Y=Paper, Z=Scissors
Rock=1p, Paper=2p, Scissors=3p
Win=6p, Lost=0p, Draw=3p*/

#include <iostream>
#include <string>
#include <fstream>
#include <map>


int main() {
    std::ifstream file("input.txt");
    std::string str;
    int score = 0;
    std::map<std::string,int> options = {{"A", 1}, {"B",2}, {"C",3}, {"X",1}, {"Y",2}, {"Z",3}, {"A Y", 6}, {"A Z", 0}, {"B X", 0}, {"B Z", 6}, {"C X", 6}, {"C Y", 0}, {"A X", 3}, {"B Y", 3}, {"C Z", 3}};
    while(std::getline(file,str)) {
        std::string safePoints = str.substr(2,1);
        score+=options[safePoints];
        score+=options[str];
        
        }
    std::cout << score << std::endl;
    return 0;
}
