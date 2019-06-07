#ifndef M_H
#define M_H

#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}

TEST(m1, t1)
{
    text txt = create_text();
    char filepath[] = "tests/tuda";

    load(txt, filepath);

    m(txt, 7, 1);


    node *current = txt->begin;
    int index = 0;

    while(current) {
        if (index == 6) {
            if (txt->cursor->position == 0) {
                SUCCEED();
            }   else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    SUCCEED();
}

TEST(m2, t2)
{
    text txt = create_text();
    char filepath[] = "tests/tuda";

    load(txt, filepath);

    m(txt, 2, 4);
    m(txt, 3, 7);
    m(txt, 10, 8);

    node *current = txt->begin;
    int index = 0;

    while(current) {
        if (index == 9) {
            if (txt->cursor->position == 7) {
                SUCCEED();
            }   else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    SUCCEED();
}

TEST(m3, t3)
{
    text txt = create_text();
    char filepath[] = "tests/tuda";

    load(txt, filepath);

    m(txt, 1, 8);
    rh(txt);

    node *current = txt->begin;
    int index = 0;

    while(current) {
        if (index == 0) {
            if (txt->cursor->position == 0) {
                SUCCEED();
            }   else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    SUCCEED();
}

TEST(m4, t4)
{
    text txt = create_text();
    char filepath[] = "tests/tuda";

    load(txt, filepath);

    m(txt, 5, 4);

    node *current = txt->begin;
    int index = 0;
    char *tost;

    while(current) {
        if (index == 4) {
            if (txt->cursor->position == 3) {
                tost = txt->cursor->line->contents;
            }   else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    m(txt, 5, 4);

    while(current) {
        if (index == 4) {
            if (txt->cursor->position == 3) {
                EXPECT_EQ(txt->cursor->line->contents, tost);
                SUCCEED();
            }   else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    SUCCEED();
}

#endif // M_H
