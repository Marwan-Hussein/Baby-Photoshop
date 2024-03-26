#include "Image_Class.h" // Include the Image class header
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    while (true)
    {
        string ImageName, Inverted_Image, extension, Inverted_extension;
        char choice;
        cout << "Enter the name of the input image: ";
        cin >> ImageName;
        cout << "Enter the image extension (png, bmp, tga, jpg): ";
        cin >> extension;
        Image image(ImageName + "." + extension);
        if (image.width == 0 || image.height == 0)
        {
            cout << "image not found!" << endl;
            break;
        }
        for (int j = 0; j < image.height; j++)
        {
            for (int i = 0; i < image.width; i++)
            {
                unsigned char &red = image(i, j, 0);
                unsigned char &green = image(i, j, 1);
                unsigned char &blue = image(i, j, 2);
                red = 255 - red;
                green = 255 - green;
                blue = 255 - blue;
            }
        }
        cout << "Do you want save the inverted_image? choise(Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            cout << "Enter name of inverted image : ";
            cin >> Inverted_Image;
            cout << "Chose inverted image extension (PNG,JPEG,JPG,BMP):";
            cin >> Inverted_extension;
            if (!image.saveImage(Inverted_Image + "." + Inverted_extension))
            {
                cout << "Image could not save" << endl;
                return -1;
            }
            cout << "The Image inverted and saved successfully" << endl;
        }
        else if (choice == 'N' || choice == 'n')
        {
            cout << "The Image inverted successfully" << endl;
        }
        else
        {
            cout << "pleas select  Y or N " << endl;
        }
    }
    return 0;
}