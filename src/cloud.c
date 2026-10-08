#include <stdio.h>
#include "cloud.h"

static int logged_in = 0;

void cloud_login(void)
{
    if (logged_in)
    {
        printf("Already logged in to cloud.\n");
        return;
    }

    logged_in = 1;
    printf("Cloud login successful.\n");
}

void cloud_logout(void)
{
    if (!logged_in)
    {
        printf("You are not logged in.\n");
        return;
    }

    logged_in = 0;
    printf("Logged out from cloud.\n");
}

void cloud_status(void)
{
    if (logged_in)
        printf("Cloud Status: CONNECTED\n");
    else
        printf("Cloud Status: DISCONNECTED\n");
}
