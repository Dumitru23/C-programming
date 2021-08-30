//----------------------------------------------
// Name:           Mindrigan Dumitru
// Student Number: 140920174
// Email:          dmindriganID@myseneca.ca
// Section:        SFF
// Workshop:       5 (in lab)
//----------------------------------------------
#include<stdio.h>
#define size 4

struct Emp{
    int     id;
    int     age;
    double  salary;
};

int main(){

struct Emp a[size]={{0},{0},{0}};
int op,i,id_n=0,j, replace=-1,k;

/*for(i=0;i<size;i++)
  {
    a[i].id=0;
    a[i].age=0;
    a[i].salary=0;
  }
*/
/*
for(i=0;i<size;i++)   //test
  {
  printf("\n id: %d",a[i].id);
  printf("\n age: %d",a[i].age);
  printf("\n salary: %lf", a[i].salary); 
  }
*/
printf("---=== EMPLOYEE DATA ===---\n");
i=0; j=0;
do 
  { 
    printf("\n");
    printf("1. Display Employee Information");  //display info
    printf("\n2. Add Employee");                   // add Employee 
    printf("\n3. Update Employee Salary");          // Update
    printf("\n4. Remove Employee");                   // Remove  
    printf("\n0. Exit");                            // exit 

    printf("\n\nPlease select from the above options: ");
    scanf("%d",&op);

    switch(op)
    { 
      case 1:         // OUTPUT
            {    
              printf("\nEMP ID  EMP AGE EMP SALARY");
              printf("\n======  ======= ==========\n");
              for(i=0;i<size;i++){
                if(a[i].id!=0) 
                {
                  printf("%6d%9d%11.2lf\n",a[i].id,a[i].age,a[i].salary);
                } 
                  
              }
              break;
        
            }
      case 2:   //ADD more Employee
            { 
              printf("\nAdding Employee");
              printf("\n==============="); 
              if(replace>0) //check first if a field must be replaced   
                 j=replace; //if yes j starts from last counter
              if(j<size)
              { 
                printf("\nEnter Employee ID: ");
                scanf("%d",&a[j].id);
                printf("Enter Employee Age: ");
                scanf("%d",&a[j].age);
                printf("Enter Employee Salary: ");
                scanf("%lf",&a[j].salary);
                j++; 
              } 
              else
                {
                  printf("\nERROR!!! Maximum Number of Employees Reached\n");
                }
                   
              break;
            }
      case 3:   // Update Employee Salary
            {     
              printf("\nUpdate Employee Salary\n");
              printf("======================");
              int flag=0;
              do
              {
                printf("\nEnter Employee ID: ");
                scanf("%d",&id_n);
                  for(i=0;i<size;i++)
                    if(id_n==a[i].id)
                        {
                          printf("The current salary is %.2lf",a[i].salary);
                          printf("\nEnter Employee New Salary: ");
                          scanf("%lf",&a[i].salary);
                          flag =1; // true --> found id
                          break;
                         }  
                if(id_n!=a[i].id) 
                  printf("*** ERROR: Employee ID not found! ***");   
              }while(flag!=1); 
              break;
            }  
            
      case 4:    //Remove Employee from struct 
            {
	      printf("\n");	              
	      printf("Remove Employee\n");
              printf("===============");
              int flag=0;
         do
          {
              printf("\nEnter Employee ID: ");
              scanf("%d",&id_n);
                for(k=0;k<size;k++)
                  if(id_n==a[k].id)
                    {
                      printf("Employee %d will be removed\n", a[k].id);
                     replace=k;
                      a[k].id=0;
                      a[k].age=0;
                      a[k].salary=0;
                      flag=1;
                      }/*for(i;i<size;i++){  // move elements up
                        a[i]=a[i+1]; size=size-1*/
                if(flag==0) 
                    printf("*** ERROR: Employee ID not found! ***");
          }while(flag!=1); 
              
              break;
              
            }
      case 0:   
              {
                printf("\nExiting Employee Data Program. Good Bye!!!\n"); 
                break;
              }
      default: 
              printf("\nERROR: Incorrect Option: Try Again\n");
    }  
  }while(op!=0);
return 0;
}



