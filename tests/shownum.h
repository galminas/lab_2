#ifndef SHOWNUM_H
#define SHOWNUM_H

#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}

TEST(shownum1, t1)
{
    text txt = create_text();
    FILE *f;
    char buf[MAXLINE + 1];
    char filepath[] = "tests/tuda";

    load(txt, filepath);

    m(txt, 5, 3);
    show(txt, 1);

    if ((f = fopen("tests/shownum", "r")) == NULL) {
        FAIL();
    }

    int index = 1;

    node *current = txt->begin;

    while (fgets(buf, MAXLINE, f)) {
        EXPECT_EQ(atoi(buf), index);
        if (current && index < 5){
                EXPECT_EQ(strlen(current->contents), strlen(buf) - 2);

                current = current->next;
         }
           else if (index == 5) {
                    EXPECT_EQ(strlen(current->contents), strlen(buf) - 3);
               }
        index++;
    }


    fclose(f);

    SUCCEED();
}

#endif // SHOWNUM_H
