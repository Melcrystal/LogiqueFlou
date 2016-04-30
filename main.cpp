// FWK VS.cpp : définit le point d'entrée pour l'application console.
//

#include <iostream>
#include "headers.h"

using namespace std;
using namespace core;
using namespace fuzzy;


/*void testOp(){
	core::ValueModel<double> mmin, nnmin;
	double min = 0.5, nmin = 0.7;
	mmin.setValue(min);
	nnmin.setValue(nmin);

	cout << "mmin : " << mmin.getValue() << " ; nmin : " << nnmin.getValue() << "\n************" << endl;

	cout << "AndMin : ";
	fuzzy::AndMin<double> andmin;
	cout << andmin.evaluate(&mmin, &nnmin) << endl;

	cout << "AndMult : ";
	fuzzy::AndMult<double> andmult;
	cout << andmult.evaluate(&mmin, &nnmin) << endl;

	cout << "AggMax : ";
	fuzzy::AggMax<double> aggmax;
	cout << aggmax.evaluate(&mmin, &nnmin) << endl;

	cout << "AggPlus : ";
	fuzzy::AggPlus<double> aggplus;
	cout << aggplus.evaluate(&mmin, &nnmin) << endl;

	cout << "OrMax : ";
	fuzzy::OrMax<double> ormax;
	cout << ormax.evaluate(&mmin, &nnmin) << endl;

	cout << "OrMult : ";
	fuzzy::OrPlus<double> ormin;
	cout << ormin.evaluate(&mmin, &nnmin) << endl;

}*/

int TestCathie(){
	AndMin<double> opAnd;
	OrMax<double> opOr;
	ThenMin<double> opThen;
	AggMax<double> opAgg;
	CogDefuzz<double> opDefuzz(0, 40, 1);
	NotMinus1<double> opNot;

	FuzzyFactory<double> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);

	//Membership function

	//First Parameter : Climate
	double minRainy = -11;
	double midRainy = 13;
	double maxRainy = 23;
	IsTrapezeLeft<double> rainy(minRainy, midRainy, maxRainy);

	double minSunny = 13;
	double midSunny = 23;
	double maxSunny = 41;
	IsTrapezeRight<double> sunny(minSunny, midSunny, maxSunny);

	//Second Parameter : Dampness
	double minDry = -1;
	double midDry = 40;
	double maxDry = 60;
	IsTrapezeLeft<double> dry(minDry, midDry, maxDry);

	double minWet = 40;
	double midWet = 60;
	double maxWet = 101;
	IsTrapezeRight<double> wet(minWet, midWet, maxWet);

	//Third Parameter : Watering time
	double minSho = -1;
	double midSho = 25;
	double maxSho = 35;
	IsTrapezeLeft<double> sho(minSho, midSho, maxSho);

	double minLon = 25;
	double midLon = 35;
	double maxLon = 60;
	IsTrapezeRight<double> lon(minLon, midLon, maxLon);


	cout << endl << "Climate : " << endl << "     Rainy [0, 23]" << endl << "     Sunny [13, 40]" << endl << endl;
	cout << endl << "Dampness : " << endl << "     Dry [0, 60]" << endl << "     Wet [40, 100]" << endl << endl;
	cout << endl << "Watering Time : " << endl << "     Short [0, 35]" << endl << "     Long [25, 60]" << endl << endl;


	ValueModel<double> dampness(0);
	ValueModel<double> climate(0);
	ValueModel<double> watering(0);

	float s;
	float d;

	Expression<double> *system;
	Expression<double> *r;


	r =
		f.newAgg(
		f.newAgg(
		f.newAgg(
		f.newThen(
		f.newAnd(
		f.newIs(&sunny, &climate),
		f.newIs(&lon, &watering)
		),
		f.newAnd(
		f.newIs(&dry, &dampness),
		f.newIs(&lon, &watering)
		)
		),
		f.newThen(
		f.newAnd(
		f.newIs(&rainy, &climate),
		f.newIs(&sho, &watering)
		),
		f.newAnd(
		f.newIs(&wet, &dampness),
		f.newIs(&sho, &watering)
		)
		)
		),
		f.newThen(
		f.newAnd(
		f.newIs(&sunny, &climate),
		f.newIs(&sho, &watering)
		),
		f.newAnd(
		f.newIs(&wet, &dampness),
		f.newIs(&sho, &watering)
		)
		)
		),
		f.newThen(
		f.newAnd(
		f.newIs(&rainy, &climate),
		f.newIs(&lon, &watering)
		),
		f.newAnd(
		f.newIs(&dry, &dampness),
		f.newIs(&lon, &watering)
		)
		)
		);

	system = f.newDefuzz(&watering, r);

	while (true)
	{
		cout << "Climate : "; cin >> s;
		cout << "Dampness : "; cin >> d;
		if (s == 777 || d == 777)
			break;
		climate.setValue(s);
		dampness.setValue(d);
		cout << "Watering Time -> " << (system->evaluate()) << endl << endl;

	}

	return 0;
}
/*
int main(){

	fuzzy::NotMinus1<double> opNot;
	fuzzy::AndMin<double> opAnd;
	fuzzy::OrMax<double> opOr;
	fuzzy::ThenMin<double> opThen;
	fuzzy::AggMax<double> opAgg;
	fuzzy::CogDefuzz<double> opDefuzz(0, 40, 1);

	FuzzyFactory<double> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);

	//1er parametre
	fuzzy::IsTrapezeLeft<double> poor(0, 5, 10);
	fuzzy::isTriangle<double> good(5, 10, 15);
	fuzzy::IsTrapezeRight<double> excellent(10, 15, 20);

	//2e parametre
	fuzzy::IsTrapezeLeft<double> cheap(0, 15, 20);
	fuzzy::isTriangle<double> average(15, 20, 25);
	fuzzy::IsTrapezeRight<double> generous(25, 30, 35);

	//Decision du systeme
	core::ValueModel<double> service(0);
	core::ValueModel<double> food(0);
	core::ValueModel<double> tips(0);

	core::Expression<double> *system;

	core::Expression<double> *r;
			
		r =
		(core::Expression<double>*)f.newAgg(
			(core::Expression<double>*)f.newAgg(
				(core::Expression<double>*)f.newThen(
					(core::Expression<double>*)f.newIs(&poor, &service),
					(core::Expression<double>*)f.newIs(&cheap, &tips)
				),
				(core::Expression<double>*)f.newThen(
					(core::Expression<double>*)f.newIs(&good, &service),
					(core::Expression<double>*)f.newIs(&average, &tips)
				)
			),
				(core::Expression<double>*)f.newThen(
					(core::Expression<double>*)f.newIs(&excellent, &service),
					(core::Expression<double>*)f.newIs(&generous, &tips)
			)
		);



		std::cout << "Service :\n\tPoor : [ -5, 5]\n\tGood :[0, 10]\n\tExcellent : [5, 15]"
			<< std::endl << "Food :\n\tCheap : [0, 15]\n\tAverage : [10, 20]\n\tGenerous : [15, 30]\n\n";

	system = (core::Expression<double>*)f.newDefuzz(&tips, r);

	double s, fd;
	while (true){
		std::cout << "Service :";
		std::cin >> s;
		service.setValue(s);

		std::cout << "Food : ";
		std::cin >> fd;
		food.setValue(fd);

		std::cout << "Tips ->" << system->evaluate() << std::endl;  // Y'a un probleme ici ?
		std::cout << std::endl;
	}

	cin.ignore();

	return 0;

}
*/

int _tmain(int argc, _TCHAR* argv[])
{
	TestCathie();
	//main();
	return 0;
}


