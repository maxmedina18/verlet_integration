#pragma once

class Particle{
public:
    Particle(float startX, float startY);

    void update(float dt);
    void applyForce(float fx, float fy);
    void pin();
    bool isPinned() const;

    float getX() const;
    float getY() const;

    void setY(float newY);
    void setOldY(float newOldY);
    float getOldY() const;






private:
  float x, y;
  float oldX, oldY;
  float ax, ay;
  bool pinned;  
};
