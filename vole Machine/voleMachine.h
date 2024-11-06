#ifndef VOLEMACHINE_H
#define VOLEMACHINE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Instruction{
    int op_code;
    int op_erand_1;
    int op_erand_2;
};

class Register{
    public:
        int value;
        Register() : value(0){};
};

class Memory{
    public:
        vector<int> data;
        Memory() : data(256, 0){};
};



class Machine{
    private:
        vector<Instruction> program;

        void load_Register(int op_erand_1, int op_erand_2);

        void load_Value(int op_erand_1, int op_erand_2);
        
        void store_Register(int op_erand_1, int op_erand_2);

        void store_Screen(int op_erand_1);

        void move_Register(int op_erand_1, int op_erand_2);

        void add_Registers(int op_erand_1, int op_erand_2);

        void add_Float_Registers(int op_erand_1, int op_erand_2);

        void jump_If_Equal(int op_erand_1, int op_erand_2);

    public:
        int countt;
        Memory memory;
        Register registers[16];


        Machine(const string& filename) : memory(), countt(0){
            for (int i = 0; i < 16; i++){
                registers[i].value = 0;
            }


            ifstream file(filename);
            string words;
            while (getline(file, words)){
                stringstream string_srm(words);
                int op_code;
                int op_erand_1;
                int op_erand_2;

                string_srm >> hex >> op_code >> op_erand_1 >> op_erand_2;

                Instruction instruction__;
                instruction__.op_code = op_code;
                instruction__.op_erand_1 = op_erand_1;
                instruction__.op_erand_2 = op_erand_2;
                program.push_back(instruction__);
            }
        }

        void orderr();

        void show_result();
};

#endif