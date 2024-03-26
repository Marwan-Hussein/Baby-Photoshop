#include <iostream>
#include <string>
#include "Image_Class.h"
using namespace std;

void filter5(Image &image)
{
    cout << "1) Horizontal Flip\n";
    cout << "2) Vertical Flip\n";
    string choice;
    cout << "Select a choice: ";
    cin >> choice;
    while (choice != "1" && choice != "2")
    {
        cout << "\nPlease select a valid choice: ";
        cin >> choice;
    }
    int width = image.width;
    int height = image.height;
    unsigned char temp[3]; // Temporary storage for pixel values during swapping

    if (choice == "1") // Horizontal flip
    {
        for (int i = 0; i < width / 2; i++)
        {
            for (int j = 0; j < height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    temp[k] = image(i, j, k);                    // swap main pixel to temp.
                    image(i, j, k) = image(width - 1 - i, j, k); // swap the opposite pixel to the main pixel.
                    image(width - 1 - i, j, k) = temp[k];        // swap the main pixel to the opposite pixel.
                }
            }
        }
    }
    else if (choice == "2") // Vertical flip
    {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height / 2; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    temp[k] = image(i, j, k);                     // swap main pixel to temp.
                    image(i, j, k) = image(i, height - 1 - j, k); // swap the opposite pixel to the main pixel.
                    image(i, height - 1 - j, k) = temp[k];        // swap the main pixel to the opposite pixel.
                }
            }
        }
    }
}

int main()
{
    cout << "Please enter the name of your image: ";
    string image_name;
    cin >> image_name;
    Image image(image_name);
    filter5(image);

    cout << "Do you want to save the edited image?\n";
    cout << "1) Yes\n2) Discard Changes\n";
    int choice2;
    cin >> choice2;

    switch (choice2)
    {
    case 1:
    {
        cout << "Enter a name to save it: ";
        string name, extension;
        cin >> name;
        cout << "Enter an extension: ";
        cin >> extension;
        for (char &x : extension)
        {
            x = tolower(x);
        }
        while (extension != ".jpg" && extension != ".jpeg" && extension != ".bmp" && extension != ".png" && extension != ".tga")
        {
            cout << "File Extension is not supported. Only .jpg, .jpeg, .bmp, .png, .tga are supported.\nEnter a valid extension: ";
            cin >> extension;
            for (char &x : extension)
            {
                x = tolower(x);
            }
        }
        image.saveImage(name + extension);
        cout << "Image saved successfully.\n";
        break;
    }
    case 2:
        cout << "Changes discarded successfully.\n";
        break;
    default:
        cout << "Please select a valid choice.\n";
    }

    return 0;
}