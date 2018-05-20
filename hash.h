#ifndef HASH_AHRT
#define HASH_AHRT

#define MAX_HASH_SIZE 256

typedef struct HASH {
    GENERIC *table;
} HASH;

GENERIC HASH_Create() {
    HASH *new_hash = (HASH*) malloc(sizeof(HASH));
    new_hash->table = calloc(MAX_HASH_SIZE, sizeof(GENERIC));
    return new_hash;
}

GENERIC HASH_Insert(HASH *hash, GENERIC data, INTEGER index) {
    hash->table[index] = data;
}

INTEGER HASH_Get_Size (HASH *hash)
{
	return MAX_HASH_SIZE;
}

GENERIC HASH_Get_hash_element (HASH *hash, INTEGER index)
{
	return hash->table[index];
}

#endif
