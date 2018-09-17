/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-
* Author: Nicholas Harding
* Class: CST 426
* Assignment: Lab 02
* Due Date: 18 - September - 2018
* Comments:
*
=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include <iostream>
#include <string>

using namespace std;


//Struct for the mesh
struct Mesh
{
    char shape[7] = "Dragon";
};

/*Dragon with neither Flyweight nor Momento and associated objects.*/
class DragonA
{
public:

  //Some sample variable types
  int size, health, exp;
  string eye_col;
  string scale_col;
  Mesh mesh;

  //A constructor that fills all the variables with the input given
  DragonA(int si, int he, int xp, string eye, string scale, Mesh mes)
  {
    size = si;
    health = he;
    exp = xp;
    eye_col = eye;
    scale_col = scale;
    mesh = mes;
  }
};

//End of Dragon A and associated objects.

//Dragon with Flyweight and associated objects.

//The mesh for all dragons. It would have a value specified as well, but we don't have
//any actual meshes to call.
Mesh dragon_mesh;

class DragonB
{
public:
  int size, health, exp;
  string eye_col;
  string scale_col;
  Mesh *mesh = &dragon_mesh;

  //This dragon is identical to DragonA, except the mesh always calls the
  //static mesh defined earlier in the code
  DragonB(int si, int he, int xp, string eye, string scale)
  {
    size = si;
    health = he;
    exp = xp;
    eye_col = eye;
    scale_col = scale;
  }
};

//End of Dragon B and associated objects.


//Dragon with Memento and associated objects.

//Saving only the relevant things into a Memento.
class Memento
{
public:
  int size, health, exp;
  string eye_col;
  string scale_col;
  Mesh *mesh = &dragon_mesh;
};

//Using a header for the class Caretaker so I can call it before I've defined it.
class Caretaker;

class DragonC
{
public:
  int size;
  int health;
  int exp;
  string eye_col;
  string scale_col;
  Mesh *mesh = &dragon_mesh;

  // DragonC(int si, int he, int xp, string eye, string scale)
  // {
  //   size = si;
  //   health = he;
  //   exp = xp;
  //   eye_col = eye;
  //   scale_col = scale;
  // }
};

class Caretaker
{
  public:

  //Storing the relevant information into a new Memento one piece at a time.
  Memento Save(DragonC dragon){
    Memento *a = new Memento;
    a->size = dragon.size;
    a->health = dragon.health;
    a->exp = dragon.exp;
    a->eye_col = dragon.eye_col;
    a->scale_col = dragon.scale_col;
    return *a;
  }

  //Loading the relevant Memento into a new Dragon one piece at a time.
  DragonC Load(Memento mem){
    DragonC *a = new DragonC;
    a->size = mem.size;
    a->health = mem.health;
    a->exp = mem.exp;
    a->eye_col = mem.eye_col;
    a->scale_col = mem.scale_col;
    return *a;
  }
};

//End of Dragon C and associated objects.

int main() {
  //Just some commented out example dragons in the main, ignore this

  // DragonA dragon1(30, 100, 500, "red", "red", dragon_mesh);
  // DragonA dragon2(40, 150, 750, "blue", "blue", dragon_mesh);
  // DragonA dragon3(50, 200, 1000, "green", "green", dragon_mesh);
}
