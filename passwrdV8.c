#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* create_password(int length, const char* uppercase_letters, const char* lowercase_letters, const char* digits, const char* special_chars) {
    static char generated_password[30]; // Store the generated password in a local static variable to prevent memory leaks
    int i;
    for (i = 0; i < length; i++) {
        if (i % 4 == 0) {
            generated_password[i] = uppercase_letters[rand() % strlen(uppercase_letters)];
        } else if (i % 4 == 1) {
            generated_password[i] = lowercase_letters[rand() % strlen(lowercase_letters)];
        } else if (i % 4 == 2) {
            generated_password[i] = digits[rand() % strlen(digits)];
        } else {
            generated_password[i] = special_chars[rand() % strlen(special_chars)];
        }
    }
    generated_password[length] = '\0'; // Null-terminate the password string
    return generated_password;
}

void hussle_order(char* str, int length) {
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Choose a random index within the unsorted range
        char temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    const char* uppercase_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* lowercase_letters = "abcdefghijklmnopqrstuvwxyz";
    const char* digits = "0123456789";
    const char* special_chars = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    int password_length;

    printf("Enter the desired password length: ");
    scanf("%d", &password_length);

    char* generated_password = create_password(password_length, uppercase_letters, lowercase_letters, digits, special_chars);
    hussle_order(generated_password, password_length);

    printf("Generated password (hussled order): %s\n", generated_password);

    // No need to free the memory allocated for generated_password since it's a static local variable in create_password() function

    return 0;
}

