#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct FCFS
{
        float wt;
        float tt;
        float bt;
        int pno;

}fcfs;

typedef struct PRI
{
        float wt;
        float tt;
        float bt;
        int pno;
        int pt;
}pri;

typedef struct RR
{
        int entry;
        float ct;
        float bt2;
        float wt;
        float tt;
        float bt;
        int pno;

}rr;

//ROUND ROBIN
typedef struct listnoderr
{
rr pr;
struct listnoderr *next;
}noderr;

typedef noderr *listrr;
typedef noderr *positionrr;
listrr initializerr();
void insertrr(int,float,listrr);
void displayrr(listrr);
void calculaterr(listrr,int);
positionrr sortbt(listrr);
positionrr sortpno(listrr);

//FCFS
typedef struct listnodefc
{
        fcfs pr1;
        struct listnodefc *nextfc;
}nodefc;
typedef nodefc *listfc;
typedef nodefc *positionfc;
listfc initializefcfs();
void insertfcfs(int,float,listfc);
void displayfcsfs(listfc);
positionfc calculatefcfs(listfc,int);

//Priority

typedef struct listnodepri
{
        pri pr2;
        struct listnodepri *nextpri;
}nodepri;
typedef nodepri *listpri;
typedef nodepri *positionpri;
listpri initializepri();
void insertpri(int,float,int,listpri);
void displaypri(listpri);
positionpri calculatepri(listpri,int);
positionpri sort(listpri);
