// Bryn Mawr College, alinen, 2020
// Haverford College, Jason Ma, 2021

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "myparticlesystem.h"

using namespace std;
using namespace agl;
using namespace glm;

void MyParticleSystem::createParticles(int size) 
{
  mTexture = theRenderer.loadTexture("../textures/particle.png");
  // initialize the list of particles based on the size
  vec3 pos = random_unit_rectangle();
  vec3 color = vec3(random_float(), random_float(), random_float());
  for (int i = 0; i < size; i++)
  {
    Particle p = {pos, random_unit_vector(), vec4(color, 1.0f), 0.1f, random_float(), 1.5f};
    mParticles.push_back(p);
  }
}

void MyParticleSystem::update(float dt)
{
   vec3 pos = random_unit_cube();
   if (life > 0.0f)
   {
      life -= dt;
      for (auto p = begin(mParticles); p != end(mParticles); p++)
      {
         if (p->life > 0.0f)
         { 
            p->life -= dt;
            if (p->life > 0.0f)
            {
               p->vel += glm::vec3(0.0f,-9.81f, 0.0f) * dt * 0.5f;
               p->color -= 0.1f * dt * p->color;
               p->pos += p->vel * dt;
            }
         }
      }
   }
   else{
      life = 1.5f;
      respawnParticles();
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
}

void MyParticleSystem::respawnParticles()
{
   vec3 pos = random_unit_rectangle();
   vec3 color = vec3(random_float(), random_float(), random_float());
   for (auto p = begin(mParticles); p != end(mParticles); p++)
   {
      p->pos = pos;
      p->vel = random_unit_vector();
      p->color = vec4(color, 1.0f);
      p->life = 1.5f;
   }
}
