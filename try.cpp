#include<iostream>
#include <cstdint>
using namespace std;

int main() {

    // vector<int> arr(); // arr indexing is not allowed
    // vector<int> arr(5); // [0, 0, 0, 0, 0]

    // int arr[2] = {5, 10} ;

    // cout << "Size of defualt integer : " << sizeof(int) <<" Bytes" << endl;
    // cout << "Size of u_int8_t : " << sizeof(u_int8_t) <<" Bytes" << endl;
    // cout << "Size of u_int16_t : " << sizeof(u_int16_t) <<" Bytes" << endl;
    // cout << "Size of u_int32_t : " << sizeof(u_int32_t) <<" Bytes" << endl;
    // cout << "Size of u_int64_t : " << sizeof(u_int64_t) <<" Bytes" << endl;


    // cout << "Size of long : " << sizeof(long) <<" Bytes " << endl;
    // cout << "Size of long long : " << sizeof(long long) <<" Bytes " << endl;

    // //Floating Point numbers
    // cout << "Size of float : " << sizeof(float) <<" Bytes " << endl;
    // cout << "Size of double : " << sizeof(double) <<" Bytes " << endl;

    // cout << "Size of bool : " << sizeof(bool) <<" Bytes " << endl;


    uint8_t x = 10;  // 0...255
    std::cout << static_cast<int>(x) << endl;
}