//------------------------------
// Edited By Pratik Patil      |
// Last Edited on 17/10/23    |
//----------------------------


#include <stdio.h>
#include <string.h>

char register_fn(char reg1[]) {
     char reg[5];
     int index = 0;
     while (index<strlen(reg1)){
         if (reg1[index] == ','){
            break;
         }
         reg[index] = reg1[index];
         index++;
     }
     reg[index] = '\0';
    
     if (strcmp(reg, "eax")==0){
       return '0';
     }else if (strcmp(reg, "ecx")==0){
       return '1';
     }else if (strcmp(reg, "edx")==0){
      return '2';
     }else if (strcmp(reg, "ebx")==0){
       return '3';
     }else if (strcmp(reg, "esp")==0){
       return '4';
     }else if (strcmp(reg, "ebp")==0){
       return '5';
     }else if (strcmp(reg, "esi")==0){
       return '6';
     }else if (strcmp(reg, "edi")==0){
       return '7';
     }else{
        return 'E';
     }
 
}

    

void hex_to_binary(char hex_digit) {
    switch (hex_digit) {
        case '0': printf("0000"); break;
        case '1': printf("0001"); break;
        case '2': printf("0010"); break;
        case '3': printf("0011"); break;
        case '4': printf("0100"); break;
        case '5': printf("0101"); break;
        case '6': printf("0110"); break;
        case '7': printf("0111"); break;
        case '8': printf("1000"); break;
        case '9': printf("1001"); break;
        case 'a': printf("1010"); break;
        case 'b': printf("1011"); break;
        case 'c': printf("1100"); break;
        case 'd': printf("1101"); break;
        case 'e': printf("1110"); break;
        case 'f': printf("1111"); break;
        default: printf("Invalid Hexadecimal Digit\n");
    }
    printf(" "); // Add a space after each 4-bit binary representation
}

int main() {
    char input1[10], input2[10], input3[10];
    char result[10] = "0x"; // Initialization of hex result variable
    FILE *inputFile = fopen("input.txt", "r"); // Open input file

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", input1) != EOF) {
        if (strcmp(input1, "rrmovl") == 0) {
            fscanf(inputFile, "%s %s", input2, input3);
            char reg1 = register_fn(input2);
            char reg2 = register_fn(input3);

            if (reg1 != 'E' && reg2 != 'E') {
                sprintf(result + 2, "20%c%c", reg1, reg2);
                printf("%s\n", result);

                // Convert hexadecimal to binary
                for (int i = 2; i < strlen(result); i++) {
                    hex_to_binary(result[i]);
                }
                printf("\n");
            } else {
                printf("Invalid register\n");
            }
        } else if (strcmp(input1, "hlt") == 0) {
            printf("0x00\n");

            // Convert hexadecimal to binary
            hex_to_binary('0');
            hex_to_binary('0');
            printf("\n");
        } else if (strcmp(input1, "nop") == 0) {
            printf("0x10\n");

            // Convert hexadecimal to binary
            hex_to_binary('1');
            hex_to_binary('0');
            printf("\n");
        } else {
            printf("Error: Invalid instruction\n");
            fclose(inputFile);
            return 1;
        }
    }

    fclose(inputFile);
    return 0;
}

