#include<iostream>
using namespace std;

int main() {
    int statusReg  = 0b10110001; 
    int controlReg = 0b00000000; 
    int dataReg    = 0b11001010; 


    const int* regPtr1 = &statusReg;
    cout << "regPtr1 initial value (*regPtr1) : " << *regPtr1 << endl;

    regPtr1 = &dataReg;      
    cout << "regPtr1 after repointing (*regPtr1): " << *regPtr1 << endl;

    int* const regPtr2 = &controlReg;
    *regPtr2 = 0b11111111;    
    cout << "\nregPtr2 modified value (*regPtr2): " << *regPtr2 << endl;

    const int* const regPtr3 = &statusReg;
    cout << "\nregPtr3 locked value (*regPtr3)  : " << *regPtr3 << endl;

    return 0;
}