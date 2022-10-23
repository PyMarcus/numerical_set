#include <bits/stdc++.h>
#include <vector>


class Conjuntos{
	/*
		Realiza operações básicas
		de dois conjuntos.
	*/

	private:
		std::vector<int> a;
		std::vector<int> b;

		void print(std::vector<int> result){
			for(int element: result){
				std::cout << element << " ";
			}
			std::cout << std::endl;
		}


	public:
		Conjuntos(std::vector<int> a, std::vector<int> b)
		{
			this->a = a;
			this->b = b;
		}

		std::vector<int> get_a()
		{
			return this->a;
		} 
		
		std::vector<int> get_b()
		{
			return this->b;
		} 
		

		std::vector<int> _union(){
			/*
				{A U B / x E A ou x E B}
			*/
			std::vector<int> uni;
			std::vector<int> aux;


			for(int element: get_a()){
				aux.push_back(element);
			}
			uni.push_back(aux.at(0));
			for(int element: aux){
				if(*std::find(uni.begin(), uni.end(), element) != element){
					uni.push_back(element);
				}
			}

			for(int element: get_b()){
				if(*std::find(uni.begin(), uni.end(), element) != element){
					uni.push_back(element);
				}
			}

			return uni;
		}

		std::vector<int> _intersection(){
			/*
				{A ∩ B / x ∈ A e x ∉ B}
			*/
			std::vector<int> inter;
			std::vector<int> aux;
			std::vector<int> a = get_a();
			std::vector<int> b = get_b();
		
			for(int j = 0; j < a.size(); ++j){
				for(int i = 0; i < b.size(); ++i){
					if(a.at(j) == b.at(i)){
						aux.push_back(b.at(i));
					}
				}
			}
			inter.push_back(aux.at(0));
			for(int element: aux){
				if(*std::find(inter.begin(), inter.end(), element) != element){
					inter.push_back(element);
				}
			}
			
			return inter;
		}

		std::vector<int> _difference()
		{
			/*
				{A - B / x ∈ A e x ∉ B}
			*/
			std::vector<int> aux;
			std::vector<int> ax;
			
			aux = _intersection();
			for(int element: get_a()){
				if(*std::find(aux.begin(), aux.end(), element) != element){
					ax.push_back(element);
				}
			}
			if(ax.size() > 0){
				return ax;
			}

			std::cout << "{}";
			ax.push_back(-1);
			return ax;
			
		}

		std::vector<int> _sum()
		{
			std::vector<int> aux;

			for(int element: get_a()){
				aux.push_back(element);
			}

			for(int element: get_b()){
				aux.push_back(element);
			}

			return aux;
		}

		std::vector<int> _cartesian_product();

		std::vector<int> _potency();

};


void operations()
{
	std::vector<int> a;
	std::vector<int> b;

	a.push_back(1);a.push_back(2);a.push_back(3);a.push_back(4); // 1 2 3 4
	b.push_back(3);b.push_back(4);b.push_back(5);b.push_back(6); // 3 4 5 6

	Conjuntos operacoes = Conjuntos(a, b);	

	operacoes._union();
	operacoes._intersection();
	operacoes._difference();
}


int main(int argc, char *argv[]){

	std::ios::sync_with_stdio(false);
	try{
		if(argv[1] == std::string("start")){
			
			operations();

		}
	}catch(std::exception& e){
		
	}
		return 0;
	}
