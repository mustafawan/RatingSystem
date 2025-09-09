#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int userID;
    int itemID;
    float rating;
    struct Node* next;
} Node;

Node* head = NULL;

// Helper: Find node
Node* findNode(int userID, int itemID) {
    Node* current = head;
    while (current != NULL) {
        if (current->userID == userID && current->itemID == itemID) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// INSERT command
void insertRating(int userID, int itemID, float rating) {
    Node* existing = findNode(userID, itemID);
    if (existing != NULL) {
        existing->rating = rating;
        printf("Customer rating (%d, %d) is updated\n", userID, itemID);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->userID = userID;
    newNode->itemID = itemID;
    newNode->rating = rating;
    newNode->next = head;
    head = newNode;

    printf("Customer rating (%d, %d) is added successful\n", userID, itemID);
}

// RATING command
void getRating(int userID, int itemID) {
    Node* node = findNode(userID, itemID);
    if (node != NULL) {
        printf("Customer rating (%d, %d) is: %.1f\n", userID, itemID, node->rating);
    } else {
        printf("Customer rating (%d, %d) is: 0.0\n", userID, itemID);
    }
}

// AVERAGE command
void averageRating(int itemID) {
    Node* current = head;
    float sum = 0;
    int count = 0;

    while (current != NULL) {
        if (current->itemID == itemID) {
            sum += current->rating;
            count++;
        }
        current = current->next;
    }

    if (count > 0) {
        printf("Average rating (%d) is: %.1f\n", itemID, sum / count);
    } else {
        printf("Average rating (%d) is: 0.0\n", itemID);
    }
}

// REMOVE command
void removeRating(int userID, int itemID) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->userID == userID && current->itemID == itemID) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Customer rating (%d, %d) is removed successful\n", userID, itemID);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Customer rating (%d, %d) does not exist\n", userID, itemID);
}

// Main loop
int main() {
    char command[100];

    while (fgets(command, sizeof(command), stdin)) {
        char cmd[10];
        int userID, itemID;
        float rating;

        if (sscanf(command, "%s %d %d %f", cmd, &userID, &itemID, &rating) == 4 && strcmp(cmd, "INSERT") == 0) {
            insertRating(userID, itemID, rating);
        } else if (sscanf(command, "%s %d %d", cmd, &userID, &itemID) == 3 && strcmp(cmd, "RATING") == 0) {
            getRating(userID, itemID);
        } else if (sscanf(command, "%s %d %d", cmd, &userID, &itemID) == 3 && strcmp(cmd, "REMOVE") == 0) {
            removeRating(userID, itemID);
        } else if (sscanf(command, "%s %d", cmd, &itemID) == 2 && strcmp(cmd, "AVERAGE") == 0) {
            averageRating(itemID);
        }
    }

    return 0;
}
