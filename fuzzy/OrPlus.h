#ifndef ORPLUS_H_INCLUDED
#define ORPLUS_H_INCLUDED

namespace fuzzy{

	template <class T>
	class OrPlus : public fuzzy::Or<T>{

	public :
			OrPlus();
			~OrPlus();

            T evaluate(core::Expression<T>*, core::Expression<T>*);
	};

	template <class T>
	OrPlus<T>::OrPlus(){
	}

		template <class T>
	OrPlus<T>::~OrPlus(){
	}

	template <class T>
	T OrPlus<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right){
		T l = left->evaluate();
		T r = right->evaluate();
		return (l + r);
	}

}

#endif // ORPLUS_H_INCLUDED
