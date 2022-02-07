/* PLEASE DO NOT MODIFY A SINGLE STATEMENT IN THE TEXT BELOW.
READ THE FOLLOWING CAREFULLY AND FILL IN THE GAPS

I hereby declare that all the work that was required to 
solve the following problem including designing the algorithms
and writing the code below, is solely my own and that I received
no help in creating this solution and I have not discussed my solution 
with anybody. I affirm that I have read and understood
the Senate Policy on Academic honesty at 
https://secretariat-policies.info.yorku.ca/policies/academic-honesty-senate-policy-on/
and I am well aware of the seriousness of the matter and the penalties that I will face as a 
result of committing plagiarism in this assignment.

BY FILLING THE GAPS,YOU 
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30
#define fieldLength 200

#define diskFile "diskFile.dat"
#define courseFile "course.txt"

struct db_type {
  char name[fieldLength];
  int age;
  char course1[fieldLength];
  char course2[fieldLength];
  char status[fieldLength];
};

struct courseInfo {
  char code[20]; // e.g., EECS2030
  char title[fieldLength];
  char date[20];
  char time_start[20];
  char time_end[20];
  char location[20];
};

struct courseInfo courseArr[SIZE]; // global variable  array of struc

void init_list(struct db_type *pArr[]) ;
void displayCourses(void);
void displayDB(struct db_type *pArr[]);
void removeRecord(struct db_type *pArr[]);
void swap(struct db_type *pArr[]);
void sort(struct db_type *pArr[]);

void enterNew(struct db_type *pArr[SIZE]);

char prompt_menu(void);
void init_list(struct db_type *pArr[]);
void clearDB(struct db_type *pArr[]);
void init_courseArr(void);

void writeDisk(struct db_type *pArr[]);
void emptyDisk(void);
void loadDisk(struct db_type *pArr[]);


void search(char [],int *,int *);//search the course;
int TimeToInt(char c[]) ;
void swaphelp(char a[], char b[]);

    int main(int argc, char *argv[]) {

  struct db_type *db_pArr[SIZE]; // main db storage

  init_list(db_pArr); // set to NULL

  init_courseArr(); // load course from diskfile

  char choice;
  for (;;) {
    choice = prompt_menu();
    switch (choice) {
    case 'n':
      enterNew(db_pArr);
      break;
    case 'd':
      displayDB(db_pArr);
      break;
    case 'w':
      writeDisk(db_pArr);
      break;
    case 'l':
      loadDisk(db_pArr);
      break;
    case 's':
      sort(db_pArr);
      break;

    case 'c':
      clearDB(db_pArr);
      break;
    case 'e':
      emptyDisk();
      break;

    case 'v':
      displayCourses();
      break;
    case 'p':
      swap(db_pArr);
      break;
    case 'r':
      removeRecord(db_pArr);
      break;

    case 'q':
      exit(1); // terminate the whole program
    }
  }
  return 0;
}

void init_list(struct db_type *pArr[]) {
  int t;
  for (t = 0; t < SIZE; t++) {
    pArr[t] = NULL;
  }
}

void clearDB(struct db_type *pArr[]) {
  char c3[3];
  printf("are you sure to clear db? (y) or (n)? ");

  fgets(c3, 3, stdin);

  if (!strcmp(c3, "y\n"))
    init_list(pArr);
}

char prompt_menu(void) {
  char s[80];
  while (1) {
    printf("\n-----------------------------------------------------------------"
           "\n");
    printf("|    %-20s", "(N)ew record");
    printf("%-20s", "(R)emove record");
    printf("Swa(p) records\t|\n");
    printf("|    %-20s", "(S)ort database");
    printf("%-20s", "(C)lear database");
    printf("(D)isplay db\t|\n");

    printf("|    %-20s", "(L)oad disk");
    printf("%-20s", "(W)rite disk");
    printf("(E)mpty disk\t|\n");

    printf("|    %-20s",
           "(V)iew courses"); //|\tSwa(p) record\t(Q)uit\t\t\t\t|\n");
    printf("%-20s", "(Q)uit");
    printf("*Case Insensitive*\t|\n");
    printf(
        "-----------------------------------------------------------------\n");
    printf("choose one: ");

    fgets(s, 50, stdin); // \n added

    if (strlen(s) == 2 && strchr("edlsuqrcwnvpr", tolower(*s)))
      return tolower(*s); // s[0], return the first character of s
    // else
    printf("not a valid input!\n");
  }
}

/* display all or specified course */
void displayCourses(void) {
   // the provide sample.out uses "%s\t%-40s%-5s %s-%s   %s\n" as formatting
    // string for printing each course info
   char s[20];
   FILE *file;
   int i = 0;
   file=fopen(courseFile,"r");
   struct courseInfo *tmp;
   printf("course code (or 'a')? ");
   fgets(s, 50, stdin);

       if (strcmp(s,"a\n")==0)
       {
        i=0;
         while ((fscanf(file, "%s %s %s %s %s %s\n", courseArr->code,
                        courseArr->title, courseArr->date,
                        courseArr->time_start, courseArr->time_end,
                        courseArr->location) == 6) &&
                (i < 21)) {
           printf("%s\t%-40s%-5s %s-%s   %s\n", courseArr[i].code,
                  courseArr[i].title, courseArr[i].date,
                  courseArr[i].time_start, courseArr[i].time_end,
                  courseArr[i].location);
           i++;
         }
         fclose(file);
       } else if ((strlen(s) == 5) || (strlen(s) == 9)) {
         int j;
         int bool;
        search(s,&j,&bool);
       if (bool == 2) {
              printf("%s\t%-40s%-5s %s-%s   %s\n", courseArr[j].code,
                     courseArr[j].title, courseArr[j].date,
                     courseArr[j].time_start, courseArr[j].time_end,
                     courseArr[j].location);
            } else {
              printf("error! course does not exist");
            }

       } else {
         printf("error! course does not exist");
       }
    }

