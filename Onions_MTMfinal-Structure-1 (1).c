
#include <stdio.h>

#include <stdlib.h>
void homeMenu()
{
tome:
    system("cls");
    int aa,ab,ac;
    printf("\t\t\t\t==================================================\t\n");
    printf("\t\t\t\t..................................................\t\n\n");

    printf("\t\t\t\t|                 Onions Cineplex                 |\t\n");

    printf("\t\t\t\t|                ------------------               |\t\n");

    printf("\t\t\t\t|              Savar,Dhaka,Bangladesh             |\t\n\n");
    printf("\t\t\t\t..................................................\t\n");

    printf("\t\t\t\t==================================================\t\n\n\n");



    printf("\t\t\t\t\t\t Select User Option \t\t\n\n");
    printf("\t\t\t____________________________________________________________________\t\t\t\n");
    printf("\t\t\t|\t\t\t\t          \t\t\t    |\n");
    printf("\t\t\t|\t\t\t\t          \t\t\t    |\n");

    printf("\t\t\t|            1 ) Admin\t\t\t\t2 ) Customer        |\n");
    printf("\t\t\t|\t\t\t\t          \t\t\t    |\n");

    printf("\t\t\t|\t\t\t3 ) About Developers\t\t\t    |\n");
    printf("\t\t\t|\t\t\t\t          \t\t\t    |\n");

    printf("\t\t\t|___________________________________________________________________|\t\t\t\n\n");
    printf("Choose your option : ");
    scanf("%d",&aa);
    getchar();
    if(aa==1)
    {

        adminMode();
    }

    else if(aa==2)
    {
        customerMode();
    }
    else if(aa==3)
    {
        aboutDev();
    }

    else
    {
        goto tome;

    }
}
void adminMode()
{
    system("cls");
    int ab;
    int ac;
tome2:
    system("cls");
    printf("\nWelcome to Admin Panel!!!\n\n\n");
    printf("1 ) Login\n\n");

    printf("2 ) Back to Select User Option\n\n");

    printf("Choose your Option : ");
    scanf("%d",&ab);

    getchar();

    if(ab==1)
    {

        system("cls");
        char cha[25],passs[20];

        printf("\t\t\t\t\t     ------------------------\t\n");
        printf("\t\t\t\t\t    |      ADMIN MODE        |\t\n");
        printf("\t\t\t\t\t     ------------------------\t\n");

        printf("\n Please Enter User Name : ");
        fgets(cha,25,stdin);
        fflush(stdin);
        printf("\n Please Enter User Password : ");
        for(int i=0; i<20; i++)
        {

            gets(passs);
            //pass - 1234

            if (strcmp(passs,"1234") == 0)             // use strcmp to compare strings
            {
                printf("\n\nWelcome!\n\n");
                break;
            }
            else
            {
                printf("\nInvalid password\n\n");
                printf("\n Please Enter User Password : ");

            }
        }
tome1:
        system("cls");
        printf("\n1 ) Add Movies\n");
        printf("2 ) Login as Customer\n");
        printf("3 ) Set Show Time \n");
        printf("4 ) View Movies \n");
        printf("5 ) Delet Movies\n");
        printf("6 ) Logout\n\n");
        printf("Enter your choice : ");
        scanf("%d",&ac);

        if(ac==1) //add movies
        {
            addMovie();

            goto tome1;

        }
        else if(ac==2)
        {
            system("cls");

            customerMode();
        }
        else if(ac==3)
        {
            system("cls");

            printf("\n11:00 am\n\n2:00pm\n\n5:00pm\n\n9:00pm\n");
            printf("\nPress any key to back admin menu ...\n");
            getch();

            goto tome1;



        }
        else if (ac == 4)
        {
            int cc=0;
            viewMovie(cc);
            goto tome1;
        }

        else if(ac==5)

        {
            //delet movie
            deletMovie();

            goto tome1;


        }
        else if(ac==6) /*logout*/
        {
            system("cls");
            printf("Logout Successful !\n");

            printf("\nPress any key to back admin menu ...\n");

            getch();

            goto tome2;


        }
        else
        {
            system("cls");
            printf("Invalid Choice\n");
            printf("\nPress any key to back admin menu ...\n");
            getch();
        }
    }

    else if(ab==2)  //back to user manu
    {

        homeMenu();
        getch();

        goto tome2;

    }
    else
    {
        goto tome2;
    }
}

struct Movie
{
    char code[50];
    char name[50];
    char genre[50];
    char director[50];
    char releaseDate[20];
} movie;

FILE *fp;

