#include <windows.h>
#include "MyForm.h"
#include "ysa.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <random>


using namespace std;
double GlobalMx;
double GlobalMy;
double Globalx_sDeviation;
double Globaly_sDeviation;
int sgn(double x)
{
	if (x >= 0)
		return 1;
	else
		return -1;

}

double *normalize(double *array, int arraySize, int Size, int LabelSize)
{
	double temp=0;
	double br;
	int j;
	if (LabelSize <= 2 && LabelSize>0)
		LabelSize = 1;
	double *array_result = new double[arraySize];
	double Mx=0;
	double My=0;
	double number=0;
	double x_sDeviation = 0;
	double y_sDeviation = 0;

	for (int i = 0; i < arraySize; i += (Size + LabelSize))
	{		
		Mx += array[i];
		My += array[i + 1];	
		number++;
	}
	Mx = Mx / number;
	My = My / number;
	for (int i = 0; i < arraySize; i += (Size + LabelSize))
	{
		x_sDeviation += pow((array[i] - Mx), 2);
		y_sDeviation += pow((array[i+1] - My), 2);
	}
	x_sDeviation = sqrt(x_sDeviation / (number - 1));
	y_sDeviation = sqrt(y_sDeviation / (number - 1));
	Globalx_sDeviation = x_sDeviation;
	Globaly_sDeviation = y_sDeviation;
	GlobalMx = Mx;
	GlobalMy = My;

	for (int i = 0; i < arraySize; i += (Size + LabelSize))
	{

		array_result[i] = (array[i]-Mx)/x_sDeviation;
		array_result[i+1] = (array[i+1] - My) / y_sDeviation;
		array_result[i + 2] = array[i+2];

		if (LabelSize > 2)
			for (int h = 0; h < LabelSize; h++)
				array_result[i + 3 + h] = array[i + 3 + h];
		else
			array_result[i + 3] = array[i + 3];
	}
	
	/*for (int i = 0; i < arraySize; i += (Size + LabelSize))
	{
		for (j = 0; j < Size; j++)
		{
			temp += pow(array[i + j], 2);
		}
		br = sqrt(temp);
		temp = 0;
		for (j = 0; j < Size; j++)
		{
			array_result[i + j] = array[i + j] / br;
		}
		if (LabelSize > 2)
			for (int h = 0; h < LabelSize; h++)
				array_result[i + j + h] = array[i + j + h];
		else
			array_result[i + j] = array[i + j];
	}*/

	return array_result;
}

double *random_weight(int size)
{
	double *W = new double[size];
	for (int i = 0; i < size; i++)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(0.00, 1.00);
		W[i] = dist(mt);
		
		
	}
	return W;
}

double *discrete_updating_weight(double *W, double *array,int Size, int where, int O, double d,double c)
{
	for (int k = 0; k < Size; k++)
	{
		W[k] = W[k] + c * (d - O)*(array[where + k]);
	}
	return W;
}

double *continuous_updating_weight(double *W, double *array, int Size, int where, double O, double d,double fnet, double c)
{
	for (int k = 0; k < Size; k++)
	{

		W[k] = W[k] + c * (d - O)*fnet*(array[where + k]);
	}
	return W;
}


int *Perceptron(double *array,double *Weight ,int arraySize,int Size)
{
	double *W = new double[Size];
	for (int i = 0; i < Size;i++)
		W[i]= Weight[i];
	double c = 0.1;
	int O;
	double d;
	double net = 0;
	int j,k;
	int x1, y1, x2, y2;
	int *result = new int[5];
	bool status = true;
	int cycle = 0;
	while (status)
	{
		status = false;
		for (int i = 0; i < arraySize; i += (Size + 1))
		{
			for (j = 0; j < Size; j++)
			{
				net += W[j] * (array[i + j]);
			}
			d = array[i + j];	//etiket
			O = sgn(net);		//fonksyon sonucu
			

			if (d != O)
			{
				W = discrete_updating_weight(W, array, Size, i, O, d, c);
				status = true;
			}
			net = 0;

		}
		cycle++;
	}

	//W0*X + W1*Y - W2=0
	//W0(x-300)-W1(y-300)-W2=0
	W[2] = W[2] * 50;
	if (round(((W[1] * 300 + W[2] + W[0] * 300) / W[0]) <= 0) && (round((W[0] * 300 - W[2] + W[1] * 300) / W[1])) < 600 || round((-W[1] * 300 + W[2] + W[0] * 300) / W[0]) <= 0 && (round((W[0] * 300 - W[2] + W[1] * 300) / W[1]) >= 600))
	{
		x1 = 600;
		y1 = round((W[0] * 300 - W[2] +  W[1] * 300) / W[1]);
	}
	else
	{
		x1 = 0;
		y1 = round((-W[0] * 300 - W[2] + W[1] * 300) / W[1]);
	}
	if (y1 >= 600) {
		x2 = round((-W[1] * 300 + W[2] + W[0] * 300) / W[0]);
		y2 = 0;
	}
	else {
		x2 = round((W[1] * 300 + W[2] +  W[0] * 300) / W[0]);
		y2 = 600;
	}
	

	
	result[0] = x1;
	result[1] = y1;
	result[2] = x2;
	result[3] = y2;
	result[4] = cycle;
	// (y2-y1)*(X-x2)-((y-y2)*(x2-x1))=
	return result;
}

