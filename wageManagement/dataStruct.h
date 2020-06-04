#ifndef DATA_STRUCT
#define DATA_STRUCT
 

/* storage basic information. */
typedef struct basicInformation
{
    char workID[80];
    char IDNumber[80];
    char name[80];
    char gender[80];
    int age;
    int workAge;
    char department[80];
    char job[80];
    int jobID;
    char homeNumber[80];
    char personNumber[80];
} BI;


/* storage basic wage information. */
typedef struct basicWageInformation 
{
    int basicWage;
    int jobWage;
    int elseWage;
    int reward;
    int wageTotal;
} BW;


/* storage cost information. */
typedef struct costInformation
{
    int homeCost;
    int jobInsurance;
    int ageInsurance;
    int personTax;
} CI;


/* storage fee information. */
typedef struct feeInformation
{
    int waterFee;
    int electricityFee;
    int cleanFee;
    int TVFee;
} FI;


/* the doubly linked list which storages all information. */
typedef struct information
{
    BI basic;
    BW wage;
    CI cost;
    FI fee;
    struct information *prior;
    struct information *next;
} *info, infor;

#endif