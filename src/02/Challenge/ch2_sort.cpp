// C++ Code Challenges, LinkedIn Learning

// Challenge #2: Sorting an Array
// Sort the elements in an array in ascending order.
// Implement the algorithm of your choice.
// Don't use STL vectors.
// Don't use a sorting function from a library.

#include <iostream>
#include <algorithm>

// sort_array()
// Summary: This function receives an array of integers and sorts it in ascending order.
// Arguments:
//           arr: A pointer acting as the array to sort.
//           n: The size of the array.
// Returns: A boolean value: True on success, false otherwise.
bool sort_array(int *arr, int n){

    if (n < 2){
        return true;
    }
    else{
        // Write your code here
        int copy[n] = {};
        int iL;//start of left run
        int iR;//start of right run
        int iE;//end of right run
        int i;//left run head
        int j;//right run head

        for (int w = 1; w < n; w = 2*w){

            // Iterate over runs
            for (int r = 0; r < n; r = r + 2*w){

                iL = r;
                iR = std::min(r + w,n);
                iE = std::min(r + 2*w, n);

                i = iL;
                j = iR;
                for (int k = iL; k < iE; k++){
                    
                    if (i < iR && (j >= iE || arr[i] <= arr[j])){
                        copy[k] = arr[i];
                        i = i + 1;
                    }
                    else{
                        copy[k] = arr[j];
                        j = j+1;
                    }
                }
            }

            //Copy `copy` array to original
            for (int i = 0; i < n; i++){
                arr[i] = copy[i];
            }
        }
        return true;
    }
}

// Main function
int main(){
    // The following array will be treated as an array of length len. 
    const int len = 10; // Don't exceed the length of the array below!
    int array[] = {2, 9, 4, 3, 5, 1, 6, 8, 0, 7};

    // Print the original array
    std::cout << "Original Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    sort_array(array, len); // Sort the array

    // Print the sorted array
    std::cout << "  Sorted Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    return 0;
}
