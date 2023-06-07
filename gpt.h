#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct Partition_Entry {
        u_int8_t Partition_Type_GUID[16];
        u_int8_t Unique_Partition_GUID[16];
        u_int64_t First_LBA;
        u_int64_t Last_LBA;
        u_int8_t Attribute_Flag[8];
        u_int8_t Partition_name_36[72];
};