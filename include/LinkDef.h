#ifndef ROOT_TREE_VECTOR_LINKDEF_H 
#define ROOT_TREE_VECTOR_LINKDEF_H 1

#include <vector>

#ifdef __CINT__

#pragma link off all classes;
#pragma link off all typedef;

#pragma link C++ class std::vector<float>;
#pragma link C++ class std::vector<std::vector<float> >;

#endif

#endif
