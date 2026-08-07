#include <iostream>
#include <string>
#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <utility>

namespace structures
{
    template <typename T>
    class Vector{
        public:
            Vector() : dados_(nullptr), tamanho_(0), capacidade_(0) {}

            ~Vector() {delete[] dados_;}

            Vector(const Vector& outro)
                :   dados_(new T[outro.capacidade_]),
                    tamanho_(outro.tamanho_),
                    capacidade_(outro.capacidade_){
                        for (std::size_t i = 0; i < tamanho_; ++i)
                            dados_[i] = outro.dados_[i];
                    }
            
            Vector& operator=(const Vector& outro){
                if(this == &outro) return *this;

                T* novo = new T[outro.capacidade_];
                for(std::size_t i = 0; i < outro.tamanho_; ++i)
                    novo[i] = outro.dados_[i];

                delete[] dados_;
                dados_      = novo;
                tamanho_    = outro.tamanho_;
                capacidade_ = outro.capacidade_;
                return *this;
            }

            Vector(Vector&& outro) noexcept
                :   dados_(outro.dados_),
                    tamanho_(outro.tamanho_),
                    capacidade_(outro.capacidade_){
                        outro.dados_        = nullptr;
                        outro.tamanho_      = 0;
                        outro.capacidade_   = 0;
                    }
            
            Vector& operator=(Vector&& outro) noexcept {
                if(this == &outro) return *this;
                delete[] dados_;
                dados_              = outro.dados_;
                tamanho_            = outro.tamanho_;
                capacidade_         = outro.capacidade_;
                outro.dados_        = nullptr;
                outro.tamanho_      = 0;
                outro.capacidade_   = 0;
                return *this;
            }

            void reserve(std::size_t nova_capacidade){
                if(nova_capacidade <= capacidade_) return;

                T* novo = new T[nova_capacidade];
                for(std::size_t i = 0; i< tamanho_; ++i)
                    novo[i] = std::move(dados_[i]);

                delete [] dados_;
                dados_      = novo;
                capacidade_ = nova_capacidade;
            }

            void push_back(const T& valor){
                if(tamanho_ == capacidade_)
                    reserve(capacidade_ == 0 ? 1 : capacidade_ * 2);
                dados_[tamanho_++] = valor;
            }

            void pop_back() {
                if(tamanho_ == 0)
                    throw std::out_of_range("pop_back em Vector vazio");
                --tamanho_;
            }

            T&       operator[](std::size_t i)       { return dados_[i]; }
            const T& operator[](std::size_t i) const { return dados_[i]; }

            T& at(std::size_t i){
                if(i >= tamanho_)
                    throw std::out_of_range("Vector::at - indice fora do intervalo");
                return dados_[i];
            }

            std::size_t size()      const { return tamanho_; }
            std::size_t capacity()  const { return capacidade_; }
            bool        empty()     const { return tamanho_ == 0; }
            void        clear()           { tamanho_ = 0; }

            T* begin() { return dados_; }
            T* end()   { return dados_ + tamanho_; }


        private:
            T*          dados_;
            std::size_t tamanho_;
            std::size_t capacidade_;
    };
    
} // namespace structures



void tests() {

    std::cout << "Teste 1...";
    structures::Vector<int> v1;
    assert(v1.empty());
    assert(v1.size() == 0);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 2...";
    for (int i = 0; i < 5; ++i) v1.push_back(i * 10);
    assert(v1.size() == 5);
    assert(v1[0] == 0 && v1[4] == 40);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 3...";
    // capacidade cresce 0 -> 1 -> 2 -> 4 -> 8, nunca menor que o tamanho
    assert(v1.capacity() >= v1.size());
    assert(v1.capacity() == 8);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 4...";
    bool estourou = false;
    try { v1.at(99); } catch (const std::out_of_range&) { estourou = true; }
    assert(estourou);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 5...";
    structures::Vector<int> v2 = v1;                          // copia profunda
    v2[0] = 999;
    assert(v1[0] == 0);                                       // original intacto
    assert(v2[0] == 999);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 6...";
    structures::Vector<int> v3 = std::move(v2);               // move
    assert(v3.size() == 5);
    assert(v2.size() == 0);                                   // origem esvaziada
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 7...";
    int soma = 0;
    for (int x : v1) soma += x;                               // range-for
    assert(soma == 100);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 8...";
    v1.pop_back();
    assert(v1.size() == 4);
    v1.clear();
    assert(v1.empty());
    assert(v1.capacity() == 8);                               // clear nao libera
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 9...";
    structures::Vector<std::string> v4;                       // funciona com tipos
    v4.push_back("oracle");                                   // nao triviais
    v4.push_back("apex");
    assert(v4.size() == 2);
    assert(v4[1] == "apex");
    std::cout << "Passou!" << std::endl;

}

int main() {
    tests();
    return 0;
}