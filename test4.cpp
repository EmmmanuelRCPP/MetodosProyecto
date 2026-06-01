#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "material.h"

int main() {
    hittable_list world;

    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));



    auto materialMadera = make_shared<lambertian>(color(1, 0.0, 0.0));
    world.add(make_shared<sphere>(point3(1, 1, -6), 1.0, materialMadera));


    auto materialEspejo = make_shared<metal>(color(1, 1, 1), 0.0);
    world.add(make_shared<sphere>(point3(0, 1, -12), 1.0, materialEspejo));
    world.add(make_shared<sphere>(point3(2, 1., 0), 1.0, materialEspejo));

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