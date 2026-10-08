#include <stdio.h>
#include "storage.h"

void list_storage(void)
{
    printf("\nCloud Storage:\n");
    printf("-----------------------------\n");
    printf("storage-main    100 GB\n");
    printf("backup-storage  250 GB\n");
    printf("database-disk   500 GB\n");
}

void create_storage(const char *name)
{
    printf("Creating storage '%s'...\n", name);
    printf("Storage '%s' created successfully.\n", name);
}

void delete_storage(const char *name)
{
    printf("Deleting storage '%s'...\n", name);
    printf("Storage '%s' deleted successfully.\n", name);
}
