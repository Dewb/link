
#pragma once

#include <byteswap.h>

#ifndef ntohll
#define ntohll(x) __bswap_64(x)
#endif

#ifndef htonll
#define htonll(x) __bswap_64(x)
#endif

//dummy definitions to get this to build
//static char* if_indextoname(unsigned int , char* ) { return 0; }
//static unsigned int if_nametoindex(const char*) {return 0; }