void addMovie()
{
    system("cls");
    printf("\t\t\t\t----------------------------------------------------\n");
    printf("\t\t\t\t\t\t   Add New Movie                          \n");
    printf("\t\t\t\t----------------------------------------------------\n\n");


    fp=fopen("movies.txt","ab");
    printf("Enter Movie Code : ");
    fflush(stdin);
    fgets(movie.code,50,stdin);

    int n=strlen(movie.code);

    movie.code[n-1] = '\0';

    getchar();

    printf("\n\nName : ");
    fflush(stdin);
    fgets(movie.name,50,stdin);

    n=strlen(movie.name);

    movie.name[n-1] = '\0';

    getchar();

    printf("Genre : ");
    fflush(stdin);
    fgets(movie.genre,50,stdin);

    n=strlen(movie.genre);

    movie.genre[n-1] = '\0';

    getchar();

    printf("Director : ");
    fflush(stdin);
    fgets(movie.director,50,stdin);

    n=strlen(movie.director);

    movie.director[n-1] = '\0';

    getchar();

    printf("Release Date : ");
    fflush(stdin);
    fgets(movie.releaseDate,50,stdin);

    n=strlen(movie.releaseDate);

    movie.releaseDate[n-1] = '\0';

    fflush(stdin);

    fwrite(&movie,sizeof(movie),1,fp);

    printf("New Movie Added!\n\nPress enter to go back...\n");

    fclose(fp);


    system("pause");
}

void viewMovie(int cc)
{

    system("cls");

    printf("\t\t\t\t----------------------------------------------------\n");
    printf("\t\t\t\t\t\t   Movie Details                     \n");
    printf("\t\t\t\t----------------------------------------------------\n\n");

    fp=fopen("movies.txt","rb");

    while (fread(&movie,sizeof(movie),1,fp)==1)
    {
        printf("Movie Code   : %s\n",movie.code);
        printf("Movie Name   : %s\n",movie.name);
        printf("Movie Genre  : %s\n",movie.genre);
        printf("Director     : %s\n",movie.director);
        printf("Release Date : %s\n\n",movie.releaseDate);
    }

    fclose(fp);
    if( cc>=1)  //search by code
    {
        char code[50];
        int f = 0;
        printf("Enter your Code: ");
        scanf("%s", code);

        fp = fopen("movies.txt", "rb");
        while (fread(&movie, sizeof(movie), 1, fp) == 1)
        {
            if (strcmp(movie.code, code) == 0)   // use strcmp to compare strings
            {
                printf("\t\t\t\t----------------------------------------------------\n");
                printf("\t\t\t\t\t\t   Movie Details                     \n");
                printf("\t\t\t\t----------------------------------------------------\n\n");
                printf("Movie Code   : %s\n", movie.code);
                printf("Movie Name   : %s\n", movie.name);
                printf("Movie Genre  : %s\n", movie.genre);
                printf("Director     : %s\n", movie.director);
                printf("Release Date : %s\n", movie.releaseDate);
                cc = 0;
                break;
            }
        }
        fclose(fp);
        system("pause");
        seatPlan();
    }

    system("pause");
}

void deletMovie()
{
    FILE *fp, *ft;
    struct Movie movie;
    char code[50];
    int found = 0;

    printf("\t\t\t\t----------------------------------------------------\n");
    printf("\t\t\t\t\t\t   Deleting Movie                     \n");
    printf("\t\t\t\t----------------------------------------------------\n\n");

    printf("Enter movie code to delete: ");
    fflush(stdin);
    fgets(code, 50, stdin);
    code[strcspn(code, "\n")] = '\0'; // Remove newline character

    fp = fopen("movies.txt", "rb");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    ft = fopen("temp.txt", "wb");
    if (ft == NULL)
    {
        printf("Unable to open temporary file.\n");
        fclose(fp);
        return;
    }

    while (fread(&movie, sizeof(struct Movie), 1, fp) == 1)
    {
        if (strcmp(movie.code, code) == 0)
        {
            found = 1;
        }
        else
        {
            fwrite(&movie, sizeof(struct Movie), 1, ft);
        }
    }

    fclose(fp);
    fclose(ft);

    if (found)
    {
        remove("movies.txt");
        rename("temp.txt", "movies.txt");
        printf("Movie with code '%s' deleted successfully.\n", code);
        system("pause");
    }
    else
    {
        printf("Movie with code '%s' not found.\n", code);
        system("pause");
    }
}

void aboutDev()
{

    system("cls");
    printf("\n\n\t\t\t\t\t    |      About Developers       |\t\n");
    printf("1 ) Rifat Parvej Pranto\n");
    printf("Project Leader,Onions\n");
    printf("Dept. of CSE , DIU\n\n");
    printf("2 ) Biltu Rahman\n");
    printf("Project Executive,Onions\n");
    printf("Dept. of CSE , DIU\n\n");
    printf("3 ) James Amin Jhon\n");
    printf("Project Executive,Onions\n");
    printf("Dept. of CSE , DIU\n\n");
    printf("4 ) Habiba Sultana Bubly\n");
    printf("Project Executive,Onions\n");
    printf("Dept. of CSE , DIU\n\n");

    system("pause");
    homeMenu();
}