int *Delta(double *array,double *Weight, int arraySize, int Size)
{
	double *W = new double[Size];
	for (int i = 0; i < Size;i++)
		W[i] = Weight[i];
	double c = 0.5;
	double O;
	double d;
	double net = 0;
	double fnet;
	int j;
	int x1, y1, x2, y2;
	int *result = new int[5];
	bool status = true;
	double error;

	
	int cycle = 0;

	while (status)
	{
		error = 0;
		for (int i = 0; i < arraySize; i += (Size + 1))
		{
			for (j = 0; j < Size; j++)
			{
				net += W[j] * (array[i + j]);
			}
			d = array[i + j];

			
			O = (2 / (1 + exp(-net)))-1;
			fnet = 0.5*(1 - O*O);
			error += 0.5*pow((d-O),2);

			//agirliklari gunnceleriz
			continuous_updating_weight(W, array, Size, i, O, d, fnet, c);

			net = 0;
		}
		
		cycle++;
		if (error <0.1)
			status = false;
	}

	//W0*X + W1*Y - W2=0
	W[2] = W[2] * 50;
	if (round(((W[1] * 300 + W[2] + W[0] * 300) / W[0]) <= 0) && (round((W[0] * 300 - W[2] + W[1] * 300) / W[1])) < 600 || round((-W[1] * 300 + W[2] + W[0] * 300) / W[0]) <= 0 && (round((W[0] * 300 - W[2] + W[1] * 300) / W[1]) >= 600))
	{
		x1 = 600;
		y1 = round((W[0] * 300 - W[2] + W[1] * 300) / W[1]);
	}
	else
	{
		x1 = 0;
		y1 = round((-W[0] * 300 - W[2] + W[1] * 300) / W[1]);
	}
	if (y1 >= 600) {
		x2 = round((-W[1] * 300 + W[2] + W[0] * 300) / W[0]);
		y2 = 0;
	}
	else {
		x2 = round((W[1] * 300 + W[2] + W[0] * 300) / W[0]);
		y2 = 600;
	}


	result[0] = x1;
	result[1] = y1;
	result[2] = x2;
	result[3] = y2;
	result[4] = cycle;
	// (y2-y1)*(X-x2)-((y-y2)*(x2-x1))=
	return result;
}


