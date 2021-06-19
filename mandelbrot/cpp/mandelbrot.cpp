#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "mandelbrot.hpp"

// void zoom(double& x0, double& x1, const double f);

class Example : public olc::PixelGameEngine {
public:
    Example() { sAppName = "Example"; }

public:
    int transStart[2] = {0, 0};
    int trans[2] = {0, 0};
    const double scaleFactor = 0.1;
    double x0 = -2.5;
    double x1 = 1;
    double y0 = -1;
    double y1 = 1;
    bool updated = true;

    bool OnUserCreate() override { return true; }

    bool OnUserUpdate(float fElapsedTime) override {
        if (GetMouse(0).bPressed) {
            updated = true;
            transStart[0] += GetMouseX();
            transStart[1] += GetMouseY();
        }
        else if (GetMouse(0).bHeld) {
            updated = true;
            trans[0] = GetMouseX() - transStart[0];
            trans[1] = GetMouseY() - transStart[1];
        }
        else if (GetMouse(0).bReleased) {
            updated = true;
            transStart[0] -= GetMouseX();
            transStart[1] -= GetMouseY();
        }
        if (GetMouseWheel() != 0) {
            updated = true;
            const double f = scaleFactor * static_cast<double>(GetMouseWheel() / 120);
            zoom(x0, x1, 1 + f);
            zoom(y0, y1, 1 + f);
        } 

        if (updated) {
            for (int i = 0; i < ScreenWidth(); i++) {
                for (int j = 0; j < ScreenHeight(); j++) {
                    double x = static_cast<double>(i) - static_cast<double>(trans[0]);
                    double y = static_cast<double>(j) - static_cast<double>(trans[1]);
                    double xOut = map(x, 0., static_cast<double>(ScreenWidth()), x0, x1);
                    double yOut = map(y, 0., static_cast<double>(ScreenHeight()), y0, y1);
                    int pixelValue = isBounded(xOut, yOut);
                    pixelValue *= 5;
                    Draw(i, j, olc::Pixel(pixelValue, pixelValue, pixelValue));
                    Draw(static_cast<int>(ScreenWidth()/2), static_cast<int>(ScreenHeight()/2), olc::Pixel(0, 0, 0));
                }
            }
        }
        updated = false;
        return true;
    }
};

int main() {
    Example demo;
    if (demo.Construct(720*1.75, 720, 1, 1, false)) {
        demo.Start();
    }

    return 0;
}
