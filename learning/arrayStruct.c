//https://www.geeksforgeeks.org/array-of-structures-vs-array-within-a-structure-in-c-and-cpp/
//https://www.javatpoint.com/array-of-structures-in-c
//https://www.tutorialspoint.com/explain-the-array-of-structures-in-c-language
//https://overiq.com/c-programming-101/array-of-structures-in-c/
#include <stdio.h>
struct arrayStruct
{
    int id;
    char grade;
    float mark;
};

void display(struct  arrayStruct record[4])
{
    int i =0;
    int len = 4;

    while (i < len)
    {
        printf("id number -> %d\n",record[i].id);
        printf("id number -> %c\n",record[i].grade);
        printf("id number -> %.2f\n\n",record[i].mark);
        i++;
    }
}

int main()
{
    // Initialize of an array of structures
    struct arrayStruct class_record[4]
        = { { 1, 'A', 89.5f },
            { 2, 'C', 67.5f },
            { 3, 'B', 70.5f },
            { 4, 'A', 98.5f } };
 
    // Function Call to display
    // the class_record
    display(class_record);
    return 0;
}