// Decimal to binary conversion by taking decimal no. as input in C++
#include <iostream>
using namespace std;

// Function to convert decimaltobinary
string decimalToBinary(int n){
    // initialize empty string
    string ans;
    // till no. becomes zero
    while(n){
        // if no has last digit odd, then add 1 to ans else zero
        if(n & 1){
            ans += '1';
        }else{
            ans += '0';
        }
        // divide the number by two
        n >>= 1;
    }
    return ans;
}

int main() {
    cout<<"Enter a decimal Number: \n";
    // Take user input
    int n;
    cin>>n;
    // call a function to convert decimal to binary 
    string ans = decimalToBinary(n);
    cout<<"Equivalent Binary number is: "<<ans;
    return 0;
}
