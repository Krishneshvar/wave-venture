#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define Pedalboat1 100
#define Pedalboat2 200
#define Rowboat 170
#define motorboat 250
#define houseboat2 500
#define houseboat4 800
#define houseboat8 999

typedef struct
{
    char Name[64];
    char PhNo[16];
    char IdType[32];
    char IdNo[64];
    int PassengerCount;
    char BoatType[32];
    int BoatCount;
    char PaymentMethod[32];
    time_t CheckInDatenTime;
    char CheckOutDatenTime[16];
    int BillAmount;
} BoatingSystem;

int main()
{
    BoatingSystem bsys;
    int i, billchoice, inpchoice, idtchoice, boattype, xbchoice, paychoice, tempchoice;
    char username[8], password[8], ch1;
    time_t now = time(NULL);
    struct tm *co = localtime(&now);

    system("cls");
    printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t\t\t| BOAT RENTAL SYSTEM |\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
    printf("\n\t\t\t\t\t\t\t+==========+\n\t\t\t\t\t\t\t| Username |\n\t\t\t\t\t\t\t+==========+ : ");
    scanf("%s", username);
    
    printf("\n\t\t\t\t\t\t\t+==========+\n\t\t\t\t\t\t\t| Password |\n\t\t\t\t\t\t\t+==========+ : ");
    scanf("%s", password);
    system("cls");

    if(strcmp(username,"Admin")==0 && strcmp(password,"Pass")==0)
    {
        do
        {
            FILE* fptr = fopen("Boating Rental History.txt", "a");
            printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
            printf("\t\t\t\t\t\t\t+=====================+\n\t\t\t\t\t\t\t| 1. Continue Billing |\n\t\t\t\t\t\t\t| 2. Close Billing    |\n\t\t\t\t\t\t\t+=====================+\n\t\t\t\t\t\t\t: ");
            scanf("%d", &billchoice);
            system("cls");
    
            switch (billchoice)
            {
                case 1:
                    fflush(stdin);
                    printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
                    printf("\n\t\t\t\t\t\t\t+======+\n\t\t\t\t\t\t\t| Name |\n\t\t\t\t\t\t\t+======+ : ");
                    gets(bsys.Name);
                    system("cls");
                    
                    do
                    {
                        printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
                        printf("\n\t\t\t\t\t\t\t+==============+\n\t\t\t\t\t\t\t| Phone Number |\n\t\t\t\t\t\t\t+==============+ : ");
                        scanf("%s", &bsys.PhNo);
                        system("cls");
                    } while (strlen(bsys.PhNo)!=10);

                    do {
                        printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
                        printf("\n\t\t\t\t\t\t\t+========================+\n\t\t\t\t\t\t\t| ID Type:-              |\n\t\t\t\t\t\t\t| ---------              |\n\t\t\t\t\t\t\t| 1. Aadhaar             |\n\t\t\t\t\t\t\t| 2. Driving License     |\n\t\t\t\t\t\t\t| 3. Voter's ID          |\n\t\t\t\t\t\t\t| 4. Service ID (Govt.)  |\n\t\t\t\t\t\t\t| 5. Passport            |\n\t\t\t\t\t\t\t| 6. Other               |\n\t\t\t\t\t\t\t+========================+\n\t\t\t\t\t\t\t: ");
                        scanf("%d", &idtchoice);
                        
                        switch (idtchoice)
                        {
                            case 1:
                                system("cls");
                                strcpy(bsys.IdType, "Aadhaar\0");
                                do {
                                    printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
                                    printf("\n\t\t\t\t\t\t\t+===========+\n\t\t\t\t\t\t\t| ID Number |\n\t\t\t\t\t\t\t+===========+\n\t\t\t\t\t\t\t: ");
                                    scanf("%s", &bsys.IdNo);
                                    system("cls");
                                } while (strlen(bsys.IdNo) != 12);
                                break;

                            case 2:
                                strcpy(bsys.IdType, "Driving License\0");
                                do {
                                    printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
                                    printf("\n\t\t\t\t\t\t\t+===========+\n\t\t\t\t\t\t\t| ID Number |\n\t\t\t\t\t\t\t+===========+\n\t\t\t\t\t\t\t: ");
                                    scanf("%s", &bsys.IdNo);
                                    system("cls");
                                } while (strlen(bsys.IdNo) != 15);
                                break;

                            case 3:
                                strcpy(bsys.IdType, "Voter's ID\0");
                                do {
                                    printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
                                    printf("\n\t\t\t\t\t\t\t+===========+\n\t\t\t\t\t\t\t| ID Number |\n\t\t\t\t\t\t\t+===========+\n\t\t\t\t\t\t\t: ");
                                    scanf("%s", &bsys.IdNo);
                                    system("cls");
                                } while (strlen(bsys.IdNo) != 16);
                                break;

                            case 4:
                                strcpy(bsys.IdType, "Service ID (Govt.)\0");
                                break;

                            case 5:
                                strcpy(bsys.IdType, "Passport\0");
                                break;

                            case 6:
                                printf("\nID Type: ");
                                gets(bsys.IdType);
                                break;
                        
                            default:
                                printf("\nINVALID INPUT!");
                                break;
                        }
                        system("cls");
                    } while (idtchoice>6);

                    fflush(stdin);
                    
                    do {
                        printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
                        printf("\n\t\t\t\t\t\t\t+=================+\n\t\t\t\t\t\t\t| Passenger Count |\n\t\t\t\t\t\t\t+=================+\n\t\t\t\t\t\t\t: ");
                        scanf("%d", &bsys.PassengerCount);

                        printf("\n\n\t\t\t\t\t\t\tConfirm?\n\t\t\t\t\t\t\t--------\n\t\t\t\t\t\t\t1. Yes\n\t\t\t\t\t\t\t2. No\n\t\t\t\t\t\t\t: ");
                        scanf("%d", &tempchoice);

                        fflush(stdin);
                        system("cls");
                    } while (tempchoice!=1);

                    system("cls");

                    do {
                        do {
                            printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
                            printf("\n\t\t\t\t\t\t\t+===================+\n\t\t\t\t\t\t\t| Boat Type:-       |\n\t\t\t\t\t\t\t| -----------       |\n\t\t\t\t\t\t\t| 1. Pedal Boat (2) |\n\t\t\t\t\t\t\t| 2. Pedal Boat (4) |\n\t\t\t\t\t\t\t| 3. Row Boat (4)   |\n\t\t\t\t\t\t\t| 4. Motor Boat (8) |\n\t\t\t\t\t\t\t| 5. House Boat (2) |\n\t\t\t\t\t\t\t| 6. House Boat (4) |\n\t\t\t\t\t\t\t| 7. House Boat (8) |\n\t\t\t\t\t\t\t+===================+\n\t\t\t\t\t\t\t: ");
                            scanf("%d", &boattype);

                            switch (boattype)
                            {
                                case 1:
                                    strcpy(bsys.BoatType, "Pedal Boat (2)");
                                    break;

                                case 2:
                                    strcpy(bsys.BoatType, "Pedal Boat (4)");
                                    break;

                                case 3:
                                    strcpy(bsys.BoatType, "Row Boat (4)");
                                    break;

                                case 4:
                                    strcpy(bsys.BoatType, "Motor Boat (8)");
                                    break;

                                case 5:
                                    strcpy(bsys.BoatType, "House Boat (2)");
                                    break;

                                case 6:
                                    strcpy(bsys.BoatType, "House Boat (4)");
                                    break;

                                case 7:
                                    strcpy(bsys.BoatType, "House Boat (8)");
                                    break;
                            
                                default:
                                    printf("INVALID INPUT!");
                                    break;
                            }
                            system("cls");
                        } while (boattype>7);
                        
                        printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
                        printf("\n\t\t\t\t\t\t\t+============+\n\t\t\t\t\t\t\t| Boat Count |\n\t\t\t\t\t\t\t+============+\n\t\t\t\t\t\t\t: ");
                        scanf("%d", &bsys.BoatCount);

                        printf("\n\n\t\t\t\t\t\t\tConfirm?\n\t\t\t\t\t\t\t--------\n\t\t\t\t\t\t\t1. Yes\n\t\t\t\t\t\t\t2. No\n\t\t\t\t\t\t\t: ");
                        scanf("%d", &tempchoice);
                        system("cls");

                    } while (tempchoice!=1);

                    if (strcmp(bsys.BoatType, "Pedal Boat (2)") == 0)
                    {
                        bsys.BillAmount = bsys.BoatCount * Pedalboat1;
                    }
                    else if (strcmp(bsys.BoatType, "Pedal Boat (4)") == 0)
                    {
                        bsys.BillAmount = bsys.BoatCount * Pedalboat2;
                    }
                    else if (strcmp(bsys.BoatType, "Row Boat (4)") == 0)
                    {
                        bsys.BillAmount = bsys.BoatCount * Rowboat;
                    }
                    else if (strcmp(bsys.BoatType, "Motor Boat (8)") == 0)
                    {
                        bsys.BillAmount = bsys.BoatCount * motorboat;
                    }
                    else if (strcmp(bsys.BoatType, "House Boat (2)") == 0)
                    {
                        bsys.BillAmount = bsys.BoatCount * houseboat2;
                    }
                    else if (strcmp(bsys.BoatType, "House Boat (4)") == 0)
                    {
                        bsys.BillAmount = bsys.BoatCount * houseboat4;
                    }
                    else if (strcmp(bsys.BoatType, "House Boat (8)") == 0)
                    {
                        bsys.BillAmount = bsys.BoatCount * houseboat8;
                    }

                    do {
                        printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
                        printf("\n\t\t\t\t\t\t\t| Bill Amount : Rs. %d |\n", bsys.BillAmount);
                        printf("\n\t\t\t\t\t\t\t+==================+\n\t\t\t\t\t\t\t| Payment Method:- |\n\t\t\t\t\t\t\t| ---------------- |\n\t\t\t\t\t\t\t| 1. Cash          |\n\t\t\t\t\t\t\t| 2. UPI           |\n\t\t\t\t\t\t\t| 3. Card          |\n\t\t\t\t\t\t\t+==================+\n\t\t\t\t\t\t\t: ");
                        scanf("%d", &paychoice);

                        switch (paychoice)
                        {
                            case 1:
                                strcpy(bsys.PaymentMethod, "Cash\0");
                                break;
                            
                            case 2:
                                strcpy(bsys.PaymentMethod, "UPI\0");
                                break;
                            
                            case 3:
                                strcpy(bsys.PaymentMethod, "Card\0");
                                break;
                            
                            default:
                                break;
                        }

                        printf("\n\n\t\t\t\t\t\t\tConfirm?\n\t\t\t\t\t\t\t--------\n\t\t\t\t\t\t\t1. Yes\n\t\t\t\t\t\t\t2. No\n\t\t\t\t\t\t\t: ");
                        scanf("%d", &tempchoice);
                        system("cls");
                    } while (tempchoice!=1);
                    

                    time(&bsys.CheckInDatenTime);
                    system("cls");

                    fflush(stdin);

                    printf("\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n\t\t\t\t\t\t\t================| BOAT RENTAL SYSTEM |================\n\t\t\t\t\t\t\t\t\t+~~~~~~~~~~~~~~~~~~~~+\n");
                    printf("\n\t\t\t\t\t\t\t+=========================+\n\t\t\t\t\t\t\t| Check-Out Date and Time |\n\t\t\t\t\t\t\t+=========================+\n\t\t\t\t\t\t\t: ");
                    gets(bsys.CheckOutDatenTime);
                    system("cls");

                    fprintf(fptr, "\n\nName                 : %s\nPhone Number         : %s\nID Type              : %s\nID Number            : %s\nPassenger Count      : %d\nBoat Type            : %s\nBoat Count           : %d\nCheck-In Date & Time : %sCheck-Out Date       : %s\nBill Amount          : %d\nPayment Method       : %s", bsys.Name, bsys.PhNo, bsys.IdType, bsys.IdNo, bsys.PassengerCount, bsys.BoatType, bsys.BoatCount, ctime(&bsys.CheckInDatenTime), bsys.CheckOutDatenTime, bsys.BillAmount, bsys.PaymentMethod);
                    fclose(fptr);
                    break;
                
                case 2:
                    printf("\nAPPLICATION CLOSING...\n\nAPPLICATION SUCCESSFULLY CLOSED!");
                    break;

                default:
                    printf("INVALID INPUT!");
                    break;
            }
        } while (billchoice != 2);
    }
    else
    {
        printf("\n!! EITHER YOUR USERNAME OR PASSWORD IS INVALID !!");
    }
}