/* input items into the list */
 void enterNew(struct db_type *pArr[SIZE]) {
     char age[20];
     static int i =0;
     int p;
     int bool, j;
     int bool2, j2;
     int boolTime=0;
     int smallest; // smallest lenght
     pArr[i] = (struct db_type *)malloc(sizeof(struct db_type));

     printf("name : ");
      fgets(pArr[i]->name, fieldLength, stdin);
      printf("age : ");
      fgets(age, 20, stdin);
      pArr[i]->age=atoi(age);
        printf("course-1 : ");
        fgets(pArr[i]->course1, fieldLength, stdin);
        search(pArr[i]->course1, &j, &bool);
        while (bool != 2) { // CHECK IF COURSE 1 EXISTS
          printf("course does not exist, enter again: ");
          fgets(pArr[i]->course1, fieldLength, stdin);
          search(pArr[i]->course1, &j, &bool);
      }
      sprintf(pArr[i]->course1, "%s\t%-40s%-5s %s-%s   %s", courseArr[j].code,
              courseArr[j].title, courseArr[j].date, courseArr[j].time_start,
              courseArr[j].time_end, courseArr[j].location);
      printf("course-2: ");
      fgets(pArr[i]->course2, fieldLength, stdin);
      search(pArr[i]->course2, &j2, &bool2);
      while (bool2 != 2) { // CHECK IF COURSE 2 EXISTS
        printf("course does not exist, enter again: ");
        fgets(pArr[i]->course2, fieldLength, stdin);
        search(pArr[i]->course2, &j2, &bool2);
      }
      sprintf(pArr[i]->course2, "%s\t%-40s%-5s %s-%s   %s",
              courseArr[j2].code, courseArr[j2].title, courseArr[j2].date,
              courseArr[j2].time_start, courseArr[j2].time_end,
              courseArr[j2].location);

      if ((bool == 2) &&
          (bool2 == 2)) // CHECK DATES INORDER TO CHECK TIME CONFLICTS
       {
        if (strlen(courseArr[j].date) > strlen(courseArr[j2].date)) {
          // p>p2)
          smallest=strlen(courseArr[j2].date);
        } else if (strlen(courseArr[j2].date) > strlen(courseArr[j].date)) {
          smallest = strlen(courseArr[j].date);
        } else {
          smallest = strlen(courseArr[j].date);
        }
 }
//printf("%d",smallest);
 for (p=0;p<smallest;p++ ) {//loop to compare date
   if (courseArr[j].date[p] == courseArr[j2].date[p]) {
     char *startCourse2;
     char *startCourse1;
     char *endCourse1;
     const char s[1] = ":";
     // remove : from time inorde to check conflicts
     startCourse2 = strtok(courseArr[j2].time_start, s);
     startCourse1 = strtok(courseArr[j].time_start, s);
     endCourse1 = strtok(courseArr[j].time_end, s);
       if ((strcmp(startCourse2, startCourse1) > 0) &&
           (strcmp(endCourse1,startCourse2)<=0)) {
         boolTime = 3; // no time conflict
         break;
       }
   }
   else {

     boolTime = 7; // when days dont match
   }
 }

  // Input to struct
     if (boolTime == 3) {
       printf("remarks: SUCCESSFUL! no time conflict\n");
       boolTime=0;

       strcpy(pArr[i]->status, "remarks: SUCCESSFUL! no time conflict");
    }
     else if (boolTime==7) {
       printf("remarks: SUCCESSFUL! no time conflict\n");
       boolTime = 0;
       strcpy(pArr[i]->status, "remarks: SUCCESSFUL! no time conflict");
     }
      else {
       printf("ATTENTION! time conflict\n");
       strcpy(pArr[i]->status, "remarks: ATTENTION! time conflict");
      }
  i++;
 }

