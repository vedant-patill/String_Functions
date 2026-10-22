#include <stdio.h>
#include <string.h>

int main() {
    int choice, cmp;
    char str1[100], str2[100];
    char ch;
    char *ptr;

    do {
        // Display the menu
        printf("\n=================================\n");
        printf("    STRING OPERATIONS MENU (C)   \n");
        printf("=================================\n");
        printf("1. Find String Length (strlen)\n");
        printf("2. Copy String (strcpy)\n");
        printf("3. Concatenate Strings (strcat)\n");
        printf("4. Compare Strings (strcmp)\n");
        printf("5. Find Character in String (strchr)\n");
        printf("6. Find Substring (strstr)\n");
        printf("7. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in the buffer by scanf

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove trailing newline
                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter source string to copy: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                strcpy(str2, str1);
                printf("String copied successfully!\n");
                printf("Destination String (str2): %s\n", str2);
                break;

            case 3:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter second string to append: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                cmp = strcmp(str1, str2);
                if (cmp == 0)
                    printf("Both strings are equal.\n");
                else if (cmp > 0)
                    printf("First string is greater than second string.\n");
                else
                    printf("First string is smaller than second string.\n");
                break;

            case 5:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter character to search: ");
                scanf("%c", &ch);
                getchar(); // Consume newline
                ptr = strchr(str1, ch);
                if (ptr != NULL)
                    printf("Character '%c' found at position %ld.\n", ch, (ptr - str1) + 1);
                else
                    printf("Character '%c' not found in the string.\n", ch);
                break;

            case 6:
                printf("Enter main string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter substring to find: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                ptr = strstr(str1, str2);
                if (ptr != NULL)
                    printf("Substring found starting at position %ld.\n", (ptr - str1) + 1);
                else
                    printf("Substring not found.\n");
                break;

            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }

    } while (choice != 7);

    return 0;
}