#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>
#include<dos.h>
struct customer{
    char ID[15];
    char name[20];
    char address[20];
    char color[20];
    char size[10];
    char date[20];
};

struct customer cus;

///This will set the forground color for printing in a console window.
void SetColor(int ForgC)
{
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     ///This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Password(void) //for password option
{

system("cls");
char d[25]="Password Protected";
char ch,pass[10];
char password[13]="123456";
char p[50]="Password Protected>>>";
int i=0,j;
//textbackground(WHITE);
//textcolor(RED);

/*for(j=0;j<10;j++)
{
Sleep(50);
printf("*");
}*/
/*for(j=0;j<20;j++)
{
Sleep(50);
printf("%c",d[j]);
}*/
for(j=0;p[j]!='\0';j++)
{
Sleep(50);
printf("%c",p[j]);
}

printf("\tEnter Password:");


while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{


//textcolor(BLINK);
//printf("Password match\t");

//printf("Press a key");
//getch();
window();
main_window();
}
else
{
gotoxy(15,16);
printf("\aWarning!! Incorrect Password");
getch();
Password();
}
}


void drawRectangle(){
    printf("\n\n\n\n\n\n\n\n\n\n");
    int i, j;
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 78; i++){
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(78,0);
    printf("%c",187);
    for(i = 1; i < 25; i++){
        gotoxy(78, i);
        if(i == 6){
            printf("%c",185);
        }else{
            printf("%c",186);
        }
    }
    gotoxy(78, 25);
    printf("%c",188);
    for(i = 77; i > 0; i--){
        gotoxy(i,25);
        if(i == 35){
            printf("%c",202);
        }else{
            printf("%c",205);
        }
    }
    gotoxy(0,25);
    printf("%c",200);
    for(i = 24; i > 0; i--){
        gotoxy(0,i);
        if(i == 6){
            printf("%c",204);
        }else{
            printf("%c",186);
        }
    }

    for(i = 1; i < 78; i++){
        gotoxy(i,6);
        if(i == 35){
            printf("%c",203);
        }else{
            printf("%c",205);
        }
    }

    for(i = 7; i < 25; i++){
        gotoxy(35,i);
        printf("%c",186);
    }

}

void clearWindow(){
    int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            gotoxy(i,j);printf(" ");
        }
    }
    return;
}

void window(){
    printf("\n\n\n\n\n\n\n\n\n\n");
    drawRectangle();
    gotoxy(28,2);
    SetColor(18);
    printf("Billing Management System");
    gotoxy(30,3);
    printf("BUBT, Dhaka, Mirpur");
    gotoxy(31,4);
    SetColor(17);

}



void sell_product(){
    clearWindow();
    //print_heading("Add Record");
    int print = 37;
    FILE *fp;
    fp = fopen("record.txt","ab+");
    SetColor(18);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }else{
        fflush(stdin);
        gotoxy(print,10);printf("ID: ");gets(cus.ID);
        //here you can confirms the ID
        gotoxy(print,12);printf("Name: ");gets(cus.name);
        gotoxy(print,14);printf("Address: ");gets(cus.address);
        gotoxy(print,16);printf("Color: ");gets(cus.color);
        gotoxy(print,18);printf("Size: ");gets(cus.size);
        gotoxy(print,20);printf("Date: ");gets(cus.date);
        fwrite(&cus, sizeof(cus), 1, fp);
        gotoxy(40,22); printf("The product is  sold");
    }
    SetColor(28);
    fclose(fp);
    return;
}

void search_record(){
    clearWindow();
    //print_heading("Search Record");
    SetColor(18);
    char s_id[15];
    int isFound = 0;
    gotoxy(37,10);printf("Enter Customer ID to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&cus,sizeof(cus),1,fp) == 1){
        if(strcmp(s_id,cus.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(37,12);printf("The record is Found");
        gotoxy(37,14);printf("ID: %s",cus.ID);
        gotoxy(37,15);printf("Name: %s",cus.name);
        gotoxy(37,16);printf("Address: %s",cus.address);
        gotoxy(37,17);printf("Color: %s",cus.color);
        gotoxy(37,18);printf("Size: %s",cus.size);
        gotoxy(37,19);printf("Date: %s",cus.date);
    }else{
        gotoxy(37,12);printf("Sory, No record found in the database");
    }
    SetColor(28);
    fclose(fp);
    return;
}



exchange_product(){
    clearWindow();
    //print_heading("Modify Record");
    SetColor(18);
    char s_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);printf("Enter ID to Exchange: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");
    while(fread(&cus, sizeof(cus),1,fp) == 1){
        if(strcmp(s_id, cus.ID) == 0){
            fflush(stdin);
            gotoxy(print,12);printf("ID: ");gets(cus.ID);
            gotoxy(print,14);printf("Name: ");gets(cus.name);
            gotoxy(print,16);printf("Address: ");gets(cus.address);
            gotoxy(print,18);printf("Color: ");gets(cus.color);
            gotoxy(print,20);printf("Size: ");gets(cus.size);
            gotoxy(print,22);printf("Date: ");gets(cus.date);
            fseek(fp,-sizeof(cus), SEEK_CUR);
            fwrite(&cus,sizeof(cus), 1, fp);
            gotoxy(42,22); printf("The product is exchanged");
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        gotoxy(print, 12);printf("No Record Found");
    }
    fclose(fp);
    SetColor(28);
    return;
}

void generate_bill(){
    clearWindow();
    //print_heading("Search Record");
    SetColor(18);
    char s_id[15];
    int isFound = 0;
    gotoxy(37,10);printf("Enter Customer ID to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&cus,sizeof(cus),1,fp) == 1){
        if(strcmp(s_id,cus.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(37,12);printf("************ Thank you ************");
        gotoxy(37,14);printf("ID: %s",cus.ID);
        gotoxy(37,15);printf("Name: %s",cus.name);
        gotoxy(37,16);printf("Address: %s",cus.address);
        gotoxy(37,17);printf("Color: %s",cus.color);
        gotoxy(37,18);printf("Size: %s",cus.size);
        gotoxy(37,19);printf("Date: %s",cus.date);
        gotoxy(37,21);printf("************ Thank you ************");
    }else{
        gotoxy(37,12);printf("Sory, No record found in the database");
    }
    SetColor(28);
    fclose(fp);
    return;
}



void main_window(){
    int choice;
    SetColor(18);
    int x = 2;
    while(1){
        gotoxy(x,8);printf("1. Sell a product");
        gotoxy(x,10);printf("2. Search customer record");
        gotoxy(x,12);printf("3. Exchange a product");
        gotoxy(x,14);printf("4. Generate bill");
        gotoxy(x,16);printf("5. Exit");
        gotoxy(x,18);printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                sell_product();
                break;
            case 2:
                search_record();
                break;
             case 3:
                exchange_product();
                break;
             case 4:
                generate_bill();
                break;
            default:
                break;
        }

}}
int main(){


    ClearConsoleToColors(18,16);
    SetConsoleTitle("Billing System");
    Password();
    //window();
    //main_window();
    return 0;
}

