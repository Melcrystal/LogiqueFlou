#ifndef FUZZYFACTORY_H_INCLUDED
#define FUZZYFACTORY_H_INCLUDED

#include "FactoryExpression.h"
#include "../fuzzy/operators.h"
#include "Expression.h"
#include "BinaryShadowExpression.h"
#include "UnaryShadowExpression.h"

namespace core{

	template <class T>
	class FuzzyFactory : public FactoryExpression<T>{

		public:
			FuzzyFactory(UnaryExpression<T>*, BinaryExpression<T>*, BinaryExpression<T>*, BinaryExpression<T>*,BinaryExpression<T>*, BinaryExpression<T>*);
			virtual ~FuzzyFactory();

			Expression<T>* newAnd(Expression<T>*, Expression<T>*);
			Expression<T>* newOr(Expression<T>*, Expression<T>*);
			Expression<T>* newThen(Expression<T>*, Expression<T>*);
			Expression<T>* newAgg(Expression<T>*, Expression<T>*);
			Expression<T>* newDefuzz(Expression<T>*, Expression<T>*);
			Expression<T>* newNot(Expression<T>*);
			Expression<T>* newIs(fuzzy::Is<T>*, Expression<T>*);

			void changeAnd(fuzzy::And<T>*);
			void changeOr(fuzzy::Or<T>*);
			void changeThen(fuzzy::Then<T>*);

			//T evaluate();    //Fonction pas encore codee

		private:
			BinaryShadowExpression<T> *And, *Or, *Then, *Agg, *Defuzz;
			UnaryShadowExpression<T>* Not;
	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(UnaryExpression<T>* opNot, BinaryExpression<T>* opAnd, BinaryExpression<T>* opOr, BinaryExpression<T>* opThen,BinaryExpression<T>* opAgg, BinaryExpression<T>* opDefuzz):
		Not(new UnaryShadowExpression<T>(opNot)),And(new BinaryShadowExpression<T>(opAnd)),Or(new BinaryShadowExpression<T>(opOr)),Then(new BinaryShadowExpression<T>(opThen)),Agg(new BinaryShadowExpression<T>(opAgg)),Defuzz(new BinaryShadowExpression<T>(opDefuzz)){
	}

	template <class T>
	FuzzyFactory<T>::~FuzzyFactory(){
        delete And,Or,Then,Agg,Defuzz,Not;
	}
/******************************
	template <class T>
	T FuzzyFactory<T>::evaluate(){

	}
/*****************************************/
    template <class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>*l,Expression<T>*r){
		return this->newBinaryExpression(And,l,r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r){
		return this->newBinaryExpression(Or,l,r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r){
		return this->newBinaryExpression(Then, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r){
		return this->newBinaryExpression(Agg, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r){
		return this->newBinaryExpression(Defuzz, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* o){
		return this->newUnaryExpression(Not, o);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newIs(fuzzy::Is<T>* is, Expression<T>* o){
		return this->newUnaryExpression(is, o);
	}

	template <class T>
	void FuzzyFactory<T>::changeAnd(fuzzy::And<T>* o){
		And->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeOr(fuzzy::Or<T>* o){
		Or.setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeThen(fuzzy::Then<T>* o){
		Then.setTarget(o);
	}

}

#endif // FUZZYFACTORY_H_INCLUDED
