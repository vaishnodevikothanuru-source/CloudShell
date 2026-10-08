#include <stdio.h>
#include "network.h"

void list_network(void)
{
    printf("\nCloud Networks:\n");
    printf("-----------------------------\n");
    printf("public-network\n");
    printf("private-network\n");
    printf("database-network\n");
}

void network_status(void)
{
    printf("\nNetwork Status\n");
    printf("-----------------------------\n");
    printf("Internet Connection : ACTIVE\n");
    printf("Private Network     : ACTIVE\n");
    printf("Firewall             : ENABLED\n");
}
