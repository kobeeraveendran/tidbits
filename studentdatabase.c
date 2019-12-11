#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_COURSES = 4;

struct student
{
    char firstname[20], lastname[20];
    int id;
    int courseList[4];
    // running count of courses taken
    int coursesTaken;
};

struct course
{
    int courseNum;
    char *name;
    int creditHours;
};

struct student studentDatabase[10];
int databaseSize = 0;

void addStudent(int id, struct course courses[], int courseOptionSize);
void editCourseList(int id);
void search(int id);
void printInvoice(int id);

int main()
{
    int id, selection, i = 0;
    int courseNums[8] = {4587, 4599, 8997, 9696, 1232, 9856, 8520, 8977};
    char courseNames[][10] = {"MAT 236", 
                              "COP 220", 
                              "GOL 124", 
                              "COP 100", 
                              "MAC 531", 
                              "STA 100", 
                              "TNV 400", 
                              "CMP 100"};
    int courseCrdHrs[8] = {4, 3, 1, 3, 5, 2, 5, 1};

    struct course courseOptions[8];

    
    for (i = 0; i < 8; i++)
    {
        courseOptions[i].courseNum = courseNums[i];
        courseOptions[i].name = courseNames[i];
        courseOptions[i].creditHours = courseCrdHrs[i];
    }
    

    
    for (int i = 0; i < 8; i++)
    {
        printf("%d %s %d\n", courseOptions[i].courseNum, courseOptions[i].name, courseOptions[i].creditHours);

    }
        
    printf ("Welcome!\nChoose from the following options:\n");
    printf ("\t1- Add a new student\n");
    printf ("\t2- Add/Delete a course\n");
    printf ("\t3- Search for a student\n");
    printf ("\t4- Print fee invoice\n");
    printf ("\t0- Exit program\n");

    printf ("\nEnter your selection: ");
    scanf ("%d", &selection);

    while (selection != 0)
    {

        printf ("\nEnter the student's id: ");
        scanf ("%d", &id);

        switch (selection)
        {
            case 1:
            {
                // check to see if a student is already in the database before adding
                int s;
                int exists = 0;
                for (s = 0; s < databaseSize; s++)
                {
                    if (id == studentDatabase[s].id)
                    {
                        printf ("Student with that ID already exists. Please try again.");
                        exists = 1;
                        break;
                    }
                }

                // if a student with that ID already exists, break out of the case
                if (exists)
                {
                    break;
                }

                // otherwise, add the student to the database
                addStudent(id, courseOptions, 8);
            }
        }
    }

    return 0;
}

void addStudent(int id, struct course courses[], int courseOptionSize)
{
    char firstname[20], lastname[20];
    int numCourses;

    printf ("Enter the student's name: ");
    scanf ("%s %s", firstname, lastname);

    printf ("\n\nEnter the number of courses [%s] is taking (up to 4 courses):\n", name);
    scanf ("%d", &numCourses);

    while (numCourses > 4 || numCourses < 1)
    {
        printf("Please enter a valid number of courses (min. 1, max. 4).\n");

        printf ("\nEnter the number of courses [%s] is taking (up to 4 courses):\n", name);
        scanf ("%d", &numCourses);
    }

    // display valid course options
    int c;
    for (c = 0; c < courseOptionSize; c++)
    {
        printf ("\t%d %s %d\n", courses[c].courseNum, courses[c].name, courses[c].creditHours);
    }



    printf("\n\nEnter the %d course numbers:", numCourses);
}