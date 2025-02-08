#include <stdio.h>
#include <string.h>
// #include <conio.h>
void welcome(void);
int main_menu(void);
int teacher_login(void);
int student_login(void);
int developers(void);
int teacher_menu(void);
int student_menu(void);

void search_student();// done !!
void searchByRoll(); // done!!
void searchByName(); // done!!
void student_details(); // done!!
void add_student(); // done!!
void edit_student_info(); //done!!
void delete_student(); //done !!
void add_exam_marks(); // done !!
void see_result();
void all_result(); // done !!
float gpa(float b, float e, float m, float s);

struct student
{
    char name[50];
    char cls[10];
    int roll;
}s;
FILE *fp; // file pointer to keep records of all students
long sz = sizeof(s);

struct exam
{
    int roll;
    float bangla;
    float english;
    float math;
    float science;
}e;
FILE *ep; // exam pointer to collect and preserve all exam nubbers

float result[10007];

int main(void)
{
    int x;
    system("cls"); // clear screen
    welcome();

START:
    while(1)
    {
        //x = 0;
        x = main_menu();/*Return value meanings
                        //0 == Exit //-1 == go back to main menu //1 == Teacher login approved //2 == student Login approved*/
        //printf("x = %d", x);

        switch(x)
        {
        case 0:
            goto END;
            break;
        case -1:
            continue;
            break;
        case 1:
            teacher_menu();
            break;
        case 2:
            student_menu();
            break;
        }
    }


END:
    system("cls");
    end();
    return 0;
}



//Welcome
void welcome(void)
{
    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    for(int i = 0; i < 39; i++)
    {
        printf("*");
    }
    printf("\n");

    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("|");
    for(int i = 0; i < 37; i++)
    {
        printf(" ");
    }
    printf("|\n");

    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("|");
    //welcome to
    for(int i = 0; i < 13; i++)
    {
        printf(" ");
    }
    printf("Welcome to");
    for(int i = 0; i < 14; i++)
    {
        printf(" ");
    }
    printf("|\n");

    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("|");
    //Daffodil Student Management App
    for(int i = 0; i < 3; i++)
    {
        printf(" ");
    }
    printf("Daffodil Student Management App");
    for(int i = 0; i < 3; i++)
    {
        printf(" ");
    }
    printf("|\n");

    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("|");
    for(int i = 0; i < 37; i++)
    {
        printf(" ");
    }
    printf("|\n");

    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    for(int i = 0; i < 39; i++)
    {
        printf("*");
    }
    printf("\n\n\n\n\n\n\n\n");
    system("pause"); // pause the screen and press any button to continue

}

void end(void)
{
    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    for(int i = 0; i < 39; i++)
    {
        printf("*");
    }
    printf("\n");

    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("|");
    for(int i = 0; i < 37; i++)
    {
        printf(" ");
    }
    printf("|\n");

    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("|");
    //welcome to
    for(int i = 0; i < 13; i++)
    {
        printf(" ");
    }
    printf("Thank you for using");
    for(int i = 0; i < 14; i++)
    {
        printf(" ");
    }
    printf("|\n");

    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("|");
    //Daffodil Student Management App
    for(int i = 0; i < 3; i++)
    {
        printf(" ");
    }
    printf("Daffodil Student Management App");
    for(int i = 0; i < 3; i++)
    {
        printf(" ");
    }
    printf("|\n");

    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    printf("|");
    for(int i = 0; i < 37; i++)
    {
        printf(" ");
    }
    printf("|\n");

    for(int i = 0; i < 40; i++)
    {
        printf(" ");
    }
    for(int i = 0; i < 39; i++)
    {
        printf("*");
    }
    printf("\n\n\n\n\n\n\n\n");
    system("pause"); // pause the screen and press any button to continue

}

