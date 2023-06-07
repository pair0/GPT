#include "gpt.h"

int main(int argc, char **argv){
    if (argc != 2) {
    printf("Usage: %s <file 1>\n", *(argv+0));
    return 0;
    }

    FILE *fp;
    struct Partition_Entry * PTE = (struct Partition_Entry *)malloc(sizeof(struct Partition_Entry));
    fp = fopen(*(argv+1), "rb");
    fseek(fp, 1024, SEEK_SET);
    
    while(1){
        fread(PTE, sizeof(* PTE), 1, fp);
        if(PTE->First_LBA == 0 && PTE->First_LBA == 0) break; //partition Entry 값이 존재하지 않으면 종료  

        //GUID
        for(int i=0; i < sizeof(PTE->Partition_Type_GUID); i++)
            printf("%02x", *(PTE->Partition_Type_GUID+i));
        for(int i=0; i < sizeof(PTE->Unique_Partition_GUID); i++)
            printf("%02x", *(PTE->Unique_Partition_GUID+i));
        printf(" ");

        //실제리얼offsetsector
        printf("%ld", PTE->First_LBA*512);
        printf(" ");

        //사이즈
        printf("%ld", ((PTE->Last_LBA - PTE->First_LBA + 1) * 512));
        printf("\n");
    }
    free(PTE);
    fclose(fp);
}
