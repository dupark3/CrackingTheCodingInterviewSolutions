/* 
2.5 Sum Digits

You have two numbers represented by a linked list, hwere each node contains a
single digit. The digits are stored in reverse order, such taht the 1's digit
is at the head of the list. Write a function that adds the two numbers and
returns the sum a linked list.
e.g. 7 1 6 + 5 9 2 = 2 1 9
     617 + 295 = 912


*/

#include <iostream>

using namespace std;

/************** SINGLY LINKED LIST IMPLEMENTATION ******************/

// forward declaration
template <class T> class node;

template <class T>
class List {
    public:
        List() : head(0) { }
        node<T>* begin(){ return head; }
        node<T>* cbegin() const { return head; } 

        node<T>* append(const T& val) {
            if (!head){
                head = new node<T>(val);
                return head;
            } else {
                node<T>* temp = head;
                while (temp->next){
                    temp = temp->next;
                }
                temp->next = new node<T>(val);
                return temp->next;
            }
        }

    private:
        node<T>* head;
};

template <class T>
class node {
    public: 
        node() { }
        node(T val) : element(val), next(0) { }
        T element;
        node<T>* next;
};


/***************** SOLUTION TO THE PROBLEM ***********************/

template <class T>
List<T> sum_digits(const List<T>& number1, const List<T>& number2){
    node<T>* first_number_digits = number1.cbegin();
    node<T>* second_number_digits = number2.cbegin();

    List<T> sum_result;
    T carry_over = T();

    while((first_number_digits || second_number_digits)){
        T digit_sum = carry_over;
        
        if (first_number_digits){
            digit_sum += first_number_digits->element;
            first_number_digits = first_number_digits->next;
        }

        if (second_number_digits){
            digit_sum += second_number_digits->element;
            second_number_digits = second_number_digits->next;
        }
        
        // in base 10, carry over anything over 10 to the next digit
        if (digit_sum < 10){
            sum_result.append(digit_sum);
            carry_over = T();
        } else {
            sum_result.append(digit_sum % 10);
            carry_over = digit_sum / 10;
        }   
    }
    
    if (carry_over != T()){
        sum_result.append(carry_over);
    }

    return sum_result;

}

int main(){
    List<int> number1;
    List<int> number2;

    // 617
    number1.append(7);
    number1.append(1);
    number1.append(6);

    // 295
    number2.append(5);
    number2.append(9);
    number2.append(2);

    cout << "FIRST NUMBER : ";
    for (auto i = number1.begin(); i != 0; i = i->next){
        cout << i->element << ' ';
    }
    cout << endl;

    cout << "SECOND NUMBER : ";
    for (auto i = number2.begin(); i != 0; i = i->next){
        cout << i->element << ' ';
    }
    cout << endl;

    List<int> sum_result = sum_digits(number1, number2);

    cout << "SUM RESULT   : ";
    for (auto i = sum_result.begin(); i != 0; i = i->next){
        cout << i->element << ' ';
    }
    cout << endl;

    return 0;
}