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
#ifndef ADMIN_MODE_H
#define ADMIN_MODE_H

#include "std_types.h"

#define Array_size     30

#define Dafault_Password      1234


typedef struct 
{
    u16 id ;
    u8 time_of_slot ;
    u16 resrved ;

    
}slot;

typedef struct patient
{
    u32 id ;
    u32 age ;
    u8 name[Array_size];
    u8 gender[Array_size];
    struct patient *next ;

}patient;



void AdminMode_voidAddRecord(void);
u8  Admin_VoidSearchForId(u8 patient_id);
void Admin_voidEditRecord(u16 Patient_id);
void Admin_Reserve_With_Doctor(void);
void Admin_Display(void);
void Admin_voidCancelReseervation(void);




#endif