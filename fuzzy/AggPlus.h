#ifndef AGGPLUS_H_INCLUDED
#define AGGPLUS_H_INCLUDED

namespace fuzzy{

	template <class T>
	class AggPlus : public fuzzy::Agg<T>{

	public :
			AggPlus();
			~AggPlus();

            T evaluate(core::Expression<T>*, core::Expression<T>*);
	};

	template <class T>
	AggPlus<T>::AggPlus(){
	}

	template <class T>
	AggPlus<T>::~AggPlus(){
	}

	template <class T>
	T AggPlus<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right){
		T l = left->evaluate();
		T r = right->evaluate();
		return (l + r);
	}

}

#endif // AGGPLUS_H_INCLUDED
