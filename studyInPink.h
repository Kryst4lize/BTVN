/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// funtion to round_up number
float round_up(float x) {
    return round(x + 0.49999999);
}

// funtion input float type of exp point and return the rounded value or legel value in case it out of the range
float check_exp(float ex) {
    if (ex > 900) {
        return 900;
    }
    else if (ex >= 0) {
        return round_up(ex);
    }
    else {
        return 0;
    }
}

//funtion input float type of hp point and return the rounded value or legel value in case it out of the range
float check_hp(float hp) {
    if (hp > 999) {
        return 999;
    }
    else if (hp >= 0) {
        return round_up(hp);
    }
    else return 0;
}

//funtion input float type of m point and return the rounded value or legel value in case it out of the range
float check_m(float m) {
    if (m > 2000) {
        return 2000;
    }
    else if (m >= 0) {
        return round_up(m);
    }
    else return 0;
}

//funtion input E point and return the legel value in case it out of the range
int check_e(int e) {
    if (e >= 0 && e <= 999) {
        return e;
    }
    else return -999;
}

int firstMeet(int& EXP_1, int& EXP_2, const int& E_1) {
    float EXP1 = EXP_1;
    float EXP2 = EXP_2;
    float E1 = E_1;
    // check legal E1 or not if it legal it must in range 0 to 999
    if (check_e(E1) == -999) {
        return -999;
    }
    // case 1 0<E1<400
    else if (E1 < 400) {
        //caculate waston exp point
        if (E1 < 50) {
            EXP2 += 25;
        }
        else if (E1 < 100) {
            EXP2 += 50;
        }
        else if (E1 < 150) {
            EXP2 += 85;
        }
        else if (E1 < 200) {
            EXP2 += 75;
        }
        else if (E1 < 250) {
            EXP2 += 110;
        }
        else if (E1 < 300) {
            EXP2 += 135;
        }
        else {
            EXP2 += 160;
        }

        // caculate sherlock experiment point
        int E1_int = E1;//need to turn E1 to interger type to caculate %2
        if (E1_int % 2 == 0) {
            EXP1 = EXP1 - E1 / 5;
        }
        else {
            EXP1 = EXP1 + E1 / 10;
        }

        // check legal exp point
        EXP1 = check_exp(EXP1);
        EXP2 = check_exp(EXP2);
        
        EXP_1 = EXP1;
        EXP_2 = EXP2;

        //return value
        return EXP2 + EXP1;
    }

    // case 2 E1 in range 400 to 999
    else {
        // caculate waston exp
        if (E1 < 500) {
            EXP2 += E1 / 7 + 9;
        }
        else if (E1 < 600) {
            EXP2 += E1 / 9 + 11;
        }
        else if (E1 < 700) {
            EXP2 += E1 / 5 + 6;
        }
        else if (E1 < 800) {
            EXP2 += E1 / 7 + 9;
            EXP2 = check_exp(EXP2);
            // in case exp point of waston bigger than 200
            if (EXP2 > 200) {
                EXP2 += E1 / 9 + 11;
                EXP2 = check_exp(EXP2);
            }
        }
        else {
            EXP2 += E1 / 7 + 9 + E1 / 9 + 11;
            EXP2 = check_exp(EXP2);
            // in case exp point of waston bigger than 600
            if (EXP2 > 600) {
                EXP2 += E1 / 5 + 6;
                EXP2 = check_exp(EXP2);
                EXP2 = EXP2 * 115 / 100;
                EXP2 = check_exp(EXP2);
            }
        }
        // caculate the exp point of sherlock
        EXP1 = EXP1 - E1 / 10;
        EXP2 = check_exp(EXP2);
        EXP1 = check_exp(EXP1);
        
        EXP_1 = EXP1;
        EXP_2 = EXP2;
        
        //return value
        return EXP1 + EXP2;
    }
}

