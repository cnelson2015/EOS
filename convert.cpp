#include "CImg.h"
#include <iostream>

using namespace std;
using namespace cimg_library;

class pixel {
    int r, g, b;

    public:
        pixel(int, int, int);
        void print() { cout << r << " " << g << " " << b << endl; }
        char* toHex() {
            char* buf = new char[16];
            snprintf(buf, sizeof(buf), "%02x%02x%02x", r, g, b);
            return buf;
        }
};

pixel::pixel (int r, int g, int b) {
    this->r = r;
    this->g = b;
    this->b = b;
}

int main() {
    CImg<unsigned char> image("bitmap.png");

    int width = image.width();
    int height = image.height();

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            pixel rgb((int)image(x,y,0,0),
                      (int)image(x,y,0,1),
                      (int)image(x,y,0,2));
            cout << rgb.toHex() << endl;
        }
    }

    return 0;
}
