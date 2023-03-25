/* Name: Charan Edison Arulraj
   Student ID: 143594208
   Section : ZEE
   EMAIL: cedison-arulraj@myseneca.ca 
   Question 3 final Exam */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "CommonHelpers.h"
#include<string.h>

#define size 4
#define details_size 50


void readdetailsfromfile(struct Phone phone[], int maxsize)
{
    int x = 0;
	char a[11];
	const char filename[] = "phoneln.txt";
	FILE* fp = fopen(filename, "r");
	if (fp != NULL)
	{
		for (x = 0; x < 7; x++)
		{

			fscanf(fp, "%[^|]|%[^|]|%lf|%d|%lf\n", phone[x].Name, phone[x].callNumber, &phone[x].callMinutes, &phone[x].dataBytes, &phone[x].screenTime);

		}

		fclose(fp);
	}
	else
	{
		printf("Failed to load File\n");
	}


}

void starttheapp(struct Phone phone[], int max, struct Temp1 temp1[], struct Temp2 temp2[], struct Temp3 temp3[])
{
	int var = 0;
	int i = 0;
	int error;
	while ( var== 0)
	{
		printf("\n");
		printf("Select one of the following options:\n");
		printf("0 - Exit\n");
		printf("1 - Show users by call duration\n");
		printf("2 - Show users by data usage\n");
		printf("3 - Show users by screen time\n");
		printf("4 - Show all user data\n");
		scanf("%d", &error);
		if (error == 0)  
		{
			var = 1; 
			printf("\n");
			printf("Goodbye\n");
			break;
		}
		if (error == 1)
		{
			

			showthe_callduration(phone, max, temp1);
		}
		if (error == 2)
		{
			

			showthe_datausage(phone, max, temp2);
		}
		if (error == 3)
		{
			showthe_screentime(phone, max, temp3);
		}
		if (error == 4)
		{

			showthedatasof_all_users(phone, max, temp1, temp2);
		}


	}
}

void showthe_callduration(struct Phone phone[], int max, struct Temp1 temp1[])
{
	int x = 0;
	int w = 0;
	int k = 0;
	char A[details_size + 1];
	int posn = 0;

	for (x = 0; x < 7; x++)
	{
		double total_duration = 0;

		strcpy(A, phone[x].Name);
		for (w = 0; w < 7; w++)
		{
			if (strcmp(A, phone[w].Name) == 0)
			{
				total_duration += phone[w].callMinutes;

				for (k = 0; k < size; k++)
				{
					if (strcmp(A, temp1[k].Name) == 0)
					{
						temp1[k].callMinutes = total_duration;

					}
				}
			}
		}
	}

	struct Temp1 temp1_copy[4];
	for (k = 0; k < size; k++)
	{
		temp1_copy[k].callMinutes = temp1[k].callMinutes;
		strcpy(temp1_copy[k].Name, temp1[k].Name);
	}

	int error;
	double swap;
	int p, y;
	char swap2[details_size];
	for (p = 0; p < size - 1; p++)
	{
		error = p;
		for (y = p + 1; y < size; y++)
		{
			if (temp1_copy[error].callMinutes > 
				temp1_copy[y].callMinutes)
				error = y;
		}
		if (error != p)
		{
			swap = temp1_copy[p].callMinutes;
			strcpy(swap2, temp1_copy[p].Name);
			temp1_copy[p].callMinutes = temp1_copy[error].callMinutes;
			strcpy(temp1_copy[p].Name, temp1_copy[error].Name);
			temp1_copy[error].callMinutes = swap;
			strcpy(temp1_copy[error].Name, swap2);
		}
	}
	int r;
	double t;
	k = 0;
	for (k = 0; k < size; k++)
	{
		r = 0, t = 0;
		r = (int)temp1_copy[k].callMinutes;
		t = temp1_copy[k].callMinutes - (int)temp1_copy[k].callMinutes;
		t = t * 60;
		temp1_copy[k].LHS = r;
		temp1_copy[k].RHS = t;

	}

	printf("\t\t User Call Duration\n");
	for (k = 0; k < size; k++)
	{
		printf("\t     %s      %d:%02.0lf\n", temp1_copy[k].Name, 
			temp1_copy[k].LHS, temp1_copy[k].RHS);
	}

}
void showthe_datausage(struct Phone phone[], int max, struct Temp2 temp2[])
{
	int x = 0;
	int w = 0;
	int k = 0;
	char A[details_size + 1];
	int var1 = 0;

	for (x = 0; x < 7; x++)  
	{
		int total_datausage = 0;

		strcpy(A, phone[x].Name);
		for (w = 0; w < 7; w++) 
		{
			if (strcmp(A, phone[w].Name) == 0) 
			{
				total_datausage += phone[w].dataBytes;

				
				for (k = 0; k < size; k++) 
				{
					if (strcmp(A, temp2[k].Name) == 0) 
					{
						temp2[k].dataBytes = total_datausage;
					}
				}
			}
		}
	}

	struct Temp2 temp2_copy[4];
	for (k = 0; k < size; k++)
	{
		temp2_copy[k].dataBytes = temp2[k].dataBytes;
		strcpy(temp2_copy[k].Name, temp2[k].Name);
	}

	int error;
	double swap;
	int p, y;
	char swap2[details_size];
	for (p = 0; p < size - 1; p++)
	{
		error = p;
		for (y = p + 1; y < size; y++)
		{
			if (temp2_copy[error].dataBytes > temp2_copy[y].dataBytes)
				error = y;
		}
		if (error != p)
		{
			swap = temp2_copy[p].dataBytes;
			strcpy(swap2, temp2_copy[p].Name);
			temp2_copy[p].dataBytes = temp2_copy[error].dataBytes;
			strcpy(temp2_copy[p].Name, temp2_copy[error].Name);
			temp2_copy[error].dataBytes = swap;
			strcpy(temp2_copy[error].Name, swap2);
		}
	}

	printf("\t\t User  Data Usage\n");
	for (k = 0; k < size; k++)
	{
		printf("\t     %s      %d\n", temp2_copy[k].Name, temp2_copy[k].dataBytes);
	}


}