int investigateScene(int& EXP_1, int& EXP_2, int& HP_2, int& M_2, const float& E_2) {
    float EXP1 = EXP_1;
    float EXP2 = EXP_2;
    float HP2 = HP_2;
    float M2 = M_2;
    float E2 = E_2;
    // STAGE 1
    float ring_exp = E2 / 9 + 10; //experience point gain from ring
    float coat_exp = E2 * 35 / 100; // experience point gain from coat
    float package_exp = (ring_exp + coat_exp) * 17 / 100; //experience point gain from package
    //check whether E2 legal or not (in range 0 to 999)
    if (check_e(E2) == -999) {
        return -999;
    }
    // in case E2 is legal we will star to caculate sherlock and waston exp, hp ,m point
    else {
        // caculate waston and sherlock exp point
        // if E2 greater than 0 wastom and sherlock gain exp from ring
        if (E2 > 0) {
            EXP2 += ring_exp;
            EXP1 += ring_exp / 3;
            EXP2 = check_exp(EXP2);
            EXP1 = check_exp(EXP1);
        }
        // if E2 is greater than 299 waston and sherlock will gain more exp from coat
        if (E2 > 299) {
            EXP2 += coat_exp;
            EXP1 += coat_exp / 3;
            EXP2 = check_exp(EXP2);
            EXP1 = check_exp(EXP1);
        }
        // if E2 is greater than 499 waston and sherlock will gain more exp from package
        if (E2 > 499) {
            EXP2 += package_exp;
            EXP1 += package_exp / 3;
            EXP2 = check_exp(EXP2);
            EXP1 = check_exp(EXP1);
        }

        // STAGE 2 
        //caculate hp point of waston
        HP2 = HP2 - E2 * E2 * E2 / pow(2, 23);
        HP2 = check_hp(HP2);
        // caculate money of waston
        int E2_int = E2;
        if (E2_int % 2 == 0) {
            M2 += E2 * E2 / 50;
        }
        M2 = check_m(M2);

        /////////////////////////
        //cout<<"EXP1 "<<EXP1<<endl;
        //cout<<"EXP2 "<<EXP2<<endl;
        //cout<<"HP2 "<<HP2<<endl;
        //cout<<"M2 "<<M2<<endl;
        /////////////////////////
        // return the require value
        
        EXP_1 = EXP1;
        EXP_2 = EXP2;
        HP_2 = HP2;
        M_2 = M2;

        return EXP1 + EXP2 + HP2 + M2;
    }

}

