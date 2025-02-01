#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//The password generator takes a random seed based on unix time, 
//so in a case where the program is run twice within the same second, a duplicate value password will be generated
void ranPasswordGen(int pswdlength){
    pswdlength/=2;
    srand((unsigned int)(time(0))); //sets rand seed, keeping it unsigned lets rand generate upto 32678

    //character sets
    char lowercase[]="abcdefghijklmnopqrstuvwxyz";
    char uppercase[]="ABCDEFGHIJKLMNOQPRSTUYWVZX";
    char num[]="0123456789";
    char special[]="!@#$^&*?()[]-=_+";
    int charSets=4;
    char password[pswdlength];

    for(int i=1; i<=pswdlength; i++){
        int chooseCharSet = rand() % charSets;
        printf("%d",chooseCharSet);
        switch(chooseCharSet%4){
            case 0:
                password[i]=num[rand()%10];
                printf("%c", password[i]);
                break;
                
            case 1:
                password[i]=lowercase[rand()%26];
                printf("%c", password[i]);
                break;
            
            case 2:
                password[i]=uppercase[rand()%26];
                printf("%c", password[i]);
                break;

            case 3:  
                password[i]=special[rand()%16];
                printf("%c", password[i]);
                break;

            default:
                password[i]=special[rand()%16];
                printf("%c", password[i]);
        }

    }
}

int main(){
    ranPasswordGen(8);
    return 0;
}