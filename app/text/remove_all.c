/**
 * remove_all.c -- реализует функцию очистки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Удаляет весь текст
 * 
 * @param txt текст
 * @returns none
 */
void remove_all(text txt)
{
    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }    

    if (txt->length == 0) {
        return;
    }

    assert(txt->begin != NULL && txt->end != NULL);

    node *current = txt->begin;

    do {
        node *next = current->next;
        free(current);
        current = next;
    } while (current);

    txt->length = 0;
    txt->begin = NULL;
    txt->end = NULL;
    txt->cursor->line = NULL;
    txt->cursor->position = 0;
}
