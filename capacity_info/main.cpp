#include <WITCH/WITCH.h>

#include <stdio.h>

#include <WITCH/generic_alloc.h>

typedef struct{
  uint8_t arr[1];
}st_t;

#define BLL_set_prefix bll
#define BLL_set_Language 0
#define BLL_set_NodeDataType st_t
#define BLL_set_type_node uint8_t
#define BLL_set_CapacityUpdateInfo \
  printf("old_capacity: %u new_capacity: %u\n", old_capacity, new_capacity);
#include <BLL/BLL.h>

int main(){
  bll_t bll;
  bll_Open(&bll);

  for(auto i = 160; i--;){
    bll_NewNode(&bll);
  }

  bll_Close(&bll);

  return 0;
}
