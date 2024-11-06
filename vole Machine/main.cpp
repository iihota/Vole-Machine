#include "simi.cpp"
#include "voleMachine.h"


int main(){
    
    string FN; 
    cout << "Enter file name here : "; cin >> FN;

    Machine mach(FN);
    mach.orderr();
    mach.show_result();

    return 0;
}
