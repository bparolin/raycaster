
#include "scene.h"

Scene::Scene(int screenWidth, int screenHeight, Vec3f screenLeftDown, Vec3f eyeOrigin, Vec3f lightPosition)
  : screenWidth_(screenWidth),
    screenHeight_(screenHeight),
    screenLeftDown_(screenLeftDown),
    camera_(eyeOrigin),
    light_(lightPosition) {
  this->init();
}

Scene::~Scene() {
  delete mesh_;
}

void Scene::init() {
  Vec3f a(-100, -100, 0);
  Vec3f b(100, -100, 0);
  Vec3f c(100, 100, 0);
  Vec3f d(-100, 100, 0);
  mesh_ = new Quad(a, b, c, d);
}

void Scene::draw() {
  std::ofstream myfile;
  myfile.open("screen.pgm");
  myfile << "P2" << std::endl
         << screenWidth_ << " " << screenHeight_ << std::endl
         << "1" << std::endl;

  for (int i = 0; i < screenWidth_; i++) {
    for (int j = 0; j < screenHeight_; j++) {
      // Compute pos of screen
      Vec3f v(screenLeftDown_.x() + i, screenLeftDown_.y() + j, screenLeftDown_.z());

      // Compute ray direction
      Vec3f dir = v - camera_;
      Ray r(camera_, dir);

      Vec3f inter;
      if (mesh_->intersect(r, inter) == true) {
        myfile << "1";
      } else {
        myfile << "0";
      }

      if ((j + 1) < screenHeight_) {
        myfile << " ";
      }
    }
    myfile << std::endl;
  }

  myfile.close();
}


