#ifndef MyParticleSystem_H_
#define MyParticleSystem_H_

#include "particlesystem.h"

namespace agl {

   class MyParticleSystem : public ParticleSystem {
   public:
      virtual void createParticles(int size) override;
      virtual void update(float dt) override;
      void respawnParticles();
   
   protected:
      float life = 1.5f;
   };
}
#endif