
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>
#include <vector>
#include "TRandom3.h"

class quickSort {
 public:
  template < class T >
    static void sort( std::vector< T >& );

 private:
  quickSort();
  template <class T>
    static std::vector< T > sortArray( const std::vector< T >& );

 private:
  static std::unique_ptr< TRandom3 > m_rdm;
};

std::unique_ptr< TRandom3 > quickSort::m_rdm( new TRandom3(0) );

quickSort::quickSort() {}

template <class T>
void quickSort::sort( std::vector< T > &input ) { input = sortArray( input ); }

template <class T>
std::vector< T > quickSort::sortArray( const std::vector< T > &input ) {
  if ( input.size() < 2 ) return input;
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

  std::vector< T > sortedLowerArray = sortArray( lowerArray );
  std::vector< T > sortedUpperArray = sortArray( upperArray );

  std::vector< T > output = sortedLowerArray;
  output.insert( output.end(),sameArray.begin(),sameArray.end() );
  output.insert( output.end(),sortedUpperArray.begin(),sortedUpperArray.end() );
  return output;
}

#endif
