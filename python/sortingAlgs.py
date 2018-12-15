
import random

class sortingAlgs:
    pass

class quickSort( sortingAlgs ):
    @staticmethod
    def sort( input ):
        if len( input ) < 2 :
            return
        
        lowerArray = []
        sameArray  = []
        upperArray = []

        index = random.randint( 0,len( input ) - 1 )
        pivot = input[ index ]

        for el in input:
            if el < pivot:
                lowerArray.append( el )
            elif el == pivot:
                sameArray.append( el )
            else:
                upperArray.append( el )

        quickSort.sort( lowerArray )
        quickSort.sort( upperArray )
                
        indexInput = 0
        for index in range( 0,len(lowerArray) ):
            input[indexInput] = lowerArray[index]
            indexInput += 1
        for index in range( 0,len(sameArray) ):
            input[indexInput] = sameArray[index]
            indexInput += 1
        for index in range( 0,len(upperArray) ):
            input[indexInput] = upperArray[index]
            indexInput += 1

class mergeSort( sortingAlgs ):
    @staticmethod
    def sort( input ):
        if len( input ) < 2 :
            return

        index = len( input )/2
        lowerArray = input[:index]
        upperArray = input[index:]
        
        mergeSort.sort( lowerArray )
        mergeSort.sort( upperArray )

        indexA = 0
        indexB = 0
        for i in range( 0,len(input) ):
            if indexA == len( lowerArray ):
                input[i] = upperArray[indexB]
                indexB += 1
            elif indexB == len( upperArray ):
                input[i] = lowerArray[indexA]
                indexA += 1
            elif lowerArray[indexA] <= upperArray[indexB]:
                input[i] = lowerArray[indexA]
                indexA += 1
            else:
                input[i] = upperArray[indexB]
                indexB += 1

