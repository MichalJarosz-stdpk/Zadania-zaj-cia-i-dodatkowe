#include <iostream>

class Buffer {
    int* data;  
    int size;   

public:
    Buffer(int sz) : size(sz) {
        data = new int[size];  
        std::cout << "Allocated " << size << "\n";  
    }

   
    ~Buffer() {
        delete[] data;  
        std::cout << "Deallocated\n"; 
    }
};

int main() {
    std::cout << "Start\n"; 
    
    {
      
        Buffer buf(10);  
    } 

    std::cout << "End\n"; 

    return 0;
}