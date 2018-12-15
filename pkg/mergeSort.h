
#ifndef MERGE_SORT
#define MERGE_SORT

#include "sortingAlgs.h"

class mergeSort : public sortingAlgs {
 public:
  virtual ~mergeSort();
  template < class T >
    static void sort( std::vector< T >& );

 private:
  mergeSort();
};

mergeSort::mergeSort() {}
mergeSort::~mergeSort() {}

template < class T >
void mergeSort::sort( std::vector< T > &input ) {
  if ( input.size() < 2 ) return;

  const int index = input.size()/2; 
  std::vector< T > lowerArray( input.begin(),input.begin() + index );
  std::vector< T > upperArray( input.begin() + index, input.end() );

  mergeSort::sort( lowerArray );
  mergeSort::sort( upperArray );

  unsigned int indexA = 0;
  unsigned int indexB = 0;
  for ( unsigned int i(0); i<input.size(); i++ ) {
    if ( indexA == lowerArray.size() )
      input.at(i) = upperArray.at( indexB++ );
    else if ( indexB == upperArray.size() )
      input.at(i) = lowerArray.at( indexA++ );
    else if ( lowerArray.at( indexA ) <= upperArray.at( indexB ) )
      input.at(i) = lowerArray.at( indexA++ );
    else 
      input.at(i) = upperArray.at( indexB++ );
  }
}

#endif
