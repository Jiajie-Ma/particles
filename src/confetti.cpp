// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "confetti.h"

using namespace std;
using namespace agl;
using namespace glm;

void Confetti::createParticles(int size) 
{
  mTexture = theRenderer.loadTexture("../textures/particle.png");
  // initialize the list of particles based on the size
  for (int i = 0; i < size; i++)
  {
    Particle p = {random_unit_cube(), random_unit_vector(), vec4(random_unit_vector(), random_float()), 0.25, random_float(), 0.0};
    mParticles.push_back(p);
  }
}

void Confetti::update(float dt)
{
  // update particles
  
  for (auto p = begin(mParticles); p != end(mParticles); p++)
  {
    vec3 _pos = p->pos + p->vel * dt;
    if (p->pos.x < -1)
    {
      p->vel = reflect(p->vel, vec3(1,0,0));
    }
    else if (p->pos.x > 1)
    {
      p->vel = reflect(p->vel, vec3(-1,0,0));
    }
    else if (p->pos.y > 1)
    {
      p->vel = reflect(p->vel, vec3(0,-1,0));
    }
    else if (p->pos.y < -1)
    {
      p->vel = reflect(p->vel, vec3(0,1,0));
    }
    else if (p->pos.z > 1)
    {
      p->vel = reflect(p->vel, vec3(0,0,-1));
    }
    else if (p->pos.z < -1)
    {
      p->vel = reflect(p->vel, vec3(0,0,1));
    }
    p->pos += p->vel * dt;
  }

  vector<Particle> _Particles;
  _Particles.push_back(mParticles.front());
  int l = 0;
  for (auto& p: mParticles)
  {
    l += 1;
    float d = p.pos.z;
    for (auto q = begin(_Particles); q != end(_Particles); q++){

      float _d = q->pos.z;

      if (d < _d)
      {
        _Particles.insert(q, p);
        break;
      }
    }
    if (_Particles.size() < l)
    {
      _Particles.push_back(p);
    }
  }

  mParticles = _Particles;

  /*
  float _d = distance(begin(mParticles) -> pos, cameraPos);
  for (auto p = begin(mParticles) + 1; p != end(mParticles); p++){

    float d = distance(p -> pos, cameraPos);

    if (d > _d){
      iter_swap(p, p-1);
    }

    _d = d;
  }
  */
}