int main_menu(void)
{

    int op, pannel, z;
    do
    {
        system("cls");
        printf("\t\t\t\t----------------------------------------------------\n");
        printf("\t\t\t\t\t\t      Main Menu                     \n");
        printf("\t\t\t\t----------------------------------------------------\n");
        printf("\t\t\t\tPress: ");
        printf("\n\t\t\t\t1. Teacher Login.");
        printf("\n\t\t\t\t2. Student Login.");
        printf("\n\t\t\t\t3. Know about the developers.");
        printf("\n\t\t\t\t0. Exit.");
        printf("\n\nEnter your choice: ");

        scanf("%d", &op);

    }
    while (op < 0 || op > 3);

    switch(op)
    {
    case 0:
        //system("cls");
        return 0;
        break;
    case 1:
        system("cls");
        return teacher_login(); // return 1(Teacher approved)
        break;
    case 2:
        system("cls");
        return student_login();
        break;
    case 3:
        return developers();
        break;
    }
}

int teacher_login(void)// If return is 1, that means both ID and Pass are correct. // If return is -1, them user want to exit.
{
    system("cls");
    printf("\t\t\t\t-------------------------------------------------------\n");
    printf("\t\t\t\t\t\t      Teacher Login                     \n");
    printf("\t\t\t\t-------------------------------------------------------\n");
    printf("\t\t\t\t\t    (Enter 0 to go back to Main Menu)\n");

Teacher_ID:
    printf("\nEnter your ID      : ");
    int id;
    scanf("%d", &id);
    const int ID = 123456;
    if(id == 0)
    {
        return -1;
    }
    else if(id == ID)
    {
        goto Teacher_pass;
    }
    else
    {
        printf("Wrong ID!\n");
        goto Teacher_ID;
    }

Teacher_pass:
    printf("Enter your Password: ");
    int pass;
    scanf("%d", &pass);
    const int PASS = 123456;
    if(pass == 0)
    {
        return -1;
    }
    else if(pass == PASS)
    {
        return 1;
    }
    else
    {
        printf("Wrong pass!\n");
        goto Teacher_pass;
    }
}

int student_login(void)
{
    system("cls");
    printf("\t\t\t\t-------------------------------------------------------\n");
    printf("\t\t\t\t\t\t      Student Login                     \n");
    printf("\t\t\t\t-------------------------------------------------------\n");
    printf("\t\t\t\t\t    (Enter 0 to go back to Main Menu)\n");

Student_ID:
    printf("\nEnter your ID      : ");
    int id;
    scanf("%d", &id);
    const int ID = 123456;
    if(id == 0)
    {
        return -1;
    }
    else if(id == ID)
    {
        goto Student_pass;
    }
    else
    {
        printf("Wrong ID!\n");
        goto Student_ID;
    }

Student_pass:
    printf("Enter your Password: ");
    int pass;
    scanf("%d", &pass);
    const int PASS = 123456;
    if(pass == 0)
    {
        return -1;
    }
    else if(pass == PASS)
    {
        return 2;
    }
    else
    {
        printf("Wrong pass!\n");
        goto Student_pass;
    }
}

