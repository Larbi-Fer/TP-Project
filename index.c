#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int day;
  int month;
  int year;
} Date;

typedef struct {
  char code[5];
  char name[45];
} Module;

char grade[5][5] = {"MAB", "MAA", "MCB", "MCA", "Prof"};
char sp[2][6] = {"Maths", "Info"};
char Choices[12][100] = {
    "choices of the teacher",
    "show teachers of maths or informatique",
    "show the grade of teacher",
    "show the teacher who has age than A and seniority more than AN ",
    "modification of grade",
    "show the teacher by the charge",
    "show the teacher who has a big charge and less charge",
    "add a teacher",
    "delete an teacher by code",
    "ranking the teacher by the name or by year of employment",
    "search for an teacher by last name ( A  dichotomous search )",
    "add a new teacher to the ranking list",

};

typedef struct {
  int cours;
  int td;
  int tp;
} Charge;

typedef struct {
  char firstn[20];
  char lastn[15];
  int grade;
  Date dn;
  char code[5];
  char sp[6];
  int ar;
  Module module[2];
  Charge charge;
} Ens;

int main() {
    int ne; // number of teachers
    printf("Enter the number of teachers: ");
    scanf("%d", &ne);
    int lng; // leangth of tabels 
    int a; // Age
    int an; // Seniority
    int now; // Current year
    int sizene = ne < 10 ? 7 : (ne < 20 ? 12 : ne * 0.4); //new teachers
  // Ens ens[ne + sizene];
    Ens ens[] = {
        {"Salah", "Gasbaoui", 4, {20, 10, 2002}, "M60", "Info", 2031, {{"F122", "Structure"}, {"F222", "/"}}, {107, 2, 0}},
        {"Amin", "AbdElaoui", 4, {10, 2, 1975}, "C77", "Maths", 2011, {{ "F122", "Analyse" }}, {2, 5, 0}},
    };

  Ens sortEns[ne + sizene];

  bool isSort = false, isRtn = false;

  char Months[][12] = {"January",   "February", "March",    "April",
                       "May",       "June",     "July",     "August",
                       "September", "October",  "November", "December"};

  printf("Enter the following values:\n");
  for (int i = 0; i < ne; i++) {
    int j;
    printf("enseignant %d:\n", i + 1);
    // Entre The value of Ens
    bool l = false;
    do {
      l = false;
      printf("\tcode: ");
      scanf("%s", &ens[i].code);
      for (int j = 0; j < i && !l; j++) {
        if (strcmp(ens[i].code, ens[j].code) == 0)
          l = true;
      }
      if (l)
        printf("\tThis code is alredy taken\n");

    } while ((ens[i].code[0] < 'A' || ens[i].code[0] > 'Z') ||
             (ens[i].code[1] < '0' || ens[i].code[1] > '9') ||
             (ens[i].code[2] < '0' || ens[i].code[2] > '9') ||
             strlen(ens[i].code) > 3 || l);
    continue;
    printf("\tLast name: ");
    scanf("%s", &ens[i].lastn);
    // تحويل الحرف الأول إلى capitel later
    if (ens[i].lastn[0] >= 'a' && ens[i].lastn[0] <= 'z')
      ens[i].lastn[0] = ens[i].lastn[0] - 32;
    for (int j = 1; j < strlen(ens[i].lastn); j++) {
      if (ens[i].firstn[j] == '_') ens[i].firstn[j] = ' ';
      if (ens[i].lastn[j] >= 'A' && ens[i].lastn[j] <= 'Z')
        ens[i].lastn[j] = ens[i].lastn[j] + 32;
    }

    printf("\tFirt name: ");
    scanf("%s", &ens[i].firstn);
    if (ens[i].firstn[0] >= 'a' && ens[i].firstn[0] <= 'z')
      ens[i].firstn[0] = ens[i].firstn[0] - 32;
    for (int j = 1; j < strlen(ens[i].firstn); j++) {
      if (ens[i].firstn[j] == '_') ens[i].firstn[j] = ' ';
      if (ens[i].firstn[j] >= 'A' && ens[i].firstn[j] <= 'Z')
        ens[i].firstn[j] = ens[i].firstn[j] + 32;
    }
    printf("%s\n", ens[i].firstn);

    printf("\tBirth day:\n");
    do {
      printf("\t\t%-7s", "Day:");
      scanf("%d", &ens[i].dn.day);
    } while (ens[i].dn.day > 31 || ens[i].dn.day < 1);
    //
    do {
      printf("\t\t%-7s", "Month:");
      scanf("%d", &ens[i].dn.month);

      // if ( mnth[0] >= '0' && mnth[0] <= '1' && mnth[1] >= '0' && mnth[1] <=
      // '9' ) {}

      if (ens[i].dn.day == 31) {
        if ((ens[i].dn.month <= 7 && ens[i].dn.month % 2 == 1) ||
            (ens[i].dn.month > 7 && ens[i].dn.month % 2 == 0))
          break;
      } else if (ens[i].dn.day > 29 && ens[i].dn.month == 2)
        continue;
      else if (ens[i].dn.month <= 12)
        break;

    } while (true);
    printf("\t\t--> %s\n", Months[ens[i].dn.month - 1]);
    // Year
    do {
      printf("\t\t%-7s", "Year:");
      scanf("%d", &ens[i].dn.year);
    } while (ens[i].dn.year > 2010 || ens[i].dn.year < 1955 ||
             ((ens[i].dn.day == 29 && ens[i].dn.month == 2) &&
              ens[i].dn.year % 4 != 0));

    // Grade
    printf("\tGrade: ");
    // choose the grade number
    lng = 5;
    for (j = 0; j < lng; j++)
      printf("%6d) %s", j + 1, grade[j]);
    printf("\n");
    do {
      printf("\t\tEntre the numbre: ");
      scanf("%d", &ens[i].grade);
      ens[i].grade -= 1;
    } while (ens[i].grade < 0 || ens[i].grade > (lng - 1));
    printf("\t\t%d --> %s\n", ens[i].grade + 1, grade[ens[i].grade]);

    // Choose between Maths and Info
    lng = 2;
    printf("\tSpecialty: ");
    for (j = 0; j < lng; j++)
      printf("%6d) %s", j + 1, sp[j]);
    printf("\n");
    do {
      printf("\t\tEntre the numbre: ");
      int j;
      scanf("%d", &j);
      j -= 1;
      if (j < 0 || j > (lng - 1))
        continue;
      strcpy(ens[i].sp, sp[j]);
      printf("\t\t%d --> %s\n", j + 1, sp[j]);
      break;
    } while (true);

    do {
      printf("\tYear of employment: ");
      scanf("%d", &ens[i].ar);
    } while (ens[i].ar - ens[i].dn.year < 25 || ens[i].ar > 2100);

    // Modules
    j = 0;
    do {
      char c = 'n';
      printf("\tmodule %d:\n", j + 1);
      do {
        printf("\t\t%-16s ", "code of module:");
        scanf("%s", &ens[i].module[j].code);
      } while (
          (ens[i].module[j].code[0] < 'A' || ens[i].module[j].code[0] > 'Z') ||
          (ens[i].module[j].code[1] < '0' || ens[i].module[j].code[1] > '9') ||
          (ens[i].module[j].code[2] < '0' || ens[i].module[j].code[2] > '9') &&
              (ens[i].module[j].code[3] < '0' ||
               ens[i].module[j].code[3] > '9') ||
          strlen(ens[i].module[j].code) > 4);
      printf("\t\t%-16s ", "The module name:");
      scanf("%s", &ens[i].module[j].name);
      for (int i2 = 0; ens[i].module[j].name[i2] != '\0'; i2++) 
          if (ens[i].module[j].name[i2] == '_') ens[i].module[j].name[i2] = ' ';
      if (j == 0) {
        printf("\t\tDo you want to enter a new module. y/n?: ");
        scanf("%s", &c);
      }
      ens[i].module[1].name[0] = '/';
      ens[i].module[1].name[1] = '\0';
      if (c == 'n')
        break;
      j++;
    } while (true);

    // Charge
    // do {
    printf("\tCharge:\n");
    printf("\t\tcours: ");
    scanf("%d", &ens[i].charge.cours);
    printf("\t\tTD:    ");
    scanf("%d", &ens[i].charge.td);
    printf("\t\tTP:    ");
    scanf("%d", &ens[i].charge.tp);
    // } while()

    printf("______________________________________________\n");
  }

  char isr;
  do {
    int ch;
    printf("___________________________________________________________________"
           "_______\n");
    printf("| -> Menu:%-64s|\n", "");
    for (int i = 0; i < 12; i++)
      printf("|   %2d) %-66s%s\n", i + 1, Choices[i], "|");
    printf("___________________________________________________________________"
           "_______\n");
    do {
      printf("Choise: ");
      scanf("%d", &ch);
    } while (ch < 1 || ch > 12);
    ch -= 1;
    printf("%d --> %s\n", ch + 1, Choices[ch]);

    // Code
    switch (ch) {
    case 0:
      printf("\tsearch by code or name or module(code or name): ");
      char srh[30];
      scanf("%s", &srh);
        if (srh[0] >= 'a' && srh[0] <= 'z')
            srh[0] = srh[0] - 32;
        for (int j = 1; j < strlen(srh); j++) {
            if (srh[j] >= 'A' && srh[j] <= 'Z')
                srh[j] = srh[j] + 32;
        }
      int j = 0;
      printf("%-3s %-5s %-15s %-15s %-8s %-17s %-11s %-15s %-7s %-3s %-3s %s\n",
             "N", "Code", "first name", "last name", "sp", "Module", "Date",
             "year of employment", "grade", "CR", "TD", "TP");
      for (int i = 0; i < ne; i++) {
        if (strcmp(srh, ens[i].code) == 0 || strcmp(srh, ens[i].firstn) == 0 ||
            strcmp(srh, ens[i].lastn) == 0 ||
            strcmp(srh, ens[i].module[0].name) == 0 ||
            strcmp(srh, ens[i].module[0].code) == 0 ||
            strcmp(srh, ens[i].module[1].name) == 0 ||
            strcmp(srh, ens[i].module[1].code) == 0) {
          j++;
          printf("%-3d %-5s %-15s %-15s %-7s %s%-5s %-10s %s%d/%s%d/%-6d %-18d "
                 "%-7s %-3d %-3d %d\n",
                 j, ens[i].code, ens[i].firstn, ens[i].lastn, ens[i].sp,
                 strcmp(ens[i].module[1].name, "/") == 0 ? " " : "|",
                 ens[i].module[0].code, ens[i].module[0].name,
                 ens[i].dn.day <= 9 ? "0" : "", ens[i].dn.day,
                 ens[i].dn.month <= 9 ? "0" : "", ens[i].dn.month,
                 ens[i].dn.year, ens[i].ar, grade[ens[i].grade],
                 ens[i].charge.cours, ens[i].charge.td, ens[i].charge.tp);
          if (strcmp(ens[i].module[1].name, "/") != 0) {
            printf("%-50s|%-5s %-10s\n", " ", ens[i].module[1].code,
                   ens[i].module[1].name);
          }
        }
      }
      if (j == 0)
        printf("\nThere is no one with this name \"%s\"\n", srh);
      break;
    case 1:
      lng = 2;
      printf("\tSpecialty: ");
      for (int j = 0; j < lng; j++)
        printf("%6d) %s", j + 1, sp[j]);
      printf("\n");
      char spi[6];
      do {
        int j;
        printf("\t\tEntre the numbre: ");
        scanf("%d", &j);
        j -= 1;
        if (j < 0 || j > (lng - 1))
          continue;
        strcpy(spi, sp[j]);
        break;
      } while (true);
      j = 0;
      printf("-> %s:\n", spi);
      printf("%-5s %-15s %-15s %s\n", "Code", "First Name", "Last Name",
             "Grade");
      for (int i = 0; i < ne; i++) {
        if (strcmp(ens[i].sp, spi) == 0) {
          printf("%-5s %-15s %-15s %s\n", ens[i].code, ens[i].lastn,
                 ens[i].firstn, grade[ens[i].grade]);
          j++;
        }
      }
      if (j == 0)
        printf("\nthere is no one employment");

      break;
    case 2:
      lng = 5;
      printf("\tGrades: ");
      for (int j = 0; j < lng; j++)
        printf("%6d) %s", j + 1, grade[j]);
      printf("\n");
      int grd;
      do {
        int j;
        printf("\t\tEntre the numbre: ");
        scanf("%d", &grd);
        grd -= 1;
        if (grd < 0 || grd > (lng - 1))
          continue;
        break;
      } while (true);
      j = 0;
      printf("-> %s:\n", grade[grd]);
      printf("%-5s %-15s %-15s %s\n", "Code", "First Name", "Last Name",
             "Spiciality");
      for (int i = 0; i < ne; i++) {
        // printf("%d %d   ", grd, grade[grd]);
        if (ens[i].grade == grd) {
          printf("%-5s %-15s %-15s %s\n", ens[i].code, ens[i].firstn,
                 ens[i].lastn, ens[i].sp);
          j++;
        }
      }
      if (j == 0)
        printf("\nthere is no employment has grade '%s'", grade[grd]);
      break;
    case 3:
      printf("enter current year: ");
      scanf("%d", &now);

      do {
        printf("enter the age you want to search: ");
        scanf("%d", &a);
      } while (a < 20 || a > 70);

      do {
        printf("enter the sinoirity age you want to search: ");
        scanf("%d", &an);
      } while (an < 1 || an > 42);
      printf("\n%-5s %-15s %-15s %s\n", "Code", "First Name", "Last Name",
             "Spiciality");
      for (int i = 0; i < ne; i++) {
        if (now - ens[i].dn.year > a && now - ens[i].ar > an) {
          printf("%-5s %-15s %-15s %s\n", ens[i].code, ens[i].firstn,
                 ens[i].lastn, ens[i].sp);
        }
      }
      break;
    case 4:
      printf("enter the code of employment: ");
      char code[4];
      scanf("%s", &code);
      bool h = false;
      for (int i = 0; i < ne; i++) {
        if (code[0] == ens[i].code[0] && code[1] == ens[i].code[1] &&
            code[2] == ens[i].code[2] && code[3] == ens[i].code[3]) {
          h = true;
          printf("the name: %s %-15s the grade: %s\n", ens[i].lastn,
                 ens[i].firstn, grade[ens[i].grade]);
          if (ens[i].grade == 4)
            printf("there is no grade more than 'prof' ");
          else {
            char ch;
            printf("the old grade is: %s, and the new one is: %s \n",
                   grade[ens[i].grade], grade[ens[i].grade + 1]);
            printf("do you accept this modification? y/n: ");
            scanf("%s", &ch);
            if (ch == 'y' || ch == 'Y') {
              ens[i].grade = ens[i].grade + 1;
              printf("the modification of grade is %s", grade[ens[i].grade]);
            }
          }

          break;
        }
      }
      if (!h)
        printf("\nthere is no one with this code");
      break;
    case 5:
      printf("enter the numbres of courses: ");
      int nc, nt, np, k = 0;
      scanf("%d", &nc);
      printf("enter the numbres of TD: ");
      scanf("%d", &nt);
      printf("enter the numbres of TP: ");
      scanf("%d", &np);

      for (int i = 0; i < ne; i++)
        if (nc == ens[i].charge.cours && nt == ens[i].charge.td &&
            np == ens[i].charge.tp)
          k++;
      if (k == 0)
        printf("there is no teachers have the same charge ");
      else
        printf("there is %d teacher%s who has the same charge", k,
               k == 1 ? "" : "s");
      break;
    case 6:
      printf("");
      int minch = ens[0].charge.cours + ens[0].charge.td + ens[0].charge.tp,
          mini = 0;
      int maxch = ens[0].charge.cours + ens[0].charge.td + ens[0].charge.tp,
          maxi = 0;
      for (int i = 1; i < ne; i++) {
        int charge = ens[i].charge.cours + ens[i].charge.td + ens[i].charge.tp;
        if (charge > maxch) {
          maxch = charge;
          maxi = i;
        }
        if (charge < minch) {
          minch = charge;
          mini = i;
        }
      }
      int i = maxi;
      printf("the maximuam charge:\n");
      printf("%-3s %-5s %-15s %-15s %-7s %-17s %-11s %-15s %-7s %-3s %-3s %s\n",
             "N", "Code", "first name", "last name", "sp", "Module", "Date",
             "year of employment", "grade", "CR", "TD", "TP");
      printf(
          "%-3d %-5s %-15s %-15s %-7s %s%-5s %-10s %s%d/%s%d/%-5d %-18d %-7s "
          "%-3d %-3d %d\n",
          j, ens[i].code, ens[i].firstn, ens[i].lastn, ens[i].sp,
          strcmp(ens[i].module[1].name, "/") == 0 ? " " : "|",
          ens[i].module[0].code, ens[i].module[0].name,
          ens[i].dn.day <= 9 ? "0" : "", ens[i].dn.day,
          ens[i].dn.month <= 9 ? "0" : "", ens[i].dn.month, ens[i].dn.year,
          ens[i].ar, grade[ens[i].grade], ens[i].charge.cours, ens[i].charge.td,
          ens[i].charge.tp);
      if (strcmp(ens[i].module[1].name, "/") != 0) {
        printf("%-50s|%-5s %-10s\n", " ", ens[i].module[1].code,
               ens[i].module[1].name);
      }

      printf("the minimuam charge:\n");
      printf(
          "%-3s %-5s %-15s %-15s %-7s %-17s %-11s %-15s %-7s %-3s %-3s %-3s\n",
          "N", "Code", "first name", "last name", "sp", "Module", "Date",
          "year of employment", "grade", "CR", "TD", "TP");
      i = mini;
      printf(
          "%-3d %-5s %-15s %-15s %-7s %s%-5s %-10s %s%d/%s%d/%-5d %-18d %-7s "
          "%-3d %-3d %d\n",
          j, ens[i].code, ens[i].firstn, ens[i].lastn, ens[i].sp,
          strcmp(ens[i].module[1].name, "/") == 0 ? " " : "|",
          ens[i].module[0].code, ens[i].module[0].name,
          ens[i].dn.day <= 9 ? "0" : "", ens[i].dn.day,
          ens[i].dn.month <= 9 ? "0" : "", ens[i].dn.month, ens[i].dn.year,
          ens[i].ar, grade[ens[i].grade], ens[i].charge.cours, ens[i].charge.td,
          ens[i].charge.tp);
      if (strcmp(ens[i].module[1].name, "/") != 0) {
        printf("%-50s|%-5s %-10s\n", " ", ens[i].module[1].code,
               ens[i].module[1].name);
      }
      break;
    case 7:
      if (sizene == 0) {
        printf("\nThere is not enough space");
        break;
      }
      isSort = false;
      Ens newT;
      // Entre The value of Ens
    printf("enseignant %d:\n", i + 1);
    // Entre The value of Ens
    bool l = false;
    do {
      l = false;
      printf("\tcode: ");
      scanf("%s", &newT.code);
      for (int j = 0; j < i && !l; j++) {
        if (strcmp(newT.code, ens[j].code) == 0)
          l = true;
      }
      if (l)
        printf("\tThis code is alredy taken\n");

    } while ((newT.code[0] < 'A' || newT.code[0] > 'Z') ||
             (newT.code[1] < '0' || newT.code[1] > '9') ||
             (newT.code[2] < '0' || newT.code[2] > '9') ||
             strlen(newT.code) > 3 || l);
    printf("\tLast name: ");
    scanf("%s", &newT.lastn);
    //
    if (newT.lastn[0] >= 'a' && newT.lastn[0] <= 'z')
      newT.lastn[0] = newT.lastn[0] - 32;
    for (int j = 1; j < strlen(newT.lastn); j++) {
      if (newT.lastn[j] >= 'A' && newT.lastn[j] <= 'Z')
        newT.lastn[j] = newT.lastn[j] + 32;
    }

    printf("\tFirt name: ");
    scanf("%s", &newT.firstn);
    if (newT.firstn[0] >= 'a' && newT.firstn[0] <= 'z')
      newT.firstn[0] = newT.firstn[0] - 32;
    for (int j = 1; j < strlen(newT.firstn); j++) {
      if (newT.firstn[j] >= 'A' && newT.firstn[j] <= 'Z')
        newT.firstn[j] = newT.firstn[j] + 32;
    }

    printf("\tBirth day:\n");
    do {
      printf("\t\t%-7s", "Day:");
      scanf("%d", &newT.dn.day);
    } while (newT.dn.day > 31 || newT.dn.day < 1);
    //
    do {
      printf("\t\t%-7s", "Month:");
      scanf("%d", &newT.dn.month);

      // if ( mnth[0] >= '0' && mnth[0] <= '1' && mnth[1] >= '0' && mnth[1] <=
      // '9' ) {}

      if (newT.dn.day == 31) {
        if ((newT.dn.month <= 7 && newT.dn.month % 2 == 1) ||
            (newT.dn.month > 7 && newT.dn.month % 2 == 0))
          break;
      } else if (newT.dn.day > 29 && newT.dn.month == 2)
        continue;
      else if (newT.dn.month <= 12)
        break;

    } while (true);
    printf("\t\t--> %s\n", Months[newT.dn.month - 1]);
    // Year
    do {
      printf("\t\t%-7s", "Year:");
      scanf("%d", &newT.dn.year);
    } while (newT.dn.year > 2010 || newT.dn.year < 1955 ||
             ((newT.dn.day == 29 && newT.dn.month == 2) &&
              newT.dn.year % 4 != 0));

    // Grade
    printf("\tGrade: ");
    // choose the grade number
    lng = 5;
    for (j = 0; j < lng; j++)
      printf("%6d) %s", j + 1, grade[j]);
    printf("\n");
    do {
      printf("\t\tEntre the numbre: ");
      scanf("%d", &newT.grade);
      newT.grade -= 1;
    } while (newT.grade < 0 || newT.grade > (lng - 1));
    printf("\t\t%d --> %s\n", newT.grade + 1, grade[newT.grade]);

    // Choose between Maths and Info
    lng = 2;
    printf("\tSpecialty: ");
    for (j = 0; j < lng; j++)
      printf("%6d) %s", j + 1, sp[j]);
    printf("\n");
    do {
      printf("\t\tEntre the numbre: ");
      int j;
      scanf("%d", &j);
      j -= 1;
      if (j < 0 || j > (lng - 1))
        continue;
      strcpy(newT.sp, sp[j]);
      printf("\t\t%d --> %s\n", j + 1, sp[j]);
      break;
    } while (true);

    do {
      printf("\tYear of employment: ");
      scanf("%d", &newT.ar);
    } while (newT.ar - newT.dn.year < 25 || newT.ar > 2100);

    // Modules
    j = 0;
    do {
      char c = 'n';
      printf("\tmodule %d:\n", j + 1);
      do {
        printf("\t\t%-16s ", "code of module:");
        scanf("%s", &newT.module[j].code);
      } while (
          (newT.module[j].code[0] < 'A' || newT.module[j].code[0] > 'Z') ||
          (newT.module[j].code[1] < '0' || newT.module[j].code[1] > '9') ||
          (newT.module[j].code[2] < '0' || newT.module[j].code[2] > '9') &&
              (newT.module[j].code[3] < '0' ||
               newT.module[j].code[3] > '9') ||
          strlen(newT.module[j].code) > 4);
      printf("\t\t%-16s ", "The module name:");
      scanf("%s", &newT.module[j].name);
      if (j == 0) {
        printf("\t\tDo you want to enter a new module. y/n?: ");
        scanf("%s", &c);
      }
      newT.module[1].name[0] = '/';
      newT.module[1].name[1] = '\0';
      if (c == 'n')
        break;
      j++;
    } while (true);

    // Charge
    printf("\tCharge:\n");
    printf("\t\tcours: ");
    scanf("%d", &newT.charge.cours);
    printf("\t\tTD:    ");
    scanf("%d", &newT.charge.td);
    printf("\t\tTP:    ");
    scanf("%d", &newT.charge.tp);

      ens[ne] = newT;
      ne++;
      sizene--;
      break;
    case 8:
      printf("Enter the code of the teacher you want to delete: ");
      scanf("%s", &code);
      h = false;
      for (int i = 0; i < ne; i++) {
        if (code[0] == ens[i].code[0] && code[1] == ens[i].code[1] &&
            code[2] == ens[i].code[2] && code[3] == ens[i].code[3]) {
          h = true;
          char ch;
          printf("Do you want to delete '%s %s'? y/n:  ", ens[i].lastn,
                 ens[i].firstn);
          scanf("%s", &ch);
        }
        if (h)
          ens[i] = ens[i + 1];
      }
        if (h) {
            ne--;
            sizene++;
            isSort = false;
        }
      if (!h)
        printf("\nthere is no one with this code");
      break;
    case 9:
      printf("do you want to sort with   1) name  |  2) year of employment: ");
      scanf("%d", &ch);
    sort:
      h = false;
      for (int i = 0; i < ne; i++)
        sortEns[i] = ens[i];
      for (int j = 0; j < ne - 1 && !h; j++) {
        h = true;
        for (int i = ne - 1; i > j; i--) {
          if (ch == 2 && !isRtn) {
            isSort = false;
            if (sortEns[i].ar < sortEns[i - 1].ar) {
              h = false;
              Ens temp = sortEns[i];
              sortEns[i] = sortEns[i - 1];
              sortEns[i - 1] = temp;
            }
          } else {
            // compare last names
            isSort = true;
            int len = strlen(sortEns[i].lastn);
            len = len > strlen(sortEns[i - 1].lastn)
                      ? strlen(sortEns[i - 1].lastn)
                      : len;
            int k = 0;
            for (int i2 = 0; i2 <= len + 1; i2++) {
              if (i2 + 1 > len)
                k = 2;
              else if (sortEns[i - 1].lastn[i2] > sortEns[i].lastn[i2])
                k = -1;
              else if (sortEns[i - 1].lastn[i2] < sortEns[i].lastn[i2])
                k = 1;
              if (k != 0)
                break;
            }
            // if the start is equal
            if (k == 2) {
              if (strlen(sortEns[i - 1].lastn) > strlen(sortEns[i].lastn))
                k = -1;
              else if (strlen(sortEns[i - 1].lastn) < strlen(sortEns[i].lastn))
                k = 1;
              else
                k = 0;
            }
            if (k == -1) {
              h = false;
              Ens temp = sortEns[i];
              sortEns[i] = sortEns[i - 1];
              sortEns[i - 1] = temp;
            }
          }
        }
      }
      if (isRtn)
        goto rtn;
      // Show the information
      if (ne != 0)
        printf("_______________________________________________________________"
               "_________________________________________________________\n");
      printf("%-3s %-5s %-15s %-15s %-10s %-17s %-11s %-15s %-7s %-3s %-3s "
             "%s\n",
             "N", "Code", "Last name", "First name", "Speciality", "Module",
             "Date", "Year of employment", "Grade", "CR", "TD", "TP");

      for (int i = 0; i < ne; i++) {
        printf("%-3d %-5s %-15s %-15s %-10s %s%-5s %-10s %s%d/%s%d/%-5d %-18d "
               "%-7s %-3d %-3d %d\n",
               i + 1, sortEns[i].code, sortEns[i].lastn, sortEns[i].firstn,
               sortEns[i].sp,
               strcmp(sortEns[i].module[1].name, "/") == 0 ? " " : "|",
               sortEns[i].module[0].code, sortEns[i].module[0].name,
               sortEns[i].dn.day <= 9 ? "0" : "", sortEns[i].dn.day,
               sortEns[i].dn.month <= 9 ? "0" : "", sortEns[i].dn.month,
               sortEns[i].dn.year, sortEns[i].ar, grade[sortEns[i].grade],
               sortEns[i].charge.cours, sortEns[i].charge.td,
               sortEns[i].charge.tp);
        if (strcmp(sortEns[i].module[1].name, "/") != 0) {
          printf("%-53s|%-5s %-10s\n", " ", sortEns[i].module[1].code,
                 sortEns[i].module[1].name);
        }
      }
      if (ne != 0)
        printf(
            "________________________________________________________________"
            "________________________________________________________\n");

      break;
    case 10:
      printf("search for name: ");
      scanf("%s", &srh);
        if (srh[0] >= 'a' && srh[0] <= 'z')
            srh[0] = srh[0] - 32;
        for (int j = 1; j < strlen(srh); j++) {
            if (srh[j] >= 'A' && srh[j] <= 'Z')
                srh[j] = srh[j] + 32;
        }
      int s = 0, e = ne;
      k = -1;
      int len;
      if (!isSort) {
        isRtn = true;
        goto sort;
      }
    rtn:
      isRtn = false;
      do {
        len = (s + e) / 2.0;
        if (e - s <= 1)
          k = 1;
        i = 0;
        for (; sortEns[len].lastn[i] == srh[i] && sortEns[len].lastn[i] != '\0';
             i++) {
        }
        if (sortEns[len].lastn[i] == srh[i])
          k = 0;
        else if (sortEns[len].lastn[i] < srh[i])
          s = len;
        else
          e = len;
      } while (k != 0 && k != 1);

      if (k == 0) {
        printf(
            "\n%-5s %-15s %-15s %-7s %-16s %-11s %-15s %-7s %-3s %-3s %-3s\n",
            "Code", "Last name", "First name", "sp", "Module", "Date",
            "year of employment", "grade", "CR", "TD", "TP");
        printf("%-5s %-15s %-15s %-6s %s%-5s %-10s %s%d/%s%d/%-5d %-18d %-7s "
               "%-3d %-3d %-3d\n",
               sortEns[len].code, sortEns[len].lastn, sortEns[len].firstn,
               sortEns[len].sp,
               strcmp(sortEns[len].module[1].name, "/") == 0 ? " " : "|",
               sortEns[len].module[0].code, sortEns[len].module[0].name,
               sortEns[len].dn.day < 10 ? "0" : "", sortEns[len].dn.day,
               sortEns[len].dn.month < 10 ? "0" : "", sortEns[len].dn.month,
               sortEns[len].dn.year, sortEns[len].ar, grade[sortEns[len].grade],
               sortEns[len].charge.cours, sortEns[len].charge.td,
               sortEns[len].charge.tp);
        if (strcmp(ens[len].module[1].name, "/") == 0) {
          printf("%-45s|%-5s %-10s\n", " ", ens[len].module[1].code,
                 sortEns[len].module[1].name);
        }
      } else {
        printf("\nYour search for %s didn't return any results", srh);
      }

      break;
    case 11:
      if (sizene == 0) {
        printf("There is not enough space");
        break;
      }
      if (!isSort) {
        printf("you need to rank the teatchers first (option N°10)");
        break;
      }

      printf("enter the number of the teatchers that you want to add: ");

      int n;
      do {
        scanf("%d", &n);
        if (n < 0 || n > sizene)
          printf("it's should be between 1 and %d: ", sizene);
        else
          break;
      } while (true);
      sizene -= n;

      for (i = 1; i <= n; i++) {
        Ens newT;
        printf("\nTeacher N°%d:\n", i);
        // Entre The value of Ens
        do {
          printf("\tcode: ");
          scanf("%s", &newT.code);
        } while ((newT.code[0] < 'A' || newT.code[0] > 'Z') ||
                 (newT.code[1] < '0' || newT.code[1] > '9') ||
                 (newT.code[2] < '0' || newT.code[2] > '9') ||
                 strlen(newT.code) > 3);

        printf("\t\nLast name: ");
        scanf("%s", &newT.lastn);
        printf("\t\nFirst name: ");
        scanf("%s", &newT.firstn);

        printf("\tBirth day:\n");
        printf("\t\t%-7s", "Day:");
        scanf("%d", &newT.dn.day);
        printf("\t\t%-7s", "Month:");
        scanf("%d", &newT.dn.month);
        printf("\t\t%-7s", "Year:");
        scanf("%d", &newT.dn.year);

        // Grade
        printf("\tGrade: ");
        // choose the grade number
        lng = 5;
        for (j = 0; j < lng; j++)
          printf("%6d) %s", j + 1, grade[j]);
        printf("\n");
        do {
          printf("\t\tEntre the numbre: ");
          scanf("%d", &newT.grade);
          newT.grade -= 1;
        } while (newT.grade < 0 || newT.grade > (lng - 1));
        printf("\t\t%d --> %s\n", newT.grade + 1, grade[newT.grade]);

        // Choose between Maths and Info
        lng = 2;
        printf("\tSpecialty: ");
        for (j = 0; j < lng; j++)
          printf("%6d) %s", j + 1, sp[j]);
        printf("\n");
        do {
          printf("\t\tEntre the numbre: ");
          int j;
          scanf("%d", &j);
          j -= 1;
          if (j < 0 || j > (lng - 1))
            continue;
          strcpy(newT.sp, sp[j]);
          printf("\t\t%d --> %s\n", j + 1, sp[j]);
          break;
        } while (true);
        printf("\tYear of employment: ");
        scanf("%d", &newT.ar);

        // Modules
        j = 0;
        do {
          char c = 'n';
          printf("\tmodule %d:\n", j + 1);
          printf("\t\t%-16s ", "code of module:");
          scanf("%s", &newT.module[j].code);
          printf("\t\t%-16s ", "The module name:");
          scanf("%s", &newT.module[j].name);
          if (j == 0) {
            printf("\t\tDo you want to enter a new module. y/n?: ");
            scanf("%s", &c);
          }

          newT.module[1].name[0] = '/';
          newT.module[1].name[1] = '\0';
          if (c == 'n')
            break;
          j++;
        } while (true);

        // Charge
        printf("\tCharge:\n");
        printf("\t\tcours: ");
        scanf("%d", &newT.charge.cours);
        printf("\t\tTD:    ");
        scanf("%d", &newT.charge.td);
        printf("\t\tTP:    ");
        scanf("%d", &newT.charge.tp);
        int i2;

        /*
            for(i=n;(i>0)&&(a[i-1]>val);i--)
                a[i]=a[i-1];
            a[i]=val;
        */

        for (i2 = ne; i2 > 0; i2--) {
          k = 0;
          int i3 = 0;
          for (; sortEns[i2 - 1].lastn[i3] == newT.lastn[i3] &&
                 sortEns[i2 - 1].lastn[i3] != '\0';
               i3++) {
          }
          if (sortEns[i2 - 1].lastn[i3] > newT.lastn[i3])
            k = 1;
          if (k != 1)
            break;
          sortEns[i2] = sortEns[i2 - 1];
          printf("%d | ", i3);
          // printf("%d,%d   ", i2, strcmp(sortEns[i2-1].lastn, newT.lastn));
        }
        sortEns[i2] = newT;

        ens[ne] = newT;
        ne += 1;
      }

      for (i = 0; i < ne; i++) {
        printf("\n%s", sortEns[i].lastn);
      }

      break;
    }

    printf("\nAre you have another choise? y/n: ");
    scanf("%s", &isr);
    if (isr != 'y') {
        printf("\nAre you sure? y/n: ");
        scanf("%s", &isr);
        if (isr == 'y' || isr == 'Y') isr = 'n';
        else isr = 'y';
    }
  } while (isr == 'y' || isr == 'Y');

  return 0;
}