#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "material.h"
#include <vector>

using namespace std;

int main() {
    hittable_list world;

    // Ground
    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(
        point3(0, -1000, 0), 1000, ground_material));

    auto material = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    double r = 0.4;

    // ===== SIX =====

    vector<vector<int>> x = 
    {
        {1,1,1,0,1,1,1},
        {1,0,0,0,0,0,1},
        {1,1,1,0,0,1,0},
        {1,0,1,0,0,1,0},
        {1,1,1,0,1,0,0}  
    };

    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x[i].size(); j++) {
            if (x[i][j] == 1) {
                world.add(make_shared<sphere>(
                    point3(j - 2, 4.5 - i, 1), r, material));
            }
        }
    }
    // Camera
    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 1200;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.vfov = 30;
    cam.lookfrom = point3(0, 3, 12);
    cam.lookat = point3(0, 2, 0);
    cam.vup = vec3(0, 1, 0);

    cam.render(world);
}