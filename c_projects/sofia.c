#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGE_LENGTH 10000 // Adjust this based on your actual data size
#define DATABASE_PAGES 300
#define KEYWORD_MAX_LENGTH 100

// Function to find occurrences of a keyword in a page
int findKeywordInPage(const char *page, const char *keyword) {
    int count = 0;
    const char *ptr = page;

    while ((ptr = strstr(ptr, keyword)) != NULL) {
        count++;
        ptr += strlen(keyword);
    }

    return count;
}

int main() {
    FILE *file;
    char buffer[MAX_PAGE_LENGTH];
    char keyword[KEYWORD_MAX_LENGTH];
    int page = 0;
    int totalMatches = 0;

    // Input: Keyword to search
    printf("Enter the keyword to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    strtok(keyword, "\n"); // Remove newline character

    // Open the database file
    file = fopen("data_base.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, "<b>")) {
            // Extract page number
            sscanf(buffer, "<b>%d/%*d</b>", &page);
        } else {
            // Check for keyword occurrences in the current page
            int matchesInPage = findKeywordInPage(buffer, keyword);

            if (matchesInPage > 0) {
                printf("Keyword found %d times on Page %d\n", matchesInPage, page);
                totalMatches += matchesInPage;
            }
        }
    }

    printf("Total keyword occurrences in the database: %d\n", totalMatches);

    // Close the file
    fclose(file);

    return 0;
}
