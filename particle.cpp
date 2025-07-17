#include "particle.h"

Particle::Particle(float startX, float startY)
    : 
    x(startX), 
    y(startY), 
    oldX(startX), 
    oldY(startY),
      ax(0.0f), 
      ay(0.0f), 
      pinned(false) {}

void Particle::applyForce(float fx, float fy) {
    ax += fx;
    ay += fy;
}

void Particle::setY(float newY) {
    y = newY;
}

void Particle::setOldY(float newOldY) {
    oldY = newOldY;
}

float Particle::getOldY() const {
    return oldY;
}



void Particle::update(float dt) {
    if (pinned) return;

    float velocityX = x - oldX;
    float velocityY = y - oldY;

    float nextX = x + velocityX + ax * dt * dt;
    float nextY = y + velocityY + ay * dt * dt;

    // Floor collision
    float floorY = 460.0f;
    if (nextY > floorY) {
        nextY = floorY;
        velocityY *= -0.8f; // bounce
        oldY = nextY - velocityY;  // "fake" a bounce by setting oldY behind
    } else {
        oldY = y;
    }

    oldX = x;
    x = nextX;
    y = nextY;

    ax = 0.0f;
    ay = 0.0f;
}




void Particle::pin() {
    pinned = true;
}

bool Particle::isPinned() const {
    return pinned;
}

float Particle::getX() const {
    return x;
}

float Particle::getY() const {
    return y;
}

