#pragma once
#include <windows.h>
#include "MyForm.h"


int sgn(double x);
double *normalize(double *array, int arraySize, int Size, int LabelSize);
double *random_weight(int size);
double *discrete_updating_weight(double *W, double *array, int Size, int where, int O, double d, double c);
double *continuous_updating_weight(double *W, double *array, int Size, int where, double O, double d, double fnet, double c);
int *Perceptron(double *array, double *Weight, int arraySize, int Size);
int *Delta(double *array, double *Weight, int arraySize, int Size);
int *MultiPerceptron(double *array, double *Weight, int arraySize, int Size, int NumberOfClass);
int *MultiDelta(double *array, double *Weight, int arraySize, int Size, int NumberOfClass);
int MultilayerNetwork(double *array, double *W,double *V, int arraySize, int Size, int NumberOfClass, int hiddenLayerSize);
int MultiLayerNetworkResultView(double *array, double *W, double *V, int Size, int NumberOfClass, int hiddenLayerSize);
int MultilayerNetworkMoment(double *array, double *W, double *V, int arraySize, int Size, int NumberOfClass, int hiddenLayerSize);
class coordinate
{
public: double x;
		coordinate* next;
};

class coordinatelist
{
public:	coordinate * head;
		coordinatelist();
		void add(const double& e);

};