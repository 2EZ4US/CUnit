#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/Basic.h"

#define GENERIC void*
#define INTEGER long int

#define MAX_HEAP_SIZE (1 << 9)


#include "basic_structures/hash.h"
#include "basic_structures/tree.h"
#include "basic_structures/list.h"
#include "basic_structures/heap.h"