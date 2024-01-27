#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countCharacterType(const char *password, int *countUpperCase, int *countLowerCase, int *countDigits, int *countSpecialChars) {
    int i, length;
    length = strlen(password);
    
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            (*countUpperCase)++;
        } else if (islower(password[i])) {
            (*countLowerCase)++;
        } else if (isdigit(password[i])) {
            (*countDigits)++;
        } else {
            (*countSpecialChars)++;
        }
    }
    return length;
}

int main() {
    char password[50];
    int length = 0, countUpperCase = 0, countLowerCase = 0, countDigits = 0, countSpecialChars = 0;

    printf("Enter the password: ");
    scanf("%s", password);

    length = countCharacterType(password, &countUpperCase, &countLowerCase, &countDigits, &countSpecialChars);

    // Evaluate password strength
    int strength = 0;
    if (length >= 8 && countUpperCase > 0 && countLowerCase > 0 && countDigits > 0 && countSpecialChars > 0) {
        strength = 4;
    } else if (length >= 8 && ((countUpperCase > 0 && countLowerCase > 0) || (countLowerCase > 0 && countDigits > 0) || (countDigits > 0 && countSpecialChars > 0) || (countSpecialChars > 0 && countUpperCase > 0))) {
        strength = 3;
    } else if (length >= 8 && (countUpperCase > 0 || countLowerCase > 0 || countDigits > 0 || countSpecialChars > 0)) {
        strength = 2;
    } else {
        strength = 1;
    }

    // Print password strength
    switch (strength) {
        case 4:
            printf("Strong password!\n");
            break;
        case 3:
            printf("Moderate password. Improve further for better security.\n");
            break;
        case 2:
            printf("Weak password. Include more diverse character types.\n");
            break;
        case 1:
            printf("Very weak password. Consider a longer and more diverse combination of characters.\n");
            break;
        default:
            printf("Invalid password strength.\n");
            break;
    }

    return 0;
}
