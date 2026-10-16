#ifndef AHBPROT_H
#define AHBPROT_H

#include <stdbool.h>

#define TEXT_RED   "\x1b[31m"
#define TEXT_GREEN "\x1b[32m"
#define TEXT_RESET "\x1b[0m"

bool is_ahbprot_disabled(void);
void display_ahbprot_state(void);

#endif