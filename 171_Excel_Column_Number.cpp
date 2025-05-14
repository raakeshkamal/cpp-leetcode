#include <cstdint>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    string name = "ZY";
    int num = 0;
    for(auto c: name){
        num *= 26;
        num += ((int)(c - 'A') + 1);
    }
    cout << num << endl;
    return 0;
}