int developers(void)
{
    int a;
    system("cls");
    printf("\t\t\t\t-------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    Developers list                     \n");
    printf("\t\t\t\t-------------------------------------------------------\n");

    printf("\nName   : Md. Nawshin Zaman\nID     : 0242310005101554\nSection: 64_A\nContact: 01996707921\n");
    printf("\nName   : Md. Rafiur Rahman\nID     : 0242310005101857\nSection: 64_A\nContact: 01783290879\n");
    printf("\nName   : Md. Rajibul Alam Rajib\nID     : 0242310005101812\nSection: 64_A\nContact: 01310511163\n");
    printf("\nName   : Md. Parvez Kabir Sakib\nID     : 0242310005101470\nSection: 64_A\nContact: 01761612529\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("\nPress:");
    printf("\n0.To Go Back\n1.To exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &a);

    if (a == 0)
    {
        return -1;
    }
    else if (a == 1)
    {
        return 0;
    }
}

int teacher_menu(void)
{
    while(1)
    {
        int op;

        system("cls");
        printf("\t\t\t\t-------------------------------------------------------\n");
        printf("\t\t\t\t\t\t      Teacher's Menu                     \n");
        printf("\t\t\t\t-------------------------------------------------------\n\n");
        printf("\t\t\t\tPress: ");
        printf("\n\t\t\t\t1. Search Student.");
        printf("\n\t\t\t\t2. Add Student.");
        printf("\n\t\t\t\t3. Delete Student.");
        printf("\n\t\t\t\t4. Watch Students details.");
        printf("\n\t\t\t\t5. Add exam marks.");
        printf("\n\t\t\t\t6. See Result.");
        printf("\n\t\t\t\t7. Edit Student Info.");
        printf("\n\t\t\t\t8. Logout.");
        printf("\n\nEnter your choice: ");

        scanf("%d", &op);

        switch(op)
        {
        case 1:
            search_student();
            break;
        case 2:
            add_student();
            break;
        case 3:
            delete_student();
            break;
        case 4:
            student_details();
            break;
        case 5:
            add_exam_marks();
            break;
        case 6:
            see_result();
            break;
        case 7:
            edit_student_info();
            break;
        case 8:
            return -1;
            break;
        }
    }

}

int student_menu(void)
{
    while(1)
    {
        int op;

        system("cls");
        printf("\t\t\t\t----------------------------------------------------\n");
        printf("\t\t\t\t\t\t      Student's Menu                     \n");
        printf("\t\t\t\t----------------------------------------------------\n\n");
        printf("\t\t\t\tPress: ");
        printf("\n\t\t\t\t1. Search Student.");
        printf("\n\t\t\t\t2. Watch Students details.");
        printf("\n\t\t\t\t3. See Result.");
        printf("\n\t\t\t\t4. Logout.");
        printf("\n\nEnter your choice: ");

        scanf("%d", &op);

        switch(op)
        {
        case 1:
            search_student();
            break;
        case 2:
            student_details();
            break;
        case 3:
            see_result();
            break;
        case 4:
            return -1;
            break;
        }
    }
}

void search_student()
{
    //system("cls");
    //printf("\t\t\t\t----------------------------------------------------\n");
    //printf("\t\t\t\t\t\t   Searching Student                     \n");
    //printf("\t\t\t\t----------------------------------------------------\n\n");

    int ch;
    while(1)
    {
        system("cls");
        printf("\t\t\t\t----------------------------------------------------\n");
        printf("\t\t\t\t\t\t   Searching Student                     \n");
        printf("\t\t\t\t----------------------------------------------------\n\n");

        printf("1. Search By Roll\n");
        printf("2. Search By Name\n");
        printf("0. Go Back to main menu\n");

        printf("Enter your choice: ");

        scanf("%d", &ch);
        if (ch == 0) break;
        switch(ch)
        {
        case 1:
            searchByRoll();
            break;
        case 2:
            searchByName();
            break;

        default:
            printf("Invalid choice.........");
            break;
        }
    }
}

void searchByRoll()
{
    int roll, f = 0;
    printf("Enter your Roll: ");
    scanf("%d", &roll);
    printf("%-30s %-20s %-10s\n", "Name", "Class", "Roll");

    fp = fopen("student.txt", "rb");
    while(fread(&s, sz, 1, fp) == 1)
    {
        if (s.roll == roll)
        {
            printf("%-30s %-20s %-10d\n", s.name, s.cls, s.roll);
            f = 1;
            break;
        }
    }
    fclose(fp);

    if(f == 0)
    {
        printf("Student not found.\n");
    }
    else
    {
        printf("Student found successfully.\n");
    }
    system("pause");
}

void searchByName()
{
    char name[50];
    int f = 0;
    printf("Enter your Name: ");
    fflush(stdin);
    fgets(name, 50, stdin);

    ///manipulating the string scanned by fgets to remove the enter at last.
    int n = strlen(name);
    name[n-1] = '\0';
    ///manipulation done!

    printf("%-30s %-20s %-10s\n", "Name", "Class", "Roll");

    fp = fopen("student.txt", "rb");
    while(fread(&s, sz, 1, fp) == 1)
    {
        if (strcmpi(s.name, name) == 0)
        {
            printf("%-30s %-20s %-10d\n", s.name, s.cls, s.roll);
            f = 1;
            break;
        }
    }
    fclose(fp);

    if(f == 0)
    {
        printf("Student not found.\n");
    }
    else
    {
        printf("Student found successfully.\n");
    }
    system("pause");
}

void add_student()
{
    system("cls");
    printf("\t\t\t\t----------------------------------------------------\n");
    printf("\t\t\t\t\t\t   Adding New Student                     \n");
    printf("\t\t\t\t----------------------------------------------------\n\n");

    //char myDate[121];

    fp = fopen("student.txt", "ab"); ///Open for append in binary mode. // this means we can write data in this file
    printf("Enter Student Name: ");
    fflush(stdin); //this clears my buffer memory before taking the next input from user
    fgets(s.name, 50, stdin);

    ///manipulating the string scanned by fgets to remove the enter at last.
    int n = strlen(s.name);
    s.name[n-1] = '\0';
    ///manipulation done!
    //scanf("%[^\n]s", s.name);
    fflush(stdin);
    printf("Enter student class: ");
    fflush(stdin);
    scanf("%s", s.cls);
    printf("Enter Roll: ");
    scanf("%d", &s.roll);
    fwrite(&s, sz, 1, fp); //fwrite is the function to write data inside file.
                           ///fwrite(adress_of_s_variable, sizeof(s), number_of_input, address of file pointer);
    printf(" Record saved successfully ....\n");
    fclose(fp); // closes my file with pointer fp
    system("pause");
    //Work of add new student is done!!!
}

void delete_student()
{
    system("cls");
    printf("\t\t\t\t----------------------------------------------------\n");
    printf("\t\t\t\t\t\t   Deleting Student                     \n");
    printf("\t\t\t\t----------------------------------------------------\n\n");

    int roll, f = 0;
    printf("Enter Roll to Delete: ");
    scanf("%d", &roll);

    fp = fopen("student.txt", "rb+");

    FILE *ft;
    ft  = fopen("temp.txt", "ab+");

    while(fread(&s, sz, 1, fp) == 1)
    {
        if (s.roll == roll)
        {
            f = 1;
        }
        else
        {
            fwrite(&s, sz, 1, ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("student.txt");
    rename("temp.txt", "student.txt");

    if(f == 0)
    {
        printf("Record not found.\n");
    }
    else
    {
        printf("Record Deleted successfully.\n");
    }

    system("pause");
}
void student_details()
{
    system("cls");
    printf("\t\t\t\t----------------------------------------------------\n");
    printf("\t\t\t\t\t\t   All Students details                     \n");
    printf("\t\t\t\t----------------------------------------------------\n\n");

    printf("%-30s %-20s %-10s\n", "Name", "Class", "Roll");

    fp = fopen("student.txt", "rb"); /// rb is read in binary mode
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("%-30s %-20s %-10d\n", s.name, s.cls, s.roll);
    }

    fclose(fp);
    system("pause");

    //work of seeing all students at a time is done.
}

void edit_student_info()
{
    system("cls");
    printf("\t\t\t\t----------------------------------------------------\n");
    printf("\t\t\t\t\t\t   Update Student Info                     \n");
    printf("\t\t\t\t----------------------------------------------------\n\n");

    int roll, f = 0;
    printf("Enter Roll to modify: ");
    scanf("%d", &roll);

    fp = fopen("student.txt", "rb+");
    while(fread(&s, sz, 1, fp) == 1)
    {
        if (s.roll == roll)
        {
            f = 1;
            printf("Enter New Name: ");
            fflush(stdin); //this clears my buffer memory before taking the next input from user
            fgets(s.name, 50, stdin);

            ///manipulating the string scanned by fgets to remove the enter at last.
            int n = strlen(s.name);
            s.name[n-1] = '\0';
            ///manipulation done!

            printf("Enter new Class: ");
            fflush(stdin);
            scanf("%s", s.cls);
            printf("Enter new Roll: ");
            scanf("%d", &s.roll);

            fseek(fp, -sz, 1);
            fwrite(&s, sz, 1, fp);
            fclose(fp);
            break;
        }
    }


    if(f == 0)
    {
        printf("Record not found.\n");
    }
    else
    {
        printf("Record Modified successfully.\n");
    }
    system("pause");
}



void add_exam_marks()
{
    system("cls");
    printf("\t\t\t\t----------------------------------------------------\n");
    printf("\t\t\t\t\t\t   Exam Marks                     \n");
    printf("\t\t\t\t----------------------------------------------------\n\n");

    ep = fopen("exam.txt", "ab");// file opening in append in binary mode
    fp = fopen("student.txt", "rb");

    int temp_roll;
    printf("Enter students roll: ");
    scanf("%d", &temp_roll);

    ///Checking is the Student Exist in my student list
    int f = 0;

    while(fread(&s, sz, 1, fp) == 1)
    {
        if (temp_roll == s.roll)
        {
            f = 1;
        }
    }
    fclose(fp);

    if(f == 0)
    {
        printf("Student Not found.\n");
        system("pause");
        return;
    }

    ep = fopen("exam.txt", "ab");

    e.roll = temp_roll;

    printf("Enter Marks for Bangla: ");
    scanf("%f", &e.bangla);

    printf("Enter Marks for English: ");
    scanf("%f", &e.english);

    printf("Enter Marks for Math: ");
    scanf("%f", &e.math);

    printf("Enter Marks for Science: ");
    scanf("%f", &e.science);

    fwrite(&e, sizeof(e), 1, ep);
    fclose(ep);
    printf("\n\n\n\n\nResult for Roll \"%d\" has been added successfully.\n", e.roll);

    system("pause");
}

void see_result()
{
    int ch;
    while(1)
    {
        system("cls");
        printf("\t\t\t\t----------------------------------------------------\n");
        printf("\t\t\t\t\t\t   Result Board                     \n");
        printf("\t\t\t\t----------------------------------------------------\n\n");

        printf("1. Search By Roll\n");
        printf("2. See all Result\n");
        printf("0. Go Back to main menu\n");

        printf("Enter your choice: ");

        scanf("%d", &ch);
        if (ch == 0) break;
        switch(ch)
        {
        case 1:
            search_result_by_roll();
            break;
        case 2:
            all_result();
            break;

        default:
            printf("Invalid choice.........");
            break;
        }
    }
}


void search_result_by_roll()
{
    system("cls");
    printf("\t\t\t\t----------------------------------------------------\n");
    printf("\t\t\t\t\t\t   Individual GPA                     \n");
    printf("\t\t\t\t----------------------------------------------------\n\n");

    int roll;
    printf("Enter your roll: ");
    scanf("%d", &roll);

    for (int i = 1; i <= 10000; i++)
    {
        if (i == roll)
        {
            printf("The GPA of %d is: %.2f\n", i, result[i]);
        }
    }
    system("pause");
}



void all_result()
{
    ep = fopen("exam.txt", "rb");
    printf("%-20s %10s\n", "Roll", "GPA");
    while(fread(&e, sizeof(e), 1, ep) == 1)
    {
        result[e.roll] = gpa(e.bangla, e.english, e.math, e.science);
    }
    fclose(ep);

    for (int i = 1; i <= 10000; i++)
    {
        if(result[i] > 0)
        {
            printf("%-20d %10.2f\n", i, result[i]);
        }

    }


    system("pause");
}

float gpa(float b, float e, float m, float s)
{
    float ban = 0, en = 0, math = 0, sc = 0;

    ban = b > 50? (b > 69?(5):(4)):(b > 33?(3):(0));
    en = e > 50? (e > 69?(5):(4)):(e > 33?(3):(0));
    math = m > 50? (m > 69?(5):(4)):(m > 33?(3):(0));
    sc = s > 50? (s > 69?(5):(4)):(s > 33?(3):(0));

    if(ban == 0 || en == 0 || math == 0 || sc == 0)return 0.00;
    else return (ban + en + math + sc)/4.0;
}
