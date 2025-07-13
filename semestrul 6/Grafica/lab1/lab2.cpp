#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

const int WIDTH = 500;
const int HEIGHT = 500;
const int BPP = 3;

struct Point3D {
    double x, y, z;
};

struct Point2D {
    int x, y;
};

void saveBitmap(const vector<unsigned char>& image, const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Saving image error!" << endl;
        return;
    }
    int rowSize = (WIDTH * BPP + 3) & (~3);
    int fileSize = 54 + rowSize * HEIGHT;

    unsigned char header[54] = { 0 };
    header[0] = 'B'; header[1] = 'M';
    *(int32_t*)&header[2] = fileSize;
    header[10] = 54;
    header[14] = 40;
    *(int32_t*)&header[18] = WIDTH;
    *(int32_t*)&header[22] = HEIGHT;
    header[26] = 1;
    header[28] = BPP * 8;
    *(int32_t*)&header[34] = fileSize - 54;

    file.write((char*)header, 54);
    vector<unsigned char> row(rowSize, 0);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH * BPP; x++)
            row[x] = image[((HEIGHT - y - 1) * WIDTH * BPP) + x];
        file.write((char*)row.data(), rowSize);
    }
    file.close();
}

Point3D scale(Point3D p, double factor) {
    return { p.x * factor, p.y * factor, p.z * factor };
}

Point3D translate(Point3D p, double dx, double dy, double dz) {
    return { p.x + dx, p.y + dy, p.z + dz };
}

Point3D rotateY(Point3D p, double angle) {
    double rad = angle * M_PI / 180.0;
    double cosA = cos(rad);
    double sinA = sin(rad);
    return { p.x * cosA - p.z * sinA, p.y, p.x * sinA + p.z * cosA };
}

Point3D rotateAroundCenter(Point3D p, double angle) {
    return rotateY(p, angle);
}

Point2D project(Point3D p, Point3D camera) {
    double d = 100.0;
    return { (int)(WIDTH / 2 + d * (p.x - camera.x) / (d - (p.z - camera.z))),
             (int)(HEIGHT / 2 - d * (p.y - camera.y) / (d - (p.z - camera.z))) };
}

void drawLine(vector<unsigned char>& image, Point2D p1, Point2D p2) {
    int dx = abs(p2.x - p1.x), dy = abs(p2.y - p1.y);
    int sx = p1.x < p2.x ? 1 : -1, sy = p1.y < p2.y ? 1 : -1;
    int err = dx - dy;
    while (true) {
        if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT) {
            int index = (p1.y * WIDTH + p1.x) * BPP;
            image[index] = 0; image[index + 1] = 0; image[index + 2] = 0;
        }
        if (p1.x == p2.x && p1.y == p2.y) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; p1.x += sx; }
        if (e2 < dx) { err += dx; p1.y += sy; }
    }
}

int main() {
    vector<unsigned char> image(WIDTH * HEIGHT * BPP, 255); 

    Point3D cube[8] = {
        {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}, {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5},
        {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5}, {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5}
    };

    for (int i = 0; i < 8; i++) {
        cube[i] = scale(cube[i], 20);
        cube[i] = rotateAroundCenter(cube[i], 45);
        cube[i] = translate(cube[i], 40, 40, -40);
    }

    Point3D camera = { -50, 50, -50 };

    int edges[12][2] = { {0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {5, 6}, {6, 7}, {7, 4}, {0, 4}, {1, 5}, {2, 6}, {3, 7} };
    for (auto& edge : edges) {
        drawLine(image, project(cube[edge[0]], camera), project(cube[edge[1]], camera));
    }

    saveBitmap(image, "cub_wireframe.bmp");
    return 0;
}