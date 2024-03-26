#include "Image_Class.h" //background..jpg
#include <iostream>
#include <string>
using namespace std;

void gray_scale(Image &image)
{
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
                image(i, j, a) = avg;
            }
        }
    }
}

void filter2(Image &image)
{
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
                if (avg > 255 / 2) // Gray is greater than the middle
                    image(i, j, a) = 255;
                else
                    image(i, j, a) = 0;
            }
        }
    }
}
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

void filter7(Image &image)
{
    string operation;
    cout << "What do you want to make ?\n";
    cout << "1) Make the image darker.\n";
    cout << "2) Make the image lighter.\n";
    cout << "Please enter  1 or 2: ";
    while (true)
    {
        getline(cin, operation);
        if (operation == "1" || operation == "2")
        {
            break;
        }
        else
        {
            cout << "Please enter a valid choice: ";
        }
    }

    if (operation == "1")
    {

        for (int i = 0; i < image.width; ++i)
        {
            for (int j = 0; j < image.height; ++j)
            {
                for (int c = 0; c < 3; ++c)
                {

                    int pixelValue = image(i, j, c);

                    pixelValue /= 2;

                    if (pixelValue < 0)
                    {
                        pixelValue = 0;
                    }

                    image(i, j, c) = pixelValue;
                }
            }
        }
    }
    else
    {

        for (int i = 0; i < image.width; ++i)
        {
            for (int j = 0; j < image.height; ++j)
            {
                for (int c = 0; c < 3; ++c)
                {

                    int pixelValue = image(i, j, c);

                    pixelValue *= 2;

                    if (pixelValue > 255)
                    {
                        pixelValue = 255;
                    }

                    image(i, j, c) = pixelValue;
                }
            }
        }
    }
}
int main()
{
    while (true)
    {
        cout << "1) Edit an Image\n";
        cout << "2) Exit\n";
        string choice0;
        cin >> choice0;
        if (choice0 == "1")
        {
            cout << "Please enter the name of your image: ";
            string image_name;
            cin >> image_name;
            Image image(image_name);
            cout << "\n1) Grayscale Conversion\n";
            cout << "2) Black and White\n";
            cout << "3) Invert Image\n";
            cout << "4) Merge Image\n";
            cout << "5) Flip Image\n";
            cout << "6) Rotate Image\n";
            cout << "7) Darken and Lighten Image\n";
            cout << "8) Crop Image\n";
            cout << "9) Adding Frame to Image\n";
            cout << "10) Detect Image Edges\n";
            cout << "11) Resizing Image\n";
            cout << "12) Blur Imagese\n\n";
            cout << "Please select a filter: ";

            int choice1;
            cin >> choice1;

            switch (choice1)
            {
            case 1:
                gray_scale(image);
                break;
            case 2:
                filter2(image);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                filter5(image);
                break;
            case 6:
                break;
            case 7:
                filter7(image);
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            default:
                cout << "Please select a valid filter: ";
                cin >> choice1;
                continue;
            }

            // Saving the edited image
            cout << "\nDo you want to save the edited image?\n";
            cout << "1) Yes\n2) Discard Changes\n";
            int choice2;
            cin >> choice2;
            while (choice2 != 1 && choice2 != 2)
            {
                cout << "Please select a valid choice: ";
                cin >> choice2;
            }
            switch (choice2)
            {
            case 1:
            {
                string newname;
                cout << "Please enter the name of new image\nand specify extension .jpg, .jpeg, .bmp, .png, .tga: ";
                cin >> newname;
                for (char &x : newname)
                {
                    x = tolower(x);
                }
                while ((newname.find(".jpg") || newname.find(".jpeg") || newname.find(".bmp") || newname.find(".png") || newname.find(".tga")) == 0)
                {
                    cout << "File Extension is not supported. Only .jpg, .jpeg, .bmp, .png, .tga are supported.\nEnter a valid extension: ";
                    cin >> newname;
                    for (char &x : newname)
                    {
                        x = tolower(x);
                    }
                }
                image.saveImage(newname);
                cout << "Image saved successfully.\n\n";
                continue;
            }
            case 2:
                cout << "Changes discarded successfully.\n\n";
                continue;
            }
        }
        else if (choice0 == "2")
            break;
        else
        {
            cout << "\nplease select a valid choice.\n";
            continue;
        }
        return 0;
    }
}