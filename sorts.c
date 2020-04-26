#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct coor
{
    int x, y, rad;
}coor;

coor* readData (FILE*, int);
int* filterData (coor*, int, int, int, int);

int main()
{
    FILE *fp;
    int temp, index, cenx, ceny, radius, size;
    coor *data;
    
    fp = fopen ("in.txt", "r");
    fscanf (fp, "%d", &cenx);
    fscanf (fp, "%d", &ceny);
    fscanf (fp, "%d", &radius);
    fscanf (fp, "%d", &size);
    printf ("%d   %d   %d   %d\n", cenx, ceny, radius, size);

    data = readData(fp, size);
    printf ("test2 main\n");
    fclose (fp);
    filterData(data, cenx, ceny, radius, size);

    free (data);
    
    
    return 0;
}

coor* readData (FILE *fp, int size)
{
    coor *data; 
    int temp, index, i;
    int count = 0;
    
    data = (coor*) malloc (size *sizeof(coor));

    for (i = 0; i<size; i++)
    {
        fscanf (fp, "%d", &data[i].x);
        fscanf (fp, "%d", &data[i].y);
    }
    printf ("test1 readData\n");
    
    return data;
}

int* filterData (coor* data, int cenx, int ceny, int rad, int size)
{
    int i;
    printf ("test3 filterData\n");

    int datasize = sizeof data / sizeof data[0];

    printf("\nsize: %d\ndata size: %u\n", size, datasize);

    for (i=0; i<size; i++)
    {
        printf ("test4 forloop%d\n", i+1);
        printf ("%d ", data[i].x);
        printf ("%d\n", data[i].y);
        printf ("test5 forloop2\n");
    }

    return 0;
}