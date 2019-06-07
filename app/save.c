/**
 * save.c -- реализует команду сохранения текста в указанный файл
 *
 * Copyright (c) 2017, Galminas Nikita <galminas@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void save_line(text txt, int index, char *contents, int cursor, void *data);

/**
 * Сохраняет содержимое файла в указанный файл
 */
void save(text txt, char *filename)
{
    FILE *fp;

    if ((fp = fopen(filename, "w")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }

    process_forward(txt, save_line, fp);
    fclose(fp);
}

/**
 * Сохраняет содержимое файла в указанный файл построчно
 */
static void save_line(text txt, int index, char *contents, int cursor, void *data)
{
    assert(contents != NULL);

    UNUSED(index);
    UNUSED(cursor);
    UNUSED(txt);

    fprintf((FILE*)data, "%s", contents);
}
