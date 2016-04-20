#include <iostream>
#include "headers.h"

using namespace std;

void testOp(){
	core::ValueModel<float> mmin, nnmin;
    float min =0.5, nmin =0.7;
    mmin.setValue(min);
    nnmin.setValue(nmin);

	cout << "mmin : " << mmin.getValue() << " ; nmin : " << nnmin.getValue() << "\n************" << endl;

	cout << "AndMin : ";
    fuzzy::AndMin<float> andmin;
    cout << andmin.evaluate(&mmin,&nnmin)<< endl;

	cout << "AndMult : ";
    fuzzy::AndMult<float> andmult;
    cout << andmult.evaluate(&mmin,&nnmin) << endl;

	cout << "AggMax : ";
    fuzzy::AggMax<float> aggmax;
    cout << aggmax.evaluate(&mmin,&nnmin) << endl;

	cout << "AggPlus : ";
    fuzzy::AggPlus<float> aggplus;
    cout << aggplus.evaluate(&mmin,&nnmin) << endl;

	cout << "OrMax : ";
    fuzzy::OrMax<float> ormax;
    cout << ormax.evaluate(&mmin,&nnmin) << endl;

	cout << "OrMult : ";
    fuzzy::OrPlus<float> ormin;
    cout << ormin.evaluate(&mmin,&nnmin) << endl;


}

int main(){

	fuzzy::NotMinus1<float> opNot;
	fuzzy::AndMin<float> opAnd;
	fuzzy::OrMax<float> opOr;
	fuzzy::ThenMin<float> opThen;
	fuzzy::AggMax<float> opAgg;
	fuzzy::CogDefuzz<float> opDefuzz(0,20,5);

	FuzzyFactory<float> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

	fuzzy::isTriangle<float> poor(-5,0,5);
	fuzzy::isTriangle<float> good(0,5,10);
	fuzzy::isTriangle<float> excellent(5,10,15);


	fuzzy::isTriangle<float> cheap(0,5,10);
	fuzzy::isTriangle<float> average(10,15,20);
	fuzzy::isTriangle<float> generous(20,25,30);

	core::ValueModel<float> service(0);
	core::ValueModel<float> food(0);
	core::ValueModel<float> tips(0);

	core::Expression<float> *r =
		(core::Expression<float>*)f.newAgg(
				(core::Expression<float>*)f.newAgg(
							(core::Expression<float>*)f.newThen(
											(core::Expression<float>*)f.newIs(&poor, &service),
											(core::Expression<float>*)f.newIs(&cheap,&tips)
							),
							(core::Expression<float>*)f.newThen(
											(core::Expression<float>*)f.newIs(&good,&service),
											(core::Expression<float>*)f.newIs(&average,&tips)
						))
				,
							(core::Expression<float>*)f.newThen(
										(core::Expression<float>*)f.newIs(&excellent,&service),
										(core::Expression<float>*)f.newIs(&generous,&tips)
							)
				);


	core::Expression<float> *system = (core::Expression<float>*)f.newDefuzz(&tips,r);

	float s;
	while (true){
			std::cout << "service";
			std::cin >> s;
			service.setValue(s);
            std::cout << "tips ->" << system->evaluate()  << std::endl;  // Y'a un probleme ici ?
            std::cout << std::endl;
	}

	cin.ignore();

}
