#ifndef RH_H
#define RH_H

#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}

TEST(rh1, t1)
{
    text txt = create_text();
    FILE *f;
    char buf[MAXLINE + 1];
    char filepath[] = "tests/tuda";

    load(txt, filepath);

    rh(txt);

    node *current = txt->begin;
    int index = 0, count = 0;


    if ((f = fopen("tests/tuda", "r")) == NULL) {
        FAIL();
    }

    while (fgets(buf, MAXLINE, f)) {
        if (current && index > 0){

                ASSERT_STREQ(buf, current->contents);

                count++;

                current = current->next;
            }
        index++;
    }

    EXPECT_EQ(count, 4);

    fclose(f);

    SUCCEED();
}

#endif // RH_H
