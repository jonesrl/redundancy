#define CATCH_CONFIG_MAIN

// avoid tons of warnings that I can't fix
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#pragma GCC diagnostic pop
#include "catch.hpp"
#endif
