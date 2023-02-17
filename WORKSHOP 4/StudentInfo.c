// StudentInfo.h - function definitions for student information

// Name : Divyanshu Dugar
// Email : ddugar@myseneca.ca
// Student ID : 177110210

#include <stdio.h>
#include "StudentInfo.h" // including the header file

void initializeInfo(struct StudentInfo *student) // function the initialize the information of a student
{
    student->lastName[0] = '\0'; // setting the last name to a NULL string (by setting the 1st character of the last name to 0)
    student->studentId = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        student->subject[i].name[0] = '\0';
        student->subject[i].mark = 0;
    }
}

int findMaxMark(struct Subjects *subject) // function to find the maximum mark of the student and returning its position
{
    int maxMark, maxIndex = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        if (subject[i].mark == 0) // terminating the loop if mark is = 0 (Invalid Mark)
        {
            break;
        }
        if (subject[i].mark > maxMark)
        {
            maxMark = subject[i].mark;
            maxIndex = i;
        }
    }
    return maxIndex; // returning the Index of the maximum mark
}

int findMinMark(struct Subjects *subject) // function to find the minimum mark of the student and returning its position
{
    int minMark, minIndex = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        if (subject[i].mark == 0) // terminating the loop if mark is = 0 (Invalid Mark)
        {
            break;
        }
        if (subject[i].mark < minMark)
        {
            minMark = subject[i].mark;
            minIndex = i;
        }
    }
    return minIndex; // returning the Index of the minimum mark
}

float calcAverageMark(struct Subjects *subject) // function to find and return the average marks of the student 
{
    float sumMark = 0.0; // stores the total marks of all the subjects of a student
    int c = 0; // counter variable to count the number of valid marks.
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        if (subject[i].mark > 0) 
        {
            sumMark += subject[i].mark;
            ++c; // incrementing the counter variable by one on every valid subject mark 
        }
        else
        {
            break;
        }
    }
    return sumMark / c; // returning the average marks of the student (dividing total marks by total number of marks)
}
