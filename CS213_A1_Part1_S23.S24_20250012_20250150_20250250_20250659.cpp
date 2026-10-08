/*
 *CS213_A1_Part1_S23.S24_20250012_20250150_20250250_20250659.cpp
 *
 *اقسم بالله أن هذا الكود من عمل الفريق 100% بلا نسخ من اي مصدر أو تخليق بالAI
 *
 *
 * Name: Ahmed Osama Mohamed
 * ID: 20250012
 * Filters done: Filter 1 (Grayscale), Filter 13 (Wano Sunlight)
 *
 * Name: Jana Ahmed Taha Hassan
 * ID: 20250150
 * Filters done: Filter 2 (Black and White), Filter 14 (Old TV)
 *
 * Name: Ziad Abd Rabo Kamel
 * ID: 20250250
 * Filters done: Filter 3 (Invert Image), Filter 7 (Darken and Lighten Image)
 *
 * Name: Malak Usama Mohamed Rashad
 * ID: 20250659
 * Filters done: Filter 8 (Resizing Images), Filter 16 (Infrared)
 *
 *
 *
 *
 *
 */





#include "image_class.h"
#include <iostream>
using namespace std;

string filename;
string filename2;

//Image output;
string s1;


Image grayscale (Image &image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int avg = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
    return image;
}

Image blackAndWhite (Image &image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int r = image.getPixel(i, j,0);
            int g = image.getPixel(i, j,1);
            int b = image.getPixel(i, j,2);

            int avr = (r + g + b) / 3;

            if (avr >= 128) {
                for (int k = 0; k < image.channels; k++) {
                    image.setPixel(i, j, k, 255);
                }
            }
            else {
                for (int k = 0; k < image.channels; k++) {
                    image.setPixel(i, j, k, 0);
                }
            }

        }
    }
    return image;
}

Image invertImage(Image &image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i,j,k) = 255 - image(i, j, k);
            }
        }
    }
    return image;
}

Image darkenAndLighten (Image &image) {
    int choice;
    cout << " options:\n brighter : 1 \n darker : 2\n";
    cin >> choice;
    while (choice != 1 && choice != 2) {
        cout << "pls enter a choice in range 1 or 2\n ";
        cin >> choice;
    }

    cout << "pls enter the precentage of \n";

    double precentage;
    cin >> precentage;
    while ( precentage> 100 || precentage < 0) {
        cout << "wrong range pls enter range between 0% to 100%\n";
        cin >> precentage;
    }
    int change_amount = static_cast<int>((precentage / 100) * 255);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int current_value = image.getPixel(i, j, k);// هناانا بقراء  الالون
                int new_value;
                if (choice == 1) { // brigther
                    new_value =current_value+ change_amount;
                }
                else // هنا هقلل القيمه عشان اجيب الدرحه الاغمق من اللون
                {
                    new_value = current_value - change_amount;
                }

                if (new_value > 255)new_value = 255;
                if (new_value < 0) new_value = 0;
                image.setPixel(i, j, k, new_value);
            }
        }
    }
    return image;
}

Image Resize(Image& image) {
    int newWidth, newHeight;
    cout << "Enter new width and height: ";
    cin >> newWidth >> newHeight;

    Image ResizedImage(newWidth,newHeight);
    for (int y = 0; y < newHeight; ++y)
    {
        for (int x = 0;x < newWidth;++x)
        {
            int oldX = x * image.width / newWidth;
            int oldY = y * image.height / newHeight;

            ResizedImage(x, y, 0) = image(oldX, oldY, 0);
            ResizedImage(x, y, 1) = image(oldX, oldY, 1);
            ResizedImage(x, y, 2) = image(oldX, oldY, 2);
        }
    }
    return ResizedImage;
}

Image  imageEdges (Image& image) {
    grayscale(image);

    for (int j = 0; j < image.height; j++) {
        for (int i = 0; i < image.width; i++) {
            if ((i < image.width - 1) && (j < image.height - 1)) {
                int current = image.getPixel(i,j,0);
                int right = image.getPixel(i+1,j,1);
                int below = image.getPixel(i,j+1,2);

                int diff = 20;

                int diffRight = abs(right-current);
                int diffBelow = abs(below-current);

                if (diffRight > diff || diffBelow > diff) {
                    for (int k = 0; k < image.channels; k++) {
                        image.setPixel(i,j,k,0);
                    }
                }
                else {
                    for (int k = 0; k < image.channels; k++) {
                        image.setPixel(i,j,k,255);
                    }
                }

            }
            else {
                for (int k = 0; k < image.channels; k++) {
                    image.setPixel(i, j, k, 255);
                }
            }
        }
    }

    return image;
}

Image wanoSunlight(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {

            int r = image(i, j, 0) + 40;
            int g = image(i, j, 1) + 20;
            int y = image(i, j, 2) - 10;

            image(i, j, 0) = min(255, max(0, r));
            image(i, j, 1) = min(255, max(0, g));
            image(i, j, 2) = min(255, max(0, y));
        }
    }
    return image;
}

