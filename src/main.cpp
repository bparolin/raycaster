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

#include "ray.h"
#include "quad.h"
#include <fstream>

#include "scene.h"

int main() {
  Vec3f a(-100, -100, 0);
  Vec3f b(100, -100, 0);
  Vec3f c(100, 100, 0);
  Vec3f d(-100, 100, 0);
  Quad q(a, b,c, d);

  const int W = 500;
  const int H = 500;

  // Screen down left position
  Vec3f s(-250, -250, -2);

  // Eye origin
  Vec3f e(0, 0, -10);

  Scene scene(W, H, s, e);
  scene.draw();

  return 0;
}