/* display records */
void displayDB(struct db_type *pArr[]) {
  int i;
  printf("===============================\n");
  for ( i = 0; i < SIZE; i++)
  {
    if (pArr[i]==NULL)
    {
      break;
    }
    printf("\nname: %sage : %d\ncourse1: %s\ncourse2: %s\n%s\n",pArr[i]->name,pArr[i]->age,pArr[i]->course1,pArr[i]->course2,pArr[i]->status);
   
  }
  printf("========== %d records ==========\n", i);
}

/* remove an existing item */
void removeRecord(struct db_type *pArr[]) {
  int i;
  int p=0;
  char n[fieldLength];//name entered
  printf("enter full name to remove: ");
  fgets(n, fieldLength, stdin);

  for (i = 0; i < SIZE; i++) {//GET LEN
    if (pArr[i] == NULL) {
      break;
    }
   p++;
   }
for (i=0; i<p; i++) {
  if (strcmp(n,pArr[i]->name) == 0) {
      memmove(&pArr[i], &pArr[i + 1], (p - i - 1) * sizeof *pArr);
      memset(&pArr[p - 1], 0, sizeof *pArr);
      printf("record [%s] removed successfully.", pArr[i]->name);
      break;
  }
  printf("record not found");
}
  }

/* swap records */
void swap(struct db_type *pArr[]) {
  int p=0;
  int i;
    struct db_type *temporary;
//char *temporary=malloc(sizeof(pArr[i]));
  for (i = 0; i < SIZE; i++) { // GET LEN
    if (pArr[i] == NULL) {
      break;
    }
    p++;
  }
  if ((p%2)==0)
  {
    i=0;
    while ( i<p) {
      temporary = (struct db_type *)malloc(sizeof(struct db_type));
      temporary=pArr[i];
      pArr[i]=pArr[i+1];
      pArr[i+1]=temporary;
      // memmove(temporary,pArr[i],sizeof(pArr[i]));
      // memmove(pArr[i], pArr[i+1], sizeof(pArr[i+1]));
      // memmove(pArr[i+1]+sizeof(pArr[i]), temporary, sizeof(pArr[i]));
      //free(temporary);
     
    }
  }else{
    i=0;
    while (i < p) {
      temporary = (struct db_type *)malloc(sizeof(struct db_type));
      temporary = pArr[i];
      pArr[i] = pArr[i + 1];
      pArr[i + 1] = temporary;
      i = i + 2;
    }
  }
 }

/* load from course.txt, store into (global) array of courses  */
void init_courseArr(void) {

  FILE *fr; // file pointer
  fr = fopen(courseFile, "r");
  char arr[50];
  int count = 0;
  while ((fgets(arr, 100, fr)) != NULL) {
    strncpy(courseArr[count].code, arr, strlen(arr) - 1); // remove \n
    courseArr[count].code[strlen(arr) - 1] = '\0';        // to be safe

    fgets(arr, 100, fr);
    strncpy(courseArr[count].title, arr, strlen(arr) - 1);
    courseArr[count].title[strlen(arr) - 1] = '\0'; // to be safe

    fgets(arr, 100, fr);
    strncpy(courseArr[count].date, arr, strlen(arr) - 1);
    courseArr[count].date[strlen(arr) - 1] = '\0'; // to be safe

    // other ways, remove \n before
    fgets(arr, 100, fr);
    arr[strlen(arr) - 1] = '\0';
    strcpy(courseArr[count].time_start, arr);

    fgets(arr, 100, fr);
    arr[strlen(arr) - 1] = '\0';
    strcpy(courseArr[count].time_end, arr);

    fgets(arr, 100, fr);
    arr[strlen(arr) - 1] = '\0';
    strcpy(courseArr[count].location, arr);

    count++;
    fgets(arr, 100, fr); // read the empty line
  }

  strcpy(courseArr[count].code, "EECS0000"); // a terminator token structure

  fclose(fr);
}

