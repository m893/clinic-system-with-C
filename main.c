/************************************
 * 
 * Author : Mohammed Akram Elsayad
 *Data : 30 March, 2023  
 * version : 3.1
 * **********************************/


/******************************************************************************************
 *           Date                        Version                         Author 
 *    30 March , 2023                      3.1                         Mohammed Akram  
 * *******************************************************************************************/


#include <stdio.h>
#include <string.h>
#include "admin_mode.h"
#include "user_mode.h"
#include "std_types.h"


 //global variables
u16 user_selected = 0;
u16 Admin_Password = 0 ;
u16 Admin_Function = 0;
u16 trails = 0 ;
u16 Admin_mode_flag = 0 ;
u16 Patient_id = 0 ;
u8 user_selction ;

u32 main (void)
{
     
    while(1)
    {
       
        printf("                        welcome                \n");
        printf("For Admin Please Enter  1   For User Please Enter   2       \n");
        scanf("%d", &user_selected);
        if(user_selected==1)
        {
                //check password for three time then terminated the program
            for(trails = 0 ; trails < 3 ; trails++)
            {       
                    printf("************************************************************************\n");
                    printf("*********************Please Enter password*******************************\n");
                    printf("************************************************************************\n");
                    scanf("%d",&Admin_Password);
                    if(Admin_Password==Dafault_Password)
                    {
                        //Flag to check correct passord and break the loop
                        Admin_mode_flag = 1 ;
                        break;

                    }
                    else 
                    {
                        printf("Incorrect Password\n ");

                    }
                 
            }
            if (trails ==3 )
            {
                printf("System Terminted \n");
                break;
            }

                while(Admin_mode_flag==1)
                {  
                    
                     printf("     Welcome Admin  \n");
                    printf(" For Add New Patient Record Please Enter 1 \n ");
                    printf(" For Edit  Patient Record Please Enter  2 \n" );
                    printf("For Reserve a slot With Doctor Please Enter 3 \n");
                    printf(" For Cancel Reservation  With Doctor Please Enter 4 \n");
                    printf(" For exit from admin mode   Please Enter 5 \n");
                    // select one function of admin function
                    scanf("%d",&Admin_Function);
                    switch (Admin_Function)
                    {
                    case 1 :
                        {
                            
                            AdminMode_voidAddRecord();
                        }
                        break;
                    case 2 :
                           { 
                            
                            printf(" Enter Patient ID\n");
                            scanf("%d",&Patient_id) ;
                            Admin_voidEditRecord( Patient_id) ;
                           }

                        break;
                    case 3 :
                            {
                              Admin_Reserve_With_Doctor();
                             }
                        break;
                    case 4 :
                            Admin_voidCancelReseervation();
                        break;   
                    default:
                        break;
                    }
                   if (Admin_Function==5)
                    {
                        printf("Exit from admin Mode \n");
                        break;
                    }
                    
         }
        }
        else if (user_selected==2)
        {
            
            printf("welcome to user mode\n");
            printf("To view patient record enter 1 \n  To view today's Reservation enter two \n");
            scanf("%d",&user_selction);
            switch (user_selction)
            {
            case 1 :
                    User_VoidViewPatientRecord();
                break;
                case 2 :
                    User_ViewTodayReservation();
                    break;
            
            default:
                    printf("Invalid selection\n");
                break;
            }



        }
        else{
            printf("Invalid Selection \n ");
        }


    }
   

    return 0; 
}


/*******   system terminate when execute some of function during debugging the code local variable deleted so i put it in global 
 scope then code run  *******/