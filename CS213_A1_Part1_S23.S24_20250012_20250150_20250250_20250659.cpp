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





#include "Image_Class.h"
#include <algorithm>
#include <vector>
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

Image AddFrame(Image& image)
{
    int choice, color;
    cout << "Select Frame Type (1: Simple, 2: Fancy)" << endl;
    cin >> choice;
    bool isFancy = (choice == 2);
    cout << "Pick a Frame Color " << endl;
    cout << "(1: Red, 2: Green, 3: Blue, 4: Yellow, 5: Orange, 6: Purple, 7: Gold, 8: White, 9: Black)" << endl;
    cin >> color;

    int FrameThickness = min(image.width, image.height) / 30;
    if (FrameThickness < 15) FrameThickness = 15;

    int gap = 8;
    int whiteThickness = 5;

    int whiteStart = FrameThickness + gap;
    int whiteEnd = whiteStart + whiteThickness;

    for (int y = 0; y < image.height; ++y)
    {
        for (int x = 0; x < image.width; ++x)
        {
            bool isEdge = (x < FrameThickness || x >= image.width - FrameThickness || y < FrameThickness || y >= image.height - FrameThickness);

            if (isEdge)
            {
                switch (color)
                {
                case 1: { // Red
                    image(x, y, 0) = 255;
                    image(x, y, 1) = 0;
                    image(x, y, 2) = 0;
                    break;
                }
                case 2: { // Green 
                    image(x, y, 0) = 88;
                    image(x, y, 1) = 204;
                    image(x, y, 2) = 138;
                    break;
                }
                case 3: { // Blue
                    image(x, y, 0) = 0;
                    image(x, y, 1) = 0;
                    image(x, y, 2) = 255;
                    break;
                }
                case 4: { // Yellow
                    image(x, y, 0) = 255;
                    image(x, y, 1) = 230;
                    image(x, y, 2) = 0;
                    break;
                }
                case 5: { // Orange
                    image(x, y, 0) = 255;
                    image(x, y, 1) = 165;
                    image(x, y, 2) = 0;
                    break;
                }
                case 6: { // Purple
                    image(x, y, 0) = 155;
                    image(x, y, 1) = 107;
                    image(x, y, 2) = 224;
                    break;
                }
                case 7: { // Gold
                    image(x, y, 0) = 235;
                    image(x, y, 1) = 180;
                    image(x, y, 2) = 20;
                    break;
                }
                case 8: { // White
                    image(x, y, 0) = 255;
                    image(x, y, 1) = 255;
                    image(x, y, 2) = 255;
                    break;
                }
                case 9: { // Black
                    image(x, y, 0) = 0;
                    image(x, y, 1) = 0;
                    image(x, y, 2) = 0;
                    break;
                }
                }
            }
            if (isFancy)
            {
                bool isStripe = ((x >= whiteStart && x < whiteEnd) || (x >= image.width - whiteEnd && x < image.width - whiteStart)|| (y >= whiteStart && y < whiteEnd) || (y >= image.height - whiteEnd && y < image.height - whiteStart));

                if (isStripe)
                {
                    switch (color)
                    {
                    case 1: { // Red
                        image(x, y, 0) = 255;
                        image(x, y, 1) = 0;
                        image(x, y, 2) = 0;
                        break;
                    }
                    case 2: { // Green 
                        image(x, y, 0) = 88;
                        image(x, y, 1) = 204;
                        image(x, y, 2) = 138;
                        break;
                    }
                    case 3: { // Blue
                        image(x, y, 0) = 0;
                        image(x, y, 1) = 0;
                        image(x, y, 2) = 255;
                        break;
                    }
                    case 4: { // Yellow
                        image(x, y, 0) = 255;
                        image(x, y, 1) = 230;
                        image(x, y, 2) = 0;
                        break;
                    }
                    case 5: { // Orange
                        image(x, y, 0) = 255;
                        image(x, y, 1) = 165;
                        image(x, y, 2) = 0;
                        break;
                    }
                    case 6: { // Purple
                        image(x, y, 0) = 155;
                        image(x, y, 1) = 107;
                        image(x, y, 2) = 224;
                        break;
                    }
                    case 7: { // Gold
                        image(x, y, 0) = 235;
                        image(x, y, 1) = 180;
                        image(x, y, 2) = 20;
                        break;
                    }
                    case 8: { // White
                        image(x, y, 0) = 255;
                        image(x, y, 1) = 255;
                        image(x, y, 2) = 255;
                        break;
                    }
                    case 9: { // Black
                        image(x, y, 0) = 0;
                        image(x, y, 1) = 0;
                        image(x, y, 2) = 0;
                        break;
                    }
                    }
                }
            }
        }
    }

    return image;
}