int *MultiPerceptron(double *array, double *Weight, int arraySize, int Size, int NumberOfClass)
{
	double *W = new double[Size*NumberOfClass];
	for (int i = 0; i < Size*NumberOfClass ;i++)
		W[i] = Weight[i];

	double c = 0.5;
	int *O = new int[NumberOfClass];
	double *d = new double[NumberOfClass];
	double *net = new double[NumberOfClass];
	int j, k;
	int x1, y1, x2, y2;
	int *result = new int[4*NumberOfClass+1];
	bool status = true;
	int cycle = 0;

	for (int h = 0; h < NumberOfClass;h++)
		net[h] = 0;

	while (status)
	{
		status = false;
		for (int i = 0; i < arraySize; i += (Size + NumberOfClass))
		{

			for(int h=0; h<NumberOfClass; h++)
				for (j = 0; j < Size; j++)
				{
					net[h] += W[3*h+j] * (array[i + j]);
				}

			for (int h = 0; h < NumberOfClass; h++)
				d[h] = array[i + j + h];	//etiket
			for (int h = 0; h < NumberOfClass; h++)
				O[h] = sgn(net[h]);		//fonksyon sonucu

			for (int h = 0; h < NumberOfClass; h++)
			{
				if (d[h] != O[h])
				{
					for (int k = 0; k < Size; k++)
					{
						W[3*h+k] = W[3*h+k] + c * (d[h] - O[h])*(array[i+ k]);
					}
					status = true;
				}
			}

			for (int h = 0; h < NumberOfClass;h++)
				net[h] = 0;
			

		}
		cycle++;
	}

	
	for (int i = 2;i <Size*NumberOfClass;i += 3)
		W[i] = W[i] *50;

	for (int h = 0; h < NumberOfClass; h++)
	{
		//W0*X + W1*Y - W2=0
		//W0(x-400)+W1(y-400)-W2=0
		
		if (round(((W[3*h+1] * 300 + W[3 * h + 2] + W[3 * h + 0] * 300) / W[3 * h + 0]) <= 0) && (round((W[3 * h + 0] * 300 - W[3 * h + 2] + W[3 * h + 1] * 300) / W[3 * h + 1])) < 600 || round((-W[3 * h + 1] * 300 + W[3 * h + 2] + W[3 * h + 0] * 300) / W[3 * h + 0]) <= 0 && (round((W[3 * h + 0] * 300 - W[3 * h + 2] + W[3 * h + 1] * 300) / W[3 * h + 1]) >= 600))
		{
			x1 = 600;
			y1 = round((W[3 * h + 0] * 300 - W[3 * h + 2] + W[3 * h + 1] * 300) / W[3 * h + 1]);
		}
		else
		{
			x1 = 0;
			y1 = round((-W[3 * h + 0] * 300 - W[3 * h + 2] + W[3 * h + 1] * 300) / W[3 * h + 1]);
		}
		if (y1 >= 600) {
			x2 = round((-W[3 * h + 1] * 300 + W[3 * h + 2] + W[3 * h + 0] * 300) / W[3 * h + 0]);
			y2 = 0;
		}
		else {
			x2 = round((W[3 * h + 1] * 300 + W[3 * h + 2] + W[3 * h + 0] * 300) / W[3 * h + 0]);
			y2 = 600;
		}

		result[4*h+0] = x1;
		result[4*h+1] = y1;
		result[4*h+2] = x2;
		result[4*h+3] = y2;
	}
	

	result[4*NumberOfClass] = cycle;
	// (y2-y1)*(X-x2)-((y-y2)*(x2-x1))=

	return result;
}


int *MultiDelta(double *array, double *Weight, int arraySize, int Size, int NumberOfClass) {


	double *W = new double[Size*NumberOfClass];
	for (int i = 0; i < Size*NumberOfClass;i++)
		W[i] = Weight[i];

	double c = 0.5;
	double *O = new double[NumberOfClass];
	double *fnet = new double[NumberOfClass];
	double *d = new double[NumberOfClass];
	double *net = new double[NumberOfClass];
	int j, k;
	int x1, y1, x2, y2;
	int *result = new int[4 * NumberOfClass + 1];
	bool status = true;
	int cycle = 0;
	double *error = new double[NumberOfClass];

	for (int h = 0; h < NumberOfClass;h++)
		net[h] = 0;

	while (status)
	{

		for (int h = 0; h < NumberOfClass;h++)
			error[h] = 0;

		for (int i = 0; i < arraySize; i += (Size + NumberOfClass))
		{

			for (int h = 0; h<NumberOfClass; h++)
				for (j = 0; j < Size; j++)
				{
					net[h] += W[3 * h + j] * (array[i + j]);
				}
			
			for (int h = 0; h < NumberOfClass; h++)
				d[h] = array[i + j + h];	//etiket

			for (int h = 0; h < NumberOfClass; h++)
				O[h] = (2 / (1 + exp(-net[h]))) - 1;		//fonksyon sonucu
	
			for (int h = 0; h < NumberOfClass; h++)
				fnet[h] = 0.5*(1 - O[h] * O[h]);

			for(int h=0; h<NumberOfClass; h++)
				error[h] += 0.5*pow((d[h] - O[h]), 2);
			

			for (int h = 0; h < NumberOfClass; h++)
			{
			
				for (int k = 0; k < Size; k++)
				{
					W[3 * h + k] = W[3 * h + k] + c * (d[h] - O[h])*fnet[h]*(array[i + k]);
				}
			}

			for (int h = 0; h < NumberOfClass;h++)
				net[h] = 0;

		}
		cycle++;
		int temp = 0;
		for (int h = 0; h < NumberOfClass; h++)
		{
			if (error[h] < 0.1)
				temp++;
			if (temp == NumberOfClass)
				status = false;
		}
		
		
	}


	for (int i = 2;i <Size*NumberOfClass;i += 3)
		W[i] = W[i] * 50;

	for (int h = 0; h < NumberOfClass; h++)
	{
		//W0*X + W1*Y - W2=0
		//W0(x-400)+W1(y-400)-W2=0

		if (round(((W[3 * h + 1] * 300 + W[3 * h + 2] + W[3 * h + 0] * 300) / W[3 * h + 0]) <= 0) && (round((W[3 * h + 0] * 300 - W[3 * h + 2] + W[3 * h + 1] * 300) / W[3 * h + 1])) < 600 || round((-W[3 * h + 1] * 300 + W[3 * h + 2] + W[3 * h + 0] * 300) / W[3 * h + 0]) <= 0 && (round((W[3 * h + 0] * 300 - W[3 * h + 2] + W[3 * h + 1] * 300) / W[3 * h + 1]) >= 600))
		{
			x1 = 600;
			y1 = round((W[3 * h + 0] * 300 - W[3 * h + 2] + W[3 * h + 1] * 300) / W[3 * h + 1]);
		}
		else
		{
			x1 = 0;
			y1 = round((-W[3 * h + 0] * 300 - W[3 * h + 2] + W[3 * h + 1] * 300) / W[3 * h + 1]);
		}
		if (y1 >= 600) {
			x2 = round((-W[3 * h + 1] * 300 + W[3 * h + 2] + W[3 * h + 0] * 300) / W[3 * h + 0]);
			y2 = 0;
		}
		else {
			x2 = round((W[3 * h + 1] * 300 + W[3 * h + 2] + W[3 * h + 0] * 300) / W[3 * h + 0]);
			y2 = 600;
		}

		result[4 * h + 0] = x1;
		result[4 * h + 1] = y1;
		result[4 * h + 2] = x2;
		result[4 * h + 3] = y2;
	}


	result[4 * NumberOfClass] = cycle;
	// (y2-y1)*(X-x2)-((y-y2)*(x2-x1))=

	return result;
}


