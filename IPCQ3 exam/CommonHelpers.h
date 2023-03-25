/* Name: Charan Edison Arulraj
   Student ID: 143594208
   Section : ZEE
   EMAIL: cedison-arulraj@myseneca.ca
   Question 3 final Exam */

#pragma once
#ifndef DATA_H_
#define DATA_H_
#define details_size 50

struct Phone
{
    char Name[details_size + 1];
    char callNumber[11];
    double callMinutes;
    int dataBytes;
    double screenTime;

};

struct Temp1
{
    char Name[details_size + 1];
    double callMinutes;
    int LHS;
    double RHS;
}temp1[4];

struct Temp2
{
    char Name[details_size + 1];
    int dataBytes;
}temp2[4];


struct Temp3
{
    char Name[details_size];
    double screenTime;
    int LHS;
    double RHS;
}temp3[4];

void readdetailsfromfile(struct Phone phone[], int maxsize);
void starttheapp(struct Phone phone[], int max, struct Temp1 temp1[], struct Temp2 temp2[], struct Temp3 temp3[]);
void showthe_callduration(struct Phone phone[], int max, struct Temp1 temp1[]);
void showthe_datausage(struct Phone phone[], int max, struct Temp2 temp2[]);
void showthe_screentime(struct Phone phone[], int max, struct Temp3 temp3[]);
void  showthedatasof_all_users(struct Phone phone[], int max, struct Temp1 temp1[], struct Temp2 temp2[]);


#endif
