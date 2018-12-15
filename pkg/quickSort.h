
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "sortingAlgs.h"

class quickSort : public sortingAlgs {
 public:
  virtual ~quickSort(); 
  template < class T >
    static void sort( std::vector< T >& );

 private:
  quickSort();
};

quickSort::quickSort() {}
quickSort::~quickSort() {} 

template <class T>
void quickSort::sort( std::vector< T > &input ) {
  if ( input.size() < 2 ) return;
  std::vector< T > lowerArray;
  std::vector< T > sameArray;
  std::vector< T > upperArray;

  const int index = m_rdm->Integer( input.size() );
  const T pivot = input.at( index );

  for ( int i(0); i<input.size(); i++ ) {
    if ( input.at(i) < pivot ) lowerArray.push_back( input.at(i) );
    else if ( input.at(i) == pivot ) sameArray.push_back( input.at(i) );
    else upperArray.push_back( input.at(i) );
  } 

  quickSort::sort( lowerArray );
  quickSort::sort( upperArray );

  input = lowerArray;
  input.insert( input.end(),sameArray.begin(),sameArray.end() );
  input.insert( input.end(),upperArray.begin(),upperArray.end() );
  return;
}

#endif
