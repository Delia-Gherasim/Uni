//#include "string"
//#include "iostream"
//#include "fstream"
//#include <Windows.h>
//#include <cmath>
//
//using namespace std;
//
//const int width = 400;
//const int height = 400;
//const int u = 20;
//
//void writeHeader(ostream& out, int width, int height);
//
//void transform(int x, int y, int& px, int& py) {
//    px = width / 2 + x * u;
//    py = height / 2 - y * u;
//}
//
//void setPixel(unsigned char* img, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
//    if (x >= 0 && x < width && y >= 0 && y < height) {
//        int index = (y * width + x) * 3;
//        img[index] = b;
//        img[index + 1] = g;
//        img[index + 2] = r;
//    }
//}
//
//void drawAxes(unsigned char* img) {
//    for (int x = 0; x < width; x++) {
//        setPixel(img, x, height / 2, 0, 0, 0); 
//    }
//    for (int y = 0; y < height; y++) {
//        setPixel(img, width / 2, y, 0, 0, 0); 
//    }
//}
//
//void drawLine(unsigned char* img, int x1, int y1, int x2, int y2) {
//    int dx = abs(x2 - x1), dy = abs(y2 - y1);
//    int sx = x1 < x2 ? 1 : -1;
//    int sy = y1 < y2 ? 1 : -1;
//    int err = dx - dy;
//
//    while (true) {
//        setPixel(img, x1, y1, 255, 0, 0); 
//
//        if (x1 == x2 && y1 == y2) break;
//        int e2 = 2 * err;
//        if (e2 > -dy) { err -= dy; x1 += sx; }
//        if (e2 < dx) { err += dx; y1 += sy; }
//    }
//}
//
//void drawCircle(unsigned char* img, int cx, int cy, int r) {
//    int x = 0;
//    int y = r;
//    int d = 3 - 2 * r;
//    while (y >= x) {
//        setPixel(img, cx + x, cy + y, 0, 0, 255); 
//        setPixel(img, cx - x, cy + y, 0, 0, 255);
//        setPixel(img, cx + x, cy - y, 0, 0, 255);
//        setPixel(img, cx - x, cy - y, 0, 0, 255);
//        setPixel(img, cx + y, cy + x, 0, 0, 255);
//        setPixel(img, cx - y, cy + x, 0, 0, 255);
//        setPixel(img, cx + y, cy - x, 0, 0, 255);
//        setPixel(img, cx - y, cy - x, 0, 0, 255);
//
//        x++;
//        if (d > 0) {
//            y--;
//            d = d + 4 * (x - y) + 10;
//        }
//        else {
//            d = d + 4 * x + 6;
//        }
//    }
//}
//
//void makeCheckerboardBMP(string fileName, int squaresize, int n) {
//    ofstream ofs;
//    ofs.open(fileName + ".bmp");
//    writeHeader(ofs, n, n);
//
//    for (int row = 0; row < n; row++) {
//        for (int col = 0; col < n; col++) {
//            // ofs << (unsigned char) 0;
//            //   ofs << (unsigned char) 0;
//            //   ofs << (unsigned char) 0;
//
//            if ((col % 2 == 0) && (row % 2 == 0)) {
//                ofs << (unsigned char)0;
//                ofs << (unsigned char)0;
//                ofs << (unsigned char)0;
//            }
//            else {
//                ofs << (unsigned char)255;
//                ofs << (unsigned char)255;
//                ofs << (unsigned char)255;
//            }
//            if ((col % 2 == 1) && (row % 2 == 1)) {
//                ofs << (unsigned char)0;
//                ofs << (unsigned char)0;
//                ofs << (unsigned char)0;
//            }
//        }
//    }
//}
//
//void writeBMP(string filename, unsigned char* img) {
//    ofstream ofs(filename + ".bmp", ios::binary);
//    writeHeader(ofs, width, height);
//    ofs.write((char*)img, width * height * 3);
//    ofs.close();
//}
//
//void writeHeader(ostream& out, int width, int height) {
//    if (width % 4 != 0) {
//        cerr << "ERROR: There is a windows-imposed requirement on BMP that the width be a multiple of 4.\n";
//        cerr << "Your width does not meet this requirement, hence this will fail.  You can fix this\n";
//        cerr << "by increasing the width to a multiple of 4." << endl;
//        exit(1);
//    }
//
//    BITMAPFILEHEADER tWBFH;
//    tWBFH.bfType = 0x4d42;
//    tWBFH.bfSize = 14 + 40 + (width * height * 3);
//    tWBFH.bfReserved1 = 0;
//    tWBFH.bfReserved2 = 0;
//    tWBFH.bfOffBits = 14 + 40;
//
//    BITMAPINFOHEADER tW2BH;
//    memset(&tW2BH, 0, 40);
//    tW2BH.biSize = 40;
//    tW2BH.biWidth = width;
//    tW2BH.biHeight = height;
//    tW2BH.biPlanes = 1;
//    tW2BH.biBitCount = 24;
//    tW2BH.biCompression = 0;
//
//    out.write((char*)(&tWBFH), 14);
//    out.write((char*)(&tW2BH), 40);
//}
//
//
//int main() {
//    unsigned char* img = new unsigned char[width * height * 3];
//    memset(img, 255, width * height * 3); 
//
//    drawAxes(img);
//
//    int ax, ay, bx, by;
//    transform(-2, 3, ax, ay);
//    transform(2, 5, bx, by);
//    drawLine(img, ax, ay, bx, by);
//
//    int cx, cy;
//    transform(3, -4, cx, cy);
//    drawCircle(img, cx, cy, int(2.5 * u));
//
//    writeBMP("coordonate", img);
//
//    delete[] img;
//    return 1;
//
//
//}
