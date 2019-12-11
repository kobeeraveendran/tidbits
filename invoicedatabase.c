#include <stdio.h>
#include <stdlib.h>
#define MAX 12
#include <string.h>


void printInvoice (int id, int *studentCourses);
void addCourses (int *studentCourses, int *options, int selection, int i);
int checkCourses(int *studentCourses, int course, int *option, int selection);
void dropCourses (int *studentCourses, int *options, int selection, int i);
void prefix (int crn);
int hours (int crn);

const int MAX_COURSES = 4;

struct student
{
   int coursesTaken;
   char name[50];
   int courseList[4];
   int id;
};

int main()
{
    int id, selection,i=0;
    int studentCourses [MAX]={0};
    int courseOptions []= {4587,4599, 8997,9696,7895,9658,4287,9599,8927,7696,7890,9008};



    printf("Enter Student ID:\n");
    scanf ("%d", &id);

    while (selection !=0)
    {

    printf ("Select an Option:\n");
    printf ("\t1- Add a new student\n");
    printf ("\t2- Add/Delete a course\n");
    printf ("\t3- Search for a student\n");
    printf ("\t4- Print fee invoice\n");
    printf ("\t0- Exit program\n");

    printf ("\nEnter your selection: ");
    scanf ("%d", &selection);

    printf ("\n");

    switch (selection)
        {
           case 1:
           
        case 1:
            {
            addCourses (studentCourses, courseOptions, selection,i);
            i++;
            }
            break;
        case 2:
            {
            dropCourses (studentCourses, courseOptions, selection,i);
            }
            break;
        case 3:
            printInvoice (id,studentCourses);
            break;
        case 4:

            printf ("Goodbye.\n");
            return 0;
            break;
        }
    }


    return 0;
}

int addStudent(int id, char name[])

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void printInvoice (int id, int *studentCourses)   //print course information and add total
{
    int i;
    float product, summ=0;

    printf ("VALENCE COMMUNITY COLLEGE\n");
    printf ("ORLANDO FL 10101\n");
    printf ("--------------------------------------\n");
    printf ("Fee Invoice Prepared for Student:\n");
    printf ("%d\n\n", id);
    printf ("1 Credit Hour = $120.25\n");
    printf ("CRN\tCr_Prefix\tCr_hrs\n");

    for (i=0;i<12;i++)
    {
        if (studentCourses[i]!=0)
        {
            prefix (studentCourses[i]);
            product= hours (studentCourses[i])*120.25;
            printf ("\t%0.2f\n", product);
            summ+=product;
        }
    }

    //call prefix function here

    printf ("\t      Health & id fees $ 35.00\n");
    printf ("--------------------------------------\n");
    printf ("\t\tTotal Payments\t$%0.2f\n", summ+35.00);


    return;

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void addCourses (int *studentCourses, int *options, int selection, int i)
{
    int course, valid;
    char list;

    printf ("Would you like to print the list of courses? Enter y/n\n");
    scanf (" %c" , &list);


    switch (list)

    {
        case 'y':
            {
            printf ("CRN\tCourse\tCredit Hours\n");
            printf ("4587\tMAT 236\t4\n");
            printf ("4599\tCOP 220\t3\n");
            printf ("8997\tGOL 124\t1\n");
            printf ("9696\tCOP 100\t3\n");
            printf ("7895\tMNT 125\t2\n");
            printf ("9658\tOPT 120\t3\n");
            printf ("4287\tMAT 836\t4\n");
            printf ("9599\tCOP 220\t3\n");
            printf ("8927\tGOM 124\t1\n");
            printf ("7696\tCOT 100\t4\n");
            printf ("7890\tMOT 125\t3\n");
            printf ("9008\tOPT 520\t5\n");

            break;

            }

        case 'n':
            break;


    }

    printf ("Enter the course number:\n");
    scanf ("%d", &course);

    valid=checkCourses(studentCourses,course,options, selection);

    switch (valid)
        {
            case 0:
            printf ("Not a valid a course\n");
            break;
        case 1:
            studentCourses[i]=course;
            printf ("Course has been added\n");
            break;
        case 2:
            printf ("Student is already taking this course\n");
            break;
        }


    return;


}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int checkCourses (int *studentCourses,int course,int *option,int selection)
{
  int total=0, i, k;

  for (i=0; i<12; i++)
  {
    if (course==option[i])
          total=1;
  }
    if (selection==1)
  {
    for (k=0;k<12;k++)
  {
      if (course==studentCourses[k])
        total=2; //student tries to add course they already take
  }
    // IF SELECTION ==2 AKADELETE COURSE FUNCTION

    if (selection==2)
    {
     for (k=0;k<12;k++)
  {
      if (course!=studentCourses[k])
        total=2; //student tries to remove course they are not taking
  }
    }

  }

  return total;

}

void dropCourses(int *studentCourses, int *options, int selection, int i)
{
    int course, valid, j;

    printf ("Enter the course you would like to remove:\n");
    scanf ("%d", &course);

    valid=checkCourses(studentCourses,course,options, selection);

    switch (valid)
        {
            case 0:
            printf ("Not a valid a course\n");
            break;
        case 1:
            for (j=0;j<12;j++)
            {
                if (studentCourses[j]==course)
                    {
                        studentCourses[j]=0;
                        printf ("The course has been removed\n");
                        break;
                    }

            }
            break;
        case 2:
            printf ("Student is not taking this course\n");
            break;
        }


}

void prefix (int crn)
{
    switch (crn)
     {
     case 4587:
        printf ("4587\tMAT 236\t\t4");
        break;
     case 4599:
        printf ("4599\tCOP 220\t\t3");
        break;
     case 8997:
        printf ("8997\tGOL 124\t\t1");
        break;
     case 9696:
        printf ("9696\tCOP 100\t\t3");
        break;
     case 7895:
        printf ("7895\tMNT 125\t\t2");
        break;
     case 9658:
        printf ("9658\tOPT 120\t\t3");
        break;
     case 4287:
        printf ("4287\tMAT 836\t\t4");
        break;
     case 9599:
        printf ("9599\tCOP 220\t\t3");
        break;
     case 8927:
        printf ("8927\tGOM 124\t\t1");
        break;
     case 7696:
        printf ("7696\tCOT 100\t\t4");
        break;
     case 7890:
        printf ("7890\tMOT 125\t\t3");
        break;
     case 9008:
        printf ("9008\tOPT 520\t\t5");
        break;
     }
}

int hours (int crn)
{
    switch (crn)
     {
     case 4587:
        return 4;
        break;
     case 4599:
        return 3;
        break;
     case 8997:
        return 1;
        break;
     case 9696:
        return 3;
        break;
     case 7895:
        return 2;
        break;
     case 9658:
        return 3;
        break;
     case 4287:
        return 4;
        break;
     case 9599:
        return 3;
        break;
     case 8927:
        return 1;
        break;
     case 7696:
        return 4;
        break;
     case 7890:
        return 3;
        break;
     case 9008:
        return 5;
        break;
     }
}

