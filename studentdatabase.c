#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void addStudent(int id, struct course courses[]);
void addDropCourse(int id, struct course courses[]);
char* upper(char str[]);
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
                addStudent(id, courseOptions);
                break;             
            }

            case 2:
            {
                addDropCourse(id, courseOptions);
                break;
            }
        }

        printf("\nEnter your selection: ");
        scanf("%d", &selection);
    }

    return 0;
}

char* upper(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }

    return str;
}

void addStudent(int id, struct course courses[])
{
    char firstname[20], lastname[20];
    int courseOptionSize = 8;
    int numCourses;

    printf ("Enter the student's name: ");
    scanf ("%s %s", firstname, lastname);

    struct student currStudent;
    currStudent.id = id;
    strcpy(currStudent.firstname, firstname);
    strcpy(currStudent.lastname, lastname);

    // display valid course options
    printf ("\n\nCurrently offered courses: \n");
    printf ("\tCRN\tCR_PREFIX\tCR_HOURS\n");
    int c;
    for (c = 0; c < courseOptionSize; c++)
    {
        printf ("\t%d\t%s\t\t%d\n", courses[c].courseNum, courses[c].name, courses[c].creditHours);
    }

    printf ("\n\nEnter the number of courses [%s %s] is taking (up to 4 courses):\n", upper(firstname), upper(lastname));
    scanf ("%d", &numCourses);

    while (numCourses > 4 || numCourses < 0)
    {
        printf("Please enter a valid number of courses (min. 0, max. 4).\n");

        printf ("\nEnter the number of courses [%s %s] is taking (up to 4 courses):\n", upper(firstname), upper(lastname));
        scanf ("%d", &numCourses);
    }

    if (numCourses)
        printf("\n\nEnter the %d course numbers:\n", numCourses);

    int i;
    int coursesTaking[numCourses];

    switch(numCourses)
    {
        case 1:
            scanf ("%d", &coursesTaking[0]);
            break;
        
        case 2:
            scanf ("%d %d", &coursesTaking[0], &coursesTaking[1]);
            break;
        
        case 3:
            scanf ("%d %d %d", &coursesTaking[0], &coursesTaking[1], &coursesTaking[2]);
            break;

        case 4:
            scanf ("%d %d %d %d", &coursesTaking[0], &coursesTaking[1], &coursesTaking[2], &coursesTaking[3]);
            break;
    }

    int j;
    int invalid = 0;

    for (i = 0; i < numCourses; i++)
    {
        int found = 0;

        for (j = 0; j < courseOptionSize; j++)
        {
            if (coursesTaking[i] == courses[j].courseNum)
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            continue;
        }
        else
        {
            printf("One or more course numbers invalid.\n");
            invalid = 1;
        }
    }

    while (invalid)
    {

        printf("\n\nEnter the %d  course numbers:\n",  numCourses);

        switch(numCourses)
        {
            case 1:
                scanf ("%d", &coursesTaking[0]);
                break;
            
            case 2:
                scanf ("%d %d", &coursesTaking[0], &coursesTaking[1]);
                break;
            
            case 3:
                scanf ("%d %d %d", &coursesTaking[0], &coursesTaking[1], &coursesTaking[2]);
                break;

            case 4:
                scanf ("%d %d %d %d", &coursesTaking[0], &coursesTaking[1], &coursesTaking[2], &coursesTaking[3]);
                break;
        }

        for (i = 0; i < numCourses; i++)
        {
            int found = 0;

            for (j = 0; j < courseOptionSize; j++)
            {
                if (coursesTaking[i] == courses[j].courseNum)
                {
                    found = 1;
                    break;
                }
            }

            if (found)
            {
                invalid = 0;
                continue;
            }
            else
            {
                printf("One or more course numbers invalid.\n");
                invalid = 1;
                break;
            }
        }
    }

    // create student and add student to database

    currStudent.coursesTaken = numCourses;
    
    for (i = 0; i < numCourses; i++)
    {
        currStudent.courseList[i] = coursesTaking[i];
    }

    studentDatabase[databaseSize] = currStudent;
    databaseSize++;

    printf("Student added successfully!\n\n");
}

void addDropCourse(int id, struct course courses[])
{
    // find student
    int studentIndex;

    for (studentIndex = 0; studentIndex < databaseSize; studentIndex++)
    {
        if (id == studentDatabase[studentIndex].id)
        {
            break;
        }
    }

    struct student currStudent = studentDatabase[studentIndex];

    // print courses being taken
    printf("Here are the courses [%s %s] is taking:\n", upper(currStudent.firstname), upper(currStudent.lastname));

    printf("Choose from:\n");
    printf("A- Add a new course for [%s %s]\n", upper(currStudent.firstname), upper(currStudent.lastname));
    printf("D- Delete a course from [%s %s]'s schedule\n", upper(currStudent.firstname), upper(currStudent.lastname));
    printf("C- Cancel operation\n");

    char choice;

    printf("\nChoose an action: ");
    scanf(" %c", &choice);

    char s = toupper(choice);

    switch(s)
    {
        case 'A':
            printf("Enter course number to add: \n");
            break;

        case 'D':
            printf("Enter course number to delete: \n");
            break;
    }
}