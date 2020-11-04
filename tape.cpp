#include <iostream>

const unsigned long long int MAX_TAPE_SIZE = ULLONG_MAX;

template <class T>
class Tape
{
private:
    //fields
    T * arr;
    unsigned long long int size = MAX_TAPE_SIZE;

public:
    //deafault constructor
    Tape()
    {
        this->arr = new T[size];
        for (unsigned long long int i = 0; i < size; i++)
        {
            arr[i] = ' ';
        }
    }
    //constructor with params
    Tape(const char * str)
    {
        this->arr = new T[size];
        for (unsigned long long int i = 0; i < strlen(str); i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                arr[i] = str[i] - '0';
            }
            arr[i] = str[i];
        }
        for (unsigned long long int i = strlen(str); i < this->size; i++)
        {
            arr[i] = ' ';
        }
    }
    //operator=
    const Tape& operator=(const Tape& other)
    {
        if(this != &other)
        {
           delete this->arr;
           this->arr = new T[other.size];
           for (unsigned long long int i = 0; i < other.size; i++)
           {
               this->arr[i] = other.arr[i];
           }    
        }
    }
    //destructor
    ~Tape()
    {
        delete this->arr;
    }

    //func to see all non-blank space elements of a tape
    void printTape()
    {
        unsigned long long int current_index = 0;
        while (this->arr[current_index] != ' ')
        {
            std::cout << arr[current_index];
            current_index += 1;
        }   
    }
    //access the element at some index of a tape
    const T& operator[](unsigned long long int return_index)
    {
        return this->arr[return_index];
    }
};