void customerMode()
{
    //Main customer Mode for user id & password{
    //start
    system("cls");

    int user_id;
    char ch[100],pass[20];

    printf("\t\t\t\t\t     ------------------------\t\n");
    printf("\t\t\t\t\t    |      CUSTOMER MODE     |\t\n");
    printf("\t\t\t\t\t     ------------------------\t\n");
    getchar();

    printf("\n Please Enter User Name : ");
    fgets(ch,100,stdin);
    getchar();
    printf("\n Please Enter User Password : ");
    for(int i=0; i<20; i++)
    {
        int cc=0;
        gets(pass);


        if (strcmp(pass,"6789") == 0)             // use strcmp to compare strings
        {
            printf("\n\nWelcome!\nLogin Successful!\n\n");
            system("pause");

            cc++;
            viewMovie(cc);
        }
        else
        {
            printf("\nInvalid password\n\n");
            printf("\n Please Enter User Password : ");

        }

    }
}                                                                              //finish

//start
void showTime()
{
    system("cls");
print1:
    printf("Select Showtime Please - \n\n");      //show time selection m1
    printf("Press 1 for 11:00 am show \n");
    printf("Press 2 for 02:30 am show \n");
    printf("Press 3 for 06:00 am show \n");

    printf("Press 4 for 09:30 am show \n");
    int m;
    printf("Enter choice : ");
    scanf("%d",&m);
    if(m<=4 && m>=1)
    {
        if(m==1)
        {
            printf("Great!You select 11:00 am show.\n");getch();
        }
        else if(m==2)
        {
            printf("Great!You select 02:30 pm show.\n");
        }
        else if(m==3)
        {
            printf("Great!You select 06:00 pm show.\n");
        }
        else if(m==4)
        {
            printf("Great!You select 09:30 pm show.\n");
        }
    }
    else
    {
        goto print1;
    }
}


void seatPlan()                                  //seatPlan
{
    showTime();
    system("cls");
    char seat[40][40];                                  //2D array
    int sNum,ticq;
    int am,vv,cc=0;
nn:
    printf("Please Select your TIcket Type : \n\n\n");

    printf("1 ) Normal Ticket - 500 Taka\n\n");

    printf("2 ) Premium Ticket - 600 Taka\n");

    printf("\nPress 0 To Go Back\n");

    printf("\nGive Your Choice : ");

    scanf("%d",&am);
    if(am==0)
    {
        viewMovie(cc);

    }
    //start
    printf("\nTicket Quatity : ");
    scanf("%d",&ticq);
    if(ticq>=0 && ticq<=500)
    {
        printf("\nPlease Enter Seat Code(Example-A1 A2) : ");                //A1,A2
        for(int i=0; i<ticq; i++)
        {

            scanf("%s",&seat[i]);

        }
        if(am==1)
        {

            am=500;
            vv=am*ticq;
        }

        else if(am==2)
        {

            am=600;
            vv=am*ticq;
        }
        else if(am>=3)
        {

            goto nn;

        }

    }
    printf("Your booked seats : ");
    for(int i=0; i<ticq; i++)
    {
        printf("%s ",seat[i]);
    }
    printf("\n\nTotal Due : %d Taka\n",vv);
    system("pause");
    vv=0;
    am=0;
    ticketPrice();
}
void ticketPrice()
{

    int o,q,r,s;
    char tranCode[15],email[50],myName[20];
    system("cls");
    printf("\nYou have 15 minutes for payment.Pay now to secure your booked seat otherwise your booked seat will be canceled.\n");
    printf("You can pay through online with Bkash,Nagad,Rocket.Or you can also pay through offline directory by our staff \n");

//ptintf("\n");
print6:

    printf("Select your payment option :\n");
    printf("1 : Online payment\n");
    printf("2 : Offline Payment\n");
    scanf("%d",&o);
    if(o==1)                                        //user selected online payment
    {
me:
        system("cls");
        printf("Choose a platform:\n");
        printf("Press 1 : Bkash\n");
        printf("Press 2 : Nagad\n");

        scanf("%d",&q);                              //user selected payment medium
        if(q==1)
        {
            printf("Your phone number : ");
            scanf("%d",&r);
            getchar();
            printf("\nYour email address : ");

            scanf("%s",&email);
            getchar();
            printf("\nGive Transaction Code : ");
            scanf("%s",tranCode);
            getchar();
            printf("\nYour transaction code is valid.\nTicket will be sent to your email address as soon as possible.ThankYou!\n");
            system("pause");
            customerMode();

        }
        else if(q==2)
        {
            printf("Your phone number : ");
            scanf("%d",&r);
            getchar();

            printf("\nYour email address : ");

            scanf("%s",&email);
            getchar();
            printf("\nGive Transaction Code : ");
            scanf("%s",tranCode);
            getchar();
            printf("\n\nYour transaction code is valid.\nTicket will be sent to your email address as soon as possible.ThankYou!\n\n");
            system("pause");
            customerMode();

        }

        else
        {
            goto me;
        }
    }

    else if(o==2)
    {
        system("cls");
        getchar();
        printf("\nEnter Your Name : ");
        fgets(myName,20,stdin);


        printf("\nYour Phone Number : ");
        scanf("%d",&s);
        printf("\nYour email : ");
        scanf("%s",&email);
        printf("\n\nThankYou!You have booked your seat successfully.For any query contact 01981840999.\n\n\n");
        printf("\n");
        system("pause");
        customerMode();
    }

    else
    {
        goto print6;
    }
}

int main()
{
repeat:

    homeMenu();


    goto repeat;
}
// THE   END
