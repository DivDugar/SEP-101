// StudentInfo.h - declarations for student information

// Name : Divyanshu Dugar
// Email : ddugar@myseneca.ca
// Student ID : 177110210

#define MAX_STR 64
#define NUM_SUBJECTS 4

struct StudentInfo // defining the 2nd structure
{
    char lastName[MAX_STR];
    int studentId;
    struct Subjects subject[NUM_SUBJECTS];
};

struct Subjects //  defining the 1st structure
{
    char name[MAX_STR];
    int mark;
};


// creating the function prototypes

void initializeInfo(struct StudentInfo *studentInfo); // pass by address
int findMaxMark(struct Subjects *subject);
int findMinMark(struct Subjects *subject);
float calcAverageMark(struct Subjects *subject);