
#include <iostream>
#include "../pkg/quickSort.h"

template < class T >
void print( std::vector<T>& );

int main() {
  std::vector< int > arrayInt;
  std::vector< double > arrayDouble;

  TRandom3 rdm( 0 );

  for ( int i=0;i<10;i++ ) {
    arrayInt.push_back( rdm.Integer(20) );
    arrayDouble.push_back( rdm.Rndm() );
  }

  print( arrayInt );
  quickSort::sort( arrayInt );
  print( arrayInt );

  std::cout<<std::endl;

  print( arrayDouble );
  quickSort::sort( arrayDouble );
  print( arrayDouble );
}

template < class T >
void print( std::vector<T>& input ) {
  for (unsigned int i(0);i<input.size();i++)
    std::cout << input.at(i) << " ";
  std::cout<<std::endl;
}
