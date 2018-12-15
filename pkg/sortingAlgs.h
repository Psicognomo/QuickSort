
#ifndef SORTING_ALGS
#define SORTING_ALGS

#include <iostream>
#include <vector>
#include "TRandom3.h"

class sortingAlgs {
 public:
  virtual ~sortingAlgs();

 protected:
  sortingAlgs();

 protected:
  static std::unique_ptr< TRandom3 > m_rdm;
};

std::unique_ptr< TRandom3 > sortingAlgs::m_rdm( new TRandom3(0) );

sortingAlgs::sortingAlgs() {}
sortingAlgs::~sortingAlgs() {}

#endif
