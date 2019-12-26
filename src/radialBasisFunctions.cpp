#include "../include/radialBasisFunctions.hpp"
#include <math.h>
#include <iostream>

Eigen::MatrixXf getMapCoord(){

	/*Une matrice ne peut pas contenir des coordonnées, donc on va avoir une matrice deux fois plus large*/
	Eigen::MatrixXf mapCoord(WORLD_WIDTH_HEIGHT, 2*WORLD_WIDTH_HEIGHT);
	for(int i=0; i<mapCoord.rows(); i++){
		for(int j=0; j<mapCoord.cols(); j += 2){
			/*La deuxieme coordonnée est divisée par 2 comme on lui ajoute 2 à chaque fois*/
			mapCoord(i, j) = i;
			mapCoord(i, j+1) = j/2;
		}
	}

	return mapCoord;
}

void test(){
	Eigen::MatrixXf ptsDeControle(1, 2);
	ptsDeControle << 0, 0;
	Eigen::VectorXf uk(1);
	uk << 1;

	std::cout << getValues(ptsDeControle, uk).rows() <<std::endl;

}


float phi(const float a){
	return exp(-0.2*a*a);
}

Eigen::VectorXf findOmega(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf uk){
	Eigen::MatrixXf A = Eigen::MatrixXf::Zero(ptsDeControle.rows(), ptsDeControle.rows());

	for(int i=0; i<A.rows(); i++){
		for(int j=0; j<A.cols(); j++){
			A(i, j) = phi(
				(ptsDeControle.row(i) - ptsDeControle.row(j)).norm() //La distance entre deux points est la norme de la différence
				);
		}
	}

	return A.inverse() * uk;
}

int findValue(const int i, const int j, const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf wk){
	if(ptsDeControle.cols() != 2){
		throw "Les points de contrôles devraient avoir 2 coordonnées";
		return 0;
	}

	float value = 0;
	Eigen::VectorXf coordPt(2);

	for(int index=0; index < ptsDeControle.rows(); index ++){
		coordPt << i, j;
		value += wk(index) * phi((coordPt.transpose() - ptsDeControle.row(index)).norm());
	}

	return round(value);
}

Eigen::MatrixXd getValues(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf uk){
	if(ptsDeControle.cols() != 2){
		throw "Les points de contrôles devraient avoir 2 coordonnées";
	}else{
		Eigen::VectorXf wk = findOmega(ptsDeControle, uk);
		Eigen::MatrixXd values = Eigen::MatrixXd::Zero(WORLD_WIDTH_HEIGHT, WORLD_WIDTH_HEIGHT);

		for(int i=0; i<values.rows(); i++){
			for(int j=0; j<values.cols(); j++){
				values(i, j) = findValue(i, j, ptsDeControle, wk);
			}
		}

		return values;
	}
}