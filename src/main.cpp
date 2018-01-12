/*
DONE proposer une structure "quad" (quadrilatère) et une structure "rayon"

DONE - implanter un calcul d'intersection entre un quad et un rayon

DONE proposer un calcul de normal à un quad
- écrire  un  modèle  permettant  de  définir  une  source  qui  est  également  une  face  et  un
modèle  d'éclairage  local  de  type  "Phong"  (avec  normalisation  des  coefficients  pour
préserver la conservation d'énergie)

- implanter  un  lancer  de  rayons  "stochastique"  permet
tant  de  calculer  une  image  en
subdivisant  les  pixels  en  N*N  sous-pixels  et  calculant  les  "pénombres"  liées  à  la
source surfacique.

- On implantera ensuite uniquement la réflexion "floue", pas la réfraction  (donc pas de
transparence). Pour cela, écrire une opération permettant de choisir aléatoirement une
direction  dans  un  cône  donné  (le  cône  est  défini  par  un  vecteur  de  direction  et  un angle).
*/

#include "scene.h"

Scene* scene = NULL;

void display() {
  scene->draw();
}

void keyboard(unsigned char keycode, int a, int b) {
  // Press Echap to leave
  if (keycode == 27) {
    exit(EXIT_SUCCESS);
  } else if (keycode == 'd') {
    scene->draw();
  }
}

int main(int argc, char* argv[]) {

  const int windowWidth = 1000;
  const int windowHeight = 1000;

  glutInit(&argc, argv);
  glutInitWindowSize(windowWidth, windowHeight);
  glutCreateWindow("Lancer de rayons");
  gluOrtho2D(0.0, windowWidth, windowHeight, 0.0);

  scene = new Scene(windowWidth, windowHeight);

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);

  glutMainLoop();

  return 0;
}
