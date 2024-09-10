#include <cstdint>
#include <cstring>
#include <iostream>

class ArrayHandler {
private:
    int* _array;
    int _max;
    int _min;
    int _size;
    int _count;
public:
    ArrayHandler(int size = 10){
        _size = size;
        _array = new int[_size];
        _max = INT32_MIN;
        _min = INT32_MAX;
        _count = 0;
    }
    void Append(int new_element){
        if (_count == _size) {
            _size = _size + 10;
            int* new_arr = new int[_size];
            std::memcpy(new_arr, _array, _size*sizeof(int));
            delete [] _array;
            _array = new_arr;
        }
        _array[_count] = new_element;
        _count++;
        if (_max < new_element) _max = new_element;
        if (_min > new_element) _min = new_element;
    }
    int GetMax(){
        return _max;
    }
    int GetMin(){
        return _min;
    }
    int GetIndexElem(int elem){
        for (int i = 0; i < _count; i++) 
            if (elem == _array[i]) 
                return i;

        return -1;
    }
    ~ArrayHandler() {
        delete [] _array;
    }
};

