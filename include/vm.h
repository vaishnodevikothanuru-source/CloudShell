#ifndef VM_H
#define VM_H

void list_vms(void);
void start_vm(const char *name);
void stop_vm(const char *name);
void status_vm(const char *name);

#endif
