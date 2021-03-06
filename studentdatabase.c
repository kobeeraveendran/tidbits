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
void studentSearch(int id, struct course courses[]);
void printInvoice(int id, struct course courses[]);

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
        
    printf ("Welcome!\n");
    printf ("Choose from the following options:\n");
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

            case 0:
                printf("\nGoodbye!\n");
                break;

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

            case 3:
            {
                studentSearch(id, courseOptions);
                break;
            }

            case 4:
            {
                printInvoice(id, courseOptions);
                break;
            }
        }

        printf ("\n\nChoose from the following options:\n");
        printf ("\t1- Add a new student\n");
        printf ("\t2- Add/Delete a course\n");
        printf ("\t3- Search for a student\n");
        printf ("\t4- Print fee invoice\n");
        printf ("\t0- Exit program\n");

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

struct course findCourse(int crn, struct course courses[])
{
    int i;

    for (i = 0; i < 8; i++)
    {
        if (crn == courses[i].courseNum)
        {
            return courses[i];
        }
    }
}

int checkEnrollment(int crn, int courses[], int numCourses)
{
    int i;

    for (i = 0; i < numCourses; i++)
    {
        if (crn == courses[i])
        {
            return 1;
        }
    }

    return 0;
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
    printf("\tCRN\tPREFIX\t\tCR. HOURS\n");

    int i;
    for (i = 0; i < currStudent.coursesTaken; i++)
    {
        int crn = currStudent.courseList[i];
        struct course currCourse = findCourse(crn, courses);
        
        printf("\t%d\t%s\t\t%d\n", crn, currCourse.name, currCourse.creditHours);
    }

    printf("Choose from:\n");
    printf("A- Add a new course for [%s %s]\n", upper(currStudent.firstname), upper(currStudent.lastname));
    printf("D- Delete a course from [%s %s]'s schedule\n", upper(currStudent.firstname), upper(currStudent.lastname));
    printf("C- Cancel operation\n");

    char choice;

    printf("\nEnter your selection: ");
    scanf(" %c", &choice);

    char s = toupper(choice);

    switch(s)
    {
        case 'A':
            if (currStudent.coursesTaken == 4)
            {
                printf("Unable to add courses at this time: Student is currently enrolled in maximum number of courses. Rerouting to menu...\n\n");
                break;
            }

            int newCourseId;
            printf("Enter course number to add: \n");
            scanf("%d", &newCourseId);

            if (!checkEnrollment(newCourseId, currStudent.courseList, currStudent.coursesTaken))
            {
                currStudent.courseList[currStudent.coursesTaken] = newCourseId;
                currStudent.coursesTaken++;

                printf("\nCourse successfully added!\n\n");
            }
            else
            {
                printf("\nYou are already enrolled in this course. Please try adding a different course.\n");
            }

            studentDatabase[studentIndex] = currStudent;

            break;

        case 'D':

            if (currStudent.coursesTaken == 0)
            {
                printf("\nUnable to delete courses at this time: Student is currently not enrolled in any courses. Rerouting to menu...\n\n");
                break;
            }

            int deleteCourseId;
            printf("Enter course number to delete: \n");
            scanf("%d", &deleteCourseId);

            if (checkEnrollment(deleteCourseId, currStudent.courseList, currStudent.coursesTaken))
            {
                int updatedCourseList[4];
                int newCourseCount = 0;
                int deleted = 0;

                for (i = 0; i < 3; i++)
                {
                    if (currStudent.courseList[i] == deleteCourseId)
                    {
                        currStudent.courseList[i] = currStudent.courseList[i + 1];
                        deleted = 1;
                        currStudent.coursesTaken--;
                    }
                    else if (deleted)
                    {
                        currStudent.courseList[i] = currStudent.courseList[i + 1];
                    }
                }

                if (!deleted)
                {
                    currStudent.coursesTaken--;
                }

                printf("\nCourse successfully deleted!\n\n");
            }

            else
            {
                printf("\nStudent is not enrolled in the course that is being deleted. Rerouting to main menu...\n\n");
                break;
            }

            studentDatabase[studentIndex] = currStudent;
            
            break;
    }
}

void studentSearch(int id, struct course courses[])
{
    int i;

    for (i = 0; i < databaseSize; i++)
    {
        if (id == studentDatabase[i].id)
        {
            printf("FIRST NAME: %s\n", studentDatabase[i].firstname);
            printf("LAST NAME: %s\n", studentDatabase[i].lastname);
            printf("STUDENT ID: %d\n", studentDatabase[i].id);
            printf("\nCURRENTLY ENROLLED COURSES:\n");
            printf("\tCRN\tPREFIX\t\tCREDIT HOURS\n");
            
            int j;
            for (j = 0; j < studentDatabase[i].coursesTaken; j++)
            {
                struct course currCourse = findCourse(studentDatabase[i].courseList[j], courses);
                printf("\t%d\t%s\t\t%d\n", currCourse.courseNum, currCourse.name, currCourse.creditHours);
            }

            return;
        }
    }

    printf("No student with ID %d found!\n\n", id);
}

void printInvoice(int id, struct course courses[])
{
    struct student currStudent;
    int i;

    for (i = 0; i < databaseSize; i++)
    {
        if (id == studentDatabase[i].id)
        {
            currStudent = studentDatabase[i];
            break;
        }
    }

    printf("\t\tVALENCE COMMUNITY COLLEGE\n");
    printf("\t\tORLANDO FL 10101\n");
    printf("\t\t---------------------\n\n");

    printf("\t\tFee Invoice Prepared for Student:\n");
    printf("\t\t%d-%s %s\n\n", currStudent.id, upper(currStudent.firstname), upper(currStudent.lastname));

    printf("\t\t1 Credit Hour = $120.25\n\n");

    printf("\t\tCRN\tCR_PREFIX\tCR_HOURS\n");

    float total = 0.0;
    
    for (i = 0; i < currStudent.coursesTaken; i++)
    {
        struct course currCourse = findCourse(currStudent.courseList[i], courses);

        float price = currCourse.creditHours * 120.25;
        total += price;

        printf("\t\t%d\t%s\t\t       %d  $ %0.2f\n", currCourse.courseNum, currCourse.name, currCourse.creditHours, price);
    }

    printf("\n\t\t\tHealth & ID fees\t  $ 35.00\n");
    printf("\n\t\t------------------------------------------\n");
    printf("\t\t\tTotal Payments\t\t  $ %0.2f\n", total + 35.0);
    printf("\n\n\n--------------------\n");

}