void showthe_screentime(struct Phone phone[], int max, struct Temp3 temp3[])
{
	int x = 0;
	int w = 0;
	int k = 0;
	char A[details_size + 1];
	int var1 = 0;
	for (x = 0; x < 7; x++)  
	{
		double total_screentime = 0;

		strcpy(A, phone[x].Name);
		for (w = 0; w < 7; w++)  
		{
			if (strcmp(A, phone[w].Name) == 0) 
			{
				total_screentime += phone[w].screenTime;
				
				for (k = 0; k < size; k++) 
				{
					if (strcmp(A, temp3[k].Name) == 0) 
					{
						temp3[k].screenTime = total_screentime;

					}
				}
			}
		}
	}

	struct Temp3 temp3_copy[4];
	for (k = 0; k < size; k++)
	{
		temp3_copy[k].screenTime = temp3[k].screenTime;
		strcpy(temp3_copy[k].Name, temp3[k].Name);
	}

	int error;
	double swap;
	int p, y;
	char swap2[details_size];
	for (p = 0; p < size - 1; p++)
	{
		error = p;
		for (y = p + 1; y < size; y++)
		{
			if (temp3_copy[error].screenTime > temp3_copy[y].screenTime)
				error = y;
		}
		if (error != p)
		{
			swap = temp3_copy[p].screenTime;
			strcpy(swap2, temp3_copy[p].Name);
			temp3_copy[p].screenTime = temp3_copy[error].screenTime;
			strcpy(temp3_copy[p].Name, temp3_copy[error].Name);
			temp3_copy[error].screenTime = swap;
			strcpy(temp3_copy[error].Name, swap2);
		}
	}

	int r;
	double s;
	k = 0;
	for (k = 0; k < size; k++)
	{
		r = 0, s = 0;
		r = (int)temp3_copy[k].screenTime;
		s = temp3_copy[k].screenTime - (int)temp3_copy[k].screenTime;
		s = s * 60;
		temp3_copy[k].LHS = r;
		temp3_copy[k].RHS = s;

	}
	printf("\t\t User  Screen Time\n");
	for (k = 0; k < size; k++)
	{
		printf("\t     %s      %d:%02.0lf\n", temp3_copy[k].Name, temp3_copy[k].LHS, temp3_copy[k].RHS);
	}

}
void showthedatasof_all_users(struct Phone phone[], int max, struct Temp1 temp1[], struct Temp2 temp2[])
{
	int x = 0, w = 0, k = 0;
	int r;
	double t;
	for (k = 0; k < 4; k++) 
	{
		printf("\n---------------------------------------------\n");
		printf("User: %s\n", temp1[k].Name);
		printf(" Number Called Duration\n"); 
		for (x = 0; x < 7; x++)
		{
			if (strcmp(temp1[k].Name, phone[x].Name) == 0)
			{
				r = (int)phone[x].callMinutes;
				t = phone[x].callMinutes - (int)phone[x].callMinutes;
				t = t * 60;
				if (phone[x].callMinutes != 0)
				{
					printf("   %s   %d:%02.0lf\n", phone[x].callNumber, r, t);
				}
			}
		}
		printf("Bytes Transferred\n"); 
		for (x = 0; x < 7; x++)
		{
			if (strcmp(temp1[k].Name, phone[x].Name) == 0)
			{
				if (phone[x].dataBytes != 0) {
					printf("\t%d\n", phone[x].dataBytes);
				}
			}
		}
		printf("Screen Minutes\n");   
		for (x = 0; x < 7; x++)
		{
			if (strcmp(temp1[k].Name, phone[x].Name) == 0)
			{
				r = (int)phone[x].screenTime;
				t = phone[x].screenTime - (int)phone[x].screenTime;
				t = t * 60;
				if (phone[x].screenTime != 0)
				{
					printf("      %d:%02.0lf\n", r, t);
				}
			}
		}
		
	}

}