Image oldTV(Image &image) {

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            if (j % 2 == 0) {
                for (int k = 0; k < image.channels; k++) {
                    image(i,j,k) = 0.7*image(i,j,k);
                }
            }

        }
    }
    return image;
}

Image Infrared(Image& image)
{
    for (int y = 0; y < image.height; ++y)
    {
        for (int x = 0; x < image.width; ++x)
        {
            int r = image(x, y, 0);
            int g = image(x, y, 1);
            int b = image(x, y, 2);

            int invertedValue = 255 - (r + g + b) / 3;

            image(x, y, 0) = 255;
            image(x, y, 1) = invertedValue;
            image(x, y, 2) = invertedValue;
        }
    }

    return image;
}

void save(Image &image) {
    bool t = true;
    while (t){
        cout << "Do want to save in the same file or a new file(s/n): ";
        cin >> s1;
        if (s1 == "s") {
            if (image.saveImage(filename)) {
                cout << "image saved successfully" << endl;
            }
            t = false;
        }
        else if (s1 == "n") {
            cout << "Choose the new filename to save your new image and specify extension .jpg, .jpeg, .bmp, .png, .tga: " ;
            cin >> filename2;
            if (image.saveImage(filename2)) {
                cout << "image saved successfully" << endl;
            }
            t = false;
        }
    }
}


int main() {

    cout << "Enter image filename to load: ";
    cin >> filename;
    Image image(filename);

    string s2;
    string s3;

    bool t2 = true;
    bool t3 = true;

    int choice;
    bool running = true;
    bool load = true;

    while (running) {
        cout << "--- MENU ---" << endl;
        cout << "1. Load a new image" << endl;
        cout << "2. Grayscale Conversion" << endl;
        cout << "3. Black and White" << endl;
        cout << "4. Invert Image" << endl;
        //cout << "5. Adding Frame to the Picture" << endl;
        //cout << "6. Flip Image" << endl;
        //cout << "7. Rotate Image" << endl;
        cout << "8. Darken and Lighten Image" << endl;
        cout << "9. Resizing Images" << endl;
        //cout << "10. Merge Images" << endl;
        cout << "11. Detect Image Edges" << endl;
        //cout << "12. Crop Images" << endl;
        //cout << "13. Blur Images" << endl;
        cout << "14. Wano Sunlight" << endl;
        cout << "15. Old TV" << endl;
        //cout << "16. Purple Wano" << endl;
        cout << "17. Infrared" << endl;
        //cout << "18. Image Skewing Filter" << endl;
        //cout << "19. Oil Painting" << endl;
        cout << "20. Save" << endl;
        cout << "21. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!load) {
                    while (t2) {
                        cout << "Before loading a new image, do you want to save the current one?(y/n): ";
                        cin >> s3;
                        if (s3 == "y") {
                            save(image);
                        }
                        if (s3 == "y" || s3 == "n") {
                            t2 = false;
                        }
                    }
                }

                cout << "Enter image filename to load: ";
                cin >> filename;

                if (image.loadNewImage(filename)) {
                    cout << "image loaded successfully" << endl;
                }
                t2 = true;
                load = true;
                break;
            case 2:
                image = grayscale(image);
                load = false;
                break;
            case 3:
                image = blackAndWhite(image);
                load = false;
                break;
            case 4:
                image = invertImage(image);
                load = false;
                break;
            case 5:
                //frame
                load = false;
                break;
            case 6:
                //flip
                load = false;
                break;
            case 7:
                //rotate
                load = false;
                break;
            case 8:
                image = darkenAndLighten(image);
                load = false;
                break;
            case 9:
                image = Resize(image);
                load = false;
                break;
            case 10:
                //merge
                load = false;
                break;
            case 11:
                image = imageEdges(image);
                load = false;
                break;
            case 12:
                //crop
                load = false;
                break;
            case 13:
                //blur
                load = false;
                break;
            case 14:
                image = wanoSunlight(image);
                load = false;
                break;
            case 15:
                image = oldTV(image);
                load = false;
                break;
            case 16:
                //purple
                load = false;
                break;
            case 17:
                image = Infrared(image);
                load = false;
                break;
            case 18:
                //skewing
                load = false;
                break;
            case 19:
                //oil painting
                load = false;
                break;
            case 20:
                save(image);
                load = false;
                break;
            case 21:
                while (t3) {
                    cout << "Before you exit, do you want to save your new image(y/n): " ;
                    cin >> s2;
                    if (s2 == "y") {
                        save(image);
                    }
                    if (s2 == "y" || s2 == "n") {
                        t3 = false;
                    }
                }
                running = false;
                break;
            default:
                cout << "Invalid Choice! Please select an option from the menu.";
        }
    }
    
    return 0;
}
