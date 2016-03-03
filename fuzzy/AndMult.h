#ifndef ANDMULT_H_INCLUDED
#define ANDMULT_H_INCLUDED


namespace fuzzy{

template <class T>
	class AndMult : public And<T>{

		public :
			AndMult();
			~AndMult();

			T evaluate(core::Expression<T>*, core::Expression<T>*);

	};


	template <class T>
	AndMult<T>::AndMult(){
	}

	template <class T>
	AndMult<T>::~AndMult(){
	}

	template <class T>
	T AndMult<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right ){
		T l = left->evaluate();
		T r = right->evaluate();
		return (l *r);
	}

}
#endif // ANDMULT_H_INCLUDED
