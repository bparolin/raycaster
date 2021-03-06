
#include "scene.h"

Scene::Scene(int screenWidth, int screenHeight)
  : screenWidth_(screenWidth),
    screenHeight_(screenHeight) {
  this->init();
}

Scene::~Scene() { }

void Scene::addCube(Vec3f leftDownPos, int size, Vec3f color) {
  Vec3f a(leftDownPos.x() + size, leftDownPos.y(), leftDownPos.z());
  Vec3f b(leftDownPos.x() + size, leftDownPos.y() + size, leftDownPos.z());
  Vec3f c(leftDownPos.x(), leftDownPos.y() + size, leftDownPos.z());
  Vec3f d(leftDownPos.x(), leftDownPos.y(), leftDownPos.z() + size);
  Vec3f e(leftDownPos.x() + size, leftDownPos.y(), leftDownPos.z() + size);
  Vec3f f(leftDownPos.x() + size, leftDownPos.y() + size, leftDownPos.z() + size);
  Vec3f g(leftDownPos.x(), leftDownPos.y() + size, leftDownPos.z() + size);

  Mesh cube(color);

  cube.addFace(Quad(leftDownPos, c, b, a));
  cube.addFace(Quad(leftDownPos, a, e, d));
  cube.addFace(Quad(leftDownPos, d, g, c));
  cube.addFace(Quad(a, b, f, e));
  cube.addFace(Quad(c, g, f, b));
  cube.addFace(Quad(d, e, f, g));

  meshes_.push_back(cube);
}

void Scene::init() {
  screenLeftDown_ = Vec3f(-screenWidth_ / 2, 0, 20);
  light_ = Vec3f(200, 400, 20);

  Vec3f cameraPos(0, 250, screenLeftDown_.z() + (screenWidth_ / std::tan(27)));
  camera_.init(cameraPos);


  Mesh groundFloor(Vec3f(0.33, 0.33, 0.33));
  Vec3f a(-screenWidth_, 0, 0);
  Vec3f b(screenWidth_, 0, 0);
  Vec3f c(screenWidth_, 0, 2 * screenHeight_);
  Vec3f d(-screenWidth_, 0, 2 * screenHeight_);
  groundFloor.addFace(Quad(a, d, c, b));
  meshes_.push_back(groundFloor);

  addCube(Vec3f(50, 0, 50), 100, Vec3f(1, 0, 0));
  addCube(Vec3f(-150, 0, 50), 100, Vec3f(0, 1, 0));
}

bool Scene::computeShadow(Ray r, int faceId) {
  int id = 0;
  Vec3f inter;
  std::vector<Mesh>::iterator itMesh;
  for (itMesh = meshes_.begin(); itMesh != meshes_.end(); ++itMesh) {
    std::vector<Quad> faces = (*itMesh).getFaces();
    std::vector<Quad>::iterator itFace;
    for (itFace = faces.begin(); itFace != faces.end(); ++itFace) {
      if ((*itFace).intersect(r, inter) == true && id != faceId) {
          return true;
      }
      id++;
    }
  }
  return false;
}

Vec3f Scene::raycast(Ray r, int bounce) {
  if (bounce > 3) {
    return Vec3f(0, 0, 0);
  }

  Vec3f inter, color(0, 0, 0);
  Mesh nearest(Vec3f(0, 0, 0));
  Quad nearestFace;
  float nearestDist = 0;
  Vec3f nearestInter;
  int nearestId = -1;
  int id = 0;

  std::vector<Mesh>::iterator itMesh;
  for (itMesh = meshes_.begin(); itMesh != meshes_.end(); ++itMesh) {
    std::vector<Quad> faces = (*itMesh).getFaces();
    std::vector<Quad>::iterator itFace;
    for (itFace = faces.begin(); itFace != faces.end(); ++itFace) {
      if ((*itFace).intersect(r, inter) == true) {
        Vec3f dist = inter - r.getOrigin();
        if (nearestId == -1) {
          nearest = (*itMesh);
          nearestDist = dist * dist;
          nearestId = id;
          nearestInter = inter;
          nearestFace = (*itFace);
        } else {
          float square = dist * dist;
          if (square < nearestDist) {
            nearest = (*itMesh);
            nearestDist = square;
            nearestId = id;
            nearestInter = inter;
            nearestFace = (*itFace);
          }
        }
      }
      id++;
    }
  }

  // No Intersection
  if (nearestId == -1)
    return color;

  Vec3f lightDir = light_ - nearestInter;
  lightDir.normalize();
  Ray shadowRay(nearestInter, lightDir);
  if (computeShadow(shadowRay, nearestId) == false) {
    color = nearest.getColor();
  }

  Vec3f ref = r.getDirection() - nearestFace.getNormal() * 2 * (r.getDirection() * nearestFace.getNormal());
  Ray reflect(nearestInter, ref);
  Vec3f col = raycast(reflect, bounce + 1);

  return color + col * 0.35;
}

void Scene::draw() {

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  for (int i = 0; i < screenWidth_; i++) {
    for (int j = 0; j < screenHeight_; j++) {
      // Compute pos of screen
      Vec3f v(screenLeftDown_.x() + i + 0.5, screenLeftDown_.y() + j + 0.5, screenLeftDown_.z());

      // Compute ray direction
      Vec3f dir = v - camera_.getPosition();
      dir.normalize();
      Ray r(camera_.getPosition(), dir);
      Vec3f color = raycast(r, 0);
      glBegin(GL_POINTS);
        glColor3f(color.x(), color.y(), color.z());
        glVertex2i(i, screenHeight_ - j);
      glEnd();
    }
  }

  glFlush();
}

