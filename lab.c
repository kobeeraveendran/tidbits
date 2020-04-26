//This code is by Thanah Raveendran
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    int count;
    struct node *left, *right;
}node;

node* newNode (int data, int count)
{
    node *temp;
    temp = (node*) malloc (sizeof (node));
    temp->data = data;
    temp->count = count;
    temp->left = NULL;
    temp -> right = NULL;

    return temp;
    free (temp);
}

node* insert(node *root, node *element) 
{
 if (root == NULL)
 {

    return element;
 }
 else {

    if (element->data > root->data)
    {

        if (root->right != NULL)
            root->right = insert(root->right, element);

        else
            root->right = element;
    }

 else
 {

    if (root->left != NULL)
        root->left = insert(root->left, element);

    else
        root->left = element;
 }

 return root;
 }
}

void inOrder (node *current, FILE *fp)
{
    if (current != NULL)
    {
        inOrder (current->left, fp);
        fprintf (fp, "(");
        putw (current->data, fp);
        fprintf (fp, ", ");
        putw (current->count, fp);
        fprintf (fp, ") ");
        printf ("(%d, %d", current->data, current->count);
        inOrder (current->right, fp);
    }
}

node* maxVal(node *root)
{

  if (root->right == NULL)
    return root;

  else
    return maxVal(root->right);
}

int single (node *root)
{
    int count;// = 0;

    if (root ==NULL)
        return 0;

    //while (node != NULL)
    if ((root->left ==NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        count ++;
    count += (single(root->left)+single (root->right));
    return count;
}

int main ()
{
    int i, N, income, count;
    printf ("test1");

    node *root = NULL;
    node *temp, *max;
    FILE *fp, *fpo;

    fp = fopen ("in.txt", "r");
    fpo = fopen ("out.txt", "w");
    printf ("test1.2");
    N = getw (fp);

    for (i=0; i<N; i++)
    {
        printf ("test3\n");
        /*fscanf (fp, "%d", income);
        fscanf (fp, "%d", count);*/
        income = getw (fp);
        count = getw(fp);
        temp = newNode (income, count);
        root = insert (root, temp);
    }

    fprintf (fpo, "In-Order: " );
    printf ("In order: ");
    inOrder (root, fpo);
    fprintf (fpo,"\n");
    
    fprintf (fpo,"Highest income: ");
    max = maxVal (root);
    printf ("\nHighest Income: %d\nTotal people with highest income: %d", max->data, max->count);
    putw (max->data, fpo);
    fprintf (fpo,"\nTotal People with highest income: ");
    putw (max->count, fpo);
    fprintf (fpo,"\n");
    printf ("\n");

    fclose (fp);
    fclose (fpo);
    

    
    return 0;
}