Image Flip(Image &image) {
   string o;
   Image tempFile(image.width, image.height);
   bool checkA = true;
    while (checkA){
   cout << "Horizontal or Vertical ?" << endl;
   cin >> o;
   if ((o == "vertical") || (o =="Vertical") || (o == " vertical") || (o ==" Vertical") || (o == "vertical ") || (o =="Vertical ")){
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    tempFile(i, j, k) = image(i, image.height - 1 - j, k);
                }
            }
        }
        image = tempFile;
        checkA = false;

}
    else if ((o == "horizontal") || (o =="Horizontal") || (o == " horizontal") || (o ==" Horizontal") || (o == "horizontal ") || (o == "Horizontal ")){
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    tempFile(i, j, k) = image(image.width - 1 - i, j, k);
                }
            }
        }
        image = tempFile;
        checkA = false;
}
    else {
        cout << "Wrong answer!" << endl;
    }
}
return image;
}

Image rotate90 (Image &image) {
    Image image2(image.height, image.width);

    for (int j = 0; j < image.height; j++) {
        for (int i = 0; i < image.width; i++) {
            int new_i = image.height -1 -j;
            int new_j = i;

            for (int k = 0; k < image.channels; k++) {
                int value = image.getPixel(i, j,k);
                image2.setPixel(new_i, new_j, k, value);
            }
        }
    }
    image = image2;

    return image;
}

Image rotate180(Image &image) {
    Image image2(image.width, image.height);

    for (int j = 0; j < image.height; j++) {
        for (int i = 0; i < image.width; i++) {
            int new_i = image.width -1 -i;
            int new_j = image.height -1 -j;

            for (int k = 0; k < image.channels; k++) {
                int value = image.getPixel(i, j,k);
                image2.setPixel(new_i, new_j, k, value);
            }
        }
    }
    image = image2;

    return image;
}

Image rotate270(Image &image) {
    Image image2(image.height, image.width);

    for (int j = 0; j < image.height; j++) {
        for (int i = 0; i < image.width; i++) {
            int new_i = j;
            int new_j = image.width -1 -i;

            for (int k = 0; k < image.channels; k++) {
                int value = image.getPixel(i, j,k);
                image2.setPixel(new_i, new_j, k, value);
            }
        }
    }
    image = image2;

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

Image Merge(Image &image) {
      string otherName;
        cout << "What is your other image name?" << endl;
        cin >> otherName;

        Image theOtherPic(otherName);


        int w = min(image.width, theOtherPic.width);
        int h = min(image.height, theOtherPic.height);
        int ch = min(image.channels, theOtherPic.channels);

        Image aNeWPic(w, h);

        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                for (int k = 0; k < ch; ++k) {
                    aNeWPic(i, j, k) = (image(i, j, k) + theOtherPic(i, j, k)) / 2;
                }
            }
        }
        image = aNeWPic;
        return image;
    }



Image  imageEdges (Image& image) {
    grayscale(image);

    for (int j = 0; j < image.height; j++) {
        for (int i = 0; i < image.width; i++) {

            int diff = 20;
            bool isEdge = false;
            int current = image.getPixel(i,j,0);

            if (i < image.width - 1) {
                int right = image.getPixel(i+1,j,1);
                int diffRight = abs(right-current);
                if (diffRight > diff) {
                    isEdge = true;
                }
            }
            if (j < image.height - 1) {
                int below = image.getPixel(i,j+1,2);
                int diffBelow = abs(below-current);
                if (diffBelow > diff) {
                    isEdge = true;
                }
            }
            if (isEdge) {
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
    }

    return image;
}
Image crop(Image &image)
{
    int x, y;
    int W, H;

    cout << "Enter X: "; 
    cin >> x;

    cout << "Enter Y: "; 
    cin >> y;

    cout << "Enter the width of the area you want to crop: ";
    cin >> W;

    cout << "Enter the height of the area you want to crop: ";
    cin >> H;

    Image cropped(W, H);

    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cropped.setPixel(i, j, k,
                    image.getPixel(x + i, y + j, k));
            }
        }
    }

    return cropped;
}