/************************ DISK IO
 * *****************************************************************/

void writeDisk(struct db_type *pArr[]) {
  FILE *fp;
  int i;

  if ((fp = fopen(diskFile, "ab")) == NULL) {
    printf("cannot open file\n");
    return;
  }

  for (i = 0; i < SIZE; i++) {
    if (pArr[i] != NULL) {
      if (fwrite(pArr[i], sizeof(struct db_type), 1, fp) != 1) {
        printf("file write error\n");
      }
    }
  }
  fclose(fp);
}

void emptyDisk(void) {

  FILE *fp;

  char c3[3];
  printf("are you sure to empty disk? (y) or (n)? ");
  fgets(c3, 3, stdin);
  if (strcmp(c3, "y\n"))
    return;

  // else
  if ((fp = fopen(diskFile, "w")) == NULL) {
    printf("no file to open\n");
    return;
  }
  fclose(fp); // open close, will empty the file
}

void loadDisk(struct db_type *pArr[]) {
  FILE *fp;
  int i;
  char c3[3];
  printf("will overwrite current records. are you sure to load disk? (y) or "
         "(n)? ");
  fgets(c3, 3, stdin);
  if (strcmp(c3, "y\n"))
    return;

  struct db_type *tmp;

  if ((fp = fopen(diskFile, "r")) == NULL) {
    printf("cannot open file\n");
    return;
  }

  init_list(pArr);
  for (i = 0; i < SIZE; i++) {

    tmp = (struct db_type *)malloc(sizeof(struct db_type));

    if (fread(tmp, sizeof(struct db_type), 1, fp) != 1) {
      if (feof(fp)) {
        fclose(fp);
        return;
      }
      printf("file read error\n");
    } else
      pArr[i] = tmp;
  }
}

void search(char s [],int * j,int  * bool){
  //int bool; //search courses
  if (strlen(s) == 5) {      // Its 5 because of \n character
                             // printf("legnth 4 letters\n");
    s[strlen(s) - 1] = '\0'; // remove new line
    * bool = 0;            // false.
     * j = 0;
     int P = 0;
     for (P = 0; P< 21; P++) {
       if (strcmp(courseArr[P].code + 4, s) == 0) {
         *bool = 2;
         *j=P;
         break;
       }
     }
  } else if (strlen(s) == 9) { // Its 9 because of \n character
    s[strlen(s) - 1] = '\0';   // remove new line
    *bool = 0;                 // false.
    *j = 0;
    int p=0;
    for (p = 0; p < 21; p++) {
      if (strcmp(courseArr[p].code, s) == 0) {
        *bool = 2;
        *j=p;
        break;
      }
    }
  }else
  {
    
  }
  }
  // int TimeToInt(char c []){
  //   int CourseTime,k;
    
  //   for (k = 2; k < strlen(c) - 1; k++) {
  //         c[k] = c[k + 1];
  //        }
     
  //         CourseTime=atoi(c);
  //     return CourseTime;
  //   }
  //   int dbTypeLen(int n){
  //     return n;
  //   }
  //   void swaphelp(char a[],char b []){ //swap helper
  //   int i;
  //   for ( i = 0; a[i]!='\0'; ++i)
  //   {
  //     b[i]=a[i];
  //   }
  //     b[i]='\0';
  //   }
        /****bonus*************************************************************************************/

        /* sort the records by ages */
        void sort(struct db_type *pArr[]) {
int i,j,p;
for (i = 0; i < SIZE; i++) { // GET LEN
  if (pArr[i] == NULL) {
    break;
  }
  p++;
}
struct db_type *temp;
for(i=0;i<p;i++){
  for(j=0;j<(p-1-i);j++){
    if (pArr[j]->age>pArr[j+1]->age)
    {
      temp=pArr[j];
      pArr[j]=pArr[j+1];
      pArr[j+1]=temp;
    }
  }
}
        }
