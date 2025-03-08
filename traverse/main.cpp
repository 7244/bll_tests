#include <WITCH/WITCH.h>

#include <stdio.h>

#include <WITCH/generic_alloc.h>

typedef struct{
  uint32_t i;
}st_t;

#define bcontainer_set_StoreFormat 1
#define BLL_set_prefix bll
#define BLL_set_Language 0
#define BLL_set_NodeDataType st_t
#define BLL_set_type_node uint8_t
#define BLL_set_nrtra 1
#include <BLL/BLL.h>

int main(){
  bll_t bll;
  bll_Open(&bll);

  for(auto i = 160; i--;){
    bll_GetNodeUnsafe(&bll, bll_NewNode(&bll))->data.i = i;
  }

  auto i = 160 - 1;
  bll_nrtra_t traverse;
  bll_NodeReference_t node_id;
  bll_nrtra_Open(&traverse, &bll, &node_id);
  while(bll_nrtra_Loop(&traverse, &bll, &node_id)){
    if(bll_GetNodeUnsafe(&bll, node_id)->data.i != (uint32_t)i){
      __abort();
    }

    i--;
  }
  if(i != (decltype(i))-1){
    __abort();
  }

  bll_Close(&bll);

  return 0;
}
