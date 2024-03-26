#include <iostream>
#include <string>

using namespace std;
#include "Image_Class.h"
void filter2()
{
    cout << "Please enter the name of your image: ";
    string image_name;
    cin >> image_name;
    Image image(image_name);
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            unsigned int avg = 0;
            for (int c = 0; c < 3; c++)
            {
                avg += image(i, j, c);
            }
            avg /= 3;
            for (int a = 0; a < 3; a++)
            {
                if (avg > 255 / 2)
                    image(i, j, a) = 255;
                else
                    image(i, j, a) = 0;
            }
        }
    }
    return;
}
int main()
{
    filter2();
    return 0;
} // background..jpg