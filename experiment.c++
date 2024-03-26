#include <iostream>
#include "Image_Class.h"
using namespace std;
int main()
{
    Image img("background..jpg");
    for (int i = img.width / 2; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                img(i, j, k) = img(img.width - i + 1, j, k);
            }
        }
    }

    img.saveImage("maro1.jpg");
    return 0;
}