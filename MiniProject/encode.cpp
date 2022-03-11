
#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

bool checkBitset(char ch, int pos)
{
    // 7 6 5 4 3 2 1 0
    ch = ch >> pos;
    if (ch & 1)
        return true;
    return false;
}

int main()
{

    // Enter path of input image here -->
    // Path = D:/cvtest/eye.png
    auto filename = "D:/cvtest/eye.png";
    Mat image = imread(filename);

    if (image.empty())
    {
        cout << "Cannot load Image.\n";
        exit(-1);
    }
    imshow("IMAGE", image);

    waitKey();

    // Enter path of text file here->
    // Path = D:/cvtest/input_text.txt
    auto filename2 = " D:/cvtest/input_text.txt";
    ifstream file(filename2);
    if (!file.is_open())
    {
        cout << "Cannot open file.\n";
        exit(-1);
    }

    char ch;

    file.get(ch);
    // contains information about which bit of char to work on
    int count_bit = 0;

    bool end_word = false;

    bool encoded = false;

    for (int rows = 0; rows < image.rows; rows++)
    {
        for (int cols = 0; cols < image.cols; cols++)
        {
            for (int colour = 0; colour < 3; colour++)
            {
                // Vec <channels> <one char for the type>
                Vec3b pixels = image.at<Vec3b>(Point(rows, cols));

                if (checkBitset(ch, 7 - count_bit))
                    pixels.val[colour] |= 1; // If bit is 1 , change LSB to 1
                else
                    pixels.val[colour] &= ~1; // If bit is 0 , change LSB to 0

                // update the image with the changed pixel values
                image.at<Vec3b>(Point(rows, cols)) = pixels;

                // increment bit_count to work on next bit
                count_bit++;

                if (end_word && count_bit == 8)
                {
                    encoded = true;
                    goto ENDLOOP;
                }

                // if bit_count is 8 we pick the next char from the file and work on it
                if (count_bit == 8)
                {
                    count_bit = 0;
                    file.get(ch);

                    // if EndOfFile(EOF) is encountered insert NULL char to the image
                    if (file.eof())
                    {
                        end_word = true;
                        ch = '\0';
                    }
                }
            }
        }
    }
ENDLOOP:;

    // whole message was not encoded
    if (!encoded)
    {
        cout << "Message too big .Cannot Encode . Try with larger image or try shorter text.\n";
        exit(-1);
    }

    destroyAllWindows();

    // Writes the stegnographic image
    // Create a local output image file with no content in it.

    // PATH = D:/cvtest/output_image.png
    auto filename3 = " D:/cvtest/output_image.png";

    bool check = imwrite(filename3, image);

    if (check == false)
    {
        cout << "Mission- SAVING THE ENCRYPTED IMAGE failed successfully." << endl;
        cin.get(); // Waiting for user to press any key.
        return -1;
    }
    cout << "IMAGE ENCRYPTED SUCCESSFULLY" << endl;

    String geek_window = "ENCRYPTED IMAGE";

    namedWindow(geek_window);
    imshow(geek_window, image);

    waitKey(0);

    destroyWindow(geek_window);

    return 0;
}
