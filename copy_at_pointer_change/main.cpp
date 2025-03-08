#include <WITCH/WITCH.h>

#include <stdio.h>

#include <WITCH/generic_alloc.h>

struct st_t;
struct st_t{
  uint32_t i;
  st_t *This = NULL;

  st_t(){
    This = this;
  }
  st_t(const st_t &st){
    This = this;
  }
};

#define BLL_set_prefix bll
#define BLL_set_Language 1
#define BLL_set_CPP_Node_ConstructDestruct 1
#define BLL_set_CPP_CopyAtPointerChange 1
#define BLL_set_NodeDataType st_t
#define BLL_set_type_node uint8_t
#define BLL_set_nrtra 1
#include <BLL/BLL.h>

int main(){
  bll_t bll;
  bll.Open();

  for(auto i = 160; i--;){
    bll.GetNodeUnsafe(bll.NewNode())->data.i = i;
  }

  bll_t::nrtra_t traverse;
  bll_NodeReference_t node_id;
  traverse.Open(&bll, &node_id);
  while(traverse.Loop(&bll, &node_id)){
    if(bll.GetNodeUnsafe(node_id)->data.This != &bll.GetNodeUnsafe(node_id)->data){
      __abort();
    }
    bll.GetNodeUnsafe(node_id)->data.This->i = 0;
  }

  bll.Close();

  return 0;
}
