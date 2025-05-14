#include <cstdint>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    unordered_map<int, int> hash_map;
    for(auto i: nums){
        cout << i << endl;
        if(hash_map.find(i) == hash_map.end()){
            hash_map[i] = 1;
        } else {
            hash_map[i]++;
        }
    }
    int max = INT32_MIN;
    int max_elem = -1;
    for(auto it = hash_map.begin(); it != hash_map.end(); it++){
        if(it->second > max){
            max_elem = it->first;
            max = it->second;
        }
    }
    cout << max << " " << max_elem << endl;
    return 0;
}