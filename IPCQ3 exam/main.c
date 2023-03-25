/* Name: Charan Edison Arulraj
   Student ID: 143594208
   Section : ZEE
   EMAIL: cedison-arulraj@myseneca.ca
   Question3 final Exam        */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CommonHelpers.h"

#define All_datas_size 7

int main(void)
{
    struct Phone phone[All_datas_size] = { {0} };
    struct Temp1 temp1[4] = { {"Billy Bob",0,0,0},{"Sue Ellen",0,0,0},{"Jimmy Joe",0,0,0},{"Sally Sue",0,0,0} };
    struct Temp2 temp2[4] = { {"Billy Bob",0},{"Sue Ellen",0},{"Jimmy Joe",0},{"Sally Sue",0} };
    struct Temp3 temp3[4] = { {"Billy Bob",0,0,0},{"Sue Ellen",0,0,0},{"Jimmy Joe",0,0,0},{"Sally Sue",0,0,0} };
    readdetailsfromfile(phone, All_datas_size);
    starttheapp(phone, All_datas_size, temp1, temp2, temp3);

    return 0;
}
