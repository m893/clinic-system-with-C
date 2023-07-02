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
#include "std_types.h"
#include <string.h>

//array of 5 struct to store slot time and id of patient
slot time [5] ;
// global pointer to patient struct  to save the address of node after Search function
patient * pointer_to_exist_node ;
//pointer to struct to save the address of first patient record (node)
patient *head=NULL;

void AdminMode_voidAddRecord(void)
{   
     printf(" Add Patient Function \n");

    u32 id ;

    printf("  Enter ID  \n");

    scanf("%d",&id);

    //search for id is already exist before or not 
    if (Admin_VoidSearchForId(id)==0)
    {
        //craete new node in dynamic memory (heap)
        patient *newrecord=(patient *)malloc(sizeof(patient));
        //check if new node already create or not
        if(newrecord != NULL)
        {
           // take patient information and save it in the node
           newrecord->id=id ;
            printf("Enter Patient Name: ");
            fflush(stdin);
             gets(newrecord->name);
            printf("Enter Patient Age: ");
             scanf("%d",&newrecord->age);
            printf("Enter Patient gender: ");
            fflush(stdin);
            gets(newrecord->gender);
             u32 patient_id =0 ;
             
            //chec if it the first node
            if(head==NULL)
            {
                
                head = newrecord;
                newrecord->next = NULL;
            
            }
            else
            {   //add new node between head and and first node 
                newrecord->next = head;
                head = newrecord; 

            }
        
            printf(" Record Added \n");

        }
        else
        {
            printf("NO space in Heap\n");
        }
    }
    else
    {
        printf("Id already exist\n");
    }

}

u8  Admin_VoidSearchForId(u8 patient_id)
{
    u8 id_avilable=0 ;
    patient *temp=head;
    while(temp!=NULL)
    {
        if((temp->id )== patient_id)
        {
            pointer_to_exist_node=temp;
            id_avilable=1;
            break;
        }
        else
        {
            temp=temp->next;
        }
    }
    return id_avilable ;

}
void Admin_voidEditRecord(u16 Patient_id)
{
    u8 name[Array_size]={0};
    u8 age = 0 ;
    u8 Patient_gender[Array_size]={0};
    u8 patient_id;
    patient * pointer = NULL ;
    if(Admin_VoidSearchForId(Patient_id)==1)
    {
        printf("enter new name :  ");
        fflush(stdin);
        gets(name);
        strcpy(pointer_to_exist_node->name,name);
        printf("enter the age :  ");
        scanf("%d",&age);
        pointer_to_exist_node->age=age;
        printf("enter gender: ");
        fflush(stdin);
        gets(Patient_gender);
        strcpy(pointer_to_exist_node->gender,Patient_gender);
    }
    else 
    {
        printf("incorrect id \n");
    }

}

void Admin_Reserve_With_Doctor(void)
{
    u16 patient_id ;
    u16 selected_time ;
    printf("2 pm to 2:30 pm  Enter 1 \n");
    printf("2:30 pm to 3  pm  Enter 2 \n");
    printf("3 pm to 3:30 pm  Enter 3 \n");
    printf("4 pm to 4:30 pm  Enter 4 \n");
    printf("4:30 pm to 5 pm  Enter 5 \n");
    
    printf("Enter Patient ID \n");
    scanf("%d",&patient_id);
     if(Admin_VoidSearchForId(patient_id)==1)
    {
        printf("Avalible slots \n");

        Admin_Display();

        printf("please Select the slot time \n");
       
        scanf("%d",&selected_time);
        switch (selected_time)
        {
        case 1 : 
            time[0].id=pointer_to_exist_node->id;
            time[0].resrved=1;
            time[0].time_of_slot=0;
            printf(" ID : %d reserve time %d\n ",pointer_to_exist_node->id ,selected_time);
            break;
        case 2 : 
             time[1].id=pointer_to_exist_node->id;
            time[1].resrved=1;
            time[1].time_of_slot=1;
            printf(" ID : %d reserve time %d \n",pointer_to_exist_node->id ,selected_time);
            break;
        case 3 : 
            time[2].id=pointer_to_exist_node->id;
            time[2].resrved=1;
            time[2].time_of_slot=2;
            printf(" ID : %d reserve time %d \n",pointer_to_exist_node->id,selected_time);
            break;
        case 4 : 
            time[3].id=pointer_to_exist_node->id;
            time[3].resrved=1;
            time[3].time_of_slot=3;
            printf(" ID : %d reserve time %d \n",pointer_to_exist_node->id ,selected_time);
            break;
        case 5 : 
             time[4].id=pointer_to_exist_node->id;
            time[4].resrved=1;
            time[4].time_of_slot=4;
            printf(" ID : %d reserve time %d \n",pointer_to_exist_node->id ,selected_time);
            break;      
        default:
            printf("Invalid selected time \n");
            break;
        }
   }
   else 
   {
    printf("patent ID not exist \n");
   }

}
void Admin_Display(void)
{
    
        if(time[0].resrved==0)
        {
            printf("2 pm to 2:30 pm\n ");

        }
        else
        {

        }
         if(time[1].resrved==0)
        {
            printf("2:30 pm to 3 pm \n ");
        }
        else
        {

        }
         if(time[2].resrved==0)
        {
            printf("3 pm to 3:30 pm \n");
        }
        else
        {

        }
         if(time[3].resrved==0)
        {
            printf("4 pm to 4:30 pm \n");
        }
        else
        {

        }
         if(time[4].resrved==0)
        {
            printf("4:30 pm to 5 pm \n");
        }
        else
        {
            printf(" no available slots\n");
        }
    

}
void Admin_voidCancelReseervation(void)
{
    u8 id ;
    printf("enter id ");
    scanf("%d",&id);
    u8 counter;
    for(counter=0;counter < 5 ; counter++)
    {
        if(time[counter].id==id)
        {
            time[counter].resrved=0;
            printf("reservation cancelledc\n");
        }
    }

}