Image Blur(Image& image)
{
    int radius = 20;
    int width = image.width;
    int height = image.height;

    vector<vector<long long>> prefixR(width, vector<long long>(height, 0));
    vector<vector<long long>> prefixG(width, vector<long long>(height, 0));
    vector<vector<long long>> prefixB(width, vector<long long>(height,0));

    // 
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            long long currentR = image(x, y, 0);
            long long leftR = 0, topR = 0, topLeftR = 0;
            if (x > 0) leftR = prefixR[x - 1][y];
            if (y > 0) topR = prefixR[x][y - 1];
            if (x > 0 && y > 0) topLeftR= prefixR[x - 1][y - 1];
            prefixR[x][y] = currentR + leftR + topR - topLeftR;

            long long currentG = image(x, y, 1);
            long long leftG = 0, topG = 0, topLeftG = 0;
            if (x > 0) leftG = prefixG[x - 1][y];
            if (y > 0) topG = prefixG[x][y - 1];
            if (x > 0 && y > 0) topLeftG = prefixG[x - 1][y - 1];
            prefixG[x][y] = currentG + leftG + topG - topLeftG;

            long long currentB = image(x, y, 2);
            long long leftB = 0, topB = 0, topLeftB = 0;
            if (x > 0) leftB = prefixB[x - 1][y];
            if (y > 0) topB = prefixB[x][y - 1];
            if (x > 0 && y > 0) topLeftB = prefixB[x - 1][y - 1];
            prefixB[x][y] = currentB + leftB + topB - topLeftB;
        }
    }

    Image blurredImage(width,height);

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int xLeft = x - radius;
            int yTop = y - radius;
            int xRight = x + radius;
            int yBottom = y + radius;

            if (xLeft < 0) xLeft = 0;
            if (yTop < 0) yTop = 0;
            if (xRight >= width) xRight = width - 1;
            if (yBottom >= height) yBottom = height - 1;

            int boxPixels = (xRight - xLeft + 1) * (yBottom - yTop + 1);

            long long totalR = prefixR[xRight][yBottom];
            long long leftR = 0, topR = 0, topLeftR = 0;
            if (xLeft > 0) leftR = prefixR[xLeft - 1][yBottom];
            if (yTop > 0) topR = prefixR[xRight][yTop - 1];
            if (xLeft > 0 && yTop > 0) topLeftR = prefixR[xLeft - 1][yTop - 1];

            long long totalG = prefixG[xRight][yBottom];
            long long leftG = 0, topG = 0, topLeftG = 0;
            if (xLeft > 0) leftG = prefixG[xLeft - 1][yBottom];
            if (yTop > 0) topG = prefixG[xRight][yTop - 1];
            if (xLeft > 0 && yTop > 0) topLeftG = prefixG[xLeft - 1][yTop - 1];

            long long totalB = prefixB[xRight][yBottom];
            long long leftB = 0, topB = 0, topLeftB = 0;
            if (xLeft > 0) leftB = prefixB[xLeft - 1][yBottom];
            if (yTop > 0) topB = prefixB[xRight][yTop - 1];
            if (xLeft > 0 && yTop > 0) topLeftB = prefixB[xLeft - 1][yTop - 1];

            long long sumR = totalR - leftR - topR + topLeftR;
            long long sumG = totalG - leftG - topG + topLeftG;
            long long sumB = totalB - leftB - topB + topLeftB;

            blurredImage(x, y, 0) = (unsigned char)(sumR / boxPixels);
            blurredImage(x, y, 1) = (unsigned char)(sumG / boxPixels);
            blurredImage(x, y, 2) = (unsigned char)(sumB / boxPixels);
        }
    }

    return blurredImage;
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
Image purpleWano(Image &image)
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int newValue = image.getPixel(i, j, k);

                if (k == 0)
                    newValue = newValue * 1.2;
                else if (k == 1)
                    newValue = newValue * 0.7;
                else if (k == 2)
                    newValue = newValue * 1.3;

                if (newValue > 255)
                    newValue = 255;

                if (newValue < 0)
                    newValue = 0;

                image.setPixel(i, j, k, newValue);
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
Image skew(Image &image)
{
    double angle;

    cout << "Please enter skew angle from 0 to less than 90:\n";
    cin >> angle;

    while (angle < 0 || angle >= 90)
    {
        cout << "Wrong angle! Enter an angle from 0 to less than 90:\n";
        cin >> angle;
    }

    double radians = angle * 3.14159 / 180;
    double factor = tan(radians);

    int extra_width = (image.height - 1) * factor;

    Image new_image(image.width + extra_width, image.height);

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int shift = (image.height - 1 - j) * factor;
            int new_x = i + shift;

            for (int k = 0; k < 3; k++)
            {
                int color = image.getPixel(i, j, k);
                new_image.setPixel(new_x, j, k, color);
            }
        }
    }

    return new_image;
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

    int rotate = 0;

    while (running) {
        cout << "--- MENU ---" << endl;
        cout << "1. Load a new image" << endl;
        cout << "2. Grayscale Conversion" << endl;
        cout << "3. Black and White" << endl;
        cout << "4. Invert Image" << endl;
        cout << "5. Adding Frame to the Picture" << endl;
        cout << "6. Flip Image" << endl;
        cout << "7. Rotate Image" << endl;
        cout << "8. Darken and Lighten Image" << endl;
        cout << "9. Resizing Images" << endl;
        cout << "10. Merge Images" << endl;
        cout << "11. Detect Image Edges" << endl;
        cout << "12. Crop Images" << endl;
        cout << "13. Blur Images" << endl;
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
                image = AddFrame(image);
                load = false;
                break;
            case 6:
                image = Flip(image);
                load = false;
                break;
            case 7:
                while (rotate != 90 && rotate != 270 && rotate != 180) {
                    cout << "rotate 90, 180 or 270? ";
                    cin >> rotate;
                }
                switch (rotate) {
                    case 90:
                        image = rotate90(image);
                        break;
                    case 180:
                        image = rotate180(image);
                        break;
                    case 270:
                        image = rotate270(image);
                        break;
                }
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
                image = Merge(image);
                load = false;
                break;
            case 11:
                image = imageEdges(image);
                load = false;
                break;
            case 12:
                image = crop(image);
                load = false;
                break;
            case 13:
                image = Blur(image);
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
