#include <iostream>
#include <vector>// Use this library to fill dynamically sized array

void mergeSort(std::vector<int> &mergeVec);// Pass vector by reference so func can modify

int main()
{
    std::vector<int> mergeVec;
    srand(time(0));
    int input = 0;

    std::cout << "Here's a magic trick; these five numbers will be sorted:\n";
    for (unsigned int i = 0; i < 20; i++){// Display and add 20 random numbers to vector
        input = rand();
        std::cout << input << " ";
        mergeVec.push_back(input);
    }
    std::cout << "\n\nTadaa!\n";
    mergeSort(mergeVec);
    for(unsigned int i = 0; i < 20; i++){
        std::cout << mergeVec[i] << " ";
    }

    return 0;
}

void mergeSort(std::vector<int> &mergeVec)// The meat and potatoes of this program
{
    int vecSize = mergeVec.size(), iter = 1, jiter = 0, current = 0;

    for (iter; iter < vecSize; iter++){// O(n) in the best case, O(n^2) in the worst case
        current = mergeVec[iter];
        jiter = iter - 1;
        while(jiter >= 0 && mergeVec[jiter] > current){
            mergeVec[jiter + 1] = mergeVec[jiter];
            jiter -= 1;
        }
        mergeVec[jiter + 1] = current;
    }
}