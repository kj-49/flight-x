#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG
    #define d_printf(...) printf(__VA_ARGS__)
#else
    #define d_printf(...) ((void)0)
#endif

#endif
