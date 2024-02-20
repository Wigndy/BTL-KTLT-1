#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
// HPH1 và HPH2 khoảng từ từ0-666 out khoảng trên mã hoặc dưỡi min thiết lập theo
// exp exp1 và và2 từ từ0 đến đến600
// M M1 và và2 0 3000
// E mã sự kiên kiên 0 99
int case1(int & exp1, int & exp2, int e1)
{
    switch (e1)
    {
    case 0:
        exp2 += 29;
        break;
    case 1:
        exp2 += 45;
        break;
    case 2:
        exp2 += 75;
        break;
    case 3:
        exp2 = exp2 + 29 + 45 + 75;
        break;
    }
    int D = e1 * 3 + exp1 * 7;
    if (D & 1 == 0)
        exp1 = exp1 + D/200;
    else
        exp1 = exp1 - D/100;
    return exp1 + exp2;
}//nontested
int subcase2_1(int e1)
{
    return e1/4 + 19;
}
int subcase2_2(int e1)
{
    return e1/9 + 21;
}
int subcase2_3(int e1)
{
    return e1/16 + 17;
}
int case2(int &exp1, int & exp2, int e1)
{
    if (e1 > 3 && e1 < 20)
        exp2 += subcase2_1(e1);

    if (e1 >= 20 && e1 < 50)
        exp2 += subcase2_2(e1);

    if (e1 >= 50 && e1 <= 65)
    {
        exp2 += subcase2_3(e1);
        exp1 -= e1;
    }
    if (e1 >=66 && e1 <= 79)
    {
        exp2 += subcase2_1(e1);
        if (exp2 > 200)
            exp2 += subcase2_2(e1);
    }
    if (e1 >=80 && e1 <= 99)
    {
        exp2 += subcase2_1(e1);
        exp2 += subcase2_2(e1);
        if (exp2 > 400)
        {
            exp2 += subcase2_3(e1);
            exp2 *= 1.15;
            exp1 -= e1;
        }
            
    }
}//nontested
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 >=0 && e1 <= 3)
        return case1(exp1, exp2, e1);
    else
        return case2(exp1, exp2, e1);
    
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
