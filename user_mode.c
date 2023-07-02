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
#include <stdlib.h>
#include "admin_mode.h"
#include "user_mode.h"
#include "std_types.h"
#include <string.h>

// global pointer to patient struct  to save the address of node after Search function
extern  patient * pointer_to_exist_node ;
//array of 5 struct to store slot time and id of patient
extern slot time [5] ;

void User_VoidViewPatientRecord(void)
{
    u8 id ;
    printf("Enter patient id \n");
    scanf("%d",&id);
    if(Admin_VoidSearchForId(id)==1)
    {
        printf("name : %s\n",pointer_to_exist_node->name);
        printf("Gender : %s\n",pointer_to_exist_node->gender);
        printf("age : %d\n",pointer_to_exist_node->age);

    }
    else 
    {
        printf(" ID not Exist\n");
    }

}
 void User_ViewTodayReservation(void)
{
    u8 Local_Counter = 0;
    u8 LOcal_u8Flag =0 ; 
    for(Local_Counter=0 ; Local_Counter < 5 ;Local_Counter++)
    {
        if (time[Local_Counter].resrved == 1 )
        {
            switch (time[Local_Counter].time_of_slot)
            {
            case 0 :
                        printf(" Patient Id : %d reserve 2pm to 2:30 pm\n",time[Local_Counter].id);
                break;
                case 1:
                        printf(" Patient Id : %d  reserve 2:30 pm to 3 pm\n",time[Local_Counter].id);
                break;
                case 2:
                        printf(" Patient Id : %d  reserve 3pm to 3:30 pm\n",time[Local_Counter].id);
                break;
                case 3 :
                        printf(" Patient Id : %d  reserve 4pm to 4:30pm\n",time[Local_Counter].id);
                break;
                case 4 :
                        printf(" Patient Id : %d  reserve 4:30 pm to 5 pm\n",time[Local_Counter].id);
                break;
            
            default:

                        
                break;
            }
       
        }
          else
        {
                printf("No reservation today \n");
        }
    }

}
