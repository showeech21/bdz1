#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *osMonitoring(void *arg) {
    // Мониторинг ОС
    while (1) {
        // Работа мониторинга ОС
        printf("Выполняется мониторинг ОС...\n");
        // Можно также записывать результаты в файл
        FILE *fp;
        fp = fopen("os_monitoring_log.txt", "a");
        if (fp != NULL) {
            fprintf(fp, "Выполняется мониторинг ОС...\n");
            fclose(fp);
        }
        sleep(10);  // Подождать 10 секунд
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t systemThread, osThread;
    int sysThread = pthread_create(&systemThread, NULL, systemWork, NULL);
    int osThread = pthread_create(&osThread, NULL, osMonitoring, NULL);
    if (sysThread || osThread) {
        fprintf(stderr, "Ошибка создания потока\n");
        return 1;
    }

    // Ждем завершения потоков
    pthread_join(systemThread, NULL);
    pthread_join(osThread, NULL);

    return 0;
}
