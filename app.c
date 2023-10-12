
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct User {
    char username[50];
    char password[50];
};

struct User users[10];
int userCount = 0;

int main() {
    addUser("medhat", "0123");
    addUser("sami", "0123");

    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if ( login(username, password)== 1) {
        printf("Login successful.\n");
    } else {
        printf("Invalid username or password.\n");
    }

    return 0;
}

void addUser(char *username, char *password) {
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
}

int login(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}


