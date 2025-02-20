#include<stdio.h>
FILE *filePtr;
#define FILENAME "employeeRecords.txt"
typedef struct {
    char name[10];
    int id;
    float salary;
}employee;
void addRecord(){
    char choice;
    do{
        employee emp;
        filePtr = fopen(FILENAME,"a");
        if(filePtr){
            printf("Enter employee name\n");
            scanf("%s",emp.name);
            printf("Enter employee Id\n");
            scanf("%d",&emp.id);
            printf("Enter salary\n");
            scanf("%f",&emp.salary);
            printf("if u want to enter another details y or n\n");
            scanf(" %c",&choice);
            fprintf(filePtr, "%s %d %.2f\n", emp.name, emp.id, emp.salary);
            fclose(filePtr);
        }
        else{
            printf("File not opened\n");
            return;
        }
    }while(choice == 'y');
}
void displayRecord(){
    employee emp;
    filePtr = fopen(FILENAME,"r");
    if(filePtr){
        while(fscanf(filePtr,"%s %d %f",emp.name,&emp.id,&emp.salary)!=EOF){
            printf("%s\t%d\t%f\n",emp.name,emp.id,emp.salary);
        }
        fclose(filePtr);
        return;
    }
    printf("File not opened\n");
    return;
}
void searchRecord(){
    employee emp;
    filePtr = fopen(FILENAME,"r");
    if(filePtr){
        int key,found=0;;
        printf("Enter id u want to search\n");
        scanf("%d",&key);
        while(fscanf(filePtr,"%s %d %f",emp.name,&emp.id,&emp.salary)!=EOF){
            if(emp.id == key){
                found = 1;
                printf("record Found\n");
                break;
            }
        }
        if (!found)
        {
           printf("record not found\n");
        }
        fclose(filePtr);
    }
}
void modifyRecord(){
    employee emp;
    FILE *tempFilePtr;
    filePtr = fopen(FILENAME,"r");
    tempFilePtr = fopen("temp.txt","w");
    if(filePtr){
        if(tempFilePtr){
            int key,found=0;
            printf("Enter id to be modified\n");
            scanf("%d",&key);
            while(fscanf(filePtr,"%s %d %f",emp.name,&emp.id,&emp.salary)!=EOF){
                if(emp.id==key){
                    printf("Enter name\n");
                    scanf("%s",emp.name);
                    printf("Enter  Id\n");
                    scanf("%d",&emp.id);
                    printf("Enter salary\n");
                    scanf("%f",&emp.salary);
                    found = 1;
                }
                fprintf(tempFilePtr,"%s %d %.2f",emp.name,emp.id,emp.salary);
            }
            fclose(filePtr);
            fclose(tempFilePtr);
            remove(FILENAME);
            rename("temp.txt",FILENAME);
            if(found){
                printf("record modified successfully\nModified record\n");
                displayRecord();
            }
            else{
                printf("record not found\n");
            }
            return;
        }
        printf("Temp file not created\n");
        return;
    }
    printf("File cannot be opened\n");
    return;
}
void deleteRecord(){
    employee emp;
    FILE *tempFilePtr;
    filePtr = fopen(FILENAME,"r");
    tempFilePtr = fopen("temp.txt","w");
    if(filePtr){
        if(tempFilePtr){
            int key,found=0;
            printf("Enter id to be deleted\n");
            scanf("%d",&key);
            while(fscanf(filePtr,"%s %d %f",emp.name,&emp.id,&emp.salary)!=EOF){
                if(emp.id==key){
                    found = 1;
                    continue;
                }
                fprintf(tempFilePtr,"%s %d %.2f",emp.name,emp.id,emp.salary);
            }
            fclose(filePtr);
            fclose(tempFilePtr);
            remove(FILENAME);
            rename("temp.txt",FILENAME);
            if(found){
                printf("record modified successfully\nModified record\n");
                displayRecord();
            }
            else{
                printf("record not found\n");
            }
            return;
        }
        printf("Temp file not created\n");
        return;
    }
    printf("File cannot be opened\n");
    return;
}
int main(){
    addRecord();
    displayRecord();
    searchRecord();
    modifyRecord();
    deleteRecord();
    return 0;
}