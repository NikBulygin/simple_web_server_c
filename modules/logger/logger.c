#include "logger.h"


#include <stdio.h>
#include <time.h>

void logger(const char *message)
{
    char filename[100];
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    // Форматируем имя файла с текущей датой
    strftime(filename, sizeof(filename), LOGGER_PATH_FILE "%Y-%m-%d.log", tm_info);

    // Открываем файл для добавления
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Ошибка при открытии файла лога");
        return;
    }

    // Записываем сообщение в файл
    fprintf(file, "%s\n", message);
    fclose(file);

#ifdef DEBUG
    // Выводим сообщение в консоль, если в режиме отладки
    printf("%s\n", message);
#endif
}
