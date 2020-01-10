#pragma once

/*!
 * \file radialBasisFunctions.hpp
 * \brief Manage rbf generator
 */


#include <eigen3/Eigen/Dense>

const int WORLD_WIDTH_HEIGHT = 50;
const int WORLD_DEPTH = -50;

/**
 * @brief calculate distance between to vectors
 * 
 * @param pt1 
 * @param pt2 
 * @return float 
 */
float distance2D(Eigen::Vector2f pt1, Eigen::Vector2f pt2);

/**
 * @brief calculate phi from RBF classes theorem
 * 
 * @param a 
 * @return float exp(-0.2*a*a)
 */
float phi(float a);

/**
 * @brief calculate value from RBF classes theorem
 * 
 * @param i 
 * @param j 
 * @param ptsDeControle 
 * @param wk 
 * @return int 
 */
int findValue(const int i, const int j, const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf wk);

/**
 * @brief fint Omega from RBF classes theorem
 * 
 * @param ptsDeControle 
 * @param uk 
 * @return Eigen::VectorXf 
 */
Eigen::VectorXf findOmega(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf uk);

/**
 * @brief Get the Values object
 * MapCoord contient tous les points de la Map et est donc de dimension N*N avec des duos de coordonnées (x, z)
 * ptsDeControle est une matrice (2, N) autrement dit avec des coordonnées, et autant de coordonnées qu'on veut
 * @param ptsDeControle 
 * @param uk 
 * @return Eigen::MatrixXd 
 */
Eigen::MatrixXd getValues(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf uk);