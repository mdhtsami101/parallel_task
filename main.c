#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
    int isActive;
};

struct User users[10];
int userCount = 0;

void addUser(char *username, char *password, int isActive) {
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    users[userCount].isActive = isActive;
    userCount++;
}

int login(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return users[i].isActive;
        }
    }
    return 0;
}

void registerUser() {
    if (userCount >= 10) {
        printf("User registration limit reached.\n");
        return;
    }

    char username[50];
    char password[50];
    int isActive;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter user activity (1 for active, 0 for inactive): ");
    scanf("%d", &isActive);

    addUser(username, password, isActive);
    printf("User registered successfully.\n");
}

void authentication() {
         addUser("medhat", "123", 1);
         addUser("sami", "123", 0);
         char username[50];
         char password[50];

        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        int isActive = login(username, password);
        if (isActive) {
        printf("Login successful.\n");
        } else {
        printf("Invalid username or password, or inactive user.\n");
    }

    }

int main() {
    char stutes[50];
    printf("login or register: \n");
    scanf("%s", stutes);

    if (strcmp(stutes, "register") == 0) {
        printf("Enter username & password & inactive user.\n");
        registerUser();
        printf("************ Login Now ************** \n");
        authentication();
    } else if (strcmp(stutes, "login") == 0) {
        authentication();
    } else {
      printf("Invalid input.\n");
    }
    return 0;
}




