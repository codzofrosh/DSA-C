#include<stdio.h>
#define encryptedFile "encrypt.txt"
#define decryptedFile "decrypt.txt"
#define originalFile "original.txt"
char contentToEncrypt[255],receivedContent[255];
void encrypt(){
    char current,prev;
    int count=1;
    FILE *originalPtr = fopen(originalFile,"r");
    FILE *encryptfileptr = fopen(encryptedFile,"w");
    prev = fgetc(originalPtr);
    if(originalPtr){
        if(encryptfileptr){
            while((current = fgetc(originalPtr))!=EOF){
                if(current==prev)
                    count+=1;
                else{
                    fprintf(encryptfileptr,"%d%c",count,prev);
                    prev = current;
                    count=1;
                }
            }
            fprintf(encryptfileptr, "%d%c", count, prev);
            fclose(encryptfileptr);
            fclose(originalPtr);
        }
        else{
            printf("New file cannot be opened\n");
            return;
        }
    }
    else{
        printf("Original file cannot be opened\n");
        return;
    }
}
void decrypt(){
    int count;
    char ch;
    FILE *encrypt,*decrypt;
    encrypt = fopen(encryptedFile,"r");
    decrypt = fopen(decryptedFile,"w");
    if(encrypt){
        if(decrypt){
            while(fscanf(encrypt,"%d%c",&count,&ch)==2){
                for(int i=0;i<count;i++)
                    fputc(ch,decrypt);
            }
            fclose(encrypt);
            fclose(decrypt);
        }
        else{
            printf("Cannot open the decrypt file\n");
            return;
        }
    }
    else{
        printf("Cannot open encrypted file\n");
        return;
    }

}
void viewContent(const char *file){
    FILE *filePtr;
    filePtr = fopen(file,"r");
    if(filePtr){
        while(fgets(receivedContent,sizeof(receivedContent),filePtr)){
            printf("%s",receivedContent);
        }
    }
}
void main(){
    printf("Enter content to be encoded. Eg:AAAABBBCCDAA\n");
    fflush(stdin);
    fgets(contentToEncrypt,sizeof(contentToEncrypt),stdin);
    FILE *filePtr;
    filePtr = fopen(originalFile,"w");
    if(filePtr){
        fputs(contentToEncrypt,filePtr);
        fclose(filePtr);
    }
    else{
        printf("File cannot be created\n");
        return;
    }
    encrypt();
    printf("Encrypted content\n");
    viewContent(encryptedFile);
    decrypt();
    printf("Decrypted Content\n");
    viewContent(decryptedFile);
}