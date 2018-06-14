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

void remove_duplicates(list<int>& my_list){
    unordered_map<int, int> element_frequency;
    for (auto it = my_list.begin(); it != my_list.end(); ){
        ++element_frequency[*it];
        if (element_frequency[*it] > 1){
            it = my_list.erase(it);
        } else {
            ++it;
        }

    }
}

int main(){
    list<int> my_list = {1, 3, 9, 7, 1, 5, 7, 7, 2, 4, 10, 1};
    
    cout << "ORIGINAL LIST: ";
    for (auto i = my_list.begin(); i != my_list.end(); ++i){
        cout << *i << ' ';
    }
    cout << endl;

    remove_duplicates(my_list);

    cout << "REMOVED DUPS : ";
    for (auto i = my_list.begin(); i != my_list.end(); ++i){
        cout << *i << ' ';
    }
    cout << endl;

    return 0;
}