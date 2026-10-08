#include <stdio.h>
#include <string.h>
#include "vm.h"

typedef struct
{
    char name[30];
    char status[20];
} VM;

VM vm_list[] =
{
    {"web-server", "STOPPED"},
    {"database", "RUNNING"},
    {"app-server", "STOPPED"}
};

int vm_count = 3;

void list_vms(void)
{
    printf("\nVirtual Machines:\n");
    printf("-----------------------------\n");

    for (int i = 0; i < vm_count; i++)
    {
        printf("%-15s %s\n",
               vm_list[i].name,
               vm_list[i].status);
    }
}

void start_vm(const char *name)
{
    for (int i = 0; i < vm_count; i++)
    {
        if (strcmp(vm_list[i].name, name) == 0)
        {
            if (strcmp(vm_list[i].status, "RUNNING") == 0)
            {
                printf("VM '%s' is already running.\n", name);
                return;
            }

            strcpy(vm_list[i].status, "RUNNING");
            printf("VM '%s' started successfully.\n", name);
            return;
        }
    }

    printf("VM '%s' not found.\n", name);
}

void stop_vm(const char *name)
{
    for (int i = 0; i < vm_count; i++)
    {
        if (strcmp(vm_list[i].name, name) == 0)
        {
            if (strcmp(vm_list[i].status, "STOPPED") == 0)
            {
                printf("VM '%s' is already stopped.\n", name);
                return;
            }

            strcpy(vm_list[i].status, "STOPPED");
            printf("VM '%s' stopped successfully.\n", name);
            return;
        }
    }

    printf("VM '%s' not found.\n", name);
}

void status_vm(const char *name)
{
    for (int i = 0; i < vm_count; i++)
    {
        if (strcmp(vm_list[i].name, name) == 0)
        {
            printf("VM: %s\n", vm_list[i].name);
            printf("Status: %s\n", vm_list[i].status);
            return;
        }
    }

    printf("VM '%s' not found.\n", name);
}
