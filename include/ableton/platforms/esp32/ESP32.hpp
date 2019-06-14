
#pragma once

#include <byteswap.h>

#ifndef ntohll
#define ntohll(x) __bswap_64(x)
#endif

#ifndef htonll
#define htonll(x) __bswap_64(x)
#endif
