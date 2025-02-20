#include <stdio.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "log.txt"

void getTimestamp(char *buffer, int size) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", timeinfo);
}


void logMessage(const char *level, const char *message) {
    FILE *filePtr = fopen(LOG_FILE, "a"); 
    if (filePtr) {
        char timestamp[20];
        getTimestamp(timestamp, sizeof(timestamp));
        fprintf(filePtr, "[%s] [%s] %s\n", timestamp, level, message);
        fclose(filePtr);
        printf("Log recorded: [%s] [%s] %s\n", timestamp, level, message);
    } else {
        printf("Error: Could not open log file!\n");
    }
}

int main() {
    logMessage("INFO", "Application started");
    logMessage("WARNING", "Low memory warning");
    logMessage("ERROR", "File not found error");

    return 0;
}
