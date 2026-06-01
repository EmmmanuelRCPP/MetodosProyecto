#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "material.h"

int main() {
    hittable_list world;

    auto ground_material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));


    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1.5, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(1, 0, 0));
    world.add(make_shared<sphere>(point3(-1.2, 1, 0.2), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(1.2, 1, 0.2), 1.0, material3));

    camera cam;

    cam.aspect_ratio      = 12.0 / 9.0;
    cam.image_width       = 600;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.vfov = 30;
    cam.lookfrom = point3(0, 3, 12);
    cam.lookat = point3(0, 2, 0);
    cam.vup = vec3(0, 1, 0);

    cam.render(world);
}