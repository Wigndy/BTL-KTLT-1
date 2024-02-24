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
    if (e1 > 65 && e1 < 80)
    {
        exp2 += subcase2_1(e1);
        if (exp2 > 200)
            exp2 += subcase2_2(e1);
    }
    if (e1 >= 80 && e1 < 100)
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
    return exp1 + exp2;
}//nontested
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 >= 0 && e1 <= 3)
        return case1(exp1, exp2, e1);
    else
        return case2(exp1, exp2, e1);
}



// Task 2
//
void road1(int & EXP1, double & P1)
{
    int unsquared_1 = floor(sqrt(EXP1));
    int unsquared_2 = unsquared_1 + 1;
    unsquared_1 *= unsquared_1;
    unsquared_2 *= unsquared_2;
    if ( (EXP1 - unsquared_1) < (EXP1 - unsquared_2))
        P1 = 100;
    else
        P1 = ((EXP1 / unsquared_2) + 80) /123;   
}
//
void action1(int & HP1, int & M1)
{
    if (HP1 < 200)
    {
        HP1 = HP1 + 0.3 * HP1;
        M1 -= 150;
    }
    else
    {
        HP1 = HP1 + 0.1 * HP1;
        M1 -= 70;
    }
}
void action2(int & EXP1, int & M1)
{
    if (EXP1 < 400)
        M1 -= 200;
    else
    {
        M1 -= 120;
        EXP1 = EXP1 + EXP1 * 0.13;
    }
}
void action3(int & EXP1, int & M1)
{
    if (EXP1 < 300)
        M1 -= 100;
    else
        M1 -= 120;
    EXP1 = EXP1 - EXP1 * 0.1;
}

void road2(int & HP1, int & EXP1, int & M1, int E2, double & P2) //dùng hàm ceil để làm tròn lên
{
    if (E2 & 1 == 0)
    {
        action1(HP1, M1);
        if (M1 < 0)
        {
            road1(EXP1, P2);
            return;
        }
        action2(EXP1, M1);
        if (M1 < 0)
        {
            road1(EXP1, P2);
            return;
        }
        action3(EXP1, M1);
        if (M1 < 0)
        {
            road1(EXP1, P2);
            return;
        }
    }

    else
    {
        while (true)
        {
            action1(HP1, M1);
            if (M1 < (0.5 * M1))
                break;
            action2(EXP1, M1);
            if (M1 < (0.5 * M1))
                break;
            action3(EXP1, M1);
            if (M1 < (0.5 * M1))
                break;
        }
        road1(EXP1, P2);
            return;
    }
    
}
void road3(int E2, double & P3)
{
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 / 10 == 0)
        P3 = P[E2];
    else
    {
        int donvi = E2 % 10;
        E2 = E2 / 10;
        E2 = donvi + E2;
        E2 %= 10;
        P3 = P[E2];
    }
    
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    double P1, P2, P3, P_total;
    //int HP1_origin = HP1;
    //int EXP1_origin = EXP1;
    //int M1_origin = M1;
    
    road1(EXP1, P1);
    road2(HP1, EXP1, M1, E2, P2);
    road3(E2, P3);
    if (P1 == 100 && P2 == 100 && P3 == 100)
        traceLuggage(HP1, EXP1, M1, E2);
    else
        P_total = (P1 + P2 + P3) / 3;
    if (P_total < 50)
    {
        HP1 = HP1 - 0.15 * HP1;
        EXP1 = EXP1 + 0.15 * EXP1;
    }
    else
    {
        HP1 = HP1 - 0.1 * HP1;
        EXP1 = EXP1 + 0.2 * EXP1;
    }
    
    return HP1 + EXP1 + M1;
}



// Task 3


int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int taxi_map[10][10] = {};
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            taxi_map[i][j] = (i - j) * ((E3 * j)+ (i * 2));
    int pos = 0;
    int neg = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (taxi_map[i][j] > (E3 * 2))
                pos ++;
            else if (taxi_map[i][j] < (-E3))
                neg ++;
    while(pos / 10 != 0)
    {
        int i = pos % 10;
        pos /= 10;
        pos += i;
    }
    while(neg / 10 != 0)
    {
        int i = neg % 10;
        neg /= 10;
        neg += i;
    }
    int point_Sher = taxi_map[pos][neg];
    int point_taxi = taxi_map[pos][neg];
    for (int i = pos, j = neg ; i < 10 && j < 10; i++, j ++)
        point_Sher = (taxi_map[i][j] > point_Sher) ? (taxi_map[i][j]) : point_Sher;
    for (int i = pos, j = neg ; i < 10 && j >= 0; i++, j --)
        point_Sher = (taxi_map[i][j] > point_Sher) ? (taxi_map[i][j]) : point_Sher;
    for (int i = pos, j = neg ; i >= 0 && j < 10; i--, j ++)
        point_Sher = (taxi_map[i][j] > point_Sher) ? (taxi_map[i][j]) : point_Sher;
    for (int i = pos, j = neg ; i >= 0 && j >= 0; i--, j --)
        point_Sher = (taxi_map[i][j] > point_Sher) ? (taxi_map[i][j]) : point_Sher;
    if (abs(point_Sher) > abs(point_taxi))
        return point_Sher;
    else
        return point_taxi;
}






// Task 4
bool shorter(int size)
{
    return (size < 8) ? 0 : 1;
}
bool longer(int size)
{
    return (size > 20) ? 0 : 1;
}
int checkPassword(const char * s, const char * email) {// one remaining case
    // TODO: Complete this function
    size_t Size_s = strlen(s);
    
    if (shorter(Size_s))
        return -1;
    if (longer(Size_s))//
        return -2;
        
    string se = "";
    for (int i = 0; email[i] != '@'; i ++)
        se += (email[i]);
    size_t Size_se = se.length();
    for (int i = 0; i <= Size_s - Size_se; i++) //se_contained();
    {   
        int j;
        for (j = 0; j < Size_se; j++)
            if (s[i + j] != se[j])
                break;
        if (j == Size_se)
            return (- 300 + i);
    }

    for (int i = 0; i < Size_s - 2; i++) //common_sub();
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            return (- 400 + i);    
    
    int count = 33;//non_special();
    bool special = 0;
    do
    {
        bool var = 0;
        for (int i = 0; i < Size_s; i++)
            if (s[i] == count)
            {
                special = 1;
                var = 1;
            }
        if (var == 1)
            break;
        if (count == 33)
        {
            count += 2;
            continue;
        }   
        count ++;
        
    }while (count <= 38);
    if (special == 0)
        return -5;
    

    
    //non_valid()___ contain other undeclared character


    return -10;
    //approriate();
}





// Task 5
#define LIMIT_ 30
//int count_(const char ** arr_pwds[], int num_pwds, char * element)

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    //char * arr_pwds_shorten[LIMIT_];
    string max_count_password;
    int max_count = 0;
    //count which max
    for (int i = 0; i < num_pwds; ++i) {
        int count = 0;
        for (int j = 0; j < num_pwds; j ++)
            if (arr_pwds[i] == arr_pwds[j])
                count ++;
        if (count > max_count || (count == max_count && strlen(arr_pwds[i]) > max_count_password.length())) {
            max_count = count;
            max_count_password = arr_pwds[i];
        }
    }

    // find first pos
    for (int i = 0; i < num_pwds; ++i) 
        if (arr_pwds[i] == max_count_password)
            return i;
    
    
    // Not found
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
