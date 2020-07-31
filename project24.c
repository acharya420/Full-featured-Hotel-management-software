#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
#include<time.h>
//declaring global variables
//initializing goto function
COORD coord ={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//structure to store restaurant bills and orders
struct restaurant//defining structure for restrurant
{
    char buffer[50];
    int choose;
    int food;
    int qty;
    int cost;
    int roomno;
};
//defining structure for hotel
struct costumer
{
    char buffer[100];
    int roomnum;
    char name[20];
  char id[20];
   char num[11];
    char address[30]
};

//global variables
void screenheader();//welcoming screen
void roomandfeatures();//see rooms and features
void roomavailability();//check room is available or not
void modify();//to update datas
void book();//make an entry
void costdetails();//see costumers informations
void food();//order foods
void restaurantbill();//see food bill
void roombill();//see room bill
void checkout();//delete after leaving hotel
void rescheck();

int main()
{
   screenheader();
    return 0;
}


//welcoming screen
void screenheader()
 {
     int ch;
   printf("\n                       :::::::::::::::::::::::::::::::::::::");
   printf("\n                       ::                                 ::");
   printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
   printf("\n                       ::     @                     @     ::");
   printf("\n                       ::     @      WELCOME TO     @     ::");
   printf("\n                       ::     @        ====         @     ::");
   printf("\n                       ::     @    HOTEL SCORPIO    @     ::");
   printf("\n                       ::     @                     @     ::");
   printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
   printf("\n                       ::       Home away from home       ::");
   printf("\n                       :::::::::::::::::::::::::::::::::::::\n\n");
   printf("\n");
   printf("                         Suryavinayak-7,Bhaktapur Ph:01-5090234,01-5090345 \n\n\n");
   printf("1.See room and features \n");
   printf("2.check available rooms \n");
   printf("3.Book room \n");
   printf("4.modify data \n");
   printf("5.Details of costumers \n");
   printf("6.See food menu and order\n");
   printf("7.see total restaurant bill amount \n");
   printf("8.see total room bill amount\n");
   printf("9.Check out\n");

   printf("Enter a choice between 1 and 8... ");
    fflush(stdin);
   scanf("%d",&ch  );
   printf("\n");
   switch(ch)
   {

       case 1:
             roomandfeatures();
              break;
        case 2:
            roomavailability();
              break;
        case 3:
            book();
            break;
        case 4:
            modify();
             break;

        case 5:
              costdetails();
              break;
        case 6:
              food();
              break;

        case 7:
              restaurantbill();
              break;

        case 8:
              roombill();
              break;
        case 9:
            checkout();
            break;

        default:
            screenheader();
            break;

   }

 }
 void roomandfeatures()//checks rooms and their features
 {


      printf("We are available with four types of room:\n");
      printf("1.Single : 1washroom 1 single bed balcony view|| Room no 1,2,3,4  \n");
      printf("2.Double: double bed,washroom,floor mat ||Room no:5,6,7,8 \n");
      printf("3.Couple :cozy double bed,washroom with hot water,good swimming pool view  ||Room no:9,10,11,12 \n");
      printf("4.Deluxe:AC, Hot and cold water on washroom,double bed,floor mat,low bed on demand,super view of town,telephone service || Room no:13,14,15,16 \n");
      printf("Press Y to book and N to go back to menu");
 }


 void roomavailability()//to check available rooms
{
    system("cls");
	int i,j;
	struct costumer var;
 	FILE *fp;
	fp=fopen("hoteldata.txt","rb+");
	if(fp==0)
    {
       printf("null");
    }
    printf("Room Number \t\t\t\t\t Availability \n");
	while(fread(&var,sizeof(var),1,fp)>0)
	{
	    for(i=1;i<=16;i++)
        {

		        if( var.roomnum==i)
            {
                 printf("%d \t\t\t\t\t Not available\n",var.roomnum);
            }
		}
	}
	fclose(fp);
	screenheader();
 }
 void book()//for writing purpose or booking room
{
    int i;
      struct costumer var;

      FILE*fp;
      fp=fopen("hoteldata.txt","ab+");
      //for time
            time_t timer;
            struct tm* tm_info;
            timer = time(NULL);
            tm_info = localtime(&timer);
            strftime(var.buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

            printf("enter Your costumer name ");
            fflush(stdin);
            gets(var.name);

            printf("enter Your costumer address ");
            fflush(stdin);
            gets(var.address);
            printf("enter your citizenship id");
            fflush(stdin);
            gets(var.id);
            printf("enter your phone number ");
            fflush(stdin);
            gets(var.num);
            printf("enter roomnumber");
            fflush(stdin);
            scanf("%d",&var.roomnum);
            fwrite(&var,sizeof(var),1,fp);

            fclose(fp);
            printf("Room booked for .%s !!!!Thanks for trusting us.Have a Good day!!!",var.name);
            delay(2000);
            system("cls");
            screenheader();
             }
 void modify()//update data
 {
     int room;
     struct costumer var;
     struct costumer var1;
     FILE*fp;
     FILE*ft;
     time_t timer;
            struct tm* tm_info;
            timer = time(NULL);
            tm_info = localtime(&timer);
            strftime(var1.buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

     fp=fopen("hoteldata.txt","rb+");
     ft=fopen("test.txt","ab+");
     printf("Enter a room number to modify");
     fflush(stdin);
     scanf("%d",&room);
     while(fread(&var,sizeof(var),1,fp))
     {
         if(var.roomnum!=room)
         {
            fwrite(&var,sizeof(var),1,ft);
         }
     }
            printf("enter Your costumer name ");
            fflush(stdin);
            gets(var1.name);

            printf("enter Your costumer address ");
            fflush(stdin);
            gets(var1.address);
            printf("enter your citizenship id");
            fflush(stdin);
            gets(var1.id);
            printf("enter your phone number ");
            fflush(stdin);
            gets(var1.num);
            printf("enter roomnumber");
            fflush(stdin);
            scanf("%d",&var1.roomnum);
            fwrite(&var1,sizeof(var),1,ft);
     fclose(fp);
     fclose(ft);
            remove("hoteldata.txt");
            rename("test.txt","hoteldata.txt");
            printf("record modified");
}
void costdetails()//for users info
{

    gotoxy(0,30);
    printf("Name");
    gotoxy(20,30);
    printf("Room number");
    gotoxy(50,30);
    printf("Address");
    gotoxy(75,30);
    printf("Phnumber ");
    gotoxy(90,30);
    printf("Id \t\t");
    gotoxy(150,30);
    printf("Checkin Date");
    gotoxy(0,31);
    printf("----------------------------------------------------------------------------------------------------------------------\n");
   struct costumer var;
      FILE*fp;
      fp=fopen("hoteldata.txt","rb+");
      if(fp==NULL)
      {
          printf("go out");
          exit(1);
      }

          while(fread(&var,sizeof(var),1,fp)==1)
          {

               printf("%s   \t",var.name);
               printf("%d\t\t",var.roomnum);
               printf("%s\t\t",var.address);
               printf("%s \t ",var.num);
               printf("%s\t",var.id);
               printf("%s \n",var.buffer);

          }
    printf("-------------------------------------------------------------------------------------------------------------------------");

fclose(fp);
}

void food()//to see total bill amount
{

    char yesorno[2];
    system("cls");
    printf("*********************************************FOOD MENU****************************************************************\n");
    printf("Foods                                                      ItemCost(NRs \n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf("1.Sadha Bhaat(plain rice and curry                           100\n");
    printf("2.chicken curry                                              30\n");
    printf("3.Mutton Curry                                               50\n");
    printf("4.Chicken Biryani                                            100\n");
    printf("5.Mutton Biryani                                             120\n");
    printf("6.Chicken momo                                               120\n");
    printf("7.Buff momo                                                  100\n");
    printf("8.Veg momo                                                   100\n");
    printf("9.Omelette                                                   30\n");
    printf("10.Beer                                                      200\n");
    printf("11.Veg chowmein                                              100\n");
    printf("12.Buff chowmein                                             100\n");
    printf("13.Chicken Chowmein                                          100\n");
    printf("14.Pakoda                                                    30/plate\n");
    printf("15.Samosa                                                    15/pcs\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
      FILE*ff;
       struct restaurant menu;
      ff=fopen("foodd.txt","ab+");
      //To find time
            time_t timer;
            struct tm* tm_info;
            timer = time(NULL);
            tm_info = localtime(&timer);
            strftime(menu.buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
            //end of time check
            //copies time from buffer to another string
            printf("enter your room number: ");
            scanf("%d",&menu.roomno);
            printf("enter respective food nuumber choice between 1 and 15: ");
            scanf("%d",&menu.choose);
            if(menu.choose==1)
            {
                printf("Enter how many plates of Daal bhaat?");
                scanf("%d",&menu.qty);
                 menu.cost=100*menu.qty;
            }
            else if(menu.choose ==2)
            {
                printf("enter how many Chicken curry?");
                scanf("%d",&menu.qty);
                menu.cost=30*menu.qty;
            }
            else if(menu.choose ==3)
            {
                printf("enter how many Mutton curry?");
                scanf("%d",&menu.qty);
                menu.cost=50*menu.qty;
            }
            else if(menu.choose ==4)
                {
                printf("enter how many Chicken Biryani?");
                scanf("%d",&menu.qty);
                menu.cost=100*menu.qty;
            }
            else if(menu.choose ==5)
            {
                printf("enter how many Mutton Biryani?");
                scanf("%d",&menu.qty);
                menu.cost=120*menu.qty;
            }
            else if(menu.choose ==6)
            {
                printf("enter how many Chicken momo?");
                scanf("%d",&menu.qty);
                menu.cost=120*menu.qty;
            }
            else if(menu.choose ==7)
            {
                printf("enter how many Buff momo?");
                scanf("%d",&menu.qty);
                menu.cost=100*menu.qty;
            }
            else if(menu.choose ==8)
            {
                printf("enter how many Veg momo?");
                scanf("%d",&menu.qty);
                menu.cost=100*menu.qty;
            }
            else if(menu.choose ==9)
            {
                printf("enter how many omelette?");
                scanf("%d",&menu.qty);
                menu.cost=30*menu.qty;
            }
            else if(menu.choose ==10)
            {
                printf("enter how many  Beer?");
                scanf("%d",&menu.qty);
                menu.cost=200*menu.qty;
            }
            else if(menu.choose ==11)
            {
                printf("enter how many Veg chowmein?");
                scanf("%d",&menu.qty);
                menu.cost=100*menu.qty;
            }
            else if(menu.choose ==12)
            {
                printf("enter how many Buff chowmein?");
                scanf("%d",&menu.qty);
                menu.cost=100*menu.qty;
            }
            else if(menu.choose ==13)
            {
                printf("enter how many Chicken chowmein?");
                scanf("%d",&menu.qty);
                menu.cost=100*menu.qty;
            }
            else if(menu.choose ==14)
            {
                printf("enter how many plates of  pakoda?");
                scanf("%d",&menu.qty);
                menu.cost=30*menu.qty;
            }
            else if(menu.choose ==15)
            {
                printf("Enter how many plates of Samosas?");
                scanf("%d",&menu.qty);
                menu.cost=15*menu.qty;
            }
            fwrite(&menu,sizeof(menu),1,ff);
            fclose(ff);
            printf("Order Taken for Room Number %d \n!!!Enjoy your meal.",menu.roomno);
            printf("Press Y to order again and N to go to Main menu");
            fflush(stdin);
            scanf("%s",yesorno);
            if(strcmp(yesorno,"y")==0)
            {
                food();
            }
            else
            system("cls");
            screenheader();

}
void restaurantbill()//bill for food ordering
{
    int roomnumber,paisa=0;
    FILE*ff;
    struct restaurant menu;
    ff=fopen("foodd.txt","rb+");
    if (ff==NULL)
    {
        printf("Null");
        exit(1);

    }
      printf("enter room number to find bill of: ");
      scanf("%d",&roomnumber);
    while(fread(&menu,sizeof(menu),1,ff)==1)
    {
         if(roomnumber==menu.roomno)
         {
                printf(" Ordered  %d of food Number %d costing NRs.%d ",menu.qty,menu.choose,menu.cost);
                printf("at %s\n",menu.buffer);
                paisa=paisa+menu.cost;
         }
    }
    printf("\n");
    printf("Total restaurant Bill amount is : Rs.%d Only",paisa);
    fclose(ff);
}
void roombill()//see room bill
{
    int enterroom,pay,days;
    struct costumer var;
            time_t timer;
            struct tm* tm_info;
            timer = time(NULL);
            tm_info = localtime(&timer);
            strftime(var.buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
     printf("Current time is %s \n",var.buffer);
      FILE*fp;
      fp=fopen("hoteldata.txt","rb+");
      if(fp==NULL)
      {
          printf("Null");
      }

      printf("enter room number to pay bill : ");
      scanf("%d",&enterroom);
      while(fread(&var,sizeof(var),1,fp)>0)
      {
         if(var.roomnum==enterroom)
         {
             if(var.roomnum==1||2||3||4)
             {
                 printf("checked in in %s\n",var.buffer);
                 printf("Enter days: ");
                 scanf("%d",&days);
                 pay=500*days;
                 printf("Your total hotel bill is : %d",pay);
             }
             else if(var.roomnum==5||6||7||8)
             {
                 printf("checked in in %s\n",var.buffer);
                 printf("Enter days: ");
                 scanf("%d",&days);
                 pay=1000*days;
                  printf("Your total hotel bill is : %d",pay);
             }
                else if(var.roomnum==9||10||11||12)
             {
                 printf("checked in in %s\n",var.buffer);
                 printf("Enter days: ");
                 scanf("%d",&days);
                 pay=2000*days;
                 printf("Your total hotel bill is NRs:%d only",pay);
             }
                else if(var.roomnum==13||14||15||16)
             {
                 printf("checked in in %s\n",var.buffer);
                 printf("Enter days: ");
                 scanf("%d",&days);
                 pay=3000*days;
                 printf("Your total hotel bill is : %d",pay);
             }

         }
      }
      fclose(fp);
}
void checkout()//delete data
{
         int room;
     struct costumer var;
     FILE*fp;
     FILE*ft;
     fp=fopen("hoteldata.txt","rb+");
     ft=fopen("test.txt","ab+");
     printf("Enter a room number to check out.");
     fflush(stdin);
     scanf("%d",&room);
     while(fread(&var,sizeof(var),1,fp))
     {
         if(var.roomnum!=room)
         {
            fwrite(&var,sizeof(var),1,ft);
            fflush(stdin);
         }
     }
     fclose(fp);
     fclose(ft);
            remove("hoteldata.txt");
            rename("test.txt","hoteldata.txt");

printf("Check out successful.!!!");
  rescheck();
}
void rescheck()//pay restaurant bill
{
     int room;
     struct restaurant menu;
     FILE*ff;
     FILE*ff1;
     ff=fopen("foodd.txt","rb+");
     ff1=fopen("test1.txt","ab+");
     printf("Enter a room number to clear bill amount.");
     fflush(stdin);
     scanf("%d",&room);
     while(fread(&menu,sizeof(menu),1,ff)==1)
     {
         if(menu.roomno!=room)
         {
            fwrite(&menu,sizeof(menu),1,ff1);
         }
     }
     fclose(ff);
     fclose(ff1);
            remove("foodd.txt");
            rename("test1.txt","foodd.txt");
            printf("Bill cleared");

}





