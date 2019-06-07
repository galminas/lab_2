/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Galminas Nikita <galminas@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"

static void show_line(text txt, int index, char *contents, int cursor, void *data);
static FILE *f;

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt, int par)
{

    f = fopen("tests/shownum", "w");

    process_forward(txt, show_line, &par);
    fclose(f);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(text txt, int index, char *contents, int cursor, void *data)
{

    int i = 0;

    assert(contents != NULL);

    UNUSED(txt);

    if(*((int*)data) == 1) {
        printf("%d ", index + 1);
        fprintf(f, "%d ", index + 1);
    }

    if(cursor >= 0)
    {
        for(i = 0; i < cursor; i++) {
            printf("%c", contents[i]);
            fprintf(f, "%c", contents[i]);
        }

        printf("|");
        fprintf(f, "%c", '|');

        for(i = cursor; i < (int)strlen(contents); i++) {
            printf("%c", contents[i]);
            fprintf(f, "%c", contents[i]);
        }
    } else {
        printf("%s", contents);
        fprintf(f, "%s", contents);
        }
}
