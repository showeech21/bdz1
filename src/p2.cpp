#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *systemWork(void *arg) {
    // Непосредственная работа системы
    while (1) {
        // Работа системы
        printf("Выполняется непосредственная работа системы...\n");
        // Можно также записывать результаты в файл
        FILE *fp;
        fp = fopen("system_log.txt", "a");
        if (fp != NULL) {
            fprintf(fp, "Выполняется непосредственная работа системы...\n");
            fclose(fp);
        }
        sleep(5);  // Подождать 5 секунд
    }
    pthread_exit(NULL);
}


