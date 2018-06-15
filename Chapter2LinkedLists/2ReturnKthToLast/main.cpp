/* 
2.1 Remove Dups
Write code to remove duplicates from an unsorted linked list.
What if temporary buffer is not allowed?
*/

#include <cstdlib> // size_t
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

template <class T>
T return_Kth_element(const list<T>& container, size_t k){
    if (container.size() < k){
        return T();
    }
    auto end = container.begin();
    auto result = container.begin();

    for (size_t i = 0; i != k; ++i){
        ++end;
    }

    while (++end != container.end()){
        ++result;
    }

    return *result;

}


int main(){
    list<int> my_list = {1, 3, 9, 7, 1, 5, 7, 7, 2, 4, 10, 1};
    
    cout << "ORIGINAL LIST: ";
    for (auto i = my_list.begin(); i != my_list.end(); ++i){
        cout << *i << ' ';
    }
    cout << endl;

    size_t k = 5; 
    int result = return_Kth_element(my_list, k);

    cout << "RETURNING ELEMENT #" << k << " FROM THE END: " << result << endl;

    return 0;
}