int  traceLuggage(int& HP_1, int& EXP_1, int& M_1, const int& E_3) {
    float HP1 = HP_1;
    float EXP1 = EXP_1;
    float M1 = M_1;
    float E3 = E_3;
    // check E3 whether legal or not
    if (check_e(E3) == -999) {
        return -999;
    }
    // in case E3 in range 0 to 999
    else {
        // set number of road doesnt find luggage to 0
        int number_fail_road = 0;
        // ROAD 1
        int P1[9];
        bool luggage_check = false;
        int k = 0;
        for (int i = 0; i < 9; i++) {
            // fill the array
            P1[i] = 2 * i + 1;
            //transform the array
            P1[i] = (P1[i] + int(E3)) % 26 + 65;
            // check whether the 80 element exis
            if (P1[i] == 80) {
                luggage_check = true;
                // record the  k value
                k = i + 1;
                break;
            }
        }
        // if k exist
        if (luggage_check) {
            //caculate sherlock hp point
            HP1 = HP1 - 80 * k * 2;
            // caculate sherlock exp point
            EXP1 = EXP1 + (1000 - 80 * k) % 101;
            // caculate sherlock m point
            M1 = M1 - k * E3 / 9;

            //cout << "road 1 has luggage" << endl;

            // round exp, hp, m point
            HP1 = check_hp(HP1);
            EXP1 = check_exp(EXP1);
            M1 = check_m(M1);
        }
        // if k doesnt exist
        else {
            M1 = M1 - 9 * 9 * E3 / 9;
            M1 = check_m(M1);
            number_fail_road += 1;
        }

        /////////////////////////////////////
        //cout<<"HP1 road 1 "<<HP1<<endl;
        //cout<<"EXP1 road 1 "<<EXP1<<endl;
        //cout<<"M1 road 1 "<<M1<<endl;
        /////////////////////////////////////

        //ROAD 2
        float s = 0;
        int P2[7] = { 2,3,5,7,11,13,17 };
        luggage_check = false;
        k = 0;
        // transform the array and caculate sum of them
        for (int i = 0; i < 7; i++) {
            P2[i] = (P2[i] + int(E3)) % 26;
            s = s + P2[i];
        }

        int m = round_up(s / 7);//caculate m value and round up to nearest bigger number
        // second transform
        for (int i = 0; i < 7; i++) {
            P2[i] = (P2[i] + int(s) + m) % 26 + 65;
            if (P2[i] == 80) {
                luggage_check = true;
                k = i + 1;
                //break;
            }
        }
        // if k exis
        if (luggage_check) {
            //caculate sherlock hp, exp, m point
            HP1 = HP1 - 80 * k * 2;
            EXP1 = EXP1 + (1000 - 80 * k) % 101;
            M1 = M1 - k * E3 / 9;

            // round up and check exp, hp, m point
            HP1 = check_hp(HP1);
            EXP1 = check_exp(EXP1);
            M1 = check_m(M1);

            //cout << "road 2 has luggage" << endl;
        }
        // if k doesnt exist
        else {
            // caculate m point for sherlock
            M1 = M1 - 7 * 7 * E3 / 9;
            M1 = check_m(M1);
            number_fail_road += 1;
        }
        /////////////////////////////////////
        //cout<<"HP1 road 2 "<<HP1<<endl;
        //cout<<"EXP1 road 2 "<<EXP1<<endl;
        //cout<<"M1 road 2 "<<M1<<endl;
        /////////////////////////////////////

        // ROAD 3 
        int P3[20];
        luggage_check = false;
        k = 0;
        int max = -1;

        // fill in array, do first transform and find max element of the array
        for (int i = 0; i < 20; i++) {
            P3[i] = (2 * (i + 1)) * (2 * (i + 1));
            P3[i] = (P3[i] + int(E3) * int(E3)) % 113;
            if (max < P3[i]) {
                max = P3[i];
            }
        }

        int anpha = 0;
        // apply second stransform on array 
        for (int i = 19; i >= 0; i--) {
            anpha = round_up((float(P3[i]) + E3) / float(max));
            P3[i] = anpha % 26 + 65;
            if (P3[i] == 80) {
                luggage_check = true;
                k = 20 - i;
                break;
            }
        }

        // caculate hp, exp, m point of sherlock
        if (luggage_check) {
            // caculate hp point
            HP1 = HP1 - 80 * k * 3;

            // caculate exp point
            EXP1 += (3500 - 80 * k) % 300;

            // caculate sherlock m point
            M1 = M1 - float(k) * E3 / 9;

            // round exp, hp, m point
            HP1 = check_hp(HP1);
            EXP1 = check_exp(EXP1);
            M1 = check_m(M1);

            //cout << "road 3 has luggage" << endl;
        }
        else {
            number_fail_road += 1;
            M1 = M1 - 20 * 20 * E3 / 9;
            M1 = check_m(M1);
        }

        //////////////////////////////////
        //cout<<"EXP1 road 3 "<< EXP1<<endl;
        //cout<<"HP1 road 3 "<< HP1<<endl;
        //cout<<"M1 road 3 "<< M1<<endl;
        //////////////////////////////////

        //ROAD 4
        int P4[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        float min = 9999999999999;
        float min_id;
        luggage_check = false;
        k = 0;
        // apply first transform and find min value
        int var;
        for (int i = 0; i < 12; i++) {
            var = round_up(P4[i] + pow(E3 / float(29), 3));
            P4[i] = var % 9;
            if (min > P4[i]) {
                min = P4[i];
            }
        }

        // find min_id
        for (int i = 0; i < 12; i++) {
            if (P4[i] == min) {
                min_id = i + 1;
                break;
            }
        }

        // second transform
        //int min_value = round_up(min / min_id);
        for (int i = 11; i >= 0; i--) {
            var = round_up((P4[i] + E3) * (min / min_id));
            P4[i] = var % 26 + 65;
            if (P4[i] == 80) {
                luggage_check = true;
                k = 12 - i;
                break;
            }
        }

        if (luggage_check) {
            // caculate hp, exp, m point of sherlock
            HP1 = HP1 - 80 * k * 4;
            EXP1 = EXP1 + (4500 - 80 * k) % 400;
            M1 = M1 - k * E3 / 9;

            // check for legal value of exp, hp, m
            M1 = check_m(M1);
            EXP1 = check_exp(EXP1);
            HP1 = check_hp(HP1);

            //cout << "road 4 has luggage" << endl;
        }

        else {
            M1 = M1 - 12 * 12 * E3 / 9;
            M1 = check_m(M1);
            number_fail_road += 1;
        }

        // in case sherlock cant find the luggage in 4 road
        if (number_fail_road == 4) {
            //recaculate hp, exp point of sherlock
            HP1 = HP1 - (59 * int(E3)) % 900;
            EXP1 = EXP1 - (79 * int(E3)) % 300;

            //check for legal point
            HP1 = check_hp(HP1);
            EXP1 = check_exp(EXP1);

            /////////////////////////////////////
            //cout << "EXP point road 4 " << EXP1 << endl;
            //cout << "HP point road 4 " << HP1 << endl;
            //cout << "M point road 4 " << M1 << endl;
            /////////////////////////////////////

            EXP_1 = EXP1;
            HP_1 = HP1;
            M_1 = M1;

            return -1;
        }
        // sherlock can find luggage at least one road
        else {
            /////////////////////////////////////
            //cout << "EXP point road 4 " << EXP1 << endl;
            //cout << "HP point road 4 " << HP1 << endl;
            //cout << "M point road 4 " << M1 << endl;
            /////////////////////////////////////

            EXP_1 = EXP1;
            HP_1 = HP1;
            M_1 = M1;

            return HP1 + EXP1 + M1;
        }
    }
}
#endif