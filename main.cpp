#include <iostream>
#include "headers.h"

using namespace std;

int main(){
	fuzzy::NotMinus1<int> opNot;
	fuzzy::AndMin<int> opAnd;
	fuzzy::OrMax<int> opOr;
	fuzzy::ThenMin<int> opThen;
	fuzzy::AggMax<int> opAgg;
	CogDefuzz<int> opDefuzz(0,20,5);

	FuzzyFactory<int> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

	fuzzy::isTriangle<int> poor(-5,0,5);
	fuzzy::isTriangle<int> good(0,5,10);
	fuzzy::isTriangle<int> excellent(5,10,15);


	fuzzy::isTriangle<int> cheap(0,5,10);
	fuzzy::isTriangle<int> average(10,15,20);
	fuzzy::isTriangle<int> generous(20,25,30);

	core::ValueModel<int> service(0);
	core::ValueModel<int> food(0);
	core::ValueModel<int> tips(0);

	core::Expression<int> *r =
		f.newAgg(
				f.newAgg(
							f.newThen(
											f.newIs(&poor, &service),
											f.newIs(&cheap,&tips)
							),
							f.newThen(
											f.newIs(&good,&service),
											f.newIs(&average,&tips)
						))
				,
							f.newThen(
										f.newIs(&excellent,&service),
										f.newIs(&generous,&tips)
							)
				)
		);


	core::Expression<int> *system = f.newDefuzz(&tips,r);

	float s;
	while (true){
			std::cout << "service";
			std::cin >> s;
			service.setValue(s);
            std::cout << "tips ->" << system->evaluate()  << std::endl;
	}

}
