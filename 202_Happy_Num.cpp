#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n = 19;
    int num = n;
    vector<int> book_keep;
    while(num > 1){
        int sqaured_out = 0;
        int curr_num = num;
        while(curr_num > 0){
            int digit = curr_num % 10;
            sqaured_out += digit*digit;
            curr_num /= 10;
        }
        num = sqaured_out;
        cout << num << endl;
        if(find(book_keep.begin(), book_keep.end(), num) != book_keep.end()){
            break;
        } else {
            book_keep.push_back(num);
        }
    }
    cout << num << endl;
    return 0;
}