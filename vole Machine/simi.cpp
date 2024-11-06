#include "voleMachine.h"
#include <stdexcept>

    void Machine:: load_Value(int op_erand_1, int op_erand_2){
        int frt = op_erand_1 & 0x0FF;
        int value = op_erand_2 & 0x0FF;
        registers[frt].value = value;
    }

    void test_1(){
        cout << "=====    test    ====";
    }

    void Machine:: store_Register(int op_erand_1, int op_erand_2){
        int frt = op_erand_1 & 0x0FF;
        int address = op_erand_2 & 0x0FF;
        memory.data[address] = registers[frt].value;
    }

    void test_2(){
        cout << "=====    test    ====";
    }

    void Machine:: load_Register(int op_erand_1, int op_erand_2){
        int frt = op_erand_1 & 0x0F;
        int address = op_erand_2 & 0x0FF;
        registers[frt].value = memory.data[address];
    }

    void test_3(){
        cout << "=====    test    ====";
    }

    void Machine:: store_Screen(int op_erand_1){
        cout << "Screen: " << hex << registers[0].value << dec << endl;
    }

    void test_4(){
        cout << "=====    test    ====";
    }

    void Machine:: move_Register(int op_erand_1, int op_erand_2){
        int  frt = op_erand_1 & 0x0F; ;
        int sec = (op_erand_2 >> 4) & 0x07;
        registers[frt].value = registers[sec].value;
    }

    void test_5(){
        cout << "=====    test    ====";
    }

    void Machine:: add_Registers(int op_erand_1, int op_erand_2){
        int frt = op_erand_1 & 0x07;  
        int sec = (op_erand_2 >> 4) & 0x0F;  
        int t = op_erand_2 & 0x0F;  
        registers[frt].value = registers[sec].value + registers[t].value;
    }

    void test_6(){
        cout << "=====    test    ====";
    }

    void Machine:: add_Float_Registers(int operand1, int operand2) {
        int register1st = operand1 & 0x07; 
        int register2nd = (operand2 >> 4) & 0x0F; 
        int register3th = operand2 & 0x0F; 
        
        float result = static_cast<float>(registers[register2nd].value) + static_cast<float>(registers[register3th].value);
        
        registers[register1st].value = result;
    }

    void test_7(){
        cout << "=====    test    ====";
    }

    void Machine:: jump_If_Equal(int op_erand_1, int op_erand_2){
        int address = op_erand_2 & 0x0FF;
        int  frt = op_erand_1 & 0x0F;
        if (registers[frt].value == registers[0].value){
            countt = address;
        }
    }

    void test_8(){
        cout << "=====    test    ====";
    }

    void Machine:: orderr(){
        while (countt < program.size()){
            Instruction& instruction__ = program[countt];
            int op_code = instruction__.op_code;
            int op_erand_1 = instruction__.op_erand_1;
            int op_erand_2 = instruction__.op_erand_2;

            if (op_code == 1){
                load_Register(op_erand_1, op_erand_2);
            }
            else if (op_code == 2){
                load_Value(op_erand_1,op_erand_2);
            }
            else if (op_code == 3){
                if (op_erand_2 + op_erand_1 == 0){
                    store_Screen(op_erand_1);
                }
                else{
                    store_Register(op_erand_1, op_erand_2);
                }
            }
            else if (op_code == 4){
                move_Register(op_erand_1, op_erand_2);
            }
            else if (op_code == 5){
                add_Registers(op_erand_1, op_erand_2);
            }
            else if (op_code == 6){
                add_Float_Registers(op_erand_1, op_erand_2);
            }
            else if (op_code == 11){
                jump_If_Equal(op_erand_1, op_erand_2);
            }
            else if (op_code == 12){
                countt = program.size();
            }
            else{
                exit(1);
            }
            countt++;
        }
    }

    void test_9(){
        cout << "=====    test    ====";
    }

    void Machine:: show_result(){
        cout << "==========    Register Status     ==========" << endl;
        for (int i = 0; i < 16; i++){
            if (registers[i].value >= 0 && registers[i].value <= 9){
                cout << "R-" << hex << i << ":     0" <<  registers[i].value << endl;
            }
            else{
                cout << "R-" << hex << i << ":     " <<  registers[i].value << endl;
            }
        }

        cout << endl << "==========    Memory Status     ==========" << endl;
        for (int i = 0; i < memory.data.size(); i++){
            if (memory.data[i] >= 0 && memory.data[i] <= 9){
                cout << "M-" << hex << i << " :     0"  << hex << memory.data[i] << endl;
            }
            else{
                cout << "M-" << hex << i << " :     "<< hex << memory.data[i] << endl;
            }
        }
    }