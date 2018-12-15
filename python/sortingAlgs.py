
import random

class sortingAlgs:
    pass

class quickSort( sortingAlgs ):
    @staticmethod
    def sort( input ):
        if len( input ) < 2 :
            return

        index = random.randint( 0,len( input ) - 1 )
        pivot = input[ index ]
        
        lowerArray = [x for x in input if x < pivot]
        sameArray  = [x for x in input if x == pivot]
        upperArray = [x for x in input if x > pivot]

        quickSort.sort( lowerArray )
        quickSort.sort( upperArray )

        sortedArray = lowerArray + sameArray + upperArray
                
        indexInput = 0
        for index in range( 0,len(sortedArray) ):
            input[indexInput] = sortedArray[index]
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

