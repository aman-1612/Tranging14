/*** @file    : Patient db
 * @brief     : To store database of patient such as Name,Contact info, Inpatient/Out-patient,Disease, Doctoe name, Patient's ID and Room number.
 * @Author    : Parchit Malhotra [Parchit.malhotra@vvdntech.in]
 * @Copyright : (c) 2019-2020 , VVDN Technologies Pvt. Ltd.
 *              Permission is hereby granted to everyone in VVDN Technologies
 *              to use the Software without restriction, including without
 *              limitation the rights to use, copy, modify, merge, publish,
 *              distribute, distribute with modifications.
*   @structure : Patient
*   @brief     : This is the basic Patient structure having information about patient.
*                Every student variable must have following properties.
*   @members   :
*     @patient_nam    : Name of the patient.
*     @patient_id     : name of different product's.
      @pn_no          : Phone no of patient.
      @doctor_nam     : name of doctor.
      @disease        : disease of the patient.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<ctype.h>
struct patient 
{
    char patient_nam[15];
    int  patient_id;
    int  ph_no;
    char disease[15];
    char doctor_nam[15];
    char patient_type;
    union
    {
        int room_no;
    };
};


int main()
{    
    char v='\0';
    struct patient *p ;int start=0,j=0,n=0,idno=0;char name[15];char choice[10];
    rep :  printf("enter the total no patients : \n");/* INPUT VALIDATION FOR NO. OF PATIENTS */
    __fpurge(stdin);
    scanf("%d%c",&n,&v);
    if(v!='\n')
    {
    printf("WRONG INPUT, enter correct input\n");
    goto rep;
      

    }
    p =(struct patient*)malloc(n*sizeof(struct patient));

    //creation of patient database
    for(start=0;start<n;start++)
    { 
        printf("enter the patient :%d's details\n",start+1);
     res:   printf("patient name : ");           /* INPUT VALIDATION FOR NAME */
        scanf("%s",p[start].patient_nam);
	j=0;
        while(p[start].patient_nam[j]!='\0')
        {
           if( isalpha( p[start].patient_nam[j] ))
           {j++;
           }
           else
           {
            printf("wrong name\n");
            goto res;
           }
          }
          char l='\0';
    rel:    printf("\npatient id :");          /* INPUT VALIDATION FOR PATIENT ID*/
        __fpurge(stdin);
        scanf("%d%c",&p[start].patient_id,&l);
        if(l!='\n')
        {
          printf("WRONG INPUT, enter correct input");
           goto rel;

        }
        
        
        if(start>0)
        {
            for(j=0;j<start;j++)
            {
                if(p[start].patient_id==(p[start-1].patient_id))
                { printf("already exist");
                    printf("re enter another id");
                    scanf("%d",&p[start].patient_id);
                }
            }
        }
        char t='\0';
  
      rea:   printf("\n phno : ");             /* INPUT VALIDATION FOR PHONE NO.*/
         __fpurge(stdin);

        scanf("%d%c",&p[start].ph_no,&t);
        if(t!='\n')
        {
          printf("WRONG PHONE NO, enter correct input\n");
           goto rea;

        }




        printf("\ndisease : ");
        scanf("%s",p[start].disease);
        printf("\ndoctor : ");
        scanf("%s",p[start].doctor_nam);
        printf("\nfor in patient type I and outpatient type O\n Patient_type : ");
        scanf(" %c",&p[start].patient_type);

        if(p[start].patient_type=='I'||p[start].patient_type=='i')
        {
            printf("\nenter room no : ");
            scanf("%d",&p[start].room_no);
            if(start>0)
            {
                for(j=0;j<start;j++)
                {
                    if(p[start].room_no==(p[start-1].room_no))
                    {
                        printf("Already exist\n");
                        printf("Re_allocate another room:\n");
                        scanf("%d",&p[start].room_no);
                    }
                }
            }

        }
        else 
            p[start].room_no=0;
    } 

    //To print the database
    printf("**********PATIENT DETAILS***********\n");
    printf("S.No\t NAME\t Ph.No.\t DISEASE\t ID\t ROOM.No\t P.TYPE\t DOCTOR\t\n\n");
    for(start=0;start<n;start++)
    {
        printf( " %d\t %s\t %d\t %s\t\t %d\t %d\t\t %c\t%s\t\n\n",start+1,p[start].patient_nam,p[start].ph_no,p[start].disease,
               p[start].patient_id,p[start].room_no,p[start].patient_type,p[start].doctor_nam);                   

    }

    //either patient id or name
reenter:
    printf("enter your choice ID or NAME of patient: \n");
    scanf(" %s",choice);
    if(strcmp(choice,"ID")||(strcmp(choice,"id"))==0)
    {  
        printf("\nID : ");
        scanf("%d",&idno);
    }
    else if(strcmp(choice,"name")||(strcmp(choice,"NAME"))==0)

    {
        printf("\nNAME:");
        scanf(" %s",name);
    }
    else
    {
        printf("wrong choice\n");
        goto reenter;
    }

    // To compare  the database and print the details of patient
    for(start=0;start<n;start++)
    {
        if(p[start].patient_id==idno || (strcmp(p[start].patient_nam,name))==0)
        {
            printf("patient name : %s\n",p[start].patient_nam);
            printf("\nid : %d",p[start].patient_id);
            printf("\nphno : %d",p[start].ph_no);
            printf("\ndisease : %s",p[start].disease);
            printf("\ndoctor : %s",p[start].doctor_nam);
            printf("\n type : %c",p[start].patient_type);
            printf("\n roomno : %d",p[start].room_no);
            goto exit;

        } 
    }
    printf("given details not matched\n");
exit:       
return 0;
}

