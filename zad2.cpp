#include <iostream>
#include <string>

class Window {
    int width;
    int height;
    std::string title;

public:
    Window(int w, int h, std::string t) : width(w), height(h), title(t) {
        std::cout << "Window created: " << width << "x" << height << " [" << title << "]\n";
    }

    Window(int w, int h) : Window(w, h, "Untitled") { }


};

int main() {
    Window w1(800, 600, "Windowone");
    Window w2(1024, 768); 
    
    return 0;
}