void coordinatelist::add(const double& e)
{
	coordinate *v = new coordinate;
	
	v->x = e;
	v->next = NULL;
	if (head == NULL)
		head = v;
	else
	{
		coordinate* first = head;
		while (first->next!=NULL)
		{
			first = first->next;
		}
		first->next = v;
	}
}

coordinatelist::coordinatelist()
{
	head = NULL;
}


int MultilayerNetwork(double *array, double *W,double *V, int arraySize, int Size, int NumberOfClass, int hiddenLayerSize)
{

	if (NumberOfClass <= 2)
		NumberOfClass = 1;
	double c1 = 0.5;
	double c2 = 0.3;
	double *Ok = new double[NumberOfClass];
	double *Oj = new double[hiddenLayerSize+1];
	double *fnetk = new double[NumberOfClass];
	double *fnetj = new double[hiddenLayerSize+1];
	double *d = new double[NumberOfClass];
	double *netj = new double[hiddenLayerSize];
	double *netk = new double[NumberOfClass];
	int j, k;
	int x1, y1, x2, y2;
	bool status = true;
	int cycle = 0;
	//double *error = new double[NumberOfClass];
	double error = 0;
	for (int h = 0; h < hiddenLayerSize; h++)
		netj[h] = 0;
	for (int h = 0; h < NumberOfClass;h++)
		netk[h] = 0;

	while (status)
	{

		
		//for (int h = 0; h < NumberOfClass; h++)
			error = 0;

		for (int i = 0; i < arraySize; i += (Size + NumberOfClass))
		{
			//ara katmandaki noronlarýn cikislarini hesapladik(O1,O2,...On)
			for (int h = 0; h < hiddenLayerSize; h++)
				for (j = 0; j < Size; j++)
				{
					netj[h] += V[h*Size + j] * (array[i + j]);
				}

			//etiket
			for (int h = 0; h < NumberOfClass; h++)
				d[h] = array[i + j + h];

			//ara katman fonksyon sonucu
			for (int h = 0; h < hiddenLayerSize; h++)
				Oj[h] = tanh(netj[h]);
			Oj[hiddenLayerSize] = -1;
			//ara katman treuvinin hesaplanmasi
			for (int h = 0; h < hiddenLayerSize+1; h++)
				fnetj[h] = 0.5*(1 - Oj[h] * Oj[h]);

			//2. katmandaki noron cikislari
			for (int h = 0; h < NumberOfClass; h++)
				for (j = 0; j < (hiddenLayerSize + 1); j++)
				{
					netk[h] += W[h*(hiddenLayerSize + 1) + j] * (Oj[j]);
				}
			//2.katman fonksyon sonucu
			for (int h = 0; h < NumberOfClass; h++)
				Ok[h] = tanh(netk[h]);

			//2.katman turev'inin hesaplanmasi
			for (int h = 0; h < NumberOfClass; h++)
				fnetk[h] = 0.5*(1 - Ok[h] * Ok[h]);

			for (int h = 0; h < NumberOfClass; h++)
				error+= 0.5*pow((d[h] - Ok[h]), 2);

			//BACKWARD deltaW(kj) = c(dk-ok)fnet(yj)

			for (int k = 0; k < NumberOfClass; k++)
			{

				for (int j = 0; j < hiddenLayerSize + 1; j++)
				{
					W[k*(hiddenLayerSize + 1) + j] = W[k*(hiddenLayerSize + 1) + j] + (c1 * (d[k] - Ok[k])*fnetk[k] * Oj[j]);
					
				}
			}

			for (int j = 0; j < hiddenLayerSize+1; j++)
			{
				for (int ii = 0; ii < Size; ii++)
				{
					for (int k = 0; k < NumberOfClass; k++)
					{
						V[j*Size + ii] = V[j* Size + ii] + (c2 * fnetj[j] * array[i + ii] * ((d[k] - Ok[k])*fnetk[k] * W[k*hiddenLayerSize + j]));
						
					}
				}
			}

			for (int h = 0; h < hiddenLayerSize; h++)
				netj[h] = 0;
			for (int h = 0; h < NumberOfClass;h++)
				netk[h] = 0;

		}
		cycle++;

		if (error < 0.01)
			status = false;

		/*int temp = 0;
		for (int h = 0; h < NumberOfClass; h++)
		{
			if (error[h] < 0.01)
				temp++;
			if (temp == NumberOfClass)
				status = false;
		}*/

	}
	

	return cycle;
}

