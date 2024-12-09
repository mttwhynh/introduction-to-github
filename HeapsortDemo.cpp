#include <iostream>
using namespace std;

// Binary max-heap percolate down
void MaxHeapPercolateDown(int nodeIndex, int* heapArray, int heapSize) {
   int childIndex = 2 * nodeIndex + 1;
   int value = heapArray[nodeIndex];
      
   while (childIndex < heapSize) {
      // Find the max among the node and all the node's children
      int maxValue = value;
      int maxIndex = -1;
      int i = 0;
      while (i < 2 && i + childIndex < heapSize) {
         if (heapArray[i + childIndex] > maxValue) {
            maxValue = heapArray[i + childIndex];
            maxIndex = i + childIndex;
         }
         i++;
      }
         
      if (maxValue == value) {
         return;
      }
         
      // Swap heapArray[nodeIndex] and heapArray[maxIndex]
      int temp = heapArray[nodeIndex];
      heapArray[nodeIndex] = heapArray[maxIndex];
      heapArray[maxIndex] = temp;
         
      nodeIndex = maxIndex;
      childIndex = 2 * nodeIndex + 1;
   }
}
   
// Sorts the array of numbers using the heap sort algorithm
void HeapSort(int* numbers, int numbersLength) {
   // Heapify numbers array
   int i = numbersLength / 2 - 1;
   while (i >= 0) {
      MaxHeapPercolateDown(i, numbers, numbersLength);
      i--;
   }
                
   i = numbersLength - 1;
   while (i > 0) {
      // Swap numbers[0] and numbers[i]
      int temp = numbers[0];
      numbers[0] = numbers[i];
      numbers[i] = temp;

      MaxHeapPercolateDown(0, numbers, i);
      i--;
   }
}

int main() {
   int numbers[] = { 82, 36, 49, 82, 34, 75, 18, 9, 23 };
   int numbersLength = sizeof(numbers) / sizeof(numbers[0]);
   cout << "UNSORTED: [";
   for (int i = 0; i < numbersLength - 1; i++) {
      cout << numbers[i] << ", ";
   }
   cout << numbers[numbersLength - 1] << "]" << endl;
      
   HeapSort(numbers, numbersLength);
   cout << "SORTED:   [";
   for (int i = 0; i < numbersLength - 1; i++) {
      cout << numbers[i] << ", ";
   }
   cout << numbers[numbersLength - 1] << "]" << endl;
}
