/* Rock paper scissors
Opponent: A = Rock, B = Paper, C=Scissors
Me: X=Rock, Y=Paper, Z=Scissors
Rock=1p, Paper=2p, Scissors=3p
Win=6p, Lost=0p, Draw=3p

Part 2
X means lose
Y means draw
Z means win*/

#include <iostream>
#include <string>
#include <fstream>
#include <map>


int main() {
    std::ifstream file("input.txt");
    std::string str;
    int score = 0;
    std::map<std::string,int> options = {{"A", 1}, {"B",2}, {"C",3}, {"X",0}, {"Y",3}, {"Z",6}, {"A Y", 1}, {"A Z", 2}, {"A X", 3}, {"B X", 1}, {"B Y", 2}, {"B Z", 3}, {"C X", 2}, {"C Y", 3}, {"C Z", 1}};
    while(std::getline(file,str)) {
        std::string safePoints = str.substr(2,1);
        score+=options[safePoints];
        score+=options[str];
        
        }
    std::cout << score << std::endl;
    return 0;
}
