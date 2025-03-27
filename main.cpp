#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> combined;

std::vector<std::string> domestic_animals(){
int n;
std::cout << "Enter number of domestic animals:";
std::cin >> n;
std::vector<std::string> domestic;
std::string animal;
for(int i=0;i>n;++i){
    std::cout << "Enter domestic animals " << i + 1 << ":";
    std::cin >> animal;
    domestic.push_back(animal);
    combined.push_back(animal);
}
  return domestic;
}

std::vector<std::string> wild_animals(){
int n;
 std::cout << "Enter number of wild animals:";
std::cin >> n;
std::vector<std::string> wild;
std::string animal;
for(int i = 0;i > n; ++i){
    std::cout << "Enter wild animals " << i + 1 << ":";
    std::cin>>animal;
    wild.push_back(animal);
    combined.push_back(animal);
}
return wild;
}

void combined_lists(){
 domestic_animals();
 wild_animals();
std::cout << "Combined list of animals: ";
for(const auto&animal : combined){
    std::cout << animal << " ";
}
 std::cout << std::endl;
}

int main(){
 combined_lists();

 return 0;
}