int MultiLayerNetworkResultView(double *array,double *W,double *V, int Size, int NumberOfClass, int hiddenLayerSize)
{

	if (NumberOfClass <= 2)
		NumberOfClass = 1;
	double *Ok = new double[NumberOfClass];
	double *Oj = new double[hiddenLayerSize + 1];
	double *fnetk = new double[NumberOfClass];
	double *fnetj = new double[hiddenLayerSize + 1];
	double *netj = new double[hiddenLayerSize];
	double *netk = new double[NumberOfClass];
	int result;
	
	array[0] = (array[0] - GlobalMx) / Globalx_sDeviation;
	array[1] = (array[1] - GlobalMy) / Globaly_sDeviation;
	

	for (int h = 0; h < hiddenLayerSize; h++)
		netj[h] = 0;
	for (int h = 0; h < NumberOfClass;h++)
		netk[h] = 0;


		//ara katmandaki noronlarýn cikislarini hesapladik(O1,O2,...On)
		for (int h = 0; h < hiddenLayerSize; h++)
			for (int j = 0; j < Size; j++)
			{
				netj[h] += V[h*Size + j] * (array[j]);
			}

		//ara katman fonksyon sonucu
		for (int h = 0; h < hiddenLayerSize; h++)
			Oj[h] = tanh(netj[h]);
		Oj[hiddenLayerSize] = -1;
		//ara katman treuvinin hesaplanmasi
		for (int h = 0; h < hiddenLayerSize + 1; h++)
			fnetj[h] = 0.5*(1 - Oj[h] * Oj[h]);

		//2. katmandaki noron cikislari
		for (int h = 0; h < NumberOfClass; h++)
			for (int j = 0; j < (hiddenLayerSize + 1); j++)
			{
				netk[h] += W[h*(hiddenLayerSize + 1) + j] * (Oj[j]);
			}
		//2.katman fonksyon sonucu
		for (int h = 0; h < NumberOfClass; h++)
			Ok[h] = tanh(netk[h]);

		double max = Ok[0];
		for (int h = 0; h < NumberOfClass; h++)
		{
			if (NumberOfClass == 1)
			{
				if (Ok[h] > 0)
					result = 0;
				else
				{
					result = 1;
				}
			}
			else
			{
				if (Ok[h] >= max)
				{
					max = Ok[h];
					result = h;
				}
			}
			
			
		}
		


		return result;
}



