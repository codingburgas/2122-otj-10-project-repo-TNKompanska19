#include <iostream>
#include <vector>
#include <algorithm>

#include "schoolPractice30032022.h"
using namespace std;

typedef bool (*DirectionPtr)(int, int);

/*void sortAsc(vector<int>& items)
{
    cout << "---------" << endl;
    //synthetic sugar
    /*
    for (int num : vtr)
    {
    cout << num;
    }
    */
   /*
    for (auto i = vtr.begin(); i != vtr.end(); i++)
    {
        cout << *i << " ";
    }
    */

   /* for (size_t i = 0; i < items.size(); i++)
    {
        for (size_t j = i + 1; j < items.size(); j++)
        {
            if (items[j] < items[i])
            {
                swap(items[j], items[i]);
            }
        }
    }
}*/

//void sortDesc(vector<int>& items)
//{
//    cout << "---------" << endl;
//    for (size_t i = 0; i < items.size(); i++)
//    {
//        for (size_t j = i + 1; j < items.size(); j++)
//        {
//            if (items[j] > items[i])
//            {
//                swap(items[j], items[i]);
//            }
//        }
//    }
//}

void showNums(std::vector<int>& numbers)
{
    cout << "---------" << endl;
    for (const auto num : numbers)
    {
        cout << num << endl;
    }
}

//void sort(std::vector<int>& items, bool (*func) (int, int))
//{
//   
//    for (size_t i = 0; i < items.size(); i++)
//    {
//        for (size_t j = i + 1; j < items.size(); j++)
//        {
//            if (func(items[i], items[j]))
//            {
//                swap(items[j], items[i]);
//            }
//        }
//    }
//}

//void sort(std::vector<int>& items, DirectionPtr pred)
//{
//
//    for (size_t i = 0; i < items.size(); i++)
//    {
//        for (size_t j = i + 1; j < items.size(); j++)
//        {
//            if (pred(items[i], items[j]))
//            {
//                swap(items[j], items[i]);
//            }
//        }
//    }
//}


//bool isDesc(int a, int b)
//{
//    return a < b;
//}
//
//bool isAsc(int a, int b)
//{
//    return a > b;
//}


int main()
{
    vector<int> numbers{3, 2, 5, 1, 4, 9, 6, 7, 0};

    showNums(numbers);
    int c = 5, d = 12;

    sort(numbers.begin(), numbers.end(),
        [&c] (int a, int b) {return a > b; });

    showNums(numbers);

    sort(numbers.begin(), numbers.end(),
        [&c](int a, int b) {return a < b; });
 
    showNums(numbers);
}


//synthetic sugar
/*
for (int num : vtr)
{
cout << num;
}
*/
/*
 for (auto i = vtr.begin(); i != vtr.end(); i++)
 {
     cout << *i << " ";
 }
 */
