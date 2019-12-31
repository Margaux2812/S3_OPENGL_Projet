#pragma once

#include <eigen3/Eigen/Dense>

const int WORLD_WIDTH_HEIGHT = 50;
const int WORLD_DEPTH = -50;

float distance2D(Eigen::Vector2f pt1, Eigen::Vector2f pt2);
float phi(float a);

int findValue(const int i, const int j, const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf wk);
Eigen::VectorXf findOmega(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf uk);

/*MapCoord contient tous les points de la Map et est donc de dimension N*N avec des duos de coordonnées (x, z)
ptsDeControle est une matrice (2, N) autrement dit avec des coordonnées, et autant de coordonnées qu'on veut*/
Eigen::MatrixXd getValues(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf uk);