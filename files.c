#include<stdio.h>
#include<ctype.h>
char content[100],filename[20],appendContent[100],receivedContent[100],dstFileName[20];
int key;
void readFile(const char *filename){
    FILE *filePtr;
    filePtr = fopen(filename,"r");
    if(filePtr){
        printf("File opened Successfully\nRetrived content from file is\n");
        while(fgets(receivedContent,sizeof(receivedContent),filePtr)){
            printf("%s",receivedContent);
        }
        fclose(filePtr);
    }
    else{
        printf("File not opened\n");
    }
}
void countFile(const char *filename){
    int character = 0,word = 0, line = 0;
    char ch,prev = '\0';
    FILE *filePtr; 
    filePtr = fopen(filename,"r");
    while ((ch = fgetc(filePtr)) != EOF)
    {
        character +=1;
        if(ch == ' ' || ch == '\t' || ch == '\n')
           word +=1;
        if(ch == '\n')
            line+=1;
        prev = ch;
    }
    if(prev != ' ' && prev != '\n' && prev != '\t')
        word+=1;
    fclose(filePtr);
    printf("Number of Characters in File %d\nNumber of words in File %d\nNumber of lines in file %d\n",character,word,line);
}
void copy(const char *filename){
    char ch;
    printf("Enter name for dst file\n");
    scanf("%s",dstFileName);
    FILE *srcFilePtr,*dstFilePtr;
    srcFilePtr = fopen(filename,"r");
    dstFilePtr = fopen(dstFileName,"w");
    if(srcFilePtr){
        if(dstFilePtr){
            while ((ch = fgetc(srcFilePtr)) != EOF)
                fputc(ch,dstFilePtr);
            fclose(srcFilePtr);
            fclose(dstFilePtr);
            printf("Contents in received file\n");
            readFile(dstFileName);
            return;
        }
        printf("Error opening Destination file\n");
        return;
    }
    printf("Error Opening source file\n");
    return;
}
void encrypt(const char *dstFileName ){
    FILE *filePtr,*encryptFilePtr;
    char ch;
    printf("Enter key u need to shift [1-26]\n");
    scanf("%d",&key);
    filePtr = fopen(dstFileName,"r");
    encryptFilePtr = fopen("encrypt.txt","w");
    if(filePtr){
        if(encryptFilePtr){
            while((ch = fgetc(filePtr))!=EOF){
                if(ch!=' ')
                    fputc(ch + key, encryptFilePtr);
                else
                    fputc(ch,encryptFilePtr);
        }
        fclose(encryptFilePtr);
        fclose(filePtr);
        printf("File contents encrypted\n");
        readFile("encrypt.txt");
        return;
        }
        printf("error creating encrypted file from function %a\n",__FUNCTION__);
        return;
    }
    printf("error opening source file from function %a\n",__FUNCTION__);
    return;
}
void decrypt(){
    FILE *filePtr;
    char ch;
    appendContent[0] = '\0';
    filePtr = fopen("encrypt.txt","r");
    if(filePtr){
        printf("\nDecrypted Content\n");
        while((ch = fgetc(filePtr))!=EOF){
            if(ch!=' ')
                printf("%c",ch - key);
            else
                printf("%c",ch);
        }
        fclose(filePtr);
        return;
    }
    printf("Encrypted file not opened\n");
    return;
}
void wordSearch(const char *filename){
    FILE *filePtr;
    receivedContent[0] = '\0';
    filePtr = fopen(filename,"r");
    if(filePtr){
        char key;
        printf("Enter keyword to search\n");
        scanf(" %c",&key);
        while(fscanf(filePtr,"%s",receivedContent)!=EOF){
            if(toupper(receivedContent[0])==toupper(key)){
                printf("%s\n",receivedContent);
            }
        }
        fclose(filePtr);
        return;
    }
    printf("Error in opening file\n");
    return;
}
int main(){
    FILE *filePtr;
    printf("Enter Filename\n");
    scanf("%s",filename);
    filePtr = fopen(filename,"w");
    if(filePtr){
        printf("File Created Successfully\nWhat do u want to write in the file?");
        fflush(stdin);
        fgets(content,sizeof(content),stdin);
        //scanf("%[^\n]s",content);
        fputs(content,filePtr);
        fclose(filePtr);
        printf("Content put in file successfully\n");
    }
    else{
        printf("Memory not alloted for creating file");
        return -1;
    }
    readFile(filename);
    filePtr = fopen(filename,"a");
    if(filePtr){
        
        printf("Enter the content u want to append\n");
        fflush(stdin);
        fgets(appendContent,sizeof(appendContent),stdin);
        fputs(appendContent,filePtr);
        printf("Content appended in file\n");
        fclose(filePtr);
    }
    readFile(filename);
    countFile(filename);
    copy(filename);
    encrypt(dstFileName);
    decrypt(key);
    wordSearch(filename);
}