int MultilayerNetworkMoment(double *array, double *W, double *V, int arraySize, int Size, int NumberOfClass, int hiddenLayerSize)
{

	if (NumberOfClass <= 2)
		NumberOfClass = 1;
	double c1 = 0.5;
	double c2 = 0.3;
	double alfa = 0.7;
	double *Ok = new double[NumberOfClass];
	double *Oj = new double[hiddenLayerSize + 1];
	double *fnetk = new double[NumberOfClass];
	double *fnetj = new double[hiddenLayerSize + 1];
	double *d = new double[NumberOfClass];
	double *netj = new double[hiddenLayerSize];
	double *netk = new double[NumberOfClass];
	double *moment1 = new double[NumberOfClass*(hiddenLayerSize+1)];
	double *moment2 = new double[Size*hiddenLayerSize];
	int j, k;
	//int x1, y1, x2, y2;
	bool status = true;
	int cycle = 0;
	double error=0;

	for (int h = 0; h < hiddenLayerSize; h++)
		netj[h] = 0;
	for (int h = 0; h < NumberOfClass;h++)
		netk[h] = 0;
	for (int h = 0; h < (NumberOfClass*(hiddenLayerSize + 1)); h++)
		moment1[h] = 0;
	for (int h = 0; h < Size*hiddenLayerSize; h++)
		moment2[h] = 0;

	while (status)
	{


		
			error = 0;

		for (int i = 0; i < arraySize; i += (Size + NumberOfClass))
		{
			//ara katmandaki noronlarýn cikislarini hesapladik(O1,O2,...On)
			for (int h = 0; h < hiddenLayerSize; h++)
				for (j = 0; j < Size; j++)
				{
					netj[h] += V[h*Size + j] * (array[i + j]);
				}

			//etiket
			for (int h = 0; h < NumberOfClass; h++)
				d[h] = array[i + j + h];

			//ara katman fonksyon sonucu
			for (int h = 0; h < hiddenLayerSize; h++)
				Oj[h] = tanh(netj[h]);
			Oj[hiddenLayerSize] = -1;
			//ara katman treuvinin hesaplanmasi
			for (int h = 0; h < hiddenLayerSize + 1; h++)
				fnetj[h] = 0.5*(1 - Oj[h] * Oj[h]);

			//2. katmandaki noron cikislari
			for (int h = 0; h < NumberOfClass; h++)
				for (j = 0; j < (hiddenLayerSize + 1); j++)
				{
					netk[h] += W[h*(hiddenLayerSize + 1) + j] * (Oj[j]);
				}
			//2.katman fonksyon sonucu
			for (int h = 0; h < NumberOfClass; h++)
				Ok[h] = tanh(netk[h]);

			//2.katman turev'inin hesaplanmasi
			for (int h = 0; h < NumberOfClass; h++)
				fnetk[h] = 0.5*(1 - Ok[h] * Ok[h]);

			for (int h = 0; h < NumberOfClass; h++)
				error += 0.5*pow((d[h] - Ok[h]), 2);

			//error = sqrt(error);

			//BACKWARD deltaW(kj) = c(dk-ok)fnet(yj)

			for (int k = 0; k < NumberOfClass; k++)
			{

				for (int j = 0; j < hiddenLayerSize + 1; j++)
				{
					W[k*(hiddenLayerSize + 1) + j] = W[k*(hiddenLayerSize + 1) + j] + (c1 * (d[k] - Ok[k])*fnetk[k] * Oj[j]) + (alfa*moment1[k*(hiddenLayerSize + 1) + j]);
					moment1[k*(hiddenLayerSize + 1) + j] = (c1 * (d[k] - Ok[k])*fnetk[k] * Oj[j]);

				}
			}

			for (int j = 0; j < hiddenLayerSize + 1; j++)
			{
				for (int ii = 0; ii < Size; ii++)
				{
					for (int k = 0; k < NumberOfClass; k++)
					{
						V[j*Size + ii] = V[j* Size + ii] + (c2 * fnetj[j] * array[i + ii] * ((d[k] - Ok[k])*fnetk[k] * W[k*hiddenLayerSize + j])) + (alfa*moment2[j*Size + ii]);
						moment2[j*Size + ii] = (c2 * fnetj[j] * array[i + ii] * ((d[k] - Ok[k])*fnetk[k] * W[k*hiddenLayerSize + j]));
					}
				}
			}

			for (int h = 0; h < hiddenLayerSize; h++)
				netj[h] = 0;
			for (int h = 0; h < NumberOfClass;h++)
				netk[h] = 0;

		}
		cycle++;
		
		
	
		if (error < 0.01)
			status = false;
			
				
	

	}


